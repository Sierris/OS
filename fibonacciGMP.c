//gcc -o salida fibonaccigMP.c -lgmp -lm

#include <stdio.h>
#include <gmp.h>

int main(int argc, char *argv[])
{	
	mpz_t n1, n2, total;
	unsigned long count, i;	

	sscanf(argv[1], "%lu", &count);

	mpz_init_set_str(n1, "0", 10);
	mpz_init_set_str(n2, "1", 10);
	mpz_init(total);

	printf("%s\n%s\n", mpz_get_str(NULL, 10, n1)
		, mpz_get_str(NULL, 10,n2));

	for (i = 0; i < count - 2; i++)
	{
  		mpz_add(total, n1, n2);			/* total = n1+n2 */

  		mpz_init_set(n1, n2);			/* n1 = n2 */
  		mpz_init_set(n2, total);		/* n2 = total */

		printf("%s\n",mpz_get_str(NULL, 10, total));

	}	

	return 0;
}