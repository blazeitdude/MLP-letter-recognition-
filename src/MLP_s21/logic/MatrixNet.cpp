//
// Created by Louvenia Dione on 2/3/23.
//

#include "headers/MatrixNet.hpp"

namespace s21 {

void MatrixNet::BackPropagation(std::vector<double> &right) {
  v_double grads;

  for (int i = weights.size() - 1; i >= 0; i--) {
    Gradient(grads, right, i + 1);

    for (size_t k = 0; k < weights[i].getColumn(); k++) {
      for (size_t j = 0; j < weights[i].getRow(); j++) {
        double pre = weights[i][j][k];
        weights[i][j][k] += lr * grads[j] * neurons[i][k][0];
      }
    }
  }
}

void MatrixNet::ForwardFeed() {
  for (size_t i = 0; i < neurons.size() - 1; i++) {
    neurons[i + 1] = weights[i] * neurons[i];
    for (size_t j = 0; j < neurons[i + 1].getRow(); j++) {
      double pre = neurons[i + 1](j, 0);
      neurons[i + 1](j, 0) = ActivateFunction(neurons[i + 1](j, 0) + biases[i]);
    }
  }
}

void MatrixNet::FeedInitValues(const v_double &values) {
  for (size_t i = 0; i < values.size(); i++) {
    neurons[0][i][0] = values[i];
  }
}

void MatrixNet::SetLayers(std::vector<config> info) {
  topology.clear();
  for (int i = 0; i < neurons.size(); i++) {
    neurons[i].clear();
  }
  for (int i = 0; i < weights.size(); i++) {
    weights[i].clear();
  }
  neurons.clear();
  weights.clear();
  biases.clear();

  for (int i = 0; i < info.size(); ++i) {
    topology.emplace_back(info[i]);
  }
  std::random_device random;
  std::mt19937 _generator(random());
  this->generator = _generator;

  for (int i = 0; i < info.size(); i++) {
    neurons.emplace_back(Matrix(info[i], 1));
    biases.emplace_back(0);
    if (i != info.size() - 1) {
      weights.emplace_back(Matrix(info[i + 1], info[i]));
      InitWeights(weights.back());
    }
  }
}

size_t MatrixNet::GetResult() {
  size_t result = 0;
  double max = neurons.back()[0][0];
  for (int i = 0; i < neurons.back().getRow(); i++) {
    if (max < neurons.back()[i][0]) {
      max = neurons.back()[i][0];
      result = i;
    }
  }
  return result;
}

const v_double MatrixNet::GetResVector() {
  v_double result(topology.back());
  for (int i = 0; i < result.size(); i++) {
    result[i] = neurons.back()[i][0];
  }
  return result;
}

void MatrixNet::InitWeights(Matrix &matrix) {
  for (size_t i = 0; i < matrix.getRow(); i++) {
    for (size_t j = 0; j < matrix.getColumn(); j++) {
      double res = RandomWeight();
      matrix(i, j) = res;
    }
  }
}

double MatrixNet::RandomWeight() {
  double ret = ((int)generator() % 10000) * 0.0001;
  return (ret);
}

void MatrixNet::Gradient(std::vector<double> &LocalGrads,
                         const std::vector<double> &ExpectedValues,
                         size_t layer) {
  if (LocalGrads.empty()) {
    for (size_t i = 0; i < neurons.back().getRow(); i++) {
      double error = ExpectedValues[i] - neurons.back()[i][0];
      LocalGrads.push_back(error * Derivate(neurons.back()[i][0]));
    }
  } else {
    // иначе получаем новые градиенты, умножая старые градиенты на веса
    // предыдущего слоя
    std::vector<double> NewGrads;

    for (size_t i = 0; i < weights[layer].getColumn(); i++) {
      double teta = 0.;

      for (size_t j = 0; j < weights[layer].getRow(); j++) {
        teta += LocalGrads[j] * weights[layer][j][i];
      }
      NewGrads.push_back(teta * Derivate(neurons[layer][i][0]));
    }
    LocalGrads = NewGrads;
  }
}

void MatrixNet::SaveExperience(std::string path) {
  std::fstream file;

  file.open(path, std::fstream::out);
  file << SIGNATURE << std::endl;
  for (int i = 0; i < topology.size(); i++) {
    file << topology[i] << ' ';
  }
  file << std::endl;
  for (int i = 0; i < weights.size(); i++) {
    for (int j = 0; j < weights[i].getRow(); j++) {
      for (int k = 0; k < weights[i].getColumn(); k++)
        file << weights[i](j, k) << std::endl;
    }
  }
  file.close();
}

bool MatrixNet::ReadExperience(std::string path) {
  std::fstream file;
  char buff = 0;
  std::string buff_str = "";

  file.close();
  file.open(path);
  if (!file.is_open()) return false;

  if (CheckFile(file)) {
    for (int i = 0; i < topology.size(); i++) {
      for (int j = 0; j < weights[i].getRow(); j++) {
        for (int k = 0; k < weights[i].getColumn(); k++) {
          std::getline(file, buff_str, '\n');
          weights[i][j][k] = std::stod(buff_str);
          buff_str = "";
        }
      }
    }
  } else {
    file.close();
    return false;
  }
  file.close();
  return true;
}
}  // namespace s21