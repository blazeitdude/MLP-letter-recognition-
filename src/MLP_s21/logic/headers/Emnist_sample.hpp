//
// Created by Louvenia Dione on 2/2/23.
//

#ifndef MLP_2_0_EMNIST_SAMPLE_HPP
#define MLP_2_0_EMNIST_SAMPLE_HPP
#define v_double std::vector<double>

#include <fstream>
#include <string>
#include <vector>

namespace s21 {

class Sample {
 public:
  Sample() = default;

  ~Sample() = default;

  Sample(const v_double &pixels, const int answer);

  v_double pixels;
  int answer;
};
class Emnist_reader {
 public:
  auto connect(std::string path) -> void;
  auto isOpen() -> bool;
  auto disconnect() -> void;
  auto getSample() -> Sample;
  auto getAmount() -> int;

 private:
  std::fstream file;
  int amount;
};
}  // namespace s21

#endif  // MLP_2_0_EMNIST_SAMPLE_HPP
