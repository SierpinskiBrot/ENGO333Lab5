// Matrix_Lab4.h
//
// Definition of a basic Matrix class.
//
// History:
//    2012.09.30 - File created by Kyle O'Keefe
//    2015.10.07 - Mark Petovello added the read() function
//    2019.10.03 - File modified by Chandra Tjhai, use #pragma once
//    2020.10.01 - Tjhai edits reverted to match Code::Blocks h.file convention

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

using namespace std;

class Matrix
{
public: //This defines the public (accesible from outside) members of the class
   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   // Constructors


   Matrix(); //This is the default constructor, which accepts no arguments

   // Create a matrix with a specific number of rows and columns
   Matrix( unsigned int rows, unsigned int cols );


   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   // Size-related functions

   // Resize the matrix to the specified number of rows and columns
   void resize( unsigned int rows, unsigned int cols );

   // Get the number of row/columns in the current matrix
   unsigned int getrows() const; //These are constant because they are read-only operations
   unsigned int getcols() const;


   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   // Access elements of the matrix

   // access one element
   double& at( unsigned int rows, unsigned int cols );
   double  at( unsigned int rows, unsigned int cols ) const;


   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   // Typical matrix operations

   // Return a new matrix containing the transpose of the matrix
   Matrix trans() const;

   // Return a new matrix containing the inverse of the matrix
   // NOTE: This inversion function only works with symmetric,
   //       positive-definite matrices (i.e., matrices whose
   //       eigen-values are all positive). These types of matrices
   //       are common in Geomatics, as you will learn in ENGO 363.
   Matrix inv() const;

   // Compute the determinant of the matrix
   double det() const;

   // read matrix from the specific file (one row per line)
   // NOTE: The function assumes there is an equal number of columns in each row of
   //       the matrix (except for blank lines, which are skipped). If not, the
   //       function will terminate the program.
   void read( const string& filename );

private: //This defines the private (only accessable from inside) members of the class
   unsigned int n_rows;
   unsigned int n_cols;
   vector< vector<double> > data; //This creates a 2d vector of doubles
};

#endif // MATRIX_H
