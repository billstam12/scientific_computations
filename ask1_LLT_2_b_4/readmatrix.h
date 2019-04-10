#ifndef READMATRIX_H
#define READMATRIX_H

void read_user_input(double **arr, int n, int m, char c);
void create_random(double **arr, int n, int m, char c);
void read_file_matrix_dims(int *n, char *filename);
void read_matrix_from_file(double **arr, int n, int m, char c,  char *filename);

#endif
