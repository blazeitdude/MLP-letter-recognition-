//
// Created by Louvenia Dione on 2/3/23.
//

#include "headers/GraphNet.hpp"

namespace s21 {
void GraphNet::BackPropagation(std::vector<double> &right) {
  v_double grads;
  for (int i = neurons.size() - 2; i >= 0; i--) {
    Gradient(grads, right, i + 1);
    for (size_t j = 0; j < neurons[i].size(); j++) {
      for (size_t k = 0; k < neurons[i + 1].size(); k++) {
        neurons[i][j].GetWeights(k) += lr * grads[k] * neurons[i][j].GetValue();
      }
    }
  }
}

void GraphNet::ForwardFeed() {
  for (size_t layer = 0; layer < neurons.size() - 1; layer++) {
    for (size_t i = 0; i < neurons[layer + 1].size(); i++) {
      double sum = 0.;
      for (size_t j = 0; j < neurons[layer].size(); j++) {
        sum += neurons[layer][j].GetWeights(i) * neurons[layer][j].GetValue();
      }
      neurons[layer + 1][i].SetValue(ActivateFunction(sum));
    }
  }
}

void GraphNet::FeedInitValues(const std::vector<double> &values) {
  for (size_t i = 0; i < neurons[0].size(); i++) {
    neurons[0][i].SetValue(values[i]);
  }
}

void GraphNet::SaveExperience(std::string path) {
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
        file << neurons[layer][k].GetWeights(j) << std::endl;
    }
  }
  file.close();
}

bool GraphNet::ReadExperience(std::string path) {
  std::fstream file;
  char buff = 0;
  std::string buff_str = "";

  file.close();
  file.open(path);
  if (!file.is_open()) return false;

  if (CheckFile(file)) {
    for (int layer = 0; layer < topology.size(); layer++) {
      for (int j = 0; j < neurons[layer + 1].size(); j++) {
        for (int k = 0; k < neurons[layer].size(); k++) {
          std::getline(file, buff_str);
          neurons[layer][k].GetWeights(j) = std::stod(buff_str);
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

void GraphNet::SetLayers(std::vector<config> info) {
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
        neuro.SetWeights(GenerateWeights(topology[i + 1]));
      neurons[i].push_back(neuro);
    }
  }
}

size_t GraphNet::GetResult() {
  size_t ret = 0;
  double max = neurons.back()[0].GetValue();
  for (int i = 0; i < neurons.back().size(); i++) {
    if (max < neurons.back()[i].GetValue()) {
      max = neurons.back()[i].GetValue();
      ret = i;
    }
  }
  return (ret);
}

const v_double GraphNet::GetResVector() {
  v_double ret(topology.back());

  for (int i = 0; i < neurons.back().size(); i++) {
    ret[i] = neurons.back()[i].GetValue();
  }
  return ret;
}

v_double GraphNet::GenerateWeights(size_t n) {
  v_double weights(n);

  for (int i = 0; i < n; i++) {
    weights[i] = ((int)generator() % 10000) * 0.0001;
  }
  return (weights);
}

void GraphNet::Gradient(std::vector<double> &grads,
                        const std::vector<double> &expect, size_t layer) {
  if (layer == neurons.size() - 1) {
    for (size_t i = 0; i < neurons[layer].size(); i++) {
      double err = expect[i] - neurons[layer][i].GetValue();
      grads.push_back(err * Derivate(neurons[layer][i].GetValue()));
    }
  } else {
    v_double new_grads;

    for (size_t i = 0; i < neurons[layer].size(); i++) {
      double buff = 0.;
      for (size_t j = 0; j < neurons[layer + 1].size(); j++) {
        buff += grads[j] * neurons[layer][i].GetWeights(j);
      }
      new_grads.push_back(buff * Derivate(neurons[layer][i].GetValue()));
    }
    grads = new_grads;
  }
}

double Neuron::GetValue() { return (value); }

void Neuron::SetValue(double res) { value = res; }

void Neuron::SetWeights(const std::vector<double> &res) { weights = res; }

double &Neuron::GetWeights(size_t index) { return (weights[index]); }
}  // namespace s21