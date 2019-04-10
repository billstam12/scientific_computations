#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void read_user_input(double **arr, int n, int m, char c){

    if(c=='A')  m=n;
    else  m=1;

    printf("\nGive matrix %c values :\n\n", c);
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    	    printf("%c[%d][%d]: ", c, i, j);
    	    scanf("%lf", &arr[i][j]);
    	}
    }

}

void create_random(double **arr, int n, int m, char c){

    int lower, upper;
    srand(time(NULL));
    printf("Range Lower bound: ");
    scanf("%d",&lower);
    printf("Range Upper bound: ");
    scanf("%d",&upper);
    printf("\nGenerating random values for matrix %c:\n\n", c);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = (double)((rand()%(upper-lower+1))+lower);
        }
    }
}

void read_file_matrix_dims(int *n, char *filename){
    char ch;
    int mflag=0;
    FILE *fp;
    *n=0;
    if((fp = fopen(filename, "r"))==NULL ){
        printf("Error opening file : %s [0]\n", filename);
        exit(EXIT_FAILURE);
    }
    while((ch=fgetc(fp)) != EOF){
        if(ch=='\n'){
            (*n)++;
	    mflag=1;
        }
    }
    fclose(fp);
    printf("Read n->%d dimensions\n", *n);
}

void read_matrix_from_file(double **arr, int n, int m, char c, char *filename){
    FILE *fp;
    if( (fp = fopen(filename, "r"))==NULL ){
    	printf("Error opening file : %s [1]\n",filename);
    	exit(EXIT_FAILURE);
    }
    int digits=0;
    char ch;
    double d;
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
        	fscanf(fp,"%lf", &d);
    	    arr[i][j] = d;
    	}
    }
    fclose(fp);
}




