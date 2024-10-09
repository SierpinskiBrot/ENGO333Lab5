// Matrix_Lab5.h
//
// Definition of a basic Matrix class.
//
// History:
//    2012.09.30 - File created by Kyle O'Keefe
//    2015.10.07 - File created by Mark Petovello

#ifndef MATRIX_LAB_5
#define MATRIX_LAB_5

#include <vector>
#include <string>

using namespace std;

class Matrix
{
public:
   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   // Constructors

   // Default constructor (accepts no arguments)
   Matrix();

   // Create a matrix with a specific number of rows and columns
   Matrix( unsigned int rows, unsigned int cols );


   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   // Size-related functions

   // Resize the matrix to the specified number of rows and columns
   void resize( unsigned int rows, unsigned int cols );

   // Get the number of row/columns in the current matrix
   unsigned int getrows() const;
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
   //       are common in Geomatics, as you will learn in ENGO 361.
   Matrix inv() const;

   // Compute the determinant of the matrix
   double det() const;

   // read matrix from the specific file (one row per line)
   // NOTE: The function assumes there is an equal number of columns in each row of
   //       the matrix (except for blank lines, which are skipped). If not, the
   //       function will terminate the program.
   void read( const string& filename );

   // print the matrix to screen (one row per line) with the given field width and
   // precision (number of decimals)
   void print( int width, int precision );

   // print the matrix to the specified file (one row per line) with the given
   // field width and precision (number of decimals)
   void print( const string& filename, int width, int precision );

   //LAB 5: Put your 3 member function prototypes here:
    Matrix multiply(Matrix B); //Multiply self by matrix B
    Matrix multiply(double K); //Multiply self by constant K
    Matrix add(Matrix B);      //Add self to matrix B

   //LAB 5: Then put 3 operator overload prototypes here:
    Matrix operator*(Matrix B); //Overload * operator for matrix multiplication
    Matrix operator*(double K); //Overload * operator for scalar multiplication
    Matrix operator+(Matrix B); //Overload + operator for matrix addition

private:
   unsigned int n_rows;
   unsigned int n_cols;
   vector< vector<double> > data;
};

#endif // MATRIX_LAB_5
