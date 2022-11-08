#include <stdlib.h>
#include <stdio.h>
#include "linkedListOfMusic.h"



#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
        return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
        Liste l = malloc(sizeof(Cellule));
        l->val = v;
        l->suiv=NULL;
        return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
        Liste res= creer(v);
        res->suiv=l;
        return res;
}

void afficheElement(Element e) {
        printf("%s ", e.name);
        printf("%s ", e.artiste);
        printf("%s", e.album);
        printf("%s ", e.genre);
        printf("%i ", e.number);

        printf("%i ", e.tracknumber);
        printf("%i", e.year)  ;      
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
        Liste p = l;
        while(!estVide(p)){
                afficheElement(p->val);
                p = p->suiv;
        }
        printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
        if(estVide(l)){
                printf("\n");
        } else {
                afficheElement(l->val);
                afficheListe_r(l->suiv);
        }
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
        Liste courant,suivant=l;
        while(!estVide(courant)){
                suivant=courant->suiv;

                detruireElement(courant->val);
                free(courant);
                courant=suivant;
        };
}

// version récursive
void detruire_r(Liste l) {
        if(estVide(l)){
        } 
        else {
                detruireElement(l->val);
                detruire_r(l->suiv);
                free(l);
                }

        }

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
        Liste elem=creer(v);
        Liste p=l;
       if (estVide(p)){
               return elem ;
        };
       while(!estVide(p->suiv)){
       p=p->suiv;}
       p->suiv=elem;
       return p;}


// version recursive
Liste ajoutFin_r(Element v, Liste l) {
        if (estVide(l)){
                return creer(v);
        }
        else{
                l->suiv=ajoutFin_r(v,l->suiv);
        }
        return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
        return (strcmp(e1.album,e2.album)==0)&&(strcmp(e1.artiste,e2.artiste)==0)&&(strcmp(e1.genre,e2.genre)==0)&&(strcmp(e1.name,e2.name)==0)&&(e1.number=e2.number)&&(e1.tracknumber==e2.tracknumber)&&(e1.year==e2.year);
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
        while(!estVide(l)){
                if(equalsElement(l->val, v)){
                        return l;
                } else {
                        l = l->suiv;
                }
        }
        return NULL;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
         if ((estVide(l))|| equalsElement(l->val,v)){
                return l;
        }
        else { 
                return cherche_r(v,l->suiv);
        }
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
       Liste p=l;
       if (estVide(p)){return NULL;}
       if (equalsElement((p->val),v)){
        return l->suiv;

       }
       while (!estVide(p->suiv)&& !equalsElement((p->suiv->val), v)){
        p=p->suiv;
       }
       if (equalsElement((p->suiv->val),v)){
        p->suiv=p->suiv->suiv;
       }
       return l;
        

}


// version recursive
Liste retirePremier_r(Element v, Liste l) {

         if (estVide(l)){
                return l;

                
         }
         if (equalsElement(l->val,v)){
                Liste p=l->suiv;
                l->suiv=NULL;
                detruire_r(l);
                return p;
         }
         l->suiv=retirePremier_r(v,l->suiv);
         return l;
 }




void afficheEnvers_r(Liste l) {
        if (!estVide(l)){
                if (!estVide(l->suiv)){
                        afficheEnvers_r(l->suiv);
                }
                afficheElement(l->val);
                printf(" ");
        }
}