//
// Created by Louvenia Dione on 2/3/23.
//

#include "headers/GraphNet.hpp"

namespace s21 {
void GraphNet::backPropagation(std::vector<double> &right) {
  v_double grads;
  for (int i = neurons.size() - 2; i >= 0; i--) {
    gradient(grads, right, i + 1);
    for (size_t j = 0; j < neurons[i].size(); j++) {
      for (size_t k = 0; k < neurons[i + 1].size(); k++) {
        neurons[i][j].getWeights(k) += lr * grads[k] * neurons[i][j].getValue();
      }
    }
  }
}

void GraphNet::forwardFeed() {
  for (size_t layer = 0; layer < neurons.size(); layer++) {
    for (size_t i = 0; i < neurons[layer + 1].size(); i++) {
      double sum = 0.;
      for (size_t j = 0; j < neurons[layer].size(); j++) {
        sum += neurons[layer][j].getWeights(i) * neurons[layer][j].getValue();
      }
      neurons[layer + 1][i].setValue(activateFunction(sum));
    }
  }
}

void GraphNet::feedInitValues(const std::vector<double> &values) {
  for (size_t i = 0; i < neurons[0].size(); i++) {
    neurons[0][i].setValue(values[i]);
  }
}

void GraphNet::saveExperience(std::string path) {
  std::fstream file;

  file.open(path, std::fstream::out);
  file << SIGNATURE << std::endl;
  for (int i = 0; i < topology.size(); i++) {
    file << topology[i] << ' ';
  }
  file << std::endl;
  for (int layer = 0; layer < neurons.size() - 1; layer++) {
    for (int j = 0; j < neurons[layer + 1].size(); j++) {
      for (int k = 0; k < neurons[layer].size(); k++)
        file << neurons[layer][k].getWeights(j) << std::endl;
    }
  }
  file.close();
}

bool GraphNet::readExperience(std::string path) {
  std::fstream file;
  char buff = 0;
  std::string buff_str = "";

  file.close();
  file.open(path);
  if (!file.is_open()) return false;

  if (check_file(file)) {
    for (int layer = 0; layer < topology.size(); layer++) {
      for (int j = 0; j < neurons[layer + 1].size(); j++) {
        for (int k = 0; k < neurons[layer].size(); k++) {
          std::getline(file, buff_str);
          neurons[layer][k].getWeights(j) = std::stod(buff_str);
          buff_str = "";
        }
      }
    }
  } else {
    file.close();
    return false;
  }
  file.close();
  return true;
}

void GraphNet::setLayers(std::vector<config> info) {
  this->topology.clear();
  for (int i = 0; i < neurons.size(); i++) {
    neurons[i].clear();
  }

  neurons.clear();
  biases.clear();

  for (int i = 0; i < info.size(); i++) {
    topology.emplace_back(info[i]);
  }

  std::random_device randomDevice;
  std::mt19937 randomizer(randomDevice());
  this->generator = randomizer;

  for (int i = 0; i < info.size(); i++) {
    neurons.push_back(Layer());
    biases.push_back(0);
    for (int j = 0; j < topology[i]; j++) {
      Neuron neuro;
      if (i != topology.size() - 1)
        neuro.setWeights(generateWeights(topology[i + 1]));
      neurons[i].push_back(neuro);
    }
  }
}

size_t GraphNet::getResult() {
  size_t ret = 0;
  double max = neurons.back()[0].getValue();
  for (int i = 0; i < neurons.back().size(); i++) {
    if (max < neurons.back()[i].getValue()) {
      max = neurons.back()[i].getValue();
      ret = i;
    }
  }
  return (ret);
}

const v_double GraphNet::getResVector() {
  v_double ret(topology.back());

  for (int i = 0; i < neurons.back().size(); i++) {
    ret[i] = neurons.back()[i].getValue();
  }
  return ret;
}

v_double GraphNet::generateWeights(size_t n) {
  v_double weights(n);

  for (int i = 0; i < n; i++) {
    weights[i] = ((int)generator() % 10000) * 0.0001;
  }
  return (weights);
}

void GraphNet::gradient(std::vector<double> &grads,
                        const std::vector<double> &expect, size_t layer) {
  if (layer == neurons.size() - 1) {
    for (size_t i = 0; i < neurons[layer].size(); i++) {
      double err = expect[i] - neurons[layer][i].getValue();
      grads.push_back(err * derivate(neurons[layer][i].getValue()));
    }
  } else {
    v_double new_grads;

    for (size_t i = 0; i < neurons[layer].size(); i++) {
      double buff = 0.;
      for (size_t j = 0; j < neurons[layer + 1].size(); j++) {
        buff += grads[j] * neurons[layer][i].getWeights(j);
      }
      new_grads.push_back(buff * derivate(neurons[layer][i].getValue()));
    }
    grads = new_grads;
  }
}

double Neuron::getValue() { return (value); }

void Neuron::setValue(double res) { value = res; }

void Neuron::setWeights(const std::vector<double> &res) { weights = res; }

double &Neuron::getWeights(size_t index) { return (weights[index]); }
}  // namespace s21