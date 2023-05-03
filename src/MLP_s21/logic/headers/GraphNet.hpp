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
  void setWeights(const v_double& res);  //
  double& getWeights(size_t index);      //
  void setValue(double);                 //
  double getValue();                     //
};

typedef std::vector<Neuron> Layer;

class GraphNet : public NetInterface {
 public:
  void backPropagation(std::vector<double>& right) override;
  void forwardFeed() override;                           //
  void feedInitValues(const v_double& values) override;  //
  void saveExperience(std::string path) override;        //
  bool readExperience(std::string path) override;        //
  void setLayers(std::vector<config> info) override;     //

  size_t getResult() override;             //
  const v_double getResVector() override;  //

 private:
  std::vector<Layer> neurons;
  v_double biases;
  std::mt19937 generator;
  v_double generateWeights(size_t n);                                    //
  void gradient(v_double& grads, const v_double& expect, size_t layer);  //
};

}  // namespace s21

#endif  // MLP_2_0_GRAPHNET_H
