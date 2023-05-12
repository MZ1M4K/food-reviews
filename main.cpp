

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#include "display.h"
#include "serilization.h"
#include "edit.h"
#include "sort.h"
#include "main.h"

rest* head = NULL;
rest* curr = NULL;
hodnoceni * hHead = NULL;
hodnoceni * hCurr = NULL;

int main()
{
	read_file(&head,curr,hHead,hCurr);
	menu(&head,curr,hHead,hCurr);
	save_file(head,curr,hHead,hCurr);
	return 0;
}
void menu(rest**head,rest*curr,hodnoceni*hHead,hodnoceni*hCurr) 
{
	int volba;
	do{
		system("cls");
		print_cara();
		printf("\tVeproKnedloBrno\n");
		print_cara();
		printf("1.ZOBRAZIT RESTAURACE PODLE ID\n");
		printf("2.ZOBRAZIT RESTAURACE PODLE HODNOCENI\n");
		printf("3.ZOBRAZIT RESTAURACE ABECEDNE\n");
		printf("4.HLEDAT RESTAURACI DLE NAZVU\n");
		printf("5.PRIDAT RESTAURACI\n");
		printf("0.EXIT\n");
		print_cara();
		printf("Zadejte volbu(0-5):");
		scanf("%d", &volba);
		switch (volba) {
		case 1:
			system("cls");
			sort_id(head,curr);
			rest_detail(head,(rest_id_search(*head,curr)));
			
			break;
		case 2:
			system("cls");
			sort_hodn(head,curr);
			break;
		case 3:
			system("cls");
			sort_abc(head,curr);
			break;
		case 4:
			system("cls");
			rest_name_search(head,curr);
			break;
		case 5:
			system("cls");
			rest_add(head,curr);
			break;
		default:
			if(volba!=0)
			{
				printf("neplatna volba!");
			}
			break;
		}
	} while (volba != 0);
}
void rest_detail(rest**head,rest*curr)
{
	if (curr == NULL)
	{
		system("cls");
		printf("\nRestaurace nenalezena!\n\n");
		getchar();
	}
	else
	{
		system("cls");
		rest_detail_print(curr,hCurr); 
		int volba_detail;
		do {
			print_cara();
			printf("1.PRIDAT HODNOCENI RESTAURACE\n");
			printf("2.SMAZAT RESTAURACI\n");
			printf("3.EDITOVAT RESTAURACI\n");
			printf("0.NAVRAT DO HLAVNIHO MENU\n\n");
			
			printf("zadejte volbu (1-3):");
			scanf("%d",&volba_detail);
			switch (volba_detail)
			{
				case 1:
				rest_hodn_add(*head,curr,hHead,hCurr);
				break;
				case 2:
				rest_del(head,curr);
				volba_detail = 0;
				break;
				case 3:
				rest_edit(curr);
				break;
				default:
				if(volba_detail!=0)
				{
					printf("neplatna volba!");
				}
				break;
			}
		}while (volba_detail != 0);
	}
}
void rest_edit(rest*curr)
{
	int volba_edit;
	do{
		system("cls");
		printf("\nZvolte údaj k editaci:");
		printf("\n\n1.NAZEV\n2.ADRESA\n3.KUCHYNE\n4.POPIS\n0.NAVRAT DO MENU");
		printf("\n\nzadejte volbu (0-4):");
		scanf("%d",&volba_edit);
		switch (volba_edit)
		{
			case 1:
			system("cls");
			printf("NAZEV: %s",curr->nazev);
			fflush(stdin);
			printf("\nzadejte novy nazev podniku: ");
			scanf("%[^\n]",curr->nazev);
			printf("\nNOVY NAZEV:%s\n",curr->nazev);
			break;
			case 2:
			system("cls");
			printf("ADRESA: %s",curr->adresa);
			fflush(stdin);
			printf("\nzadejte novou adresu podniku: ");
			scanf("%[^\n]",curr->adresa);
			printf("\nNOVA ADRESA:%s\n",curr->adresa);
			break;
			case 3:
			system("cls");
			printf("KUCHYNE: %s",curr->kuchyne);
			fflush(stdin);
			printf("\nzadejte kuchyni podniku: ");
			scanf("%[^\n]",curr->kuchyne);
			printf("\nNOVA KUCHYNE:%s\n",curr->kuchyne);
			break;
			case 4:
			system("cls");
			printf("POPIS: %s",curr->popis);
			fflush(stdin);
			printf("\nzadejte novy popis: ");
			scanf("%[^\n]",curr->popis);
			printf("\nNOVY POPIS:%s\n",curr->popis);
			break;
			default:
			if(volba_edit!=0)
				{
					printf("neplatna volba!");
				}
			break;
		}
	}while (volba_edit != 0);
}