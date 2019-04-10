#include <stdio.h>
#include <stdlib.h>
#include "cholesky_decomposition.h"
#include <math.h>
#include "functions.h"

void cholesky_decomposition(double **A, int na){

    //dynamically allocate matrix L
    //double L[na][na];
    double **L = malloc(na*sizeof(double*));
    for(int i=0; i<na; i++)
	L[i] = malloc(na*sizeof(double));

    //initialize L with zeros
    for(int i=0; i<na; i++){
	for(int j=0; j<na; j++){
	    L[i][j] = 0;
	}
    }

    //Calculate L
    for(int i=0; i<na; i++){
        for(int j=0; j<=i; j++){
	    double sum = 0;
	    if(i==j){
		for(int k=0; k<j; k++)
		    sum += pow(L[j][k], 2.0);
		L[j][j] = sqrt(A[j][j]-sum);
	    }else{
		for(int k=0; k<j; k++)
                    sum += (L[i][k]*L[j][k]);
		L[i][j] = (A[i][j]-sum)/L[j][j];
	    }
	}
    }

    //print matrix L
    printf("L:\n");
    for(int i=0; i<na; i++){
	for(int j=0; j<na; j++){
	    printf("%.2lf ",L[i][j]);
	}
	printf("\n");
    }

    //dynamically allocate matrix L transpose
    double **L_transpose = malloc(na*sizeof(double*));
    for(int i=0; i<na; i++)
	L_transpose[i] = malloc(na*sizeof(double));

    //Calculate L Transpose
    //double L_transpose[na][na];
    for(int i=0; i<na; i++){
        for(int j=0; j<na; j++){
            L_transpose[j][i] = L[i][j];
        }
    }

    printf("\nL TRANSPOSE:\n");
    for(int i=0; i<na; i++){
        for(int j=0; j<na; j++){
            printf("%.2lf ", L_transpose[i][j]);
        }
        printf("\n");
    }

    printf("\nDETERMINANT OF L: %.2lf\n", get_determinant(L,na, na));
    double **inverseL = malloc(na*sizeof(double*));
    for(int i=0; i<na; i++)
	inverseL[i]=malloc(na*sizeof(double));
    get_inverse(L, na, inverseL);
    printf("\nINVERSE L:\n");
    for(int i=0; i<na; i++){
	for(int j=0; j<na; j++){
	    printf("%.2lf ", inverseL[i][j]);
        }
        printf("\n");
    }


    printf("\nDETERMINANT OF L TRANSPOSE: %.2lf\n", get_determinant(L_transpose, na, na));
    double **inverseLT = malloc(na*sizeof(double*));
    for(int i=0; i<na; i++)
        inverseLT[i]=malloc(na*sizeof(double));
    get_inverse(L_transpose, na, inverseLT);
    printf("\nINVERSE L TRANSPOSE:\n");
    for(int i=0; i<na; i++){
        for(int j=0; j<na; j++){
            printf("%.2lf ", inverseLT[i][j]);
        }
        printf("\n");
    }

    double **AXB = malloc(na*sizeof(double*));
    for(int i=0; i<na; i++)
        AXB[i]=malloc(na*sizeof(double));

    multiply_matrixes(inverseLT, inverseL, na, AXB);

    //free dynamically allocated arrays
    for(int i=0; i<na; i++){
	free(inverseL[i]);
	free(inverseLT[i]);
        free(AXB[i]);
    }
    free(inverseL);
    free(inverseLT);
    free(AXB);

    for(int i=0; i<na; i++){
	free(L[i]);
	free(L_transpose[i]);
    }
    free(L);
    free(L_transpose);
}
