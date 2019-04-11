/* 
  Vasileios Stamatopoulos 
  1115201400188
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int read_method();
void read_matrix_dimensions(int *, char , int *, char *);
//void fill_matrix(double **arr, int n, int option, char c, char *filename);
void pei_matrix(long double **, int );
long double factorial(long double );

long double get_determinant(long double **, int, int );
void get_cofactor(long double **, int , long double **, int , int , int );
void get_adjoint(long double **, int , long double **);
long double** get_inverse(long double **, int );
void print_matrix(long double ** , int );
long double ** transpose_matrix(long double ** , int );
void multiply_matrixes(long double **, long double **, int , long double **);

#endif
