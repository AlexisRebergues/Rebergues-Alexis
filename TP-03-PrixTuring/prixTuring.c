/**
Compilation
gcc --std=c99 -W -Wall -o prixTuring prixTuring.c
Exécution
./prixTuring < turingWinners.txt > out.txt
Tests
diff out.txt turingWinners.txt
Détection de fuites mémoires
valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
   int annee;
   char* nom_gagnant;
   char* sujet;
}gagnant;
/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
   int maxLineSize = 255;
   char c, *line = calloc(maxLineSize+1,sizeof(char));
   scanf("%250[^\n]", line);
   if ( (c = getchar()) != '\n') {
       /* we did not get all the line */
       line[250] = '[';
       line[251] = line[252] = line[253] = '.';
       line[254] = ']';
       // line[255] = '\0'; // useless because already initialized by calloc
       // let's skip all chars untli the end of line
       while (( (c = getchar()) != '\n') && c != EOF) ;
   }
   return line;
}
/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
   int buf;
   scanf("%i\n",&buf);
   return buf;
}
gagnant* Readwinners(int n){
   gagnant* t;
   t=calloc(n,sizeof(gagnant));
   for (int i=0;i<n;i++){
       gagnant a;
       a.annee=scanLineAsInt();
       a.nom_gagnant=scanLine();
       a.sujet=scanLine();
       t[i]=a;
   }
   return t;
}
 
 
void printWinners(gagnant* t,int n){
   for (int i=0;i<n;i++){
       printf("%i \n",t[i].annee);
       printf("%s \n",t[i].nom_gagnant);
       printf("%s \n", t[i].sujet) ;
   }
}
 
 
gagnant infosAnnee(gagnant* t, int annee,int n){
   for (int i=0; i<n; i++){
       if (t[i].annee==annee){
           return t[i];
       }
   }
   gagnant p;
   p.annee=0;
   p.nom_gagnant="Inconnu";
   p.sujet="Inconnu";
 
   return p;
}
 
 
gagnant* triparannee(int n){
   gagnant* t =Readwinners(n);
   gagnant* t2 =calloc(n,sizeof(gagnant));
   for (int i=0;i<n;i++){
       gagnant g;
       int k=t[i].annee;
       for (int j=0;j<n;j++){
           if (t[j].annee<k){
               k=t[j].annee;
           }
 
 
       }
       t2[i]=infosAnnee(t,k,n);
 
 
   }
   return t2;
}
 
 
      
void printgagnant(gagnant t){
   printf("%i\n",t.annee);
   printf("%s\n",t.nom_gagnant);
   printf("%s\n",t.sujet);
}
 
 
/*int main(void)
{
   int nbGagnants = scanLineAsInt();
   //printf("nbGagnants = %i\n",nbGagnants);
   gagnant* t=Readwinners(nbGagnants);
   //printWinners(t,nbGagnants);
   int nbGagnants = scanLineAsInt();
   gagnant* t=Readwinners(nbGagnants);
   gagnant t2=infosAnnee(t,2005,nbGagnants);
   printgagnant(t2);
   for (int i=0;i<nbGagnants;i++){
 
       free(t[i].nom_gagnant);
       free(t[i].sujet);
   }   
   free(t);
 
   gagnant* t3=triparannee(nbGagnants);
   printWinners(t3,nbGagnants);
   for (int i=0;i<nbGagnants;i++){
       free(t3[i].nom_gagnant);
       free(t3[i].sujet);
   }
   free(t3);
 
 
   return EXIT_SUCCESS;
}*/
 
 
int main(int argc, char *argv[]){
   int nbGagnants = scanLineAsInt();
   gagnant* t = Readwinners(nbGagnants);
   if(argc<1){
   
       printWinners(t,nbGagnants);
   }
   else{
       if (argv[1]=="infosAnnee"){
           int i = scanf("%i",&argv[2]);
           gagnant a = infosAnnee(t,i,nbGagnants);
           printgagnant(a);
       }
 
 
   }
 
   //gagnant* t=Readwinners(nbGagnants);
   //gagnant t2=infosAnnee(t,argv[1],nbGagnants);
  
 
}
