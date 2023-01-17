#include <iostream>
#include "../includes/Dataset.hpp"
#include <chrono>
#include "../includes/NeuralNetwork.hpp"

using namespace std::chrono;

int main() {
	s21::Dataset	dataset;
	s21::NeuralNetwork	nn;
	double ra = 0, right, predict, maxra = 0;
	int epoch = 0;
	bool study, repeat = true;
	int ex;

	nn.init(); // с этим чето сделать надо
	while (repeat) {
		std::cout << "turn on the training mode?[0][1]\n";
		std::cin >> study;
		if (study) {
			auto start = high_resolution_clock::now();
			dataset.read_csv_dataset(STD_TRAINT_DSET, TRAIN_MODE);
			ex = dataset.getAmount();
			while (ra / ex * 100 < 100) {
				ra = 0;
				for (int i = 0; i < ex; ++i) {
					nn.set_input(dataset.getDataSet().at(i));
					right = dataset.getMap().at(i);
					predict = nn.forwardFeed();
					if (predict != right) {
						nn.backPropogation(right);
						nn.update_weights(0.15 * exp(-epoch / 20.));
					}
					else
						ra++;
				}
				if (ra  > maxra)
					maxra = ra;
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<seconds>(stop - start);
				std::cout << "right answers " << ra / ex * 100 << '\t' << "maxra: " << maxra / ex * 100 << '\t' << "epoch " << epoch << "time: " << duration.count() << std::endl;
				if (epoch == 20)
					break;
			}
			auto end = duration_cast<seconds>(high_resolution_clock::now() - start);
			std::cout << "time: " << end.count() << std::endl;
			nn.save_weights();
		}
		else {
			nn.downloads_weights();
		}

		std::cout << "Start?[0][1]\n";
		bool inp;
		std::cin >> inp;
		if (inp) {
			dataset.clean();
			dataset.read_csv_dataset(STD_DSET, TEST_MODE);
			ra = 0;
			ex = dataset.getAmount();

			for (int i = 0; i < ex; i++) {
				nn.set_input(dataset.getDataSet().at(i));
				predict = nn.forwardFeed();
				std::cout << "I think that's -> " << (char) predict + 39 << std::endl;
			}
		}
	}
//	for (int i = 0; i < dataset.getAmount(); i++) {
//		std::cout << map.at(i) << std::endl;
//	}
}
