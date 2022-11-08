#include <stdio.h>
#include <stdlib.h>
#include "linkedListOfMusic.c"
#include <string.h>


Liste creerlistedesmusiques(int n){
    char filename[]="music.csv";
    FILE* f;
    Liste listedemusique= calloc(n, sizeof(Music));
    f=fopen(filename,"r");
    for (int i=0; i<n; i++){
          char* ligne1=fgets(filename, 500, f);
          Music* t = malloc(sizeof(Music));
          int j=0;
          char* name;
          while(!(ligne1[j]==",")){
            name[j]=ligne1[j];
            j+=1;
          }
          j+=1;
          char* artiste;
          int j2=0;
          while(!(ligne1[j]==",")){
            artiste[j2]=ligne1[j];
            j+=1;
            j2+=1;
    }
          j+=1;
          char* album;
          int j3=0;
          while(!(ligne1[j]==",")){
            album[j3]=ligne1[j];
            j+=1;
            j3+=1;
}
        j+=1;
          char* genre;
          int j7=0;
          while(!(ligne1[j]==",")){
            album[j7]=ligne1[j];
            j+=1;
            j7+=1;
}
        j+=1;
          char* number;
          int j4=0;
          while(!(ligne1[j]==",")){
            number[j4]=ligne1[j];
            j+=1;
            j4+=1;}
          j+=1;
          char* tracknumber;
          int j5=0;
          while(!(ligne1[j]==",")){
            tracknumber[j5]=ligne1[j];
            j+=1;
            j5+=1;}
            j+=1;
          char* year;
          int j6=0;
          while(!(ligne1[j]==NULL)){
            year[j2]=ligne1[j];
            j+=1;
            j6+=1;}

            t->album=album;
            t->artiste=artiste;
            t->genre=genre;
            t->name=name;
            t->number=(int) number;
            t->tracknumber=(int) tracknumber;
            t->year=(int) year;
            listedemusique[i]=t;}}




int main(void){
    char filename[]="music.csv";
    FILE* f;
    f=fopen(filename,"r");
  
    printf("%s",ligne1);
    //traiter le contenu du fichier ici

    fclose(f);


    return EXIT_SUCCESS;
}

