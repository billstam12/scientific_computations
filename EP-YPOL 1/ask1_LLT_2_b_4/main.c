/* 
  Vasileios Stamatopoulos 
  1115201400188
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "cholesky_decomposition.h"

int main(void){

    printf("Cholesky LL^T Decomposition\n");

    //Select method of reading matrices
    int size_a, size_b;
    int flag=0, option;

    char *filename1=malloc(100 * sizeof(char));
    printf("Give matrix dimension:\n>");
    scanf("%d", &size_a);
    printf("\n");
    long double **A=malloc(size_a * sizeof(long double*));
    for(int i=0; i < size_a; i++){
       A[i] = malloc(size_a * sizeof(long double));
    }
    
    fill_matrix(A, size_a, option, 'A', filename1);


    free(filename1);
    filename1=NULL;

    cholesky_decomposition(A, size_a);

    for(int i=0; i < size_a; i++){
       free(A[i]);
    }
    free(A);

    return 0;
}



