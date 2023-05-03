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
  auto setNeural(s21::NeuralType type, int hiddenLayers) -> void;
  auto getNeural() const -> NetInterface*;
  auto feedForward() -> void;
  auto initValues(const std::vector<double>& values) -> void;
  auto getResult() -> size_t;
  auto saveWeights(const std::string& fileName) -> void;
  auto loadWeights(const std::string& fileName) -> void;
  auto getInfo(const std::string& fileName, const double dataset) -> Info;
  auto trainModel(const std::string& fileName, const size_t epoch)
      -> std::vector<double>;
  auto validation(const std::string& fileName, const size_t k)
      -> std::vector<double>;

 private:
  NetInterface* _net{};
  s21::NeuralType _netType{};
  int _hiddenLayers{};
};
}  // namespace s21

#endif
