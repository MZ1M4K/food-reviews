
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#include "display.h"
#include "serialization.h"
#include "edit.h"
#include "sort.h"
#include "main.h"


//Hleda mezeru v ID jednotlivych restauraci, pokud je ID prvni restaurace >1 vraci NULL, jinak vraci posledni restauraci pred volnym ID.
rest* rest_id(rest*head,rest*curr) 
{
	int id = 1;
	curr = head;
    if(curr->id == 1)
    {
        while (curr != NULL)
        {
            if(curr->next == NULL)
            {
                break;
            }
            else if(curr->next->id - curr->id > 1)
            {
                break;
            }
            curr = curr->next;
        }
    }
    else
    {
        curr = NULL;
    }
	return curr;
}

void rest_add(rest**head,rest*curr) 
{
	rest* pAdd;
	pAdd = (rest*)malloc(sizeof(rest));
	fflush(stdin);
	printf("Zadejte nazev podniku:");
	scanf(" %[^\n]s", pAdd->nazev);
	fflush(stdin);
	printf("Zadejte adresu podnuku:");
	scanf(" %[^\n]s", pAdd->adresa);
	fflush(stdin);
	printf("Zadejte kuchyni podniku:");
	scanf(" %[^\n]s", pAdd->kuchyne);
	fflush(stdin);
	printf("Zadejte kratky popis podniku:");
	scanf(" %[^\n]s", pAdd->popis);
	pAdd->avg_znamka = 0;
	pAdd->next = NULL;
	
	if (*head == NULL) //pokud je list prazdy, nova restaurace je prvni
		{
			pAdd->id = 1;
			*head = pAdd;
		}
	else
	{
		curr = rest_id(*head, curr);
		if(curr == NULL) //pridava restauraci na zacatek listu
		{
			pAdd->id = 1;
			pAdd->next = *head;
			*head = pAdd;
			
		}
		else		//pridava restauraci na volne id
		{
			pAdd->id = curr->id + 1;
			pAdd->next = curr->next;
			curr->next = pAdd;
		}	
	}
}
// FUNKCE PRO PRIDANI NOVEHO HODNOCENI VYBRANE RESTAURACE, ZAROVEN I VYPOCITA PRUMERNE HODNOCENI RESTAURACE (avg_znamka)
void rest_hodn_add(rest*head,rest*curr,hodnoceni*hHead,hodnoceni*hCurr) 
{ 
	system("cls");
	hodnoceni * pHodAdd = (hodnoceni*)malloc(sizeof(hodnoceni));
	fflush(stdin);
	printf("Zadejte hodnoceni podniku(0-10):");
	scanf(" %d", &(pHodAdd->znamka));
	if (pHodAdd->znamka > 10){
		pHodAdd->znamka = 10;
	}
	if (pHodAdd->znamka < 0){
		pHodAdd->znamka = 0;
	}
	fflush(stdin);
	printf("Zadejte recenzi podniku:");
	scanf(" %[^\n]", pHodAdd->recenze);
	int znamka_count = 0;
	double znamka_sum = 0;
	if(curr->prvni_hodn==NULL)
        {
            curr->prvni_hodn= pHodAdd;
			curr->avg_znamka=pHodAdd->znamka;
        }
        else
        {
			hCurr=curr->prvni_hodn;
			znamka_count++;
			znamka_sum = znamka_sum + hCurr->znamka;
			while(hCurr->next!=NULL)
			{	
					hCurr=hCurr->next;
					znamka_count++;
					znamka_sum = znamka_sum + hCurr->znamka;
			}
			hCurr->next=pHodAdd;
		}
	znamka_sum = znamka_sum + pHodAdd->znamka;
	znamka_count++;
	curr->avg_znamka = znamka_sum / znamka_count;
	//free(pHodAdd);
}
//maze vybranou restauraci
void rest_del(rest**head,rest*curr) 
{
	rest* last;
	last = *head;
	printf("tesrt");
	if(curr == *head) //pokud je vybrana restauracde prvni
	{
		printf("test prvni");
		*head = curr->next;
	}
	while(last != curr) //prochazi list dokud "last" není poslední restaurace pred vybranou(curr)
	{
		if(last->next == curr)
		{
		printf("tesrt");
		last->next = curr->next;
		curr->next = last->next;
		curr = last;
		break;
		}
		last=last->next;
	}
	//free(last);
}