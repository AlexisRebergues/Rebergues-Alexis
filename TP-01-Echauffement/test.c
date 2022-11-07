#include <stdio.h>
#include <stdlib.h>

typedef struct Matrice
{
    int nombreligne;
    int nombrecolonne;
    int** val;

}Matrice;

Matrice* multipliermatrice(Matrice matrice1, Matrice matrice2){
    Matrice* m3=malloc(sizeof(Matrice));
    

    m3->nombrecolonne=matrice2.nombrecolonne;
    m3->nombreligne=matrice1.nombreligne;
    int ** matricecolonne=malloc(m3->nombrecolonne);
    for (int i=0;i<m3->nombrecolonne;i++){
         int* matriceligne=malloc(m3->nombreligne);
         
        
        for (int j=0;j<m3->nombreligne;j++){
            int somme=0;
            for(int i2=0;i2<matrice1.nombrecolonne;i2++){
                    somme=somme+(matrice1.val)[j][i2]*(matrice2.val)[i2][i];


                }
                matriceligne[i]=somme;
            }
            matricecolonne[i]=matriceligne;
            free(matriceligne);
           
            
        }
        m3->val=matricecolonne;
        return m3;
    }



int main(void)
{

    




    }

