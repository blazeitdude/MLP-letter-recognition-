//
// Created by Louvenia Dione on 2/2/23.
//

#include "Net.hpp"

namespace s21 {

	double	NetInterface::activateFunction(double res) {
		return 1.0 / (1.0 + exp(-res));
	}

	double	NetInterface::derivate(double res) {
		return res * (1 - res);
	}

	std::vector<config>	NetInterface::getLayersConfig(size_t n) {
		std::vector<config>	conf;
		conf.push_back(INPUT);
		for (int i = 0; i < n; ++i) {
			conf.push_back(HIDDEN);
		}
		conf.push_back(OUTPUT);
		return conf;
	}

	bool	NetInterface::check_file(std::fstream& file) {
		char buff = 0;
		std::string buff_str;
		std::string check;
		std::vector<size_t>	example;

		std::getline(file, check);

		if (check != SIGNATURE) {
			return false;
		}

		while (buff != '\n' && !file.eof()) {
			buff = 0;
			while (buff != ' ' && buff  != '\n' && !file.eof()) {
				file.get(buff);
				if (buff != '\n' && !file.eof())
					buff_str += buff;
			}
			if (buff != '\n')
				example.push_back(std::stod(buff_str));
			buff_str = "";
		}

		if (this->topology.size() != example.size())
			return false;
		for (int i = 0; i < this->topology.size(); i++) {
			if (this->topology[i] != example[i])
				return false;
		}
		return true;
	}

	auto Info::calculate(int tp, int fp, int tn, int fn, int dataSize) -> void {
		accuracy = static_cast<double>(accuracy) / dataSize;
		precision = static_cast<double>(tp) / static_cast<double>(tp + fp);
		recall = static_cast<double>(tp) / static_cast<double>(tp + fn);
		f_measure = 2 * (precision * recall) / (precision + recall);
	}

	Info::Info()
	: accuracy(0), precision(0), recall(0), f_measure(0), ed_time(0){}
} // s21