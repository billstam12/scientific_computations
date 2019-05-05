/* 
  Vasileios Stamatopoulos 
  1115201400188
*/
#include <stdio.h>
#include <stdlib.h>
#include "cholesky_decomposition.h"
#include <math.h>
#include "functions.h"

void cholesky_decomposition(long double **A, int size_a){

    // Initialize L with size_a*size_a
    long double **L = malloc(size_a * sizeof(long double*));
    for(int i = 0; i < size_a; i++){
       L[i] = malloc(size_a * sizeof(long double));
    }

    //Make L a zero matrix
    for(int i=0; i<size_a; i++){
       for(int j=0; j<size_a; j++){
           L[i][j] = 0;
       }
    }

    for(int i = 0; i < size_a; i++){
        for(int j = 0; j <= i; j++){
           long double sum = 0;
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
    long double **L_transpose = transpose_matrix(L, size_a);


    printf("\nL Transpose:\n");
    print_matrix(L_transpose, size_a);


    printf("\nThe determinant of L is : %.2Lf\n", get_determinant(L, size_a, size_a));
    long double **inverseL = get_inverse(L, size_a);
    
    
    printf("\nL Inverse:\n");
    print_matrix(L, size_a);


    printf("\nnThe determinant of L Transpose is: %.2Lf\n", get_determinant(L_transpose, size_a, size_a));
    long double **inverseLT = get_inverse(L, size_a);
    
    printf("\nInverse L Transpose:\n");
    print_matrix(L, size_a);


    long double **AXB = malloc(size_a*sizeof(long double*));
    for(int i=0; i < size_a; i++)
        AXB[i]=malloc(size_a*sizeof(long double));

    multiply_matrixes(inverseLT, inverseL, size_a, AXB);

    //free dysize_amically allocated arrays
    for(int i = 0; i < size_a; i++){
      free(inverseL[i]);
    	free(inverseLT[i]);
      free(AXB[i]);
    }
    free(inverseL);
    free(inverseLT);
    free(AXB);

    for(int i = 0; i < size_a; i++){
    	free(L[i]);
    	free(L_transpose[i]);
    }
    free(L);
    free(L_transpose);
}
