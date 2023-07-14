

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#include "display.h"
#include "serialization.h"
#include "edit.h"
#include "sort.h"
#include "main.h"



void rest_name_search(rest**head,rest*curr){
	printf("zadejte nazev hledane restaurace:");
	char  search_nazev[SNAME];
	fflush(stdin);
	scanf("%[^\n]",search_nazev);
	int results_count;
	rest* curr_true;
	for(curr = *head ; curr != NULL ; curr = curr->next)
	{
		int i;
		int true_count = 1;
		for(i = 0; search_nazev[i] != 0; i++)
		{
			if(curr->nazev[i] != 0)
			{
				if(search_nazev[i] == curr->nazev[i])
				{
					true_count++;
					curr_true = curr;
				}
				else
				{
					true_count = 0;
					break;
				}
			}
		}
		if(true_count != 0)
		{
			results_count++;
			print_rest(curr);
		}
	}
	if(results_count == 0)
	{
		printf("Restaurace nenalezena");
	}
	else if(results_count == 1)
	{
		curr = curr_true;
		rest_detail(head,curr);
	}
	else if(results_count > 1)
	{
		getchar();
		rest_detail(head, rest_id_search(*head, curr));
	}
}


rest* rest_id_search(rest*head,rest*curr)
{
	int  search_id = 0;
	printf("Zadejte ID vybrane restaurace:");
	scanf("%d",&search_id);
	for (curr = head; &(curr->id) != NULL; curr = curr->next) 
	{
		if(curr->id == search_id){
			break;
		}
	}	
	return curr;
}


void sort_id(rest**head,rest*curr) 
{
	print_cara();
	printf("Seznam restauraci:\n");
	print_cara();
	for (curr = *head; curr != NULL; curr = curr->next) 
	{
		print_rest(curr);
	}
}
int rest_countf(rest*head,rest*curr)
{
	int r_count = 0;
	for(curr = head;curr != NULL;curr = curr->next)
	{
		r_count++;
	}
	return r_count;
}
void sort_abc(rest**head,rest*curr)
{
	
	int rest_count = rest_countf(*head,curr);
	int count = 0;
	rest* rest_array[rest_count];
	for(curr = *head;curr != NULL;curr = curr->next)
	{
		rest_array[count] = curr;
		count++;
	}
	rest* temp;
	for(int j = 0; j != rest_count - 1;j++)
	{
		for(int k = 0; k != rest_count - j - 1;k++)
		{
			if(strcmp(rest_array[k]->nazev,rest_array[k+1]->nazev)>=0)
			{
				temp = rest_array[k];
        		rest_array[k] = rest_array[k + 1];
      			rest_array[k + 1] = temp;
			}
		}
	}
	print_cara();
	printf("Seznam restauraci:\n");
	print_cara();
	for(int i = 0;i !=rest_count;i++)
	{
		print_rest(rest_array[i]);
	}
	rest_detail(head,(rest_id_search(*head, curr)));
}
void sort_hodn(rest**head,rest*curr)
{
	int rest_count = rest_countf(*head,curr);
	int count = 0;
	rest* rest_array[rest_count];
	for(curr = *head;curr != NULL;curr = curr->next)
	{
		rest_array[count] = curr;
		count++;
	}
	rest* temp;
	for(int j = 0; j != rest_count - 1;j++)
	{
		for(int k = 0; k != rest_count - j - 1;k++)
		{
			if(rest_array[k]->avg_znamka <=rest_array[k+1]->avg_znamka)
			{
				temp = rest_array[k];
        		rest_array[k] = rest_array[k + 1];
      			rest_array[k + 1] = temp;
			}
		}
	}
	print_cara();
	printf("Seznam restauraci:\n");
	print_cara();
	for(int i = 0;i !=rest_count;i++)
	{
		print_rest(rest_array[i]);
	}
	rest_detail(head,(rest_id_search(*head,curr)));
}
