#include "controller.hpp"

namespace s21 {

Controller::~Controller() { delete _net; }

auto Controller::GetNeural() const -> NetInterface* { return _net; }

auto Controller::SetNeural(s21::NeuralType netType, int hiddenLayers) -> void {
  if (netType != _netType || hiddenLayers != _hiddenLayers) {
    delete _net;
    if (netType == s21::NeuralType::MATRIX) {
      _net = new MatrixNet;
    } else {
      _net = new GraphNet;
    }
    _netType = netType;
    _hiddenLayers = hiddenLayers;
    _net->SetLayers(_net->GetLayersVect(_hiddenLayers));
  }
}

auto Controller::FeedForward() -> void { _net->ForwardFeed(); }

auto Controller::InitValues(const std::vector<double>& values) -> void {
  _net->FeedInitValues(values);
}

auto Controller::GetResult() -> size_t { return _net->GetResult(); }

auto Controller::SaveWeights(const std::string& fileName) -> void {
  _net->SaveExperience(fileName);
}

auto Controller::LoadWeights(const std::string& fileName) -> void {
  _net->ReadExperience(fileName);
}

auto Controller::GetInfo(const std::string& fileName, const double dataset)
    -> Info {
  return _net->TestMode(fileName, dataset);
}

auto Controller::TrainModel(const std::string& fileName, const size_t epoch)
    -> std::vector<double> {
  return _net->TrainMode(fileName, epoch);
}

auto Controller::Validation(const std::string& fileName, const size_t k)
    -> std::vector<double> {
  return _net->Validation(fileName, k);
}
}  // namespace s21
