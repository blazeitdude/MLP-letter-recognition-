//
// Created by Louvenia Dione on 1/15/23.
//

#include <stdexcept>
#include "../includes/Weights.hpp"

namespace s21 {
	void	s21::Weights::init(int row, int col) {
		this->row = row;
		this->col = col;
		this->matrix = new double *[row];
		for (int i = 0; i < this->row; i++) {
			this->matrix[i] = new double[col];
		}
	}

	void	s21::Weights::randomize() {
		for (int i = 0; i < this->row; i++) {
			for (int j; j < this->col; j++) {
				this->matrix[i][j] = ((rand() % 100) * 0.03 / (this->row + 35));
			}
		}
	}

	void	s21::Weights::multi(const Weights &matrix, const double *multiplier, int size_m, double *result) {
		if (matrix.col != size_m)
			throw std::runtime_error("it is impossible to multiply the matrix of weights by a vector");
		for (int i = 0; i < matrix.row; ++i) {
			double tmp = 0;
			for (int j = 0; j < matrix.col; ++j) {
				tmp += matrix.matrix[i][j] * multiplier[j];
			}
			result[i] = tmp;
		}
	}

	void	s21::Weights::multi_T(const Weights &matrix, const double *multiplier, int size_m, double *result) {
		if (matrix.row != size_m)
			throw std::runtime_error("it is impossible to multiply the matrix of weights by a vector");
		for (int i = 0; i < matrix.col; ++i) {
			double	tmp = 0;
			for (int j = 0; j < matrix.row; ++j) {
				tmp += matrix.matrix[j][i] * multiplier[j];
			}
			result[i] = tmp;
		}
	}

	void	s21::Weights::sumVector(double *a, const double *b, int size) {
		for (int i = 0; i < size; i++) {
			a[i] += b[i];
		}
	}

	double&	s21::Weights::operator()(int i, int j) {
		return (this->matrix[i][j]);
	}

	std::ostream&	operator<<(std::ostream &stream, const Weights &m) {
		for (int i = 0; i < m.row; ++i) {
			for (int j = 0; j < m.col; j++) {
				stream << m.matrix[i][j] << " ";
			}
		}
		return stream;
	}

	std::istream&	operator>>(std::istream &stream, Weights &m) {
		for (int i = 0; i < m.row; ++i) {
			for (int j = 0; j < m.col; j++) {
				stream >> m.matrix[i][j];
			}
		}
		return stream;
	}
} // s21