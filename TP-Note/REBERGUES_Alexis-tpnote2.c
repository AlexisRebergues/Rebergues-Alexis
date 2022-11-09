#include <stdlib.h>
#include <stdio.h>
#define CHUNK_SIZE_MAX 5

typedef struct String
{
    struct String* next;
    int chunkSize;
    char chunk[CHUNK_SIZE_MAX];
}String;

String* string_new(void){
    String* hello= malloc(sizeof(String*)+sizeof(int)+CHUNK_SIZE_MAX*sizeof(char));
    hello->chunkSize=5;
    (hello->chunk)[0]="H";
    (hello->chunk)[1]="E";
    (hello->chunk)[2]="L";
    (hello->chunk)[3]="L";
    (hello->chunk)[4]="O";
    String* hellonext=malloc(sizeof(String*)+sizeof(int)+CHUNK_SIZE_MAX*sizeof(char));
    (hellonext)->next=NULL;
    hellonext->chunkSize=2;
    hellonext->chunk[0]=" " ;
    hellonext->chunk[1]="!";
     hellonext->chunk[2]=NULL;
      hellonext->chunk[3]=NULL;
       hellonext->chunk[4]=NULL;
    hello->next=hellonext;
    return hello;}



void afficherstring(String* h){
    while(!((h)==NULL)){
        for( int i=0;i<CHUNK_SIZE_MAX;i++){
            printf("%s",(h->chunk)[i]);
        }
        afficherstring(h->next);
    }
}

int main(void){
    String* s=string_new();
    afficherstring(s);

// segmentation fault . Je ne sais pas pourquoi, peut être que la taille de mon malloc n'est pas suffisante, ce qui me semble étrange. 



    return EXIT_SUCCESS;
}




