#include <stdio.h>
#include <string.h>

char* reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	return s;
}

int check_palabra(char* p1, char* p2, int t1, int t2)
{
	if(t1 != t2)
	{
		return 1;
	}
	else
	{

		char *palabra = reverse(p2);
		for (int i = 0; i < t1; i++)
		{

			if(p1[i] == palabra[i])
			{
				continue;
			}
			else
			{
				return 1;
			}
		}
		return 0;
	}
}

int main(int argc, char *argv[])
{
	char *palabra1 = argv[1];
	char *palabra2 = argv[2];

	int tam1 = strlen(palabra1);
	int tam2 = strlen(palabra2);


	printf("%d\n", check_palabra(palabra1, palabra2, tam1, tam2));
	
}