#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

	FILE *fp;


	fp=fopen("test.txt","r+");

	int caracter;
	int pos = 0;
	int c;

	while((caracter=fgetc(fp))!=EOF)
	{
		pos = ftell(fp);

		if(caracter==32)
		{
            fseek(fp, pos+1, SEEK_SET);
            c = fgetc(fp);
            fprintf(fp, "%c", c);
            fseek(fp, pos, SEEK_SET);
		}	

	}

	fseek(fp, -1, SEEK_END);
	pos = ftell(fp);
	ftruncate(fileno(fp), pos);

	fclose(fp);
}