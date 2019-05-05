#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include <fcntl.h>
#include "functions.h"
#include "esor.h"

/* relaxation factor must be 0 < omega < 2 */
/* set to greater than 1 for speeding up convergency of a 
   slow-converging process, while values less than 1 are used to help 
   establish convergence of a diverging iterative process or speed up 
   convergence of an overshooting process */
#define taf 0.1
#define omega 1.25
#define MAX_NUM 100000
#define MIN_NUM 0.01

int check_convergence(double* A, double* B, int n){
	int i;
	int count = 0;
	for(i = 0; i < n; i ++){
		if(abs(A[i]-B[i]) <= 0.000005){
			count += 1;
		}	
	}
	if(count == n){
		return 1;
	}
	return 0;
}

void esor(double** A, double* b, int n){
	int i;
	// Initialize X
	double * X = (double*)malloc(sizeof(double)*n);
	for(i = 0; i < n; i++){
		X[i] = 1.0;
	}

	double * current_error = (double*)malloc(sizeof(double)*n);
	double * new_error = (double*)malloc(sizeof(double)*n);
	for(i = 0; i < n; i++){
		current_error[i] = 0;
		new_error[i] = 0;
	}
	while(1){
		for(i = 0; i < n; i++){
			current_error[i] = new_error[i];
		}

		X = solveSystem(A, b, n, X, &new_error);
		
		
		// Check for convergence
		if(check_convergence(current_error, new_error, n)){
			break;
		}

	}
	//Print solution
	printf("\nSolution of the system is:\n");
	print_matrix_1d(X, n);

	//Print error mean
	double sum = 0.0;
	for(i = 0; i < n; i++){
		sum += new_error[i];
	}
	printf("\nError was: %f\n", sum/n);


}

double count_s1(double** A, double* X_new, int n, int i){
	int j;
	double sum = 0;
	for(j = 1; j < i - 1; j++){
		sum += (A[i][j]*X_new[j]);
	}
	return sum;
}

double count_s2(double** A, double* X_new, int n, int i){
	int j;
	double sum = 0;
	for(j = i; j < n; j++){
		sum += (A[i][j]*X_new[j]);
	}
	return sum;
}

double* solveSystem(double **A, double *b, int n, double* X, double** current_error) {
	// New X
	double * X_new = (double*)malloc(sizeof(double)*n);

	// Naive solution
	int i,j;
	for(i = 0; i < n; i++){
		X_new[i] = (1-taf)*X[i] + omega*count_s1(A, X_new, n, i) + (taf - omega)*count_s1(A, X, n, i) + taf*count_s2(A, X, n, i) + taf* b[i]; 
	}

	//Calculate error
	int m;
	for (m = 0; m < n; m++) {
		(*current_error)[m] = fabs( ( ( X_new[m] - X[m] )  / (X_new[m]) )  * 100 );
	}

	return X_new;	
}