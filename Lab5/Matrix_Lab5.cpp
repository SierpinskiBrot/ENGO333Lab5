// Matrix_Lab5.h
//
// Implementation of a basic Matrix class.
//
// History:
//    2012.09.30 - File created by Kyle O'Keefe
//    2015.10.07 - Mark Petovello added the read() function

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Matrix_Lab5.h"


//Constructor: Used to set size to zero
Matrix::Matrix()
{
   n_rows = 0;
   n_cols = 0;
   data.resize( 0 );  //this line not necessary as the vector constructor will do this.
}

//Overload of constructor, to declare a matrix with dimensions
Matrix::Matrix( unsigned int rows, unsigned int cols )
{
   n_rows = rows;
   n_cols = cols;
   data.resize( rows );
   for( unsigned int i = 0; i < n_rows; i++ )
      data[i].resize( n_cols );
   return;
}

//Resize function, uses the resize function of vector
void Matrix::resize( unsigned int rows, unsigned int cols )
{
   n_rows = rows;
   n_cols = cols;
   data.resize( rows );
   for( unsigned int i = 0; i < n_rows; i++ )
      data[i].resize( n_cols );
   return;
}

double& Matrix::at( unsigned int rows, unsigned int cols )
{
   if( rows < n_rows && cols < n_cols )
      return data.at( rows ).at( cols );
   else
   {
      cout << "Error: Matrix::at Index requested exceeds matrix dimensions" << endl;
      exit( 1 );
   }
}

double Matrix::at( unsigned int rows, unsigned int cols ) const
{
   if( rows < n_rows && cols < n_cols )
      return data.at( rows ).at( cols );
   else
   {
      cout << "Error: Matrix::at const Index requested exceeds matrix dimensions" << endl;
      exit( 1 );
   }
}

unsigned int Matrix::getrows() const
{
   return this->n_rows;
}

unsigned int Matrix::getcols() const
{
   return this->n_cols;
}

Matrix Matrix::trans() const
{
   Matrix temp( n_cols, n_rows );
   for( unsigned int i = 0; i < n_rows; i++ )
      for( unsigned int j = 0; j < n_cols; j++ )
         temp.at( j, i ) = at( i, j );
   return temp;
}

double Matrix::det() const
{
   if( n_rows != 2 || n_cols != 2 )
   {
      cout << "Error: Matrix::det Function only defined for 2x2 matrices" << endl;
      exit( 1 );
   }
   return at( 0, 0 )*at( 1, 1 ) - at( 1, 0 )*at( 0, 1 );
   //return this->at(0,0)*this->at(1,1) - this->at(1,0)*this->at(0,1);
}

Matrix Matrix::inv() const
{
   const double EPSILON = 1.0E-12;

   if( n_rows == 0 || n_cols == 0 )
   {
      cout << "I don't know how you were inverted, no one alerted you (Harrison, 1968)" << endl;
      cout << "Error: Matrix::inv Inverse called on matrix with zero rows and/or columns" << endl;
      exit( 1 );
   }

   if( n_rows != n_cols )
   {
      cout << "I don't know how you were inverted, no one alerted you (Harrison, 1968)" << endl;
      cout << "Error: Matrix::inv Non-square matrix in Cholesky Decomposition" << endl;
      exit( 1 );
   }

   // temp object to hold the result
   Matrix A( n_rows, n_cols ); // store result

   for( unsigned int i = 0; i < this->n_rows; i++ )
   for( unsigned int j = 0; j < this->n_cols; j++ )
      A.at( i, j ) = this->at( i, j );

   // check for positive definiteness
   for( unsigned int i = 0; i < n_rows; i++ )
   {
      if( A.at( i, i ) < 0.0 )
      {
         cout << "I don't know how you were inverted, no one alerted you (Harrison, 1968)" << endl;
         cout << "Error: Matrix::inv Matrix not positive definite in Cholesky Decomposition" << endl;
         exit( 1 );
      }

      if( fabs( A.at( i, i ) ) < EPSILON )
      {
         cout << "I don't know how you were inverted, no one alerted you (Harrison, 1968)" << endl;
         cout << "Error: Matrix::inv Singular matrix in Cholesky Decomposition" << endl;
         exit( 1 );
      }
   }

   // Perform Choleski decomposition
   for( unsigned int j = 0; j < n_rows; j++ )
   {
      for( unsigned int k = 0; k < j; k++ )
         A.at( j, j ) -= A.at( j, k ) * A.at( j, k );
      if( A.at( j, j ) < 0.0 )
      {
         cout << "I don't know how you were inverted, no one alerted you (Harrison, 1968)" << endl;
         cout << "Error: Matrix::inv Square root of negative number in Cholesky Decomposition" << endl;
         exit( 1 );
      }

      A.at( j, j ) = sqrt( A.at( j, j ) );
      for( unsigned int i = j + 1; i < n_rows; i++ )
      {
         for( unsigned int k = 0; k < j; k++ )
            A.at( i, j ) -= A.at( i, k ) * A.at( j, k );

         if( fabs( A.at( j, j ) ) < EPSILON )
         {
            cout << "I don't know how you were inverted, no one alerted you (Harrison, 1968)" << endl;
            cout << "Error: Matrix::inv Division by zero in Cholesky Decomposition" << endl;
            exit( 1 );
         }
         A.at( i, j ) /= A.at( j, j );
      }
   }

   // inversion of lower triangular matrix
   for( unsigned int j = 0; j < n_rows; j++ )
   {
      A.at( j, j ) = 1.0 / A.at( j, j );

      for( unsigned int i = j + 1; i < n_rows; i++ )
      {
         A.at( i, j ) *= -A.at( j, j ) / A.at( i, i );

         for( unsigned int k = j + 1; k < i; k++ )
            A.at( i, j ) -= A.at( i, k ) * A.at( k, j ) / A.at( i, i );
      }
   }

   // construction of lower triangular inverse matrix
   for( unsigned int j = 0; j < n_rows; j++ )
   {
      for( unsigned int i = j; i < n_rows; i++ )
      {
         A.at( i, j ) *= A.at( i, i );

         for( unsigned int k = i + 1; k < n_rows; k++ )
            A.at( i, j ) += A.at( k, i ) * A.at( k, j );
      }
   }

   // fill upper diagonal
   for( unsigned int i = 1; i < n_rows; i++ )
   {
      for( unsigned int j = 0; j < i; j++ )
         A.at( j, i ) = A.at( i, j );
   }
   return A; // return a copy
}

