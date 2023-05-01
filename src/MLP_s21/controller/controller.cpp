#include "controller.hpp"

namespace s21 {

Controller::~Controller() { delete _net; }

auto Controller::getNeural() const -> NetInterface* { return _net; }

auto Controller::setNeural(s21::NeuralType netType, int hiddenLayers) -> void {
  if (netType != _netType || hiddenLayers != _hiddenLayers) {
    delete _net;
    if (netType == s21::NeuralType::MATRIX) {
      _net = new MatrixNet;
    } else {
      _net = new GraphNet;
    }
    _netType = netType;
    _hiddenLayers = hiddenLayers;
    _net->setLayers(_net->getLayersVect(_hiddenLayers));
  }
}

auto Controller::feedForward() -> void { _net->forwardFeed(); }

auto Controller::initValues(const std::vector<double>& values) -> void {
  _net->feedInitValues(values);
}

auto Controller::getResult() -> size_t { return _net->getResult(); }

auto Controller::saveWeights(const std::string& fileName) -> void {
  _net->saveExperience(fileName);
}

auto Controller::loadWeights(const std::string& fileName) -> void {
  _net->readExperience(fileName);
}

auto Controller::getInfo(const std::string& fileName, const double dataset)
    -> Info {
  return _net->testMode(fileName, dataset);
}

auto Controller::trainModel(const std::string& fileName, const size_t epoch)
    -> std::vector<double> {
  return _net->trainMode(fileName, epoch);
}

auto Controller::validation(const std::string& fileName, const size_t k)
    -> std::vector<double> {
  return _net->validation(fileName, k);
}
}  // namespace s21
