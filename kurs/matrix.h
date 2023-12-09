#pragma once
using namespace std;
#include <vector>
#include <fstream>
class Matrix
{
private:
	size_t cols;
	size_t rows;
	vector<vector<double>> matrix;
	Matrix GetMatrix(int col) const;
	bool IsMultiplicate(const Matrix& other) const;
	bool IsEqualSize(const Matrix& other) const;
public:
	Matrix() : cols(0), rows(0), matrix(0, vector<double>(0)) {};
	Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), matrix(vector<vector<double>>(rows, vector<double>(cols))) {};
	Matrix(const Matrix& other); // конструктор копирования

	Matrix operator +(const Matrix& other) const;
	Matrix operator +(double digit) const;
	Matrix& operator +=(double digit);
	Matrix& operator +=(const Matrix& other);
	Matrix& operator ++(); 
	Matrix operator ++(int); 
	Matrix operator *(double digit) const; // умножение на число
	Matrix operator *(const Matrix& other) const; // умножение на другую матрицу
	Matrix& operator *=(double digit);
	Matrix& operator *=(const Matrix& other);

	Matrix operator -(const Matrix& other) const;
	Matrix operator -(double digit) const;
	Matrix& operator -=(double digit);
	Matrix& operator -=(const Matrix& other);
	Matrix& operator --(); // префиксный декремент
	Matrix operator --(int); // постфиксный декремент

	Matrix operator !() const; // транспонирование
	bool operator ==(const Matrix& other) const;
	bool operator != (const Matrix& other) const;

	double& operator ()(size_t i, size_t j);
	double operator()(size_t i, size_t j) const;

	size_t GetRows() const { return this->rows; }
	size_t GetColumns() const { return this->cols; }
	
	double Determinant() const;

	friend Matrix operator+(double digit, const Matrix& other);
	friend Matrix operator*(double digit, const Matrix& other);
};

ostream& operator <<(ostream& out, const Matrix& matrix);
istream& operator >>(istream& in, Matrix& matrix);
Matrix operator+(double digit, const Matrix& matrix);
Matrix operator *(double digit, const Matrix& matrix);
