#include "s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix &rhs) {
  if (!valid_matrix() || !rhs.valid_matrix()) {
    throw std::logic_error("invalid matrix");
  }

  if (rows_ != rhs.rows_ || cols_ != rhs.cols_) {
    throw std::logic_error("invalid size");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += rhs.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double &rhs) {
  if (!valid_matrix()) {
    throw std::logic_error("invalid matrix");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= rhs;
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &rhs) {
  if (!valid_matrix() || !rhs.valid_matrix()) {
    throw std::logic_error("invalid matrix");
  }

  if (rows_ != rhs.rows_ || cols_ != rhs.cols_) {
    throw std::logic_error("invalid size");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= rhs.matrix_[i][j];
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &rhs) {
  if (!valid_matrix() || !rhs.valid_matrix()) {
    throw std::logic_error("invalid matrix");
  }

  if (rows_ != rhs.cols_) {
    throw std::logic_error("invalid size");
  }

  S21Matrix result(rows_, rhs.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < rhs.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * rhs.matrix_[k][j];
      }
    }
  }

  *this = S21Matrix(std::move(result));
}