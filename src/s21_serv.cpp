#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(const int rows, const int columns) {
  if (rows < 0 || columns < 0) {
    throw std::out_of_range("Indexes of rows or cols out of range");
  }
  rows_ = rows;
  cols_ = columns;
  matrix_ = new double* [rows_] {};
  for (int i = 0; i < rows; i++) {
    matrix_[i] = new double[cols_]{};
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_[i][j] = 0;
    }
  }
}

S21Matrix::S21Matrix(const int n) { *this = S21Matrix(n, n); }

S21Matrix::~S21Matrix() {
  if (valid_matrix()) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

S21Matrix::S21Matrix(const S21Matrix& rhs) { *this = rhs; }

S21Matrix::S21Matrix(S21Matrix&& rhs) {
  *this = rhs;
  rhs.rows_ = 0;
  rhs.cols_ = 0;
  rhs.matrix_ = nullptr;
}