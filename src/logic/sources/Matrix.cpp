//
// Created by Louvenia Dione on 2/2/23.
//

#include "Matrix.hpp"

namespace s21 {
	Matrix::Matrix() : row(0), column(0), value(nullptr) {}

	Matrix::Matrix(int row, int column) {
		this->row = row;
		this->column = column;
		memalloc(row, column);
		setZero();
	}

	Matrix::Matrix(const Matrix &res) {
		if (this != &res) {
			this->row = res.row;
			this->column = res.column;
			this->memalloc(res.row, res.column);
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					this->value[i][j] = res.value[i][j];
				}
			}
		}
	}

	Matrix::~Matrix() {
		if (value != nullptr) {
			for (int i = 0; i < row; i++) {
				delete value[i];
			}
			delete value;
		}
		value = nullptr;
		this->row = 0;
		this->column = 0;
	}

	auto	Matrix::memalloc(int row, int column) -> void {
		value = new double*[row];
		for (int i = 0; i < row; i++) {
			value[i] = new double[column];
		}
	}

	auto	Matrix::setZero() -> void {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				value[i][j] = 0;
			}
		}
	}

	void 	Matrix::multi_matrix(const Matrix &res) {
		if (this->column != res.row) {
			throw std::invalid_argument("column != row");
		}
		Matrix	out(row, res.column);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < res.column; j++) {
				for (int k = 0; k < column; k++) {
					out.value[i][j] += value[i][k] * res.value[k][j];
				}
			}
		}
		this->~Matrix();
		value = new double*[out.row];
		for (int i = 0; i < out.row; i++) {
			value[i] = new double[column];
		}
		*this = out;
	}

	int Matrix::getRow() {
		return row;
	}

	int Matrix::getColumn() {
		return column;
	}

	int Matrix::setRow(int _row) {
		if (_row > 0) {
			this->~Matrix();
			row = _row;
			memalloc(row, column);
			setZero();
		}
		else {
			throw std::invalid_argument("Error: incorrect arguments for changing the value!");
		}
	}

	int Matrix::setColumn(int _column) {
		if (_column > 0) {
			this->~Matrix();
			column = _column;
			memalloc(row, column);
			setZero();
		}
		else {
			throw std::invalid_argument("Error: incorrect arguments for changing the value!");
		}
	}

	Matrix&	Matrix::operator=(const Matrix& res) {
		if (this != &res)
			this->~Matrix();
		row = res.row;
		column = res.column;
		memalloc(row, column);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				value[i][j] = res.value[i][j];
			}
		}
		return *this;
	}

	double*	Matrix::operator[](int i) {
		double*	res;
		if (i >= row) {
			res = nullptr;
			throw std::invalid_argument("Error: unable to access this index");
		}
		res = value[i];
		return res;
	}

	double&	Matrix::operator()(int i, int j) {
		if (i >= row || j >= column) {
			throw std::out_of_range("Error: going out of the array");
		}
		else {
			return value[i][j];
		}
	}

	Matrix	Matrix::operator*(const Matrix &res) {
		Matrix	ret = *this;
		ret.multi_matrix(res);
		return ret;
	}

	void Matrix::clear() {
		if (value != nullptr) {
			for (int i = 0; i < row; i++) {
				delete value[i];
			}
			delete value;
			value = nullptr;
			row = 0;
			column = 0;
		}
	}
} // s21