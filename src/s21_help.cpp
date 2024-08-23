#include "s21_matrix_oop.h"

bool S21Matrix::valid_matrix() const noexcept {
  return matrix_ != nullptr && cols_ > 0 && rows_ > 0;
}

int S21Matrix::GetRows() const noexcept { return rows_; }

void S21Matrix::SetRows(const int new_rows) {
  if (new_rows < 0) throw std::logic_error("Invalid size");
  if (rows_ != new_rows) {
    S21Matrix temp(new_rows, cols_);
    int min = std::min(rows_, new_rows);
    for (int i = 0; i < min; i++) {
      for (int j = 0; j < cols_; j++) {
        temp.matrix_[i][j] = matrix_[i][j];
      }
    }
    this->~S21Matrix();
    *this = temp;
  }
}

int S21Matrix::GetCols() const noexcept { return cols_; }

void S21Matrix::SetCols(const int new_cols) {
  if (new_cols < 0) throw std::logic_error("Invalid size");
  if (cols_ != new_cols) {
    S21Matrix temp(rows_, new_cols);
    int min = std::min(cols_, new_cols);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min; j++) {
        temp.matrix_[i][j] = matrix_[i][j];
      }
    }
    this->~S21Matrix();
    *this = temp;
  }
}

void S21Matrix::new_pointer(double **a, double *b) const noexcept { *a = b; }

double S21Matrix::det(double **a, int n) const noexcept {
  if (n == 1) {
    return a[0][0];
  }
  if (n == 2) {
    return a[0][0] * a[1][1] - a[0][1] * a[1][0];
  }
  double sum = 0;
  double **temp = new double *[n - 1] {};
  for (int i = 0; i < n; i++) {
    int number = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      new_pointer(&temp[number++], a[j]);
    }
    sum += pow(-1, i + n - 1) * a[i][n - 1] * det(temp, n - 1);
  }
  free(temp);
  return sum;
}

void S21Matrix::make_minor(int row, int column, double **matrix) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i != row && j != column) {
        matrix[i - (i > row)][j - (j > column)] = matrix_[i][j];
      }
    }
  }
}

void S21Matrix::alg_dop(S21Matrix &a) noexcept {
  if (rows_ == 1) {
    matrix_[0][0] = Determinant();
  } else {
    for (int i = 0; i < a.rows_; i++) {
      for (int j = 0; j < a.cols_; j++) {
        S21Matrix minor(a.rows_ - 1, a.cols_ - 1);
        a.make_minor(i, j, minor.matrix_);
        matrix_[i][j] = minor.Determinant();
        matrix_[i][j] *= pow(-1, i + j);
      }
    }
  }
}
