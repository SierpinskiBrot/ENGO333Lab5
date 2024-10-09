// Lab4.cpp
// Main program file for lab 4
// Insert author information here

#include "Matrix_Lab5.h"
#include "MatrixFunctions_Lab5.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int rows;
    int cols;

    cout << "Enter # of rows in matrix: ";
    cin >> rows;
    cout << "Enter # of cols in matrix: ";
    cin >> cols;

    ofstream input;
	input.open("input.txt");
	for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            double usrin;
            cout << "Enter row " << i+1 << " col " << j+1 << ": ";
            cin >> usrin;
            input << usrin << " ";
        }
        input << endl;
	}
	input.close();

	Matrix mat;
    mat.read("input.txt");
    cout << endl << "Matrix entered: " << endl;
    mat.print(6,3);

    cout << endl << "Determinant of matrix: " << mat.det() << endl;

    cout << endl << "Inverse of matrix: " << endl;
    Matrix inverse = mat.inv();
    inverse.print(6,3);

    cout << endl << "Product of matrix and its inverse: " << endl;
    Matrix product = Multiply(mat,inverse);
    product.print(6,3);



	return 0;
}



