#include "MatrixFunctions_Lab5.h"
#include <iostream>
#include <math.h>

using namespace std;

//multiply two matrices and return the product, from Lab 4
Matrix Multiply(const Matrix& A, const Matrix& B)
{
    if(A.getcols()!=B.getrows())
    {
        cout << "Matrix multiplication only works if the inner dimensions (A columns == B rows) agree" << endl;
        exit(1);
    }
    Matrix result(A.getrows(), B.getcols());
    for (unsigned int i = 0; i < result.getrows(); i++)
    {
        for (unsigned int j = 0; j < result.getcols(); j++)
        {
            result.at(i,j) = 0.0;
            for (unsigned int k = 0; k < A.getcols(); k++)   //A columns = B rows
            {
                result.at(i,j) += A.at(i,k)*B.at(k,j);   //multiply and add up the inner dimension
            }
        }
    }
    return result;
}

//multiply a matrix by a scalar (double) and return the result
Matrix Multiply(const Matrix& A, double k)
{
    //To do: implement this function to return A scaled by k
    Matrix result;


    return result;
}

//add two matrices and return the result;
Matrix Add(const Matrix& A, Matrix& B)
{
    if(A.getrows() != B.getrows() || A.getcols() != B.getcols())
    {
        cout << "Can't add matrices with different dimensions" << endl;
        exit(1);
    }
    //make a matrix to store the result
    Matrix result(A.getrows(), A.getcols());

    //do a nested for loop to do the addition
    for (unsigned int i = 0; i < A.getrows(); i++)
    {
        for (unsigned int j = 0; j < A.getcols() ; j++)
        {
            result.at(i,j) = A.at(i,j) + B.at(i,j);
        }
    }
    //return the result.
    return result;
}


// TO DO: Implement rotation matrix functions from the prelab

Matrix R1(double angle) {
    Matrix rMat(3,3);
    rMat.at(0,0) = 1;
    rMat.at(1,1) = cos(angle);
    rMat.at(2,2) = cos(angle);
    rMat.at(1,2) = sin(angle);
    rMat.at(2,1) = -sin(angle);
    return rMat;
}
Matrix R2(double angle) {
    Matrix rMat(3,3);
    rMat.at(1,1) = 1;
    rMat.at(0,0) = cos(angle);
    rMat.at(2,2) = cos(angle);
    rMat.at(0,2) = -sin(angle);
    rMat.at(2,0) = sin(angle);
    return rMat;
}
Matrix R3(double angle) {
    Matrix rMat(3,3);
    rMat.at(2,2) = 1;
    rMat.at(1,1) = cos(angle);
    rMat.at(0,0) = cos(angle);
    rMat.at(0,1) = sin(angle);
    rMat.at(1,0) = -sin(angle);
    return rMat;
}
