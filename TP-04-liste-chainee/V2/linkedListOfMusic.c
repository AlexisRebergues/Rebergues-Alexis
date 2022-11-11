#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedListOfMusic.h"

 void afficheElement(Element e) {
        Music* p=(Music*) e;

        printf("%s, ", p->name);
    
        printf("%s, ", p->artiste);
      
        printf("%s, ", p->album);
   
        printf("%s, ", p->genre);
 
        printf("%i, ", p->number);
  
        printf("%i, ", p->tracknumber);

        printf("%i", p->year)  ;      
}


 void detruireElement(Element e) {}


// compare deux elements
 bool equalsElement(Element e1 , Element e2){
        Music* p=(Music*)e2;
        Music* p2=(Music*)e1;
        return (strcmp(p2->album,p->album)==0)&&(strcmp(p2->artiste,p->artiste)==0)&&(strcmp(p2->genre,p->genre)==0)&&(strcmp(p2->name,p->name)==0)&&(p2->number==p->number)&&(p2->tracknumber==p->tracknumber)&&(p2->year==p->year);
}


Liste trierListeParAnnee(Liste L)
{
      Liste i;
      Liste j;
      Liste min;
      Music* aux;
      i=L;
      while (i->suiv!=NULL)
      {
         min=i; // la valeur de min est initialisée à la valeur de i
          Music* music2=(Music*) min->val; // afin de pouvoir comparer les annees
         j=i->suiv;
         while (j!=NULL) // on va parcourir l'ensemble des valeurs de la liste pour trouver la valeur minimale pour la position fixée
         {
            
              Music* music1= (Music*) j->val;
   
            if (music1->year < music2->year) // on compare comme prévu 
            {
               min=j; 
               music2=(Music*) min->val;}
              j=j->suiv;
                                                       // ici on a donc trouvé la valeur minimale pour la position fixée
            }
            if (min != i) // si la valeur du minimum n'est pas la valeur de l
            {
               aux=(Music*)min->val;
               min->val = i->val;
               music2=(Music*) min->val;
               i->val = aux;  // alors on échange les deux valeurs
            }
          i=i->suiv; // on fait de même pour toutes les positions
      }
      return(L);
      } 
             
 




