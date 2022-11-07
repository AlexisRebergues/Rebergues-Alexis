#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void nombreparfait(int n){
	printf("%i",0);
	if (n>=1){
	for (int j=1;j<=n;j++){
		int somme=0;
		for (int i=1;i<j;j++){
			if(j%i==0){
				somme+=i;
			}



		}
		if (somme==j){
			printf("%i",j);
		}

	}

}




bool isEven(int i) { return i%2==0; }

int main (void)
{
	nombreparfait(15);
   for(int i=0;i<11;i++)
	   printf("%i est %s\n",i,isEven(i)? "pair" : "impair");

	return EXIT_SUCCESS;
}