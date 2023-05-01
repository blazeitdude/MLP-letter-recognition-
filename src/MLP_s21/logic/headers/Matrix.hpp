//
// Created by Louvenia Dione on 2/2/23.
//

#ifndef MLP_2_0_MATRIX_HPP
#define MLP_2_0_MATRIX_HPP

#include <string>
#include <vector>

namespace s21 {

class Matrix {
 private:
  int row;
  int column;
  double** value;
  auto setZero() -> void;
  void multi_matrix(const Matrix& res);

 public:
  auto memalloc(int row, int column) -> void;
  Matrix();
  Matrix(int row, int column);
  Matrix(const Matrix& res);
  ~Matrix();

  int getRow();
  int getColumn();
  int setRow(int _row);
  int setColumn(int _column);

  Matrix& operator=(const Matrix& res);
  double* operator[](int i);
  ;
  double& operator()(int i, int j);
  Matrix operator*(const Matrix& res);
  void clear();
};

}  // namespace s21

#endif  // MLP_2_0_MATRIX_HPP
