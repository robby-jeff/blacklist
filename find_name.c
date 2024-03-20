#include <stdio.h>
#include <stdlib.h>
#include "find_name.h"

//fonction de recherche du nom d'un élève
int find_name(char name[50]){

    FILE* file;
    file = fopen("ro.txt", "r");
    char yo[50];
    char temp[50];
    int resul;
    int i;

    while(fgets(yo, 50, file)){
        resul = strstr(yo,name);
        if(resul != NULL){
            strcpy(temp, yo);
            i = 1;
            break;
        }else{
            i = 0;
        }
    }
    if(i == 1)
    {
        printf("Le nom recherche est : %s\n",temp);
    }else if(i == 0){
        printf("Ce nom n'existe pas dans la liste de bavard !\n");
    }
    if(file == NULL){
        printf("Erreur");
        return 1;
    }
    fclose(file);
}

