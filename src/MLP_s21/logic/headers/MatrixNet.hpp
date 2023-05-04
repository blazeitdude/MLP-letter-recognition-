//
// Created by Louvenia Dione on 2/3/23.
//

#ifndef MLP_2_0_MATRIXNET_HPP
#define MLP_2_0_MATRIXNET_HPP
#include <cmath>

#include "Net.hpp"

namespace s21 {

class MatrixNet : public NetInterface {
 public:
  void BackPropagation(v_double& right) override;
  void ForwardFeed() override;
  void FeedInitValues(const v_double& values) override;
  void SaveExperience(std::string path) override;
  bool ReadExperience(std::string path) override;
  void SetLayers(std::vector<config> info) override;

  size_t GetResult() override;
  const v_double GetResVector() override;

 private:
  std::vector<Matrix> neurons;
  std::vector<Matrix> weights;
  v_double biases;

  void InitWeights(Matrix& matrix);
  double RandomWeight();
  void Gradient(v_double& grads, const v_double& expect, size_t layer);
};

}  // namespace s21

#endif  // MLP_2_0_MATRIXNET_HPP
