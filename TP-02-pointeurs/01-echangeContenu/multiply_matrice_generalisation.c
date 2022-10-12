#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 5

typedef struct{
    uint8_t numLines;
    uint8_t numColums;
    int **values;

}Matrix;



void matrix_mult(Matrix res  , Matrix m1 , Matrix m2){
    m1.values[0][0];
}

void matrix_print (int64_t M[SIZE][SIZE]){
    int i,j;
    for (i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            printf("%i",M[i][j]);
        }
    }
}
#include <stdint.h>
#include <stdlib.h>
#define SIZE 5
int main(void) {
//matrices en ligne * colonne
    int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[SIZE][SIZE];
    matrix_mult(matriceResultat,matrice1,matrice2);
    matrix_print(matriceResultat);
    return EXIT_SUCCESS;