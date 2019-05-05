
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void read_user_input(double **arr, int n, int m, char c){

    if(c=='A')  m=n;
    else  m=1;

    printf("\nGive matrix %c values :\n\n", c);
    int ii, jj; // Keep non-zero positions
    ii = 0;
    jj = 3;
    int i, j;
    for( i = 0; i < n; i++){
        for( j = ii ; j < ii + jj; j++){
            printf("%c[%d][%d]: ", c, i, j);
            scanf("%lf", &arr[i][j]);
            //arr[i][j] = 1;
        }
        for(j = ii + jj; j < n; j++){
            arr[i][j] = 0;
        }
        if(jj < 5){
            jj++;
        }
        else{     
            if(ii+jj > n){
                jj -- ;
            }
            else{
                j=5;
            }
            ii++;
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

    int ii, jj; // Keep non-zero positions
    ii = 0;
    jj = 3;
    int i, j;
    for( i = 0; i < n; i++){
        for( j = ii ; j < ii + jj; j++){
            arr[i][j] = (double)((rand()%(upper-lower+1))+lower);

        }
        for(j = ii + jj; j < n; j++){
            arr[i][j] = 0;
        }
        if(jj < 5){
            jj++;
        }
        else{     
            if(ii+jj > n){
                jj -- ;
            }
            else{
                j=5;
            }
            ii++;
        }
    }
}


void read_matrix_from_file(double **arr, int n, int m, char c, char *filename){
    FILE *fp;

    char * line = NULL;
    size_t len = 0;
    int lines = 0;
    ssize_t read;

    if( (fp = fopen(filename, "r"))==NULL ){
        printf("Error opening file : %s [1]\n",filename);
        exit(EXIT_FAILURE);
    }
    int digits=0;
    char ch;
    double d;
    int i = 0;

    while((read = getline(&line, &len, fp)) !=  -1 ){
        int j = 0;
        line = strtok(line,"\t");
        arr[i][j] = atof(line);
        while((line = strtok(NULL,"\t")) != NULL){       
            arr[i][j] = atof(line);
            j++;
        }
        i++;
    }
    fclose(fp);
}



