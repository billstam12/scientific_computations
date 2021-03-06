/* 
  Vasileios Stamatopoulos 
  1115201400188
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


long double factorial(long double );

long double get_determinant(long double **, int, int );
void get_cofactor(long double **, int , long double **, int , int , int );
void get_adjoint(long double **, int , long double **);
long double** get_inverse(long double **, int );
void print_matrix(long double ** , int );
long double ** transpose_matrix(long double ** , int );
void multiply_matrixes(long double **, long double **, int , long double **);
void fill_matrix(long double **, int , int , char , char *);

#endif
