//
// Created by Louvenia Dione on 1/15/23.
//

#include "../includes/NeuralNetwork.hpp"

namespace s21 {

	void	s21::NeuralNetwork::activate_func(double *value, int len) {
		for (int i = 0; i < len; i++) {
			value[i] = 1 / (1 + exp(-value[i]));
		}
	}

	void s21::NeuralNetwork::derivative(double *value, int len) {
		for (int i = 0; i < len; i++) {
			value[i] = value[i] * (1 - value[i]);
		}
	}

	void s21::NeuralNetwork::init() {
		srand(time(NULL));
		this->layers = 3;
		this->size = new int[layers]; // заполнить количество нейронов на слое надо
		this->bios = new double *[layers - 1];
		matrix = new Weights[layers - 1];
		bios = new double *[layers - 1];
		for (int i = 0; i < layers - 1; i++) {
			matrix[i].init(size[i + 1], size[i]);
			matrix->randomize();
			for (int j = 0; j < size[i + 1]; j++) {
				bios[i][j] = ((rand() % 50)) * 0.06  / (size[i] + 15);
			}
		}

		neuron = new double *[layers];
		neuron_err = new double *[layers];
		for (int k = 0; k < layers; k++) {
			neuron[k] = new double [size[k]];
			neuron_err[k] = new double[size[k]];
		}
		neuron_bios = new double[layers];
		for (int t = 0; t < layers - 1; t++) {
			neuron_bios[t] = 1;
		}
	}
} // s21