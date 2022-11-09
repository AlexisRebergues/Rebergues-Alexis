#include <stdlib.h>
#include <stdio.h>
#include "linkedListOfMusic.h"



#define TODO NULL;





extern void afficheElement(Element e) {
        Music* p=(Music*) e;
        printf("%s ", p->name);
        printf("%s ", p->artiste);
        printf("%s", p->album);
        printf("%s ", p->genre);
        printf("%i ", p->number);
        printf("%i ", p->tracknumber);
        printf("%i", p->year)  ;      
}


extern void detruireElement(Element e) {}



// compare deux elements
extern bool equalsElement(Element e1 , Element e2){
        Music* p=(Music*)e2;
        Music* p2=(Music*)e1;
        return (strcmp(p2->album,p->album)==0)&&(strcmp(p2->artiste,p->artiste)==0)&&(strcmp(p2->genre,p->genre)==0)&&(strcmp(p2->name,p->name)==0)&&(p2->number==p->number)&&(p2->tracknumber==p->tracknumber)&&(p2->year==p->year);
}


