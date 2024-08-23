#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <algorithm>
#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  bool valid_matrix() const noexcept;
  double det(double** matrix, int rows) const noexcept;
  void new_pointer(double** a, double* b) const noexcept;
  void alg_dop(S21Matrix& a) noexcept;
  void make_minor(int row, int column, double** matrix) noexcept;

 public:
  S21Matrix();
  explicit S21Matrix(const int n);
  S21Matrix(const int rows, const int columns);
  S21Matrix(const S21Matrix& rhs);
  S21Matrix(S21Matrix&& rhs);
  ~S21Matrix();
  int GetRows() const noexcept;
  void SetRows(const int new_rows);
  int GetCols() const noexcept;
  void SetCols(const int new_cols);
  bool EqMatrix(const S21Matrix& rhs) const;
  void SumMatrix(const S21Matrix& rhs);
  void SubMatrix(const S21Matrix& rhs);
  void MulNumber(const double& rhs);
  void MulMatrix(const S21Matrix& rhs);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  S21Matrix& operator=(const S21Matrix& rhs);
  S21Matrix& operator+=(const S21Matrix& rhs);
  S21Matrix& operator-=(const S21Matrix& rhs);
  S21Matrix& operator*=(const double& rhs);
  S21Matrix& operator*=(const S21Matrix& rhs);
  double& operator()(int i, int j);
};

S21Matrix operator+(const S21Matrix lhs, const S21Matrix rhs);
S21Matrix operator-(const S21Matrix lhs, const S21Matrix rhs);
S21Matrix operator*(const S21Matrix lhs, const double rhs);
S21Matrix operator*(const S21Matrix lhs, const S21Matrix rhs);
bool operator==(const S21Matrix lhs, const S21Matrix rhs);
bool operator!=(const S21Matrix lhs, const S21Matrix rhs);

#endif