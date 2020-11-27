// gcc -Wall -O2 -Wextra -fanalyzer -g main.c -o morseF
//by Art0v1r0s
//read sentence by scanf and convert in morse alpha
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
main()
{
 char *alphamorse[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                    "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
     "...-",".--","-..-","-.--","--.."};
 char *nummorse[]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};

 time_t t = time(NULL); /* t contient maintenant la date et l'heure courante */


 int i;
 char str[1000],str1[1000];
 printf("Enter a sentence\n");
 gets(str);
 i=0;
  while(str[i]!='\0')
  {
 if(str[i]!=' '&&(!isdigit(str[i])))
 {
     printf("%s ",alphamorse[toupper(str[i])-65]);
 }
    if(str[i]==' ')
    {
     printf(" ");
    }
    if(isdigit(str[i])&&str[i]!=' ')
    {
      printf("%s ",nummorse[str[i]-48]);
    }

   i++;
  }
  printf("\n");

  printf("%s\n", ctime(&t));

}
