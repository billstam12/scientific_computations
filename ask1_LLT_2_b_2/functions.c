#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "readmatrix.h"

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

    printf("\tOPTIONS:\n");
    printf("\t1.Read matrix from user\n");
    printf("\t2.Create random matrix\n");
    printf("\t3.Read matrix from file\n");
    printf("\tSelect one of the above\n>");
    scanf("%d", option);

    if(*option==1 || *option==2){
        printf("Give dimensions of matrix %c:\n",c);
        printf("\tn:");
        scanf("%d", n);

        printf("%c[%d][%d]\n%d\n", c, *n, *n, *option);

   }else if(*option==3){
        printf("Enter the path of the file to read the matrix: ");
        scanf("%s", filename);
        read_file_matrix_dims(n, filename);
        //printf("E3WTERIKO %d %d --> %s\n",*n,*m,filename);
   }

}

void pei_matrix(double **ar, int n){

    for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
	    if(i==j)
		ar[i][j] = n;
	    else
		ar[i][j] = 1;
	}
    }

}

//*******   *******
double get_determinant(double **arr, int n, int dim){

    double det = 0;
    if(dim==1)
	return arr[0][0];

    double **temp = malloc(n*sizeof(double*));
    for(int i=0; i<n; i++){
	temp[i] = malloc(n*sizeof(double));
    }
    double sign=1;
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

void get_cofactor(double **arr, int n, double **temp, int r, int c, int dim){

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

void get_adjoint(double **arr, int n, double **adj){

    if(n==1){
	adj[0][0] = 1;
	return;
    }

    int sign=1;
    double **temp = malloc(n*sizeof(double*));
    for(int i=0; i<n; i++)
	temp[i]=malloc(n*sizeof(double));

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

    for(int i=0; i<n; i++)
        free(temp[i]);
    free(temp);

//    for(int i=0; i<n; i++){
//	for(int j=0; j<n; j++){
//	    printf("%.2lf ", adj[i][j]);
//	}
//	printf("\n");
//    }
}

int get_inverse(double **arr, int n, double **inverted){

    double det = get_determinant(arr, n, n);
    if(det == (double)0){
	printf("Cant find its inverse, det = 0\n");
	return -1;
    }

    double **adjoint = malloc(n*sizeof(double*));
    for(int i=0; i<n; i++)
	adjoint[i]=malloc(n*sizeof(double));
    get_adjoint(arr, n, adjoint);
    for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
	    inverted[i][j] = adjoint[i][j]/det;
	}
    }

    for(int i=0; i<n; i++)
	free(adjoint[i]);
    free(adjoint);

    return -1;
}

void multiply_matrixes(double **A, double **B, int n, double **AXB){

    double sum = 0;
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
            printf("%.2lf ", AXB[i][j]);
        }
        printf("\n");
    }
}
