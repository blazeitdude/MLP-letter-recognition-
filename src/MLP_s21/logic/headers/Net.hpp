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

  auto calculate(int tp, int fp, int tn, int fn, int dataSize) -> void;
  Info();
};

class NetInterface {
 protected:
  bool check_file(std::fstream& file);
  std::vector<size_t> topology;
  std::mt19937 generator;

 public:
  NetInterface() = default;
  virtual ~NetInterface() = default;
  virtual void backPropagation(v_double& right) = 0;
  virtual void forwardFeed() = 0;
  virtual void feedInitValues(const v_double& values) = 0;
  virtual void saveExperience(std::string path) = 0;
  virtual bool readExperience(std::string path) = 0;
  virtual void setLayers(std::vector<config> info) = 0;
  v_double trainMode(const std::string& fileName, const size_t epoch);
  Info testMode(const std::string& fileName, const double DataCoef);
  static double activateFunction(double res);
  static double derivate(double res);

  std::vector<config> getLayersConfig(size_t n);
  virtual size_t getResult() = 0;
  virtual const v_double getResVector() = 0;
  auto getLayersVect(int number) const -> std::vector<config>;
  auto validation(const std::string& fileName, const size_t k)
      -> std::vector<double>;
};

}  // namespace s21

#endif  // MLP_2_0_NET_HPP
