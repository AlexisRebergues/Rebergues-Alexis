#include <stdio.h>
#include <stdlib.h>
#include "linkedListOfMusic.h"
#include <string.h>



int main(void){
  Music music;
  music.album="jiodfjdsoi";
  music.artiste="ifdsjfiodf";
  music.genre="jdfsif";
  music.name="jfdsj";
  music.number=2;
  music.tracknumber=3;
  music.year=2022;

  Music music2;
  music2.album="jiodfjdsoi";
  music2.artiste="ifdsjfiodf";
  music2.genre="jdfsif";
  music2.name="jfdsjf";
  music2.number=2;
  music2.tracknumber=3;
  music2.year=2022;

  afficheElement(&music);
  bool egal=equalsElement(&music2,&music);
  printf("%d",egal);
    // char filename[]="music.csv";
    // FILE* f;
    // f=fopen(filename,"r");
  
    // printf("%s",ligne1);
    // //traiter le contenu du fichier ici

    // fclose(f);


    return EXIT_SUCCESS;
}

