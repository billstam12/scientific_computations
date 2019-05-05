/* 
  Vasileios Stamatopoulos 
  1115201400188
*/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "readmatrix.h"


void pei_matrix(long double **ar, int n){

    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    	    if(i==j)
    		ar[i][j] = n;
    	    else
    		ar[i][j] = 1;
    	}
    }

}

long double factorial(long double num){

    if(num>=1)
       return num*factorial(num-1);
    else
       return 1;
}



void print_matrix(long double ** L, int size_a){
    for(int i=0; i<size_a; i++){
        for(int j=0; j<size_a; j++){
            printf("%.2Lf ",L[i][j]);
        }
    printf("\n");
    }
}

long double ** transpose_matrix(long double ** L, int size_a){
    long double **L_transpose = malloc(size_a * sizeof(long double*));
    for(int i = 0; i < size_a; i++){
       L_transpose[i] = malloc(size_a*sizeof(long double));
    }
    for(int i = 0; i < size_a; i++){
        for(int j = 0; j < size_a; j++){
            L_transpose[j][i] = L[i][j];
        }
    }
    return L_transpose;
}

long double get_determinant(long double **arr, int n, int dim){

    long double det = 0;
    if(dim==1)
    return arr[0][0];

    long double **temp = malloc(n*sizeof(long double*));
    for(int i=0; i<n; i++){
    temp[i] = malloc(n*sizeof(long double));
    }
    long double sign=1;
    for(int i=0; i<dim; i++){
        get_cofactor(arr, n, temp, 0, i, dim);
        det += sign*arr[0][i]*get_determinant(temp, n, dim-1);
        sign = -sign;
    }
    for(int i=0; i<n; i++)
        free(temp[i]);
    free(temp);
    return det;
}

void get_cofactor(long double **arr, int n, long double **temp, int r, int c, int dim){

    int i=0, j=0;
    for(int k=0; k<dim; k++){
        for(int l=0; l<dim; l++){
            if(k!=r && l!=c){
                temp[i][j++] = arr[k][l];
                if(j==(dim-1)){
                    j=0;
                    i++;
                }
            }
        }
    }
}

void get_adjoint(long double **arr, int n, long double **adj){

    if(n==1){
        adj[0][0] = 1;
        return;
    }

    int sign=1;
    long double **temp = malloc(n*sizeof(long double*));
    for(int i=0; i<n; i++){
       temp[i]=malloc(n*sizeof(long double));
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            get_cofactor(arr, n, temp, i, j, n);
            if((i+j)%2==0)
            sign = 1;
            else
            sign = -1;
            adj[j][i] = sign*get_determinant(temp, n, n-1);
        }
    }

    for(int i=0; i<n; i++){
        free(temp[i]);
    }
    free(temp);
}

long double** get_inverse( long double **arr, int n){

    long double **inverted = malloc(n * sizeof( long double*));
    for(int i = 0; i < n; i++){
        inverted[i] = malloc(n*sizeof(long double));
    }
    long double det = get_determinant(arr, n, n);
    if(det == (double)0){
       printf("Cant find its inverse, det = 0\n");
       exit(-1);
    }

    long double **adjoint = malloc(n*sizeof(long double*));
    for(int i=0; i<n; i++){
       adjoint[i]=malloc(n*sizeof(long double));
    }
    get_adjoint(arr, n, adjoint);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            inverted[i][j] = adjoint[i][j]/det;
        }
    }

    for(int i=0; i<n; i++){
       free(adjoint[i]);
    }
    free(adjoint);

    return inverted;
}



void multiply_matrixes(long double **A, long double **B, int n, long double **AXB){

    long double sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                sum += A[i][k]*B[k][j];
            }
            AXB[i][j] = sum;
            sum=0;
        }
    }

    printf("\nA^(-1):\n");
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            printf("%.2Lf ", AXB[i][j]);
        }
        printf("\n");
    }
}
