//gcc -Wall -O2 -Wextra -fanalyzer -g main2.c -o morseF2
//by Art0v1r0s
//read a files(morseF) et convert the sentence into a morse alpha
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

int main(int argc, char *argv[])
{
  int end = 0;
  time_t t = time(NULL); /* t contient maintenant la date et l'heure courante */
  do {
    FILE* fichier = NULL;
    int caractereActuel = 0;

    char *alphamorse[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                       "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
        "...-",".--","-..-","-.--","--.."};
    char *nummorse[]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};

    fichier = fopen("morseF.txt", "r");

    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            //condition fifferent chiffre decimal et espace
            if(caractereActuel!=' ' &&( !isdigit(caractereActuel) ) )//si caractère ou espace
            {
              //toupper converti lettre minuscule en maj ne prend pas en compte lettre accentué
                printf("%s ",alphamorse[toupper(caractereActuel)-65]);
            }
                //condition si lettre est espace alors affiché espace
            if(caractereActuel==' '){
                printf(" ");
               }
               //condition est chiffre decimal et non espace
            if(isdigit(caractereActuel)&&caractereActuel!=' '){
                 printf("%s  ",nummorse[caractereActuel-48]);
               }

            //printf("%c", caractereActuel); // On l'affiche

        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        //ferme fichier
        fclose(fichier);

    }
    printf("\n voulez vous recomencez 0 sinon 1:");
    scanf("%d ",end);

  } while(end!=0);
    printf("\n");
    //affiche date et heure;
    printf("%s\n", ctime(&t));

    return EXIT_SUCCESS;
}
