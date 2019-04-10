#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int read_method();
void read_matrix_dimensions(int *, char , int *, char *);
void fill_matrix(double **, int , int , char , char *);
void print_matrix(double ** , int );
double ** transpose_matrix(double ** , int );
double * forward_subs(double** , double **, int );
double * backward_subs(double** , double **, int );

#endif
