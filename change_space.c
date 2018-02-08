#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void correr(FILE *fp)
{
	
	int carSig;

    
    int cont=0;
        
        while((carSig=fgetc(fp))!=EOF)
        {
		    fseek(fp, ftell(fp) -2, SEEK_SET);
		    fprintf(fp,"%c",carSig);
		    fseek(fp, ftell(fp) +1, SEEK_SET);
        }
        
        fseek(fp,-1,SEEK_END);
        int position = ftell(fp);
        ftruncate(fileno(fp), position);
}



int main()
{

	FILE *fp;


	fp=fopen("test.txt","r+");

	int caracter;
	int pos = 0;
	
	while((caracter=fgetc(fp))!=EOF)
	{
		pos = ftell(fp);

		if(caracter==32)
		{
            correr(fp);
            fseek(fp, pos, SEEK_SET);
		}	

	}

fclose(fp);

}