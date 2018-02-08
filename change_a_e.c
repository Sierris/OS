#include <stdio.h>

int main()
{

	FILE *file = fopen("test.txt", "r+");
	int c;
	
	if(file)
	{
		while((c = fgetc(file)) != EOF)
		{			
			if(c == 'e' || c == 'E')
			{	
				fseek(file, -1, SEEK_CUR);
				fputc('a',file);
				fseek(file, 0, SEEK_CUR);
			}
		}
		return 1;
	}
	return 0;
}