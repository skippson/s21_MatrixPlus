#include "s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() const {
  if (!valid_matrix()) {
    throw std::logic_error("invalid matrix");
  }
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res.matrix_[j][i] = matrix_[i][j];
    }
  }

  return res;
}

double S21Matrix::Determinant() const {
  if (!valid_matrix()) {
    throw std::logic_error("invalid matrix");
  }
  if (rows_ != cols_) {
    throw std::logic_error("invalid matrix");
  }

  return det(matrix_, rows_);
}

S21Matrix S21Matrix::CalcComplements() const {
  if (!valid_matrix()) {
    throw std::logic_error("invalid matrix");
    ;
  }
  if (rows_ != cols_) {
    throw std::logic_error("invalid matrix");
  }

  S21Matrix res(rows_, cols_);
  S21Matrix tem(*this);
  res.alg_dop(tem);
  return res;
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (!valid_matrix()) {
    throw std::logic_error("invalid matrix");
  }
  if (rows_ != cols_) {
    throw std::logic_error("invalid size");
  }
  double matrixDeterminant = Determinant();
  if (fabs(matrixDeterminant - 0) <= 1E-7) {
    throw std::logic_error("invalid det");
  }
  S21Matrix res = CalcComplements().Transpose();
  res.MulNumber(1 / matrixDeterminant);

  return res;
}