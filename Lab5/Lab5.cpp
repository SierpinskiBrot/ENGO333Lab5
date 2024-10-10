// Lab4.cpp
// Main program file for lab 4
// Insert author information here

#include "Matrix_Lab5.h"
#include "MatrixFunctions_Lab5.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    Matrix textM;
    textM.read("M.txt");
    textM.print(6,3);

    Matrix rotation = R3(30.0*M_PI/180.0);
    Matrix rotation2 = R2(-45.0*M_PI/180.0);
    Matrix rotated = (rotation*(textM.trans())).trans();
    Matrix scaled = rotated*2.0;
    scaled.print(6,3);
    Matrix rotated2 = (rotation2*(rotated.trans())).trans();

    rotated.print("outputr30.txt",6,3);
    scaled.print("outputr30s2.txt",6,3);
    rotated2.print("outputr30r45.txt",6,3);

    /*
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

    Matrix multps = mat*6;
    cout << "mat*6" << endl;
    multps.print(6,3);

    Matrix r2 = R2(1);
    cout << "r2: " << endl;
    r2.print(6,3);

    Matrix rt = multps*R2(1);
    cout << "rt*r2" << endl;
    rt.print(6,3);

    Matrix add = rt+mat;
    cout << "rt+mat" << endl;
    add.print(6,3);

    */

    /*
    cout << endl << "Determinant of matrix: " << mat.det() << endl;

    cout << endl << "Inverse of matrix: " << endl;
    Matrix inverse = mat.inv();
    inverse.print(6,3);

    cout << endl << "Product of matrix and its inverse: " << endl;
    Matrix product = Multiply(mat,inverse);
    product.print(6,3);
    */

	return 0;
}



