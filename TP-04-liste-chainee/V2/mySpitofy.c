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

  // afficheElement(music2);
    
  
   Music listemusique[2800];  
     int i = 0;                         
    Liste liste;                                      
    FILE* f;                                      
    char ligne[200];                               
    char* ligneextraite;                                  
                                     
    f=fopen("music.csv","r");

    printf("%s",fgets(ligne,200,f));               

    while (fgets(ligne,200,f) != NULL) {
        ligneextraite = strdup(ligne);
       listemusique[i].name = strsep(&ligneextraite,",");
        listemusique[i].artiste = strsep(&ligneextraite,",");
        listemusique[i].album = strsep(&ligneextraite,",");
        listemusique[i].genre = strsep(&ligneextraite,",");
        listemusique[i].number = atoi(strsep(&ligneextraite,","));
        listemusique[i].tracknumber = atoi( strsep(&ligneextraite,",") );
        listemusique[i].year = atoi( strsep(&ligneextraite,",") );
        liste = ajoutFin_r(&(listemusique[i]), liste);
        i++;
    }
  
    fclose(f);
    // liste=trierListeParAnnee(liste);
    afficheListe_i(liste); //pour récupérer la liste triée par ordre croissant

   detruire_i(liste);
   free(liste);
    }
