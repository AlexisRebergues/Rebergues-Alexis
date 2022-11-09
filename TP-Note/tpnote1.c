#include <stdlib.h>
#include <stdio.h>


int* repeat (int * t1, int* t2){
    int espace=0;
    for(int i=0;i<=sizeof(t1);i++){
        espace=espace+t1[i];
    }
    int* t3 = malloc(espace);
    int j=0;
    int i2=0;
    while (j<sizeof(t1))
    {
        for (int i1=0;i1<=t1[i2];i1++){
            t3[j]=t2[i2];


        }
        i2=i2+1;
        j=j+t1[i2];
    }
    return &t3;


}

void print(int * t){
    for (int i=0;i<sizeof(t);i++){
        if (i==0){
            printf ("%i", t[i]);

        }
        if (i== sizeof(t)-1){
            printf("%i }", t[i] );
        }
        else{
            printf(" %i", t[i] );

        }
        
        
        

    }
}


int main(void)
{
    int* t=malloc(3);
    t[0]=1;
    t[1]=3;
    t[2]=4;
    int* t2=malloc(3);
    t2[0]=0;
    t2[1]=1;
    t2[2]=2;
    int* t3=repeat(t,t2);
    print (t3);
    free(t);
    free(t2);
    free(t3);

	
}