void Matrix::read( const string& filename )
{
   // clear the matrix by using the clear member function of <vector>
   data.clear( );
   n_rows = 0;
   n_cols = 0;

   // open the input file
   ifstream in( filename );
   if( in.fail( ) )
   {
      cout << "Could not open input file" << endl;
      exit( 1 );
   }

   // read the first line
   string line;
   if( !getline( in, line ) )
   {
      cout << "Could not read first line" << endl;
      exit( 1 );
   }

   // An 'istringstream' is a bit like a ifstream, but instead of connecting to and
   // reading from a file, it reads from a string (in this case, the line that was
   // just read). NOTE: You are NOT expected to know about stringstreams for ENGO 333
   istringstream strStream( line );
   strStream.str( line );

   // count how many values can be read on the line
   vector< double > oneRow;
   double oneValue;
   while( strStream >> oneValue )
      oneRow.push_back( oneValue );
   unsigned int numColumns = oneRow.size( );

   // store the first row in the matrix
   data.push_back( oneRow );

   // continue reading rows...
   while( !in.eof( ) )
   {
      // read the next line
      if( !getline( in, line ) && !in.eof( ) )
      {
         cout << "Error reading file" << endl;
         exit( 1 );
      }

      // check for blank line
      if( line.length( ) == 0 )
         continue;

      // update the string stream
      strStream.clear( );
      strStream.str( line );

      // remove all elements in the row and read a new row
      oneRow.clear( );
      for( unsigned int i = 0; i < numColumns; ++i )
      {
         if( strStream >> oneValue )
         {
            oneRow.push_back( oneValue );
         }
         else
         {
            cout << "Different number of columns per row" << endl;
            exit( 1 );
         }
      }

      // add the row to the matrix
      data.push_back( oneRow );
   }

   // close the file
   in.close( );

   // store the final size of the matrix
   n_rows = data.size( );
   n_cols = numColumns;
}

void Matrix::print( int width, int precision )
{
   // setup
   cout << fixed << showpoint << setprecision( precision );

   // print the data
   for( unsigned int i = 0; i < getrows( ); ++i )
   {
      for( unsigned int j = 0; j < getcols( ); ++j )
      {
         cout << setw( width ) << at( i, j ) << " ";
      }
      cout << endl;
   }
}

void Matrix::print( const string& filename, int width, int precision )
{
   // open the output file
   ofstream out( filename );
   if( out.fail( ) )
   {
      cout << "Could not open output file" << endl;
      exit( 1 );
   }

   // setup
   out << fixed << showpoint << setprecision( precision );

   // print the data
   for( unsigned int i = 0; i < getrows(); ++i )
   {
      for( unsigned int j = 0; j < getcols(); ++j )
      {
         out << setw( width ) << at( i, j ) << " ";
      }
      out << endl;
   }

   // close the file
   out.close();
}

Matrix Matrix::operator*(Matrix B) {
    if(this->getcols()!=B.getrows())
    {
        cout << "Matrix multiplication only works if the inner dimensions (A columns == B rows) agree" << endl;
        exit(1);
    }
    Matrix result(this->getrows(), B.getcols());
    for (unsigned int i = 0; i < result.getrows(); i++)
    {
        for (unsigned int j = 0; j < result.getcols(); j++)
        {
            result.at(i,j) = 0.0;
            for (unsigned int k = 0; k < this->getcols(); k++)   //A columns = B rows
            {
                result.at(i,j) += this->at(i,k)*B.at(k,j);   //multiply and add up the inner dimension
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double k) {
    //To do: implement this function to return A scaled by k
    Matrix result(this->getrows(), this->getcols());
    for (unsigned int i = 0; i < result.getrows(); i++)
    {
        for (unsigned int j = 0; j < result.getcols(); j++)
        {
            result.at(i,j) = k*this->at(i,j);
        }
    }
    return result;
}

Matrix Matrix::operator+(Matrix B) {
    if(this->getcols()!=B.getcols() || this->getrows() != B.getrows())
    {
        cout << "Matrix addition only works if the matrices are the same dimensions" << endl;
        exit(1);
    }
    Matrix result(this->getrows(), B.getcols());
    for (unsigned int i = 0; i < result.getrows(); i++)
    {
        for (unsigned int j = 0; j < result.getcols(); j++)
        {
            result.at(i,j) = this->at(i,j)+B.at(i,j);
        }
    }
    return result;
}
