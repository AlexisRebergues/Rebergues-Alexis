#pragma once

#include <stdbool.h>
#include "linkedList.h"


typedef struct
{
    char* name ;
    char* artiste;
    char* album ;
    char* genre ;
    int number;
    int tracknumber;
    int year;
}Music;

void afficheElement(Element e);
bool equalsElement(Element e1, Element e2);
void detruireElement(Element e);