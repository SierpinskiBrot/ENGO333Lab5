// Lab4.cpp
// Main program file for lab 4
// Insert author information here

#include "Matrix_Lab4.h"
#include "MatrixFunctions.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// Insert your pre-lab program here
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
    displayMatrix(mat);

    cout << endl << "Determinant of matrix: " << mat.det() << endl;

    cout << endl << "Inverse of matrix: " << endl;
    Matrix inverse = mat.inv();
    displayMatrix(inverse);

    cout << endl << "Product of matrix and its inverse: " << endl;
    Matrix product = Product(mat,inverse);
    displayMatrix(product);

	// Before you go further, build the project and make sure your program works with
    // with no errors


	return 0;

}



