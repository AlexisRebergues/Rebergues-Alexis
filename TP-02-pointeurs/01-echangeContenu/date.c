#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum  { Janvier=1, Fevrier, Mars, Avril, Mai, Juin, Juillet, Août, Septembre, Octobre, Novembre, Décembre} Mois;

typedef struct 
{
    int jour;
    Mois mois;
    int année; 
} Date;

void * InitialiserDate(Date *d){
    d->jour=1;
    d->mois=1;
    d->année=2022;

}

void afficheDate(Date* d){
    printf()
}

//retourne date initalisée par copie

Date creerDateParCopie(){
    Date d;
    InitialiserDate(&d);
    return d;
}


Date * newDate(){
    Date* d= (Date*)malloc(sizeof(Date));
    InitialiserDate(d);
    return d;


}

int main(void)
{
    Date *pdate;
    pdate=newDate();
    afficheDate(pdate);
    free(pdate);
    pdate=NULL;}

