#include "matrix.h"

Matrix::Matrix(const Matrix& other)
{
	matrix = other.matrix;
	cols = other.cols;
	rows = other.rows;
}
// индексирование

double& Matrix::operator()(size_t i, size_t j)
{
	if (i >= this->rows || j >= this->cols)
		throw std::out_of_range("operator (): Выход за пределы матрицы");
	return matrix[i][j];
}

double Matrix::operator()(size_t i, size_t j) const
{
	if (i >= this->rows || j >= this->cols)
		throw std::out_of_range("operator (): Выход за пределы матрицы");
	return matrix[i][j];
}


// перегрузка операторов ввода-вывода

ostream& operator <<(ostream& out, const Matrix& matrix) {
	size_t rows = matrix.GetRows();
	size_t columns = matrix.GetColumns();
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != columns; ++j) {
			if (j > 0) {
				out << "\t";
			}
			out << matrix(i,j);
		}
		out << "\n";
	}
	return out;
}

istream& operator >> (istream& in, Matrix& matrix) {
	size_t rows = matrix.GetRows();
	size_t columns = matrix.GetColumns();
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != columns; ++j) {
			in >> matrix(i,j);
		}
	}
	return in;
}





//------------------------------------------------

// перегрузка операторов сложения


Matrix Matrix::operator+(const Matrix&other) const
{
	Matrix res(*this);
	if (IsEqualSize(other))
	{
		for (size_t i = 0; i != rows; ++i) {
			for (size_t j = 0; j != cols; ++j) {
				res(i,j) += other(i,j);
			}
		}
		return res;
	}
	else throw std::invalid_argument("operator +: Размеры матриц должны быть одинаковы.");
}

Matrix Matrix::operator+(double digit) const
{
	Matrix res(*this);
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			res(i,j) += digit;
		}
	}
	return res;
}

Matrix operator+(double digit, const Matrix& matrix)
{
	Matrix res(matrix);
	for (size_t i = 0; i != res.rows; ++i) {
		for (size_t j = 0; j != res.cols; ++j) {
			res(i, j) += digit;
		}
	}
	return res;
}


Matrix& Matrix::operator+=(double digit)
{
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			(*this)(i, j) += digit;
		}
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	if (IsEqualSize(other))
	{
		for (size_t i = 0; i != rows; ++i) {
			for (size_t j = 0; j != cols; ++j) {
				(*this)(i, j) += other(i, j);
			}
		}
		return *this;
	}
	else throw std::invalid_argument("operator +=: Размеры матриц должны быть одинаковы.");
}

Matrix& Matrix::operator++()
{
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			++(*this)(i,j);
		}
	}
	return *this;
}

Matrix Matrix::operator++(int)
{
	Matrix last_copy(*this);
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			++(*this)(i, j);
		}
	}
	return last_copy;
}

//-----------------------------------------------------------

// перегрузка операторов умножения

Matrix Matrix::operator!() const
{
	Matrix res(this->cols, this->rows);
	for (size_t i = 0; i < this->cols; ++i)
		for (size_t j = 0; j < this->rows; ++j)
		{
			res(i,j) = (*this)(j,i);
		}
	return res;
}

Matrix Matrix::operator*(double digit) const
{
	Matrix res(*this);
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			res(i,j) *= digit;
		}
	}
	return res;
}

Matrix Matrix::operator*(const Matrix& other) const
{
	if (IsMultiplicate(other))
	{
		Matrix ans(this->rows, other.cols);
		for (size_t i = 0; i < this->rows; ++i)
			for (size_t j = 0; j < other.cols; ++j)
			{
				ans(i,j) = 0;
				for (size_t k = 0; k < this->cols; ++k)
					ans(i,j) = ans(i,j) + (*this)(i,k) * other(k,j);
			}
		return ans;
	}
	else throw std::invalid_argument("operator *: Количество столбцов первой матрицы должно быть равно количеству строк второй");
}
Matrix operator*(double digit, const Matrix& matrix)
{
	Matrix res(matrix);
	for (size_t i = 0; i != res.rows; ++i) {
		for (size_t j = 0; j != res.cols; ++j) {
			res(i, j) *= digit;
		}
	}
	return res;
}

Matrix& Matrix::operator*=(double digit)
{
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			(*this)(i,j) *= digit;
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	if (IsMultiplicate(other))
	{
		Matrix ans(this->rows, other.cols);
		for (size_t i = 0; i < this->rows; ++i)
			for (size_t j = 0; j < other.cols; ++j)
			{
				ans(i,j) = 0;
				for (size_t k = 0; k < this->cols; ++k)
					ans(i, j) = ans(i, j) + (*this)(i,k) * other(k,j);
			}
		*this = ans;
		return *this;
	}
	else throw std::invalid_argument("Количество столбцов первой матрицы должно быть равно количеству строк второй");
}



//-----------------------------------------------------------

// перегрузка операторов вычитания

Matrix Matrix::operator-(const Matrix& other) const
{
	Matrix res(*this);
	if (IsEqualSize(other))
	{
		for (size_t i = 0; i != rows; ++i) {
			for (size_t j = 0; j != cols; ++j) {
				res(i,j) -= other(i,j);
			}
		}
		return res;
	}
	else throw std::invalid_argument("operator -: Размеры матриц должны быть одинаковы.");
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	if (IsEqualSize(other))
	{
		for (size_t i = 0; i != rows; ++i) {
			for (size_t j = 0; j != cols; ++j) {
			   (*this)(i, j) -= other(i, j);
			}
		}
		return *this;
	}
	else throw std::invalid_argument("operator -=: Размеры матриц должны быть одинаковы.");;
}

Matrix& Matrix::operator--()
{
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			--(*this)(i,j);
		}
	}
	return *this;
}

Matrix Matrix::operator--(int)
{
	Matrix last_copy(*this);
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			(*this)(i, j)--;
		}
	}
	return last_copy;
}

Matrix Matrix::operator-(double digit) const
{
	Matrix res(*this);
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			res(i,j) -= digit;
		}
	}
	return res;
}

Matrix& Matrix::operator-=(double digit)
{
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			(*this)(i, j) -= digit;
		}
	}
	return *this;
}


//-----------------------------------------------------------

// перегрузка операторов логики

bool Matrix::operator==(const Matrix& other) const
{
	return this->matrix == other.matrix;
}

bool Matrix::operator!=(const Matrix& other) const
{
	return !(this->matrix == other.matrix);
}



//-----------------------------------------------------------

// вспомогательные функции

//Возвращает матрицу matrix без row-ой строки и col-того столбца
Matrix Matrix::GetMatrix(int col) const {

	Matrix newMatrix(this->rows- 1, this->cols - 1);
	int offsetCol = 0; //Смещение индекса столбца в матрице
	for (size_t i = 1; i < this->rows; i++) {
		offsetCol = 0;
		for (size_t j = 0; j < this->rows - 1; j++) {
			if (j == col) {
				offsetCol = 1;
			}

			newMatrix(i-1,j) = (*this)(i,j+offsetCol);
		}
	}
	return newMatrix;
}

double Matrix::Determinant() const
{
	if (this->cols != this->rows) throw std::invalid_argument("Determinant: Матрица должна быть квадратной!");
	if (this->cols == 0 || this->rows == 0) throw std::invalid_argument("Determinant: Невозможно вычислить определитель пустой матрицы");
	if (this->cols == 1) return (*this)(0,0);
	if (this->cols == 2) return (*this)(0,0) * (*this)(1,1) - (*this)(1,0) * (*this)(0,1);
	double det = 0;
	int degree = 1;
	for (size_t j = 0; j < this->cols; j++)
	{
		det += (*this)(0,j) * this->GetMatrix(j).Determinant() * degree;
		degree = -degree;
	}
	return det;
}

void Matrix::FillRandom()
{
	srand(time(NULL));
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			(*this)(i, j) = rand() % 100 - 50; // случайные числа от -50 до 50
		}
	}
}

bool Matrix::IsEqualSize(const Matrix& other) const
{
	return this->cols == other.cols && this->rows == other.rows;
}

bool Matrix::IsMultiplicate(const Matrix& other) const
{
	return this->cols == other.rows;
}

//-----------------------------------------------------------

