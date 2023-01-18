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

	double s21::NeuralNetwork::derivative(double value) {
		value = 1 / (1 + exp(-value));
		return (value);
	}


	void s21::NeuralNetwork::init() {
		srand(time(NULL));
		this->layers = 4;
		this->size = new int[layers];
//		size[0] = 784;
//		size[1] = 100;
//		size[2] = 50;
//		size[3] = 26;
//		//size[0] = dataset->getSize();
		size[1] = 100;
		size[2] = 50;
		size[3] = 35; // надо изменить
		size[4] = 26;
		this->bios = new double *[layers - 1];
		matrix = new Weights[layers - 1];
		for (int i = 0; i < layers - 1; i++) {
			matrix[i].init(size[i + 1], size[i]);
			matrix[i].randomize();
			bios[i] = new double[size[i + 1]];
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
		neuron_bios = new double[layers - 1];
		for (int t = 0; t < layers - 1; t++) {
			neuron_bios[t] = 1;
		}
	}

	double s21::NeuralNetwork::searchMaxIndex(double *value) {
		double	max = value[0];
		int		prediction = 0;
		double 	tmp;

		for (int i = 1; i < size[layers - 1]; i++) {
			tmp = value[i];
//			std::cout << tmp << " ";
			if (tmp > max) {
				prediction = i;
				max = tmp;
			}
		}
			//std::cout << std::endl;
			return prediction;
	}

	double	s21::NeuralNetwork::forwardFeed() {
//		std::cout << "\n-------------------------------------------------------------------------\n\n";
//		std::cout << "PRE\n";
//		for (int i = 0; i < size[4]; i++) {
//			std::cout << neuron[4][i] << " ";
//		}
		for (int k = 1; k < layers; ++k) {
			Weights::multi(matrix[k - 1], neuron[k - 1], size[k - 1], neuron[k]);
			Weights::sumVector(neuron[k], bios[k - 1], size[k]);
			activate_func(neuron[k], size[k]);
		}
//		std::cout << "\nAFTER\n";
//		for (int i = 0; i < size[4]; i++) {
//			std::cout << neuron[4][i] << " ";
//		}
//		for (int i = 0; i < size[4]; i++) {
//			std::cout << std::internal << std::setfill(' ') << std::setw(5) << neuron[4][i];
//		}
		int pred = searchMaxIndex(neuron[layers - 1]);
		return pred;
	}

	void s21::NeuralNetwork::backPropogation(double expect) {
		for (int i = 0; i < size[layers - 1]; i++) {
			if (i != int(expect)) {
				neuron_err[layers - 1][i] = -neuron[layers - 1][i] * derivative(neuron[layers - 1][i]);
			} else
				neuron_err[layers - 1][i] = (1.0 - neuron[layers - 1][i]) * derivative(neuron[layers - 1][i]);
		}
		for (int k = layers - 2; k > 0; k--) {
			Weights::multi_T(matrix[k], neuron_err[k + 1], size[k + 1], neuron_err[k]);
			for (int j = 0; j < size[k]; j++)
				neuron_err[k][j] *= derivative(neuron[k][j]);
		}
	}

	void s21::NeuralNetwork::update_weights(double lr) {
		for (int i = 0; i < layers - 1; ++i) {
			for (int j = 0; j < size[i + 1]; ++j) {
				for (int k = 0; k < size[i]; ++k)
					matrix[i](j, k) += neuron[i][k] * neuron_err[i + 1][j] * lr;
			}
		}
		for (int i = 0; i < layers - 1; i++) {
			for (int k = 0; k < size[i + 1]; k++) {
				bios[i][k] += neuron_err[i + 1][k] * lr;
			}
		}
	}

	void s21::NeuralNetwork::save_weights() {
		std::ofstream fout;
		fout.open("Experience.txt");
		if (!fout.is_open()) {
			std::cout << "Error reading the file";
			system("pause");
		}
		for (int i = 0; i < layers - 1; ++i)
			fout << matrix[i] << " ";

		for (int i = 0; i < layers - 1; ++i) {
			for (int j = 0; j < size[i + 1]; ++j) {
				fout << bios[i][j] << " ";
			}
		}
		std::cout << "weights are saved\n";
		fout.close();
	}

	void s21::NeuralNetwork::downloads_weights() {
		std::ifstream fin;
		fin.open("Experience.txt");
		if (fin.is_open()) {
			std::cout << "experience loading error\n";
			system("pause");
		}
		for (int i = 0; i < layers - 1; ++i) {
			fin >> matrix[i];
		}
		for (int k = 0; k < layers - 1; ++k) {
			for (int j = 0; j < size[k + 1]; ++j) {
				fin >> bios[k][j];
			}
		}
		std::cout << "the experience is loaded\n";
		fin.close();
	}

	void s21::NeuralNetwork::set_input(double *ex) {
		for (int i = 0; i < size[0]; i++) {
			neuron[0][i] = ex[i];
		}
//		for (int i = 0; i < size[0]; i++) {
//			std::cout << std::internal << std::setfill(' ') << std::setw(5) << neuron[0][i];
//			if (i % 28 == 0)
//				std::cout << "\n";
//		}
	}
} // s21