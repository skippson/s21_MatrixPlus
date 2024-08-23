#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &rhs) const {
  if (!valid_matrix() || !rhs.valid_matrix()) {
    throw std::logic_error("invalid matrix");
  }

  if (rows_ != rhs.rows_ || cols_ != rhs.cols_) {
    return false;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(this->matrix_[i][j] - rhs.matrix_[i][j]) > 1E-7) {
        return false;
      }
    }
  }

  return true;
}