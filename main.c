#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//inclusion des fichiers headers (prototypes)

#include "add_name.h"
#include "delte_name.h"
#include "find_name.h"



/* ----PROGRAMME PRINCIPAL---- */

int main()
{
	FILE* fichier;
	int choix;
	char nom[60];
	printf("Bienvenue dans Black_List\n")
	printf("Cette application assure la gestion des noms de bavards\n\n\n");
label1 : printf("\t\t******MENU******\n");
	printf("1= ajout d'un nom\n2= suppression d'un nom\n3= recherche d'un nom\n0= fermer l'application\nchoix =");
	scanf("%d",&choix);
	if(choix!=1 && choix != 2 && choix!= 3 && choix != 0)
	{
		do
		{
			printf("veuillez choisir une option VALIDE svp!!!"),
			scanf("%d",&choix);
		}
		while(choix != 0 && choix !=1 && choix != 2 && choix != 3 && choix != 4);
	}
	if(choix == 1)
	{
		printf("Quel nom voulez-vous ajouter a la liste ?");
		scanf("%s",&nom);
		add_name(fichier,nom);
		goto label1;
	}
	if(choix == 2)
	{
		printf("Entrer le nom que vous voulez supprimer de la liste\n");
		scanf("%s",&nom);
		delete_name(fichier,nom);
		goto label1;
	}
	if(choix == 3)
	{
		printf("Quel nom recherchez-vous ?\n");
		scanf("%s",&nom);
		find_name(fichier,nom);
		goto label1;
	}
	if(choix == 0)
	{
		printf("*****FIN DU PROGRAMME*****");
	}	
}
