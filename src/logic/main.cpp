#include <iostream>
#include "./includes/Dataset.h"


//#include <chrono>
//using namespace std::chrono;

int main() {
//	auto start = high_resolution_clock::now();
	s21::Dataset	dataset(STD_TRAINT_DSET, 1);
	v_int&	map	=	dataset.getMap();

//	auto stop = high_resolution_clock::now();
//	auto duration = duration_cast<seconds>(stop - start);
//	std::cout << duration.count() << std::endl;
//	for (int i = 0; i < dataset.getAmount(); i++) {
//		std::cout << map.at(i) << std::endl;
//	}
}
