# include <stdio.h>
#include <gmp.h>
 
int main(int argc, char *argv[])
{
    mpz_t n;
    mpz_init_set_str(n, argv[1], 10);
    printf("%s\n", mpz_get_str(NULL, 10, n));
    return 0;
}

