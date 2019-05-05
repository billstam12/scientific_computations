/* 
  Vasileios Stamatopoulos 
  1115201400188
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "esor.h"

int main(void){

    printf("ESOR on PentaDiagonal Matrix\n");
    int size_a, size_b;
    size_a = 0;
    size_b = 0;
    int option;
    //Select method of reading matrices
    char *file1 = malloc(100*sizeof(char));
    char *file2 = malloc(100*sizeof(char));

    read_matrix_dimensions(&size_a, 'A', &option, file1);
    printf("Matrix size = %d\n",size_a);
    double **A = (double**)malloc(size_a * sizeof(double*));
    for(int i = 0; i < size_a; i++){
       A[i] = malloc(size_a * sizeof(double));
    }
    fill_matrix(A, size_a, option, 'A', file1);
    free(file1);
    file1=NULL;
    printf("Matrix A:\n");
    print_matrix_2d(A, size_a);
    
    read_matrix_dimensions(&size_b, 'B', &option, file2);
    double *b=malloc(size_b*sizeof(double*));
    
    fill_matrix_b(b, size_b, option, 'B', file2);
    free(file2);
    file2=NULL;

    printf("\nArray b:\n");
    print_matrix_1d(b, size_a);
    esor(A, b, size_a);
    
}

