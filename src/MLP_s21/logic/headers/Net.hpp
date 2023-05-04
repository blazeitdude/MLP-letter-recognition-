//
// Created by Louvenia Dione on 2/2/23.
//

#ifndef MLP_2_0_NET_HPP
#define MLP_2_0_NET_HPP
#define v_double std::vector<double>
#define EXPERIENCE_FILE "experience.txt"
#define SIGNATURE "ODFQMVNQHVIBYT"

#include <cstring>
#include <fstream>
#include <iostream>
#include <random>

#include "Matrix.hpp"

namespace s21 {

static constexpr double lr = 0.08;
enum config { INPUT = 784, HIDDEN = 100, OUTPUT = 26 };

enum class NeuralType { MATRIX = 0, GRAPH = 1 };

class Info {
 public:
  double accuracy;
  double precision;
  double recall;
  double f_measure;
  double ed_time;

  auto Calculate(int tp, int fp, int tn, int fn, int dataSize) -> void;
  Info();
};

class NetInterface {
 protected:
  bool CheckFile(std::fstream& file);
  std::vector<size_t> topology;
  std::mt19937 generator;

 public:
  NetInterface() = default;
  virtual ~NetInterface() = default;
  virtual void BackPropagation(v_double& right) = 0;
  virtual void ForwardFeed() = 0;
  virtual void FeedInitValues(const v_double& values) = 0;
  virtual void SaveExperience(std::string path) = 0;
  virtual bool ReadExperience(std::string path) = 0;
  virtual void SetLayers(std::vector<config> info) = 0;
  v_double TrainMode(const std::string& fileName, const size_t epoch);
  Info TestMode(const std::string& fileName, const double DataCoef);
  static double ActivateFunction(double res);
  static double Derivate(double res);

  std::vector<config> GetLayersConfig(size_t n);
  virtual size_t GetResult() = 0;
  virtual const v_double GetResVector() = 0;
  auto GetLayersVect(int number) const -> std::vector<config>;
  auto Validation(const std::string& fileName, const size_t k)
      -> std::vector<double>;
};

}  // namespace s21

#endif  // MLP_2_0_NET_HPP
