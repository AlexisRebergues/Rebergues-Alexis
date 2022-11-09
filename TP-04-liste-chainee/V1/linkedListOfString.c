
#include "linkedList.h"
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

	ajoutFin_r("r",l);
	afficheListe_i(l);

	ajoutFin_r("c",l);
	afficheListe_i(l);

	p = cherche_i("d",l);
	printf("cherche_i(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i("f",l);
	if(estVide(p))
		printf("cherche_i(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r("c",l);
	printf("cherche_r(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r("c",l);
	if(estVide(p))
		printf("cherche_r(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(b)   : ");
	l = retirePremier_i("b",l);
	afficheListe_r(l);

	printf("retirePremier_i(c)   : ");
	l = retirePremier_i("c",l);
	afficheListe_r(l);

	printf("retirePremier_i(e) : ");
	l = retirePremier_i("e",l);
	afficheListe_r(l);

	printf("retirePremier_r(h)   : ");
	l = retirePremier_r("h",l);
	afficheListe_r(l);

	printf("retirePremier_r(i)   : ");
	l = retirePremier_r("i",l);
	afficheListe_r(l);

	printf("retirePremier_r(j)  : ");
	l = retirePremier_r("j",l);
	afficheListe_r(l);

	detruire_r(l);

	return EXIT_SUCCESS;
}