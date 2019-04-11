#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


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
