#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void read_user_input(double **arr, int n, int m, char c){

    if(c=='A'){
	m=n;
    }else{
	m=1;
    }

    printf("\nGive values of matrix %c:\n\n", c);
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
/*    printf("Range Lower bound: ");
    scanf("%d",&lower);
    printf("Range Upper bound: ");
    scanf("%d",&upper);*/
    printf("\nGenerating random values of matrix %c:\n\n", c);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
	    if(i==j)
            	arr[i][j] = (double)(rand()+1);
	    else
		arr[i][j] = (double)rand();
        }
    }
}

void read_file_matrix_dims(int *n, char *filename){

    char ch;
    int mflag=0;
    FILE *fp;
    *n=0;
    if( (fp = fopen(filename, "r"))==NULL ){
        printf("Error opening file : %s [0]\n", filename);
        exit(EXIT_FAILURE);
    }
    while( (ch=fgetc(fp)) != EOF){
        /*if(ch=='\t'){
	    if(mflag==0)
            	(*m)++;
        }*/if(ch=='\n'){
            (*n)++;
	    mflag=1;
        }
    }
    fclose(fp);
    printf("READ MATRIX FILE DIMENSIONS n->%d\n", *n);
}

void read_matrix_from_file(double **arr, int n, int m, char c, char *filename){
//printf("ESWTERIKO: %s\t",filename);

    FILE *fp;
    if( (fp = fopen(filename, "r"))==NULL ){
	printf("Error opening file : %s [1]\n",filename);
	exit(EXIT_FAILURE);
    }
	//printf("!!!!!!!!!!! %d %d\n",n,m);
    int digits=0;
    char ch;
    double d;
    for(int i=0; i<n; i++){
	for(int j=0; j<m; j++){
    	    fscanf(fp,"%lf", &d);
	    arr[i][j] = d;
		//printf("%.2lf ", d);
	}
	//puts("\n");
    }
    fclose(fp);
}




