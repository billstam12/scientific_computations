#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int read_method();
void read_matrix_dimensions(int *n, char c, int *option, char *filename);
void fill_matrix(double **arr, int n, int option, char c, char *filename);

double get_determinant(double **arr, int n, int dim);
void get_cofactor(double **arr, int n, double **temp, int r, int c, int dim);
void get_adjoint(double **arr, int n, double **adj);
int get_inverse(double **arr, int n, double **inverted);

void multiply_matrixes(double **A, double **B, int n, double **AXB);

#endif
