#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int read_method();
void read_matrix_dimensions(int *n, char c, int *option, char *filename);
//void fill_matrix(double **arr, int n, int option, char c, char *filename);
void PascalMatrix(long double **ar, int n);
long double factorial(long double num);

long double get_determinant(long double **arr, int n, int dim);
void get_cofactor(long double **arr, int n, long double **temp, int r, int c, int dim);
void get_adjoint(long double **arr, int n, long double **adj);
long double** get_inverse(long double **arr, int n);
void print_matrix(long double ** , int );
long double ** transpose_matrix(long double ** , int );
void multiply_matrixes(long double **A, long double **B, int n, long double **AXB);

#endif
