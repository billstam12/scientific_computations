/* 
  Vasileios Stamatopoulos 
  1115201400188
*/
#include <stdio.h>
#include <stdlib.h>
#include "cholesky_decomposition.h"
#include <math.h>
#include "functions.h"

void cholesky_decomposition(double **A, int size_a, double **B, int size_b){

    // Initialize L with size_a*size_a
    double **L = malloc(size_a * sizeof(double*));
    for(int i = 0; i < size_a; i++){
       L[i] = malloc(size_a * sizeof(double));
    }

    //Make L a zero matrix
    for(int i=0; i<size_a; i++){
       for(int j=0; j<size_a; j++){
           L[i][j] = 0;
       }
    }

    for(int i = 0; i < size_a; i++){
        for(int j = 0; j <= i; j++){
           double sum = 0;
           if(i == j){
              for(int k = 0; k < j; k++){
                  sum += pow(L[j][k], 2.0);
              }
              L[j][j] = sqrt(A[j][j]-sum);
           }
           else{
              for(int k = 0; k < j; k++){
                    sum += (L[i][k] * L[j][k]);
              }
              L[i][j] = (A[i][j] - sum)/L[j][j];
           }
       }
    }

    // Print out Matrix
    printf("Matrix L:\n");
    print_matrix(L, size_a);
    
   
    // Now allocate the transpose of L and create it
    double **L_transpose = transpose_matrix(L, size_a);
    
    printf("\nL Transpose:\n");
    print_matrix(L_transpose, size_a);

    //Forward Substitution
    double* Z = (double*)malloc(size_a*sizeof(double));
    Z = forward_subs(L, B, size_a);
    

    printf("\n(Forward Substitution) Z:\n");
    for(int i=0; i < size_a; i++){
        printf("%.2lf ", Z[i]);
    }
    printf("\n");

    //Backward Substitution
    double* X = (double*)malloc(size_a*sizeof(double));
    X = backward_subs(L_transpose, B, size_a);
        
    printf("\n(Backward Substitution) X:\n");
    for(int i = 0; i < size_a; i++){
        printf("%.2lf ", X[i]);
    }
    printf("\n");

    // Free space
    for(int i = 0; i < size_a; i++){
       free(L[i]);
       free(L_transpose[i]);
    }
    free(L);
    free(L_transpose);
}
