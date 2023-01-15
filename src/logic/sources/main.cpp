#include <iostream>
#include "../includes/Dataset.hpp"


#include <chrono>
using namespace std::chrono;

int main() {
	auto start = high_resolution_clock::now();
	s21::Dataset	dataset;

	dataset.read_csv_dataset(STD_TRAINT_DSET, TRAIN_MODE);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	std::cout << duration.count() << std::endl;
//	for (int i = 0; i < dataset.getAmount(); i++) {
//		std::cout << map.at(i) << std::endl;
//	}
}
