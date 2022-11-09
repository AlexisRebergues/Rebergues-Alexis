#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef void* Element;

struct cellule_s {
	Element val;
	struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;

typedef Cellule* Liste;


extern void afficheElement(Element e);
extern bool equalsElement(Element e1, Element e2);
extern void detruireElement(Element e);