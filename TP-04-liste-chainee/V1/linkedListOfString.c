
#include "linkedList.c"
#include <stdio.h>
#include <stdio.h>

int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete("a",l);
	l = ajoutTete("b",l);
	l = ajoutTete("c",l);
	l = ajoutTete("d",l);
	l = ajoutTete("e",l);
	l = ajoutTete("f",l);
	l = ajoutTete("g",l);
	l = ajoutTete("h",l);
	l = ajoutTete("i",l);

	afficheListe_i(l);

	// ajoutFin_r(99,l);
	// afficheListe_i(l);

	// ajoutFin_r(100,l);
	// afficheListe_i(l);

	// p = cherche_i(200,l);
	// printf("cherche_i(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	// p = cherche_i(99,l);
	// if(estVide(p))
	// 	printf("cherche_i(99) : [ERREUR] pas trouve \n");
	// else {
	// 	printf("cherche_i(99) : trouve ");
	// 	afficheElement(p->val);
	// 	printf("\n");
	// }

	// p = cherche_r(200,l);
	// printf("cherche_r(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	// p = cherche_r(99,l);
	// if(estVide(p))
	// 	printf("cherche_r(99) : [ERREUR] pas trouve \n");
	// else {
	// 	printf("cherche_r(99) : trouve ");
	// 	afficheElement(p->val);
	// 	printf("\n");
	// }

	// printf("retirePremier_i(1)   : ");
	// l = retirePremier_i(1,l);
	// afficheListe_r(l);

	// printf("retirePremier_i(1)   : ");
	// l = retirePremier_i(1,l);
	// afficheListe_r(l);

	// printf("retirePremier_i(100) : ");
	// l = retirePremier_i(100,l);
	// afficheListe_r(l);

	// printf("retirePremier_r(4)   : ");
	// l = retirePremier_r(4,l);
	// afficheListe_r(l);

	// printf("retirePremier_r(4)   : ");
	// l = retirePremier_r(4,l);
	// afficheListe_r(l);

	// printf("retirePremier_r(99)  : ");
	// l = retirePremier_r(99,l);
	// afficheListe_r(l);

	detruire_r(l);

	return EXIT_SUCCESS;
}