//
// Created by Louvenia Dione on 2/3/23.
//

#ifndef MLP_2_0_GRAPHNET_H
#define MLP_2_0_GRAPHNET_H
// #define Layer std::vector<Neuron>

#include "Net.hpp"

namespace s21 {

class Neuron {
 private:
  double value{};

 public:
  v_double weights;
  void SetWeights(const v_double& res);  //
  double& GetWeights(size_t index);      //
  void SetValue(double);                 //
  double GetValue();                     //
};

typedef std::vector<Neuron> Layer;

class GraphNet : public NetInterface {
 public:
  void BackPropagation(std::vector<double>& right) override;
  void ForwardFeed() override;                           //
  void FeedInitValues(const v_double& values) override;  //
  void SaveExperience(std::string path) override;        //
  bool ReadExperience(std::string path) override;        //
  void SetLayers(std::vector<config> info) override;     //

  size_t GetResult() override;             //
  const v_double GetResVector() override;  //

 private:
  std::vector<Layer> neurons;
  v_double biases;
  std::mt19937 generator;
  v_double GenerateWeights(size_t n);                                    //
  void Gradient(v_double& grads, const v_double& expect, size_t layer);  //
};

}  // namespace s21

#endif  // MLP_2_0_GRAPHNET_H
