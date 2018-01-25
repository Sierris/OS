#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t fibonacci(uint64_t n){
	if(n==0){
		return 0;
	}else if(n==1){
		return 1;
	}else{
		return (fibonacci(n-1) + fibonacci(n-2));
	}
}

int main(int argc, int *argv[]){
	printf("Ejecutando fibonacci con %d terminos...\n", argv[1]);
	
	uint64_t x = atoi(argv[1]);
	for (uint64_t i = 0; i < x; i++)
	{
		printf("%" PRIu64 "\n", fibonacci(i));
	}
	
	printf("\n");
	
	return 0;
}