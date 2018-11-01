#include"pch.h"
#include "matrix.h"
#include <iostream>
using namespace std;


istream & operator>>(istream & in, matrix & mat)// input matrix
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			in >> mat.data[i][j];
		}
	}
	return in;
}
ostream & operator<<(ostream & out, matrix mat)// display matrix
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			out << mat.data[i][j] << " ";;
		}
		out << endl;
	}
	return out;
}
matrix matrix :: operator+ (matrix mat1)//Add if same dimensions
{
	matrix sum;
	sum.row = mat1.row;
	sum.col = mat1.col;

	sum.data = new int*[mat1.row];

	for (int i = 0; i < mat1.row; i++)
		sum.data[i] = new int[mat1.col];

	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			sum.data[i][j] = data[i][j] + mat1.data[i][j];
		}
	}

	return sum;
}


matrix matrix :: operator-  (matrix mat1) // Sub if same dimensions
{
	matrix sum;
	sum.row = mat1.row;
	sum.col = mat1.col;

	sum.data = new int*[mat1.row];

	for (int i = 0; i < mat1.row; i++)
		sum.data[i] = new int[mat1.col];

	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			sum.data[i][j] = data[i][j] - mat1.data[i][j];
		}
	}

	return sum;


}

matrix matrix :: operator+  (int scalar) // Add a scalar to matrix
{
	matrix sum;
	sum.row = row;
	sum.col = col;
	sum.data = new int*[row];

	for (int i = 0; i < row; i++)
		sum.data[i] = new int[col];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum.data[i][j] = data[i][j] + scalar;
		}
	}

	return sum;
}

matrix matrix :: operator-  (int scalar) // sub a scalar from matrix
{
	matrix sum;
	sum.row = row;
	sum.col = col;
	sum.data = new int*[row];

	for (int i = 0; i < row; i++)
		sum.data[i] = new int[col];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum.data[i][j] = data[i][j] - scalar;
		}
	}

	return sum;
}

matrix matrix :: operator*  (int scalar) // Multiple by scalar
{
	matrix sum;
	sum.row = row;
	sum.col = col;
	sum.data = new int*[row];

	for (int i = 0; i < row; i++)
		sum.data[i] = new int[col];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum.data[i][j] = data[i][j] * scalar;
		}
	}

	return sum;
}

matrix matrix :: operator*  (matrix mat1) // Multi if col1 == row2
{
	matrix sum;
	sum.row = row;
	sum.col = mat1.col;
	sum.data = new int*[row];

	for (int i = 0; i < row; i++) {

		sum.data[i] = new int[mat1.col];
	}

	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum.data[i][j] = 0;

			for (int k = 0; k < mat1.col; k++) {

				sum.data[i][j] += mat1.data[i][k] * data[k][j];
			}

		}
	}
	return sum;
}

matrix matrix :: operator+= (matrix mat1)// mat1 changes & return and new matrix with the sum
{
	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			mat1.data[i][j] += data[i][j];
		}
	}
	return mat1;
}

matrix matrix :: operator-= (matrix mat1)// mat1 changes + return new and matrix with difference
{
	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			mat1.data[i][j] -= data[i][j];
		}
	}
	return mat1;
}

matrix matrix :: operator+= (int scalar) // change mat & return new
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] += scalar;
		}
	}
	matrix sum;
	sum.row = row;
	sum.col = col;
	sum.data = new int*[row];

	for (int i = 0; i < row; i++) {

		sum.data[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum.data[i][j] = data[i][j];
		}
	}

	return sum;
}

matrix matrix :: operator-= (int scalar) // change mat & return new
{


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] -= scalar;
		}
	}
	matrix sum;
	sum.row = row;
	sum.col = col;
	sum.data = new int*[row];

	for (int i = 0; i < row; i++) {

		sum.data[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum.data[i][j] = data[i][j];
		}
	}

	return sum;
}

void matrix ::  operator++ ()// Add 1 to each element ++mat
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] += 1;
		}
	}
}

void matrix :: operator-- () // Sub 1 from each element --mat
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] -= 1;
		}
	}
}
bool matrix ::  operator== (matrix mat1) // True if identical
{
	bool found = true;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			if (mat1.data[i][j] == data[i][j])
			{
				continue;
			}
			else
			{
				found = false;
				break;
			}
		}
		if (!found)
		{
			return false;
			break;
		}
	}
	return true;
}

bool matrix ::  operator!= (matrix mat1) // True if not same
{
	bool found = true;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			if (mat1.data[i][j] != data[i][j])
			{
				continue;
			}
			else
			{
				found = false;
				break;
			}
		}
		if (!found)
		{
			return false;
			break;
		}
	}
	return true;
}

bool matrix::isSquare()// True if square matrix
{
	if (col == row)
	{
		return true;
	}
	else
	{
		return false;
	}
}

matrix matrix::transpose() // Return new matrix with the transpose
{
	matrix m;
	m.row = col;
	m.col = row;
	m.data = new int*[col];

	for (int i = 0; i < col; i++)
		m.data[i] = new int[row];

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			m.data[i][j] = data[j][i];
		}
	}
	return m;
}

bool matrix::isSymetric() // True if square and symmetric
{
	matrix m;
	m.row = col;
	m.col = row;
	m.data = new int*[col];

	for (int i = 0; i < col; i++)
		m.data[i] = new int[row];

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			m.data[i][j] = data[j][i];
		}
	}

	bool found = true;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (m.data[i][j] == data[i][j])
			{
				continue;
			}
			else
			{
				found = false;
				break;
			}
			if (!found)
			{
				return false;
				break;
			}
		}
	}
	return true;
}

bool matrix::isIdentity() // True if square and identity
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (data[i][j] != 1 && i == j) {
				return false;
			}
			if (i != j && data[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}