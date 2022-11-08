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
    
     int* matriceligne=(int *)malloc((m3->nombreligne)*sizeof(int));
     int ** matricecolonne=(int**)calloc(m3->nombreligne,sizeof(matriceligne));
    for (int i=0;i<m3->nombrecolonne;i++){
        

         
        
        for (int j=0;j<m3->nombreligne;j++){
                int somme=0;
          
            for(int i2=0;i2<matrice1.nombrecolonne;i2++){
                    somme=somme+(matrice1.val)[j][i2]*(matrice2.val)[i2][i];


                }
                matriceligne[j]=somme;
                printf("%i",matriceligne[j]);
            }
            matricecolonne[i]=matriceligne;
         
          
           
            
        }
      
     
        m3->val=matricecolonne;
            
 
   
                

            
        return m3;
    }


    void printmatrice (Matrice* matrice){
        for(int i=0;i<matrice->nombreligne;i++){
            for (int j=0;j<matrice->nombreligne;j++){
                printf("%i",(matrice->val)[i][j]);
            }
        }
    }



int main(void)
{
    Matrice matrice1;
    Matrice matrice2;
    matrice1.nombrecolonne=2;
    matrice1.nombreligne=2;
    matrice2.nombrecolonne=2;
    matrice2.nombreligne=2;
    int** valeurmatrice= malloc(2*(sizeof(int)));
    int* ligne1=malloc(2*sizeof(int));
    int* ligne2=malloc(2*sizeof(int));
    for (int i=0;i<2;i++){
        ligne1[i]=2;

    }
     for (int i=0;i<2;i++){
        ligne2[i]=2;

    }
        valeurmatrice[0]=ligne1;
        valeurmatrice[1]=ligne2;
        matrice1.val=valeurmatrice;
        matrice2.val=valeurmatrice;
    Matrice* matrice3= (Matrice*)malloc(sizeof(Matrice));
    matrice3=multipliermatrice(matrice1,matrice2);
    printmatrice(matrice3);
    printmatrice(&matrice1);
    printmatrice(&matrice2);
    free(matrice3);
    free(ligne1);
    free(valeurmatrice);
    free(ligne2);


    }


    




    

