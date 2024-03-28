#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add_name.h"



// fonction ajout d'un nom
void add_name(FILE* fichier, char* name)
{
	int choice;
	int i = 0;
	char noms[60];
	char nomf[60];
	char* result = NULL;
	fichier = NULL;
	fichier = fopen("names.txt","a+");
	if(fichier != NULL)
	{
		do
		{
			result = strstr(nomf,name);
			if(result != NULL)
			{
				i = 1;
				printf("Ce nom est exite deja dans la liste !");
				break;
			}
		}
		while((fgets(nomf,60,fichier)) != NULL);
		if(i==0)
		{
			fseek(fichier, 0, SEEK_END);
			fprintf(fichier,"\n%s",name);
			printf("Le nom a ete ajoute merci\n");
			
		}
		
		
	}
	printf("Voulez vous ajouter un autre nom ?\n");
		printf("1= oui\t0= non\n");
		scanf("%d",&choice);
		if(choice != 1 && choice != 0)
		{
			do
			{
				printf("Veuillez entrer une option valide svp!!\n");
				scanf("%d",&choice);
			}
			while(choice != 1 && choice != 0);
		}
		if(choice == 1)
		{
			printf("Quel nom voulez-vous ajouter ?\n");
			scanf("%s",&noms);
			add_name(fichier,noms);
		}
		if(choice == 0)
		{
			printf("$$ Retour au menu $$\n\n");	
		}
	
	if(fichier == NULL)
	{
		printf("Erreur!! ouverture impossible !!");
	}
	fclose(fichier);
}
