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
      Liste ListeDeMusiques;
      ListeDeMusiques=NULL;
      // traiter le contenu du fichier ici
      char buffer[200];
      while( fgets(buffer,200,f) != NULL ) {
         char* ligne= fgets(buffer,200,f);
         int len = strlen(ligne);
         char d[] = ",";
         char *p = strtok(ligne, d);
        //  printf("%s\n",p);
        
         int j=0;
         Music* music=malloc(sizeof(Music));
         while(p != NULL)
  {
     
    if (j==0){
     
      music->name=p;
      p = strtok(NULL, d);
       j+=1;

    }
    else if (j==1){
      music->artiste=p;
     p = strtok(NULL, d);
       j+=1;


    }
    else if (j==2){
      music->album=p;
     p = strtok(NULL, d);
       j+=1;

   
    }
    else if(j==3){
      music->genre=p;
       p = strtok(NULL, d);
       j+=1;

   
    }
    else if (j==4){
      int a=atoi(p);
      music->number=a;
      p = strtok(NULL, d);
       j+=1;

  
    }
    else if (j==5){
      int a=atoi(p);
      music->tracknumber=a ;
       p = strtok(NULL, d);
       j+=1;

 
    }
    else if (j==6){
      int a=atoi(p);
      music->year=a;
      // afficheElement(music);
       p = strtok(NULL, d);

      j=0;
     ListeDeMusiques=ajoutFin_i(music,ListeDeMusiques);
    }
   
    // printf("'%s'\n", p);
   
    
   ;
   
  }
  trierListeParAnnee(ListeDeMusiques);
  // afficheElement(ListeDeMusiques->suiv->val);
     afficheListe_i(ListeDeMusiques);
 
 
  // printf("\n");
  // free(music);
  }

   free(ListeDeMusiques);
         
  

        //  printf(" %s",buffer);
        // }
      fclose(f);
      return EXIT_SUCCESS;
}


