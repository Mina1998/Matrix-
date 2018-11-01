#pragma
#include"pch.h"
#include <iostream>
using namespace std;

class matrix
{
private:
	int** data;
	int row, col;
public:
	matrix(int r = 0, int c = 0, int num[] = 0)
	{
		row = r;
		col = c;
		data = new int*[r];

		for (int i = 0; i < r; i++)
			data[i] = new int[c];

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				data[i][j] = num[i * col + j];
	}

	matrix operator+  (matrix mat1);   // done
	matrix operator-  (matrix mat1);   //done
	matrix operator*  (matrix mat1);   //done
	matrix operator+  (int scalar);    //done
	matrix operator-  (int scalar);    //done
	matrix operator*  (int scalar);    //done

	matrix operator+= (matrix mat1);  //done
	matrix operator-= (matrix mat1);  //done
	matrix operator+= (int scalar);    //done
	matrix operator-= (int scalar);    //done
	void   operator++ ();    //done
	void   operator-- ();    //done
	friend istream& operator>> (istream& in, matrix& mat);	// done
	friend ostream& operator<< (ostream& out, matrix mat);	// done

	bool   operator== (matrix mat1);    //done
	bool   operator!= (matrix mat1);    //done
	bool   isSquare(); //done
	bool   isSymetric();  // done
	bool   isIdentity();  // done
	matrix transpose();   //done

};

