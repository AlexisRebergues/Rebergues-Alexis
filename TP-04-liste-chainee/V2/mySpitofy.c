#include <stdio.h>
#include <stdlib.h>
#include "linkedListOfMusic.h"
#include <string.h>
#include <errno.h>



int main(void){
  // Music music;
  // music.album="jiodfjdsoi";
  // music.artiste="ifdsjfiodf";
  // music.genre="jdfsif";
  // music.name="jfdsj";
  // music.number=2;
  // music.tracknumber=3;
  // music.year=2022;

  // Music music2;
  // music2.album="jiodfjdsoi";
  // music2.artiste="ifdsjfiodf";
  // music2.genre="jdfsif";
  // music2.name="jfdsjf";
  // music2.number=2;
  // music2.tracknumber=3;
  // music2.year=2022;

  // afficheElement(&music);
  // bool egal=equalsElement(&music2,&music);
  // printf("%d",egal);
    // char filename[]="music.csv";
    // FILE* f;
    // f=fopen(filename,"r");
  
    // printf("%s",ligne1);
    // //traiter le contenu du fichier ici

    // fclose(f);
  char fileName[] = "music.csv";
  FILE* f;
  if( (f=fopen(fileName,"r")) == NULL) {
       printf ("Code de l'erreur : %d\n", errno);
      return EXIT_FAILURE; }
      // traiter le contenu du fichier ici
      char buffer[10];
      // while( fgets(buffer,10,f) != NULL ) {
         char* ligne= fgets(buffer,150,f);
         int len = strlen(ligne);
         char d[] = ",";
         char *p = strtok(ligne, d);
         while(p != NULL)
  {
    printf("'%s'\n", p);
    p = strtok(NULL, d);
  }
  printf("\n");

         


        //  printf(" %s",buffer);
        // }
      fclose(f);
      return EXIT_SUCCESS;
}

