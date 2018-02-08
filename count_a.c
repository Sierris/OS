#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

int count =0;
regex_t regex;
int reti;

/*Chekea si existe la expresión regular dentro de la palabra*/

void check_reg(char *c)
{
	char msgbuf[100];
	if(strlen(c)<3)
	{	}
	else
	{

	reti = regcomp(&regex, "^[aA]", REG_ICASE == 0); /*compila el regex*/

		if (reti)
		{
			exit(1);
		}

	reti = regexec(&regex, c, 0, NULL, 0); /*ejecuta el regex sobre la palabra*/
		if(!reti) 
		{
			count++;
		}
	else if (reti == REG_NOMATCH) /*No hacer nada si no hay match*/
		{	}
		else
		{
		regerror(reti, &regex, msgbuf, sizeof(msgbuf)); /*Error si no ejecuta el regex*/
			printf("Regex fallo\n");
			exit(1);
		}
	}
	

}

int main(int argc, int *argv[])
{
	FILE *file = fopen("test.txt", "r"); /*el archivo de entrada se llama test.txt*/
	char c[1024]; /*Leer palabras completas, asumir que ninguna es de mas de 1024 bits*/

	if(file)
	{
		while(fscanf(file, "%1023s", c) == 1)
		{
			check_reg(c);
		}
	}
	else
	{
		printf("Error al abrir el archivo\n");
		exit(1);
	}

	printf("%d\n", count);
	regfree(&regex);
	
	return 0;
}