//
// Created by Louvenia Dione on 1/14/23.
//

#include <iostream>
#include "../includes/Dataset.hpp"

int	getLen(std::string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',')
			count++;
	}
	return (count);
}

void s21::Dataset::read_csv_dataset(char *filepath, bool is_train) {
	this->min = 4213532;
	this->max = 1;
	int	nums = 0;
	this->amount = 0;
	std::ifstream 	fin(filepath);
	std::string 	buff_line;
	int 			num_buff = 0;
	int 			len = 0;
	int 			len_of_arr = 0;

	if (is_train)
		this->is_train = true;
	else
		this->is_train = false;
	while (std::getline(fin, buff_line)) {
		nums = 0;
		len = 0;

		if (this->is_train) {
			while (buff_line[len] != ',') {
				num_buff *= 10;
				num_buff += buff_line[len++] - 48;
			}
			this->map.push_back(num_buff);
		}
		num_buff = 0;
		len++;
		if (this->amount == 0)
			len_of_arr = getLen(buff_line);
		this->dataset.push_back(new double[len_of_arr]);
		while (buff_line[len] != '\0') {
			if (buff_line[len] == ',') {
				if (num_buff >= this->max && num_buff != 0)
					this->max = num_buff;
				else if (num_buff <= this->min && num_buff != 0) {
					this->min = num_buff;
				}
				this->dataset[amount][nums++] = num_buff;
				num_buff = 0;
				len++;
				continue;
			}
			num_buff *= 10;
			num_buff += buff_line[len] - 48;
			len++;
		}
		amount++;
		this->size = len_of_arr;
		fin.close();
	}
//	std::cout << "PRE" << std::endl;
//	this->DEV_PRINT();
	this->normalize();
//	std::cout << "AFTER" << std::endl;
//	this->DEV_PRINT();
	this->size = len_of_arr;
}

void s21::Dataset::clean() {
	for (int i = 0; i < amount; i++) {
		delete(dataset.at(i));
	}
	amount = 0;
	size = 0;
	min = 0;
	max = 0;
}

v_intp &s21::Dataset::getDataSet() {
	return (this->dataset);
}

bool s21::Dataset::getCondition() {
	return (this->is_train);
}

int s21::Dataset::getAmount() {
	return (this->amount);
}

void s21::Dataset::normalize() {
	for (size_t i = 0; i < this->dataset.size(); i++) {
		for (size_t j = 0; j < this->size; j++) {
			if (this->dataset[i][j] != 0)
				this->dataset[i][j] = (this->dataset[i][j] - this->min) / (this->max - this->min);
		}
	}
}

void	s21::Dataset::DEV_PRINT() {
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < this->size; j++) {
			std::cout << this->dataset.at(i)[j] << " ";
		}
		std::cout << std::endl;
	}
}

v_int&	s21::Dataset::getMap() {
	return (this->map);
}

int	s21::Dataset::getSize() {
	return (this->size);
}