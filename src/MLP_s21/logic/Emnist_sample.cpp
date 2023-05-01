//
// Created by Louvenia Dione on 2/2/23.
//

#include "headers/Emnist_sample.hpp"

namespace s21 {
Sample::Sample(const v_double &pixels, const int answer)
    : pixels(pixels), answer(answer) {}

auto Emnist_reader::isOpen() -> bool { return file.is_open(); }

auto Emnist_reader::connect(std::string path) -> void {
  this->amount = 0;
  file.close();
  file.open(path);
  if (!file.is_open())
    throw std::invalid_argument("Error: Unable to open file");
  while (!file.eof()) {
    char buff;
    file.get(buff);
    if (!file.eof() && buff == '\n') amount++;
  }
  file.close();
  file.open(path);
  if (!file.is_open())
    throw std::invalid_argument("Error: Unable to open file");
}

auto Emnist_reader::disconnect() -> void {
  if (isOpen()) file.close();
}

auto Emnist_reader::getSample() -> Sample {
  int answer;
  std::string temp;
  char buff = 0;
  v_double result;
  bool first = true;
  if (!file.is_open())
    throw std::invalid_argument("Error: unable to read string");
  while (buff != '\n' && !file.eof()) {
    file.get(buff);
    if (buff != ',' && buff != '\n' && !file.eof()) {
      temp += buff;
    } else if (!file.eof()) {
      double res = std::stod(temp);
      if (first) {
        answer = res;
        first = false;
      } else {
        result.push_back(res / 255.0);
      }
      temp = "";
    }
  }
  if (file.eof()) {
    file.close();
    return (Sample(v_double(), 0));
  }
  return (Sample(result, answer));
}

auto Emnist_reader::getAmount() -> int { return (amount); }
}  // namespace s21