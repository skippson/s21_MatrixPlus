#include "s21_matrix_oop.h"

S21Matrix& S21Matrix::operator=(const S21Matrix& rhs) {
  if (!rhs.valid_matrix()) {
    throw std::logic_error("invalid matrix");
  }
  if (this != &rhs) {
    S21Matrix temp(rhs.rows_, rhs.cols_);
    for (int i = 0; i < temp.rows_; i++) {
      for (int j = 0; j < temp.cols_; j++) {
        temp.matrix_[i][j] = rhs.matrix_[i][j];
      }
    }
    this->rows_ = temp.rows_;
    this->cols_ = temp.cols_;
    this->matrix_ = temp.matrix_;
    temp.matrix_ = nullptr;
  }

  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& rhs) {
  SumMatrix(rhs);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& rhs) {
  SubMatrix(rhs);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double& rhs) {
  MulNumber(rhs);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& rhs) {
  MulMatrix(rhs);
  return *this;
}

S21Matrix operator+(const S21Matrix lhs, const S21Matrix rhs) {
  S21Matrix res = lhs;
  res += rhs;
  return res;
}

S21Matrix operator-(const S21Matrix lhs, const S21Matrix rhs) {
  S21Matrix res = lhs;
  res -= rhs;
  return res;
}

S21Matrix operator*(const S21Matrix lhs, const double rhs) {
  S21Matrix res = lhs;
  res *= rhs;
  return res;
}

S21Matrix operator*(const S21Matrix lhs, const S21Matrix rhs) {
  S21Matrix res = lhs;
  res *= rhs;
  return res;
}

bool operator==(const S21Matrix lhs, const S21Matrix rhs) {
  return lhs.EqMatrix(rhs);
}

double& S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || j >= cols_) {
    throw std::logic_error("Invalid index");
  }
  return matrix_[i][j];
}

bool operator!=(const S21Matrix lhs, const S21Matrix rhs) {
  return !lhs.EqMatrix(rhs);
}