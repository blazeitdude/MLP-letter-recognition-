#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QString>

#include "../logic/headers/GraphNet.hpp"
#include "../logic/headers/MatrixNet.hpp"
#include "../logic/headers/Net.hpp"

namespace s21 {

class Controller {
 public:
  Controller() = default;
  ~Controller();
  auto SetNeural(s21::NeuralType type, int hiddenLayers) -> void;
  auto GetNeural() const -> NetInterface*;
  auto FeedForward() -> void;
  auto InitValues(const std::vector<double>& values) -> void;
  auto GetResult() -> size_t;
  auto SaveWeights(const std::string& fileName) -> void;
  auto LoadWeights(const std::string& fileName) -> void;
  auto GetInfo(const std::string& fileName, const double dataset) -> Info;
  auto TrainModel(const std::string& fileName, const size_t epoch)
      -> std::vector<double>;
  auto Validation(const std::string& fileName, const size_t k)
      -> std::vector<double>;

 private:
  NetInterface* _net{};
  s21::NeuralType _netType{};
  int _hiddenLayers{};
};
}  // namespace s21

#endif
