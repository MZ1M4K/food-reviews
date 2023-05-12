
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serilization.h"
#include "main.h"
#include "display.h"

void save_file(rest*head, rest*curr, hodnoceni*hCurr, hodnoceni*hHead) 
{
	FILE* file = fopen("data.txt", "w");
	if (file == NULL) {
		printf("nenacteny soubor");
		exit(1);
	}
	for (curr = head; curr != NULL; curr = curr->next) {
		fprintf(file, "_%d; ", curr->id);
		fprintf(file, "%s; ", curr->nazev);
		fprintf(file, "%s; ", curr->adresa);
		fprintf(file, "%s; ", curr->kuchyne);
		fprintf(file, "%lf; ", curr->avg_znamka);
		fprintf(file, "%s;", curr->popis);
		for (hCurr = curr->prvni_hodn; hCurr != NULL; hCurr = hCurr->next){
			fprintf(file,"%d,", hCurr->znamka);
			fprintf(file," %s;", hCurr->recenze);
		}
		fprintf(file,"\n");
	}
	fclose(file);
}
void read_file(rest**head, rest*curr, hodnoceni*hCurr, hodnoceni*hHead)
{	
	FILE* file = fopen("data.txt", "r");
	if (file == NULL) 
	{
		printf("Soubor se nepodarilo nacist, chcete vytvorit novy?(y/n)");
		//char volba = 'y';
		if(getchar() == 'y')
		{
			FILE* file = fopen("data.txt", "w");
		}
		else
		{
			exit(1);
		}
		
	}
	else
	{
		rest * pRead = NULL;
		pRead = (rest*)malloc(sizeof(rest));
		while (fscanf(file,"_%d; %[^;]; %[^;]; %[^;]; %lf; %[^;];", &(pRead->id), pRead->nazev, pRead->adresa, pRead->kuchyne, &(pRead->avg_znamka), pRead->popis) == 6 ) 
		{
			rest * pNew;
			pNew = (rest*)malloc(sizeof(rest));
			pNew->id = pRead->id;
			strcpy(pNew->nazev, pRead->nazev);
			strcpy(pNew->adresa, pRead->adresa);
			strcpy(pNew->kuchyne, pRead->kuchyne);
			pNew->avg_znamka = pRead->avg_znamka;
			strcpy(pNew->popis, pRead->popis);
			pNew->next = NULL;
			hodnoceni* pHodRead = NULL;
			pHodRead = (hodnoceni*)malloc(sizeof(hodnoceni));
			while (fscanf(file, "%d, %[^;];", &(pHodRead->znamka), pHodRead->recenze) == 2 ) 
			{

				hodnoceni * pHodNew;
				pHodNew = (hodnoceni*)malloc(sizeof(hodnoceni));
				pHodNew->znamka = pHodRead->znamka;
				strcpy(pHodNew->recenze, pHodRead->recenze);
				if (pNew->prvni_hodn == NULL) 
				{
					pNew->prvni_hodn = pHodNew;
					hHead = pHodNew;
				}
				else 
				{
					hCurr = hHead;
					while (hCurr->next != NULL){
					hCurr = hCurr->next;
					}
					hCurr->next = pHodNew;
				}
				int read_count = 0;
			}
			free(pHodRead);
			if (*head == NULL) 
			{
				*head = pNew;			
			}
			else 
			{
				curr = *head;
				while (curr->next != NULL)
				{
					//*curr = pNew;
					curr = curr->next;
				}
				curr->next = pNew;
			}
		}
		free(pRead);
	}
	
	fclose(file);
}