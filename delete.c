#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void delete_name(FILE* fichier, char* name)
{

	FILE* fichier2;
	int i=0;
	char nomf2[60];
	char nomf1[60];
	char* result = NULL;
	fichier = fopen("names.txt","r");
	fichier2 = fopen("brouillon.txt","w+");
	
	if((fichier != NULL)&&(fichier2 != NULL))
	{
		do
		{
			result = strstr(nomf1,name);// on compare le nom lu à celui qu'on veut supprimer
			if(result == NULL)
			{
				fprintf(fichier2,"%s",nomf1);// on copie s'il n'est pas à supprimer
			}
			if(result != NULL)
			{
				i = 1;
			}
			
		}
		while((fgets(nomf1,60,fichier)) != NULL);
		fclose(fichier);
		fclose(fichier2);
		if(i==0)
		{
			printf("Le nom '%s' n'est pas dans la liste!!\n",name);
		}
		
		
		if(i==1)
		{
			fichier = fopen("names.txt","w+");
			fichier2 = fopen("brouillon.txt","r");
			if((fichier != NULL)&&(fichier2 != NULL))
			{
				fgets(nomf2,60,fichier2);
				do
				{
					fprintf(fichier,"%s",nomf2);// copie des noms à conserver dans la vraie liste	
				}
				while((fgets(nomf2,60,fichier2)) != NULL);
			}
			printf("le nom %s a ete supprime de la liste!",name);
		}
		fclose(fichier);
		fclose(fichier2);	
    }	
}