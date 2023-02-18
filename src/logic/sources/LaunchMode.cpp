//
// Created by Louvenia Dione on 2/3/23.
//
#include "MatrixNet.hpp"
#include "Emnist_sample.hpp"

namespace s21 {

	auto NetInterface::trainMode(const std::string &fileName, const size_t epoch) -> v_double {
		Emnist_reader	reader;
		v_double		error;

		for (int i = 0; i < epoch; i++) {
			std::cout << "epoch " << i << std::endl;
			reader.connect(fileName);
			const int ex = reader.getAmount();
			int accuracy = 0;
			for (int j = 0; j < ex; j++) {
				v_double	right(topology.back());
				Sample	sample = reader.getSample();
				right[sample.answer - 1] = 1;
				feedInitValues(sample.pixels);
				forwardFeed();
				getResVector();
				if (sample.answer - 1 == getResult())
					accuracy++;
				backPropagation(right);
			}
			accuracy = (static_cast<double>(accuracy) / static_cast<double>(ex) * 100.0);
			std::cout << "accuracy: " << accuracy << std::endl;
			error.push_back(100.0 - accuracy);
		}
		reader.disconnect();
		return error;
	}

	auto	NetInterface::testMode(const std::string &fileName, const double DataCoef) -> Info {
		Emnist_reader	reader;
		Info			info;

		reader.connect(fileName);
		const int usage = static_cast<int>(reader.getAmount() * DataCoef);
		int tp = 0, fp = 0, tn = 0, fn = 0;
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < usage; i++) {
			Sample sample = reader.getSample();

			feedInitValues(sample.pixels);
			forwardFeed();
			v_double	result = getResVector();
			int answer = getResult();
			if (sample.answer - 1 == answer)
				info.accuracy++;
			for (int j = 0; j < 26; j++) {
				if (j == answer) {
					if (result[j] > 0.5)
						tp++;
					else
						fp++;
				}
				else {
					if (result[j] > 0.5)
						fn++;
					else
						tn++;
				}
			}
		}
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		info.ed_time = duration.count();
		info.calculate(tp, fp, tn, fn, usage);
		reader.disconnect();
		return info;
	}
} // s21