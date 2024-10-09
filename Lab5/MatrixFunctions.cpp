// MatrixFunctions.cpp
// ENGO 333 Lab 4
// Definitions for Matrix-related functions.

#include "MatrixFunctions.h"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


Matrix Product( const Matrix& A, const Matrix& B )
{
	// this implementation returns an empty matrix; you need to update the function
	// to return the matrix product (see the prelab for implementation guidelines)
   int h1 = A.getrows();
   int h2 = B.getrows();
   int w1 = A.getcols();
   int w2 = B.getcols();


   //Result is height of 1st x width of 2nd
	Matrix C = Matrix(h1, w2);

	for(int i = 0; i < h1; i++) { //i is current row
        for(int j = 0; j < w2; j++) { //j is current col
            C.at(i,j) = 0;
            for(int k = 0; k < w1; k++) {//k is uhhhh like what pair of numbers u are on like crawling across A and down B
                C.at(i,j) += A.at(i,k)*B.at(k,j);
            }
        }
	}


	return C;
}

void displayMatrix(Matrix matrix) {
    for(int i = 0; i < matrix.getrows(); i++) {
        for(int j = 0; j < matrix.getcols(); j++) {
            cout << fixed << setw(6) << setprecision(3) << right << matrix.at(i,j) << " ";
        }
        cout << endl;
    }
}
