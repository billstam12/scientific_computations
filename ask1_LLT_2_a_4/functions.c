/* 
  Vasileios Stamatopoulos 
  1115201400188
*/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "readmatrix.h"

void print_matrix(double ** L, int size_a){
    for(int i=0; i<size_a; i++){
        for(int j=0; j<size_a; j++){
            printf("%.2lf ",L[i][j]);
        }
    printf("\n");
    }
}

double ** transpose_matrix(double ** L, int size_a){
    double **L_transpose = malloc(size_a * sizeof(double*));
    for(int i = 0; i < size_a; i++){
       L_transpose[i] = malloc(size_a*sizeof(double));
    }
    for(int i = 0; i < size_a; i++){
        for(int j = 0; j < size_a; j++){
            L_transpose[j][i] = L[i][j];
        }
    }
    return L_transpose;
}

double * forward_subs(double** L, double ** B, int size_a){
    double* Z = (double*)malloc(size_a*sizeof(double));
    Z[0] = B[0][0] / L[0][0];
    for(int i = 1; i < size_a; i++){
        double s=0;
        for(int j = 0; j < i; j++){
            s += L[i][j] * Z[j];
        }
        Z[i] = (B[i][0] - s)/L[i][i];
    }
    return Z;
}

double * backward_subs(double** L_transpose, double ** B, int size_a){
    double* X = (double*)malloc(size_a*sizeof(double));
    X[size_a-1] = B[size_a-1][0] / L_transpose[size_a-1][size_a-1];
    for(int i = size_a-2; i >= 0; i--){
        double s=0;
        for(int j = size_a-1; j > i; j--){
            s += L_transpose[i][j] * X[j];
        }
        X[i] = (B[i][0] - s)/ L_transpose[i][i];
    }
    return X;
}

int read_method(){
    int selected=0;
    printf("\t1. LU Decomposition\n");
    printf("\t2. Cholesky LL^T Decomposition\n\n");

    printf("Select method:\n>");
    scanf("%d", &selected);
    int flag=0;
    if(selected!=0 && (selected==1 || selected==2)){
        flag=1;
    }
    while(flag==0){
        printf("\nSelect method:\n>");
        scanf("%d", &selected);
        if(selected==1 || selected==2){
            flag=1;
        }
    }
    return selected;
}

void read_matrix_dimensions(int *n, char c, int *option, char *filename){

    printf("\nMATRIX %c:\n",c);

    printf("\tChoose an option:\n");
    printf("\t1.Give my own matrix\n");
    printf("\t2.Create a random matrix\n");
    printf("\t3.Give matrix from file\n");
    scanf("%d", option);

    if(((*option)==1) || ((*option)==2)){
        printf("PLease give matrix dimensions %c:\n",c);
        printf("\tn:");
        scanf("%d", n);

        printf("%c[%d][%d]\n%d\n", c, *n, *n, *option);

   }
   else if((*option)==3){
        printf("Give filepath: ");
        scanf("%s", filename);
        read_file_matrix_dims(n, filename);
   }

}

void fill_matrix(double **arr, int n, int option, char c, char *filename){


    switch(option){
    case 1:
        if(c=='A')
            read_user_input(arr, n, n, c);
        else
            read_user_input(arr, n, 1, c);
        break;
    case 2:
        if(c=='A')
            create_random(arr, n, n, c);
        else
            create_random(arr, n, 1, c);
                break;
    case 3:
        if(c=='A')
            read_matrix_from_file(arr, n, n, c, filename);
        else
            read_matrix_from_file(arr, n, 1, c, filename);
                break;
    default:
        if(c=='A')
            read_user_input(arr, n, n, c);
        else
            read_user_input(arr, n, 1, c);
                break;
    }
}

