#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "cholesky_decomposition.h"


int main(void){

    
    //Select method of reading matrices
    int size_a, size_b;
    int flag=0, option;

    char *file1 = malloc(100*sizeof(char));
    char *file2 = malloc(100*sizeof(char));

    read_matrix_dimensions(&size_a, 'A', &option, file1);
    double **A = malloc(size_a * sizeof(double*));
    for(int i = 0; i < size_a; i++){
       A[i] = malloc(size_a * sizeof(double));
    }
    fill_matrix(A, size_a, option, 'A', file1);
    free(file1);
    file1=NULL;


    read_matrix_dimensions(&size_b, 'B', &option, file2);
    double **B=malloc(size_b*sizeof(double*));
    for(int i=0; i<size_b; i++){
       B[i] = malloc(size_b*sizeof(double));
    }
    fill_matrix(B, size_b, option, 'B', file2);
    free(file2);
    file2=NULL;

    // Do the Decomposition
    cholesky_decomposition(A, size_a, B, size_b);

    // Free allocated space
    for(int i=0; i<size_a; i++){
       free(A[i]);
    }
    free(A);
    for(int i=0; i<size_b; i++){
        free(B[i]);
    }
    free(B);

    return 0;
}



