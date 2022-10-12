
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 5




void matrix_mult(int64_t mRES[SIZE][SIZE]  , int64_t m1[SIZE][SIZE] , int64_t m2[SIZE][SIZE]){
    int i,j,j;
    for (int i=0;i<=4;i++){
        for (int j=0;j<=4;j++){
            int somme=0;
            for (int k=0;k<=4;k++){
                somme=somme+ m1[i][k]*m2[k][j];
            }
            mRES[i][j]=somme;
        }
    }
    
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