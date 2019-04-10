#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "cholesky_decomposition.h"

int main(void){

    //Select method of solving
    //int selected = read_method();
    //if(selected == 1){
    //	printf("LU Decomposition\n");
    //}else if(selected == 2){
        printf("Cholesky LL^T Decomposition\n");
    //}

    //Select method of reading matrices
    int na, nb;
    int flag=0, option;

    char *filename1=malloc(100*sizeof(char));
    //read_matrix_dimensions(&na, 'A', &option, filename1);
    printf("Give matrix dimension:\n>");
    scanf("%d", &na);
    printf("\n");
    double **A=malloc(na*sizeof(double*));
    for(int i=0; i<na; i++){
	A[i] = malloc(na*sizeof(double));
    }
	//printf("MAIN: %s\n",filename1);
    //fill_matrix(A, na, option, 'A', filename1);
    pei_matrix(A, na);

    free(filename1);
    filename1=NULL;

    cholesky_decomposition(A, na);

    for(int i=0; i<na; i++)
	free(A[i]);
    free(A);

    return 0;
}

