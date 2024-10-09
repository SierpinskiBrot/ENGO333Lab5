#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H

#include "Matrix_Lab5.h"

//Prototypes of 3 non-member functions to do arithmetic on matrix objects

//multiply two matrices and return the result (from lab 4)
Matrix Multiply(const Matrix& A, const Matrix& B);

//multiply a matrix by a scalar (double) and return the result
Matrix Multiply(const Matrix& A, double k);

//add two matrices and return the result; (from the lecture)
Matrix Add(const Matrix& A, Matrix& B);

//TO DO: Add prototypes for rotation matrices from the Prelab:


#endif // MATRIX_FUNCTIONS_H



