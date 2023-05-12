
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "display.h"
#include "main.h"


void print_cara() 
{
	char c = '-';
	int i, count = 40;
	for (i = 0; i < count; i++) {
		putchar(c);
	}
	printf("\n");
}

void print_rest(struct rest*curr)
{
		printf("%s \n\n", curr->nazev);
		printf("ID: %d\t\t", curr->id);
		printf("HODNOCENI: %.1lf/10 \n", curr->avg_znamka);
		printf("ADRESA:\t\t%s \n", curr->adresa);
		printf("KUCHYNE:\t%s \n", curr->kuchyne);
		printf("POPIS:\n%s\n", curr->popis);
		print_cara();
}
void rest_detail_print(rest * curr,hodnoceni*hCurr)
{	
		print_cara();
		print_cara();
		printf("Vybrana restaurace:\n");
		print_cara();
		print_rest(curr);
		int recenze_count = 0;
		printf("\nHODNOCENI RESTAURACE:\n\n");
		for (hCurr = curr->prvni_hodn; hCurr != NULL; hCurr = hCurr->next){
			printf("(%d/10)\n", hCurr->znamka);
			printf("%s \n\n", hCurr->recenze);
			//cara();
			recenze_count++;
		}
		if (recenze_count == 0){
			printf("\nRestaurace zatím nemá žádné hodnocení\n\n");
		}
}