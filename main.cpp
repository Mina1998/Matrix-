/*
Program: operation on 2 matrix
Purpose: Demonstrate use of struct and operator
		  overloading to create matrix and
		  functions to operation on matrix
 Author:  Mina Emad Lotfy & Mina Botros
 ID's  :  20170309 , 20170307
 Date  :  27/10/82018
 Version: 1.0
*/
#include"pch.h"
#include <iostream>
#include "matrix.h"
#include <cmath>
#include <cassert>
using namespace std;
void menu() {
	cout << "\t 1. Add two Matrices" << endl;
	cout << "\t 2. Subtract two Matrices" << endl;
	cout << "\t 3. Multiply two Matrices" << endl;
	cout << "\t 4. Add a Scalar to a Matrix" << endl;
	cout << "\t 5. Subtract a Scalar from a Matrix" << endl;
	cout << "\t 6. Multiply a Scalar and a Matrix" << endl;
	cout << "\t 7. Subtract Matrix from another matrix" << endl;
	cout << "\t 8. Increase the Matrix by 1" << endl;
	cout << "\t 9. Decrease the Matrix by 1" << endl;
	cout << "\t10. Transpose the Matrix" << endl;
	cout << "\t11. Check if the Two Matrices are equal" << endl;
	cout << "\t12. Check if the Two Matrices are not equal" << endl;
	cout << "\t13. Check if the Matrix is a Square one" << endl;
	cout << "\t14. Check if the Matrix is Symmetric" << endl;
	cout << "\t15. Check if the Matrix is Identity" << endl;
	cout << "\t16. End the Program" << endl;
}//display all operators to choice
void cinrowwcol(int &row1, int &col1) {
	cout << "enter the row of matrix :" << endl;
	cin >> row1;
	cout << "enter the colomn of matrix :" << endl;
	cin >> col1;
}
int setmat(int &row1, int &col1, int data[]) {
	cout << "enter the data of the matrix " << endl;
	for (int i = 0; i < row1*col1; i++)
	{
		cin >> data[i];
	}
	return *data;
}

int main()
{
	matrix mat1, mat2;
	int choice, num_matrix;
	cout << "HI USER !! " << endl;
	while (true) {
		menu();
		cout << "\n\n";
		cout << "Enter your Choice : ";
		cin >> choice;
		if (choice == 1) {
			int row1, col1, row2, col2;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1,col1, data1);
			cinrowwcol(row2, col2);
			int *data2 = new int[row2*col2];
			setmat(row2, col2, data2);
			matrix mat1(row1, col1, data1);
			matrix mat2(row2, col2, data2);
			matrix sum;
			if (row1 == row2 && col1 == col2)
			{
				sum = mat1 + mat2;
				cout << sum;
			}
			else
			{
				cout << "the two matrix can't be add" << endl;
			}

		}

		if (choice == 2) {
			int row1, col1, row2, col2;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			cinrowwcol(row2, col2);
			int *data2 = new int[row2*col2];
			setmat(row2, col2, data2);
			matrix mat1(row1, col1, data1);
			matrix mat2(row2, col2, data2);
			matrix sum;
			if (row1 == row2 && col1 == col2)
			{
				sum = mat1 - mat2;
				cout << sum;
			}
			else
			{
				cout << "the two matrix can't be add" << endl;
			}


		}

		if (choice == 3) {
			int row1, col1, row2, col2;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			cinrowwcol(row2, col2);
			int *data2 = new int[row2*col2];
			setmat(row2, col2, data2);
			matrix mat1(row1, col1, data1);
			matrix mat2(row2, col2, data2);
			matrix sum;
			if (col1 == row2) {
				sum = mat1 * mat2;
				cout << sum;
			}

		}

		if (choice == 4) {
			int row1, col1;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			int scalar;
			cout << "enter the scalar :" << endl;
			cin >> scalar;
			matrix mat1(row1, col1, data1);
			matrix sum;
			sum = mat1 + scalar;
			cout << sum;
		}

		if (choice == 5) {
			int row1, col1;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			int scalar;
			cout << "enter the scalar :" << endl;
			cin >> scalar;
			matrix mat1(row1, col1, data1);
			matrix sum;
			sum = mat1 - scalar;
			cout << sum;
		}

		if (choice == 6) {
			int row1, col1;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			int scalar;
			cout << "enter the scalar :" << endl;
			cin >> scalar;
			matrix mat1(row1, col1, data1);
			matrix sum;
			sum = mat1 * scalar;
			cout << sum;

		}

		if (choice == 7) {
			int row1, col1, row2, col2;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			cinrowwcol(row2, col2);
			int *data2 = new int[row2*col2];
			setmat(row2, col2, data2);
			matrix mat1(row1, col1, data1);
			matrix mat2(row2, col2, data2);
			matrix sum;
			cout << "if you want sub mat 1 - mat 2 choose (1) or (2)if you want sub mat2 -mat1 :" << endl;
			cin >> num_matrix;
			if (num_matrix == 1) {
				sum = mat1 - mat2;
				cout << sum;
			}
			else if (num_matrix == 2) {
				sum = mat2 - mat1;
				cout << sum;
			}
			else {
				cout << "choose 1 or 2 only :" << endl;
			}
		}

		if (choice == 8) {
			int row1, col1;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			
			matrix mat1(row1, col1, data1);
			matrix sum;
			sum = mat1 + 1;
			cout << sum;

		}

		if (choice == 9) {
			int row1, col1;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			matrix mat1(row1, col1, data1);
			matrix sum;
			sum = mat1 - 1;
			cout << sum;
		}

		if (choice == 10) {
			int row1, col1;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			matrix mat1(row1, col1, data1);
			matrix sum;
			sum = mat1.transpose();
			cout << sum;

		}

		if (choice == 11) {
			
			int row1, col1, row2, col2;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			cinrowwcol(row2, col2);
			int *data2 = new int[row2*col2];
			setmat(row2, col2, data2);
			matrix mat1(row1, col1, data1);
			matrix mat2(row2, col2, data2);
			if (row1 == row2 && col1 == col2) {
				if (data1 == data2) {
					cout << "two matrix are equal" << endl;
				}
				else {
					cout << "two matrix are not equal " << endl;
				}
			}
			else { cout << "two matrix are not equql" << endl; }

		}

		if (choice == 12) {
			int row1, col1, row2, col2;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			cinrowwcol(row2, col2);
			int *data2 = new int[row2*col2];
			setmat(row2, col2, data2);
			matrix mat1(row1, col1, data1);
			matrix mat2(row2, col2, data2);
			if (row1 != row2 && col1 != col2) {
				if (data1 != data2) {
					cout << "two matrix are not equal" << endl;
				}
				else {
					cout << "two matrix are  equal " << endl;
				}
			}
			else {
				cout << "two matrix are equal" << endl;
			}

		}

		if (choice == 13) {
			int row1, col1, row2, col2;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			matrix mat1(row1, col1, data1);
			bool issquare = mat1.isSquare();
			cout << issquare;
		}

		if (choice == 14) {
			int row1, col1, row2, col2;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			matrix mat1(row1, col1, data1);
			bool issymetrk = mat1.isSymetric();
			cout << issymetrk;
		}

		if (choice == 15) {
			int row1, col1;
			cinrowwcol(row1, col1);
			int *data1 = new int[row1*col1];
			setmat(row1, col1, data1);
			matrix mat1(row1, col1, data1);
			bool isidentity = mat1.isIdentity();
			cout << "\n" << isidentity;
		}

		if (choice == 16) {
			cout << "BYEEE" << endl;
			return 0;
		}
	}
	return 0;
}