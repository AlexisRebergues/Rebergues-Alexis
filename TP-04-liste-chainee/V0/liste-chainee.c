#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>
 
#define TODO NULL;
 
// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
   return l == NULL;
}
 
// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
   Liste l=malloc(sizeof(Cellule));
   if(l!=NULL){
       l->val=v;
       l->suiv=NULL;
      
   }
  
   return l;
}
 
// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
 
   Liste l2=malloc(sizeof(Cellule));
   l2->val=v;
   l2->suiv=l;
   return l2;
}
 
 
void afficheElement(Element e) {
   printf("%i ",e);
}
 
// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
   Liste l2=malloc(sizeof(Cellule));
   l2=l;
   while (l2->suiv!=NULL)
   {
       printf("%i",l2->val);
       l2=l2->suiv;
      
   }
   printf("%i",l2->val);
}
 
// version recursive
void afficheListe_r(Liste l) {
   printf("%i",l->val);
   while (l->suiv!=NULL)
   {
      
       afficheListe_r(l->suiv);
   }
}
 
void detruireElement(Element e) {
   free(&e);
 
}
 
// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
   Liste l2=malloc(sizeof(Cellule));
   l2=l;
   while (l->suiv!=NULL){
       detruireElement(l->val);
       l2=l->suiv;
 
 
   }
   detruireElement(l2->val);
}
 
// version récursive
void detruire_r(Liste l) {
   detruireElement(l->val);
   while (l->suiv != NULL)
   {
       detruire_r(l->suiv);
 
   }
}
 
 
// retourne la liste dans laquelle l'élément v a été ajouté en fin
<<<<<<< HEAD
// version itérative 
Liste ajoutFin_i(Element v, Liste l) {
   Liste l_suiv= l->suiv;
   while(l_suiv->suiv != NULL){
      l_suiv=l_suiv->suiv;
   }
   l_suiv->suiv=creer(v);
   return l;

   }

 
// version recursive 
Liste ajoutFin_r(Element v, Liste l) {
   if (l->suiv==NULL){
            l->suiv=creer(v);
            return l;
   }
   else{  
      ajoutFin_r(v,l->suiv);
   }
   return l;
  
=======
// version itérative JE NE SAIS PAS
Liste ajoutFin_i(Element v, Liste l) {
   Liste v2 = malloc(sizeof(Liste));

   while (l->suiv!=NULL){
      l=l->suiv;
   }
   l->suiv=v;

   }
}
 
// version recursive JE NE SAIS PAS
Liste ajoutFin_r(Element v, Liste l) {
   if (l->suiv=NULL){
            l->suiv=v;
   }
>>>>>>> d18021bff701250db7dec28b106590f6159f58fc


}
 
// compare deux elements
bool equalsElement(Element e1, Element e2){
   return e1 == e2;
}
 
// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
<<<<<<< HEAD
   while (l->suiv != NULL) {
=======
   while (l->suiv!=NULL) {
>>>>>>> d18021bff701250db7dec28b106590f6159f58fc
      if (l->val==v){
         return l;
      }
      l=l->suiv;
         
      }
   return NULL;

   }

   
<<<<<<< HEAD

=======
}
>>>>>>> d18021bff701250db7dec28b106590f6159f58fc
 
// version récursive
Liste cherche_r(Element v,Liste l) {
   if (l->val==v)
   {
      return l;
   }
   if (l->suiv==NULL){
      return NULL;
   }
<<<<<<< HEAD
   return cherche_r(v,l->suiv);
=======
   return cherche_r(v,l.suiv);
>>>>>>> d18021bff701250db7dec28b106590f6159f58fc
   
}
 
// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative JE NE SAIS PAS
Liste retirePremier_i(Element v, Liste l) {
   Liste l2=malloc(sizeof(Liste));
   l2=cherche_i(v,l);
   if (l2==NULL){
      return l;
   }
   l2->val=(l2->suiv)->val;
   l2->suiv=(l2->suiv)->suiv;
   int i =0;
   Liste l3= malloc(sizeof(Liste));
   
}
 
 
// version recursive JE NE SAIS PAS
Liste retirePremier_r(Element v, Liste l) {
   return TODO;
}
 
 //je ne sais pas non plus
void afficheEnvers_r(Liste l) {
   
}
 
