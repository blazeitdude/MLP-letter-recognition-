//
// Created by Louvenia Dione on 1/14/23.
//

#include <sstream>
#include "includes/Dataset.h"

int	getLen(std::string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',')
			count++;
	}
	return (count);
}

s21::Dataset::Dataset(char *filepath, bool is_train) {
	int	nums = 0;
	this->amount = 0;
	std::ifstream 	fin(filepath);
	std::string 	buff_line;
	int 			num_buff = 0;
	int 			len = 0;

	if (is_train)
		this->is_train = true;
	else
		this->is_train = false;
	while (std::getline(fin, buff_line)) {
		nums = 0;
		len = 0;
		int len_of_arr = 784;
		if (this->is_train)
			len_of_arr = getLen(buff_line);
		this->dataset.push_back((int *)malloc(len_of_arr * sizeof(int)));
		if (this->is_train) {
			while (buff_line[len] != ',') {
				num_buff *= 10;
				num_buff += buff_line[len] - 48;
				len++;
			}
			this->map.push_back(num_buff);
		}
		num_buff = 0;
		len++;
		while (buff_line[len] != '\0') {
			if (buff_line[len] == ',') {
				this->dataset[amount][nums] = num_buff;
				num_buff = 0;
				nums++;
				len++;
				continue;
			}
			num_buff += buff_line[len] - 48;
			num_buff *= 10;
			len++;
		}
		amount++;
	}
}

vv_int &s21::Dataset::getDataSet() {
	return (this->dataset);
}

v_int&	s21::Dataset::getMap() {
	return (this->map);
}

bool s21::Dataset::getCondition() {
	return (this->is_train);
}

int s21::Dataset::getAmount() {
	return (this->amount);
}