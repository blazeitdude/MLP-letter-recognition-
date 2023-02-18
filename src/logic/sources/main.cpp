//
// Created by Louvenia Dione on 2/3/23.
//
#include "MatrixNet.hpp"
#include "Emnist_sample.hpp"
#include "GraphNet.hpp"

int	main(void) {
	s21::NetInterface*	nn = new s21::GraphNet();

	nn->setLayers(nn->getLayersConfig(2));
//	nn->trainMode("/Users/ldione/Desktop/mlp_2.0/emnist-letters-train.csv", 10);
//	nn->saveExperience("/Users/ldione/Desktop/mlp_2.0/exp_2.txt");
//	nn->testMode("/Users/ldione/Desktop/mlp_2.0/emnist-letters-test.csv", 1);
	nn->readExperience("/Users/ldione/Desktop/mlp_2.0/exp_2.txt");
//	nn->saveExperience("/Users/ldione/Desktop/mlp_2.0/exp_test.txt");
	s21::Info info = nn->testMode("/Users/ldione/Desktop/mlp_2.0/emnist-letters-test.csv", 0.1);
	std::cout << "----------------------------------------------------\n";
	std::cout << "accuracy: " << info.accuracy << std::endl
	<< "precision: " << info.precision << std::endl
	<< "recall: " << info.recall << std::endl
	<< "f_measure: " << info.f_measure << std::endl
	<< "time: " << info.ed_time << std::endl;
}