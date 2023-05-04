//
// Created by Louvenia Dione on 2/3/23.
//
#include <chrono>

#include "headers/Emnist_sample.hpp"
#include "headers/MatrixNet.hpp"

namespace s21 {

auto NetInterface::TrainMode(const std::string &fileName, const size_t epoch)
    -> v_double {
  Emnist_reader reader;
  v_double error;

  for (int i = 0; i < epoch; i++) {
    reader.Connect(fileName);
    const int ex = reader.GetAmount();
    int accuracy = 0;
    for (int j = 0; j < ex; j++) {
      v_double right(topology.back());
      Sample sample = reader.GetSample();
      right[sample.answer - 1] = 1;
      FeedInitValues(sample.pixels);
      ForwardFeed();
      GetResVector();
      if (sample.answer - 1 == GetResult()) accuracy++;
      BackPropagation(right);
    }
    accuracy =
        (static_cast<double>(accuracy) / static_cast<double>(ex) * 100.0);
    error.push_back(100.0 - accuracy);
  }
  reader.Disconnect();
  return error;
}

auto NetInterface::TestMode(const std::string &fileName, const double DataCoef)
    -> Info {
  Emnist_reader reader;
  Info info;

  reader.Connect(fileName);
  const int usage = static_cast<int>(reader.GetAmount() * DataCoef);
  int tp = 0, fp = 0, tn = 0, fn = 0;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < usage; i++) {
    Sample sample = reader.GetSample();

    FeedInitValues(sample.pixels);
    ForwardFeed();
    v_double result = GetResVector();
    int answer = GetResult();
    if (sample.answer - 1 == answer) info.accuracy++;
    for (int j = 0; j < 26; j++) {
      if (j == answer) {
        if (result[j] > 0.5)
          tp++;
        else
          fp++;
      } else {
        if (result[j] > 0.5)
          fn++;
        else
          tn++;
      }
    }
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::seconds>(stop - start);
  info.ed_time = duration.count();
  info.Calculate(tp, fp, tn, fn, usage);
  reader.Disconnect();
  return info;
}

auto NetInterface::Validation(const std::string &fileName, const size_t k)
    -> std::vector<double> {
  Emnist_reader reader;
  reader.Connect(fileName);
  const int fileSize = reader.GetAmount();

  std::vector<Sample> testDataIn;
  v_double accuracyVals;
  v_double expectedVals(topology.back());
  Sample data;

  int testDataSize = fileSize / k;
  int getTest = 0, endTest = testDataSize;

  for (int i = 0; i < k; i++) {
    int accuracy = 0;
    for (int iterator = 0; iterator < fileSize; iterator++) {
      if (iterator >= getTest && iterator < endTest) {
        testDataIn.push_back(reader.GetSample());
      } else {
        data = reader.GetSample();
        expectedVals[data.answer - 1] = 1;
        this->FeedInitValues(data.pixels);
        this->ForwardFeed();
        this->BackPropagation(expectedVals);
        expectedVals[data.answer - 1] = 0;
      }
    }
    for (int j = 0; j < testDataIn.size(); j++) {
      this->FeedInitValues(testDataIn[j].pixels);
      this->ForwardFeed();
      if (this->GetResult() == testDataIn[j].answer - 1) accuracy++;
    }
    getTest += testDataSize;
    endTest += testDataSize;

    testDataIn.clear();
    accuracyVals.push_back(static_cast<double>(accuracy) / testDataSize * 100);
    if (i != k - 1) reader.Connect(fileName);
  }
  reader.Disconnect();
  return accuracyVals;
}
}  // namespace s21
