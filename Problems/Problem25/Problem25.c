#include <stdio.h>
#include <string.h>
#include <gmp.h>

unsigned int Fibonacci(int digits)
{
	mpz_t Fn1; // Fn-1
	mpz_t Fn2; // Fn-2
	mpz_t Fn;  // Fn

	mpz_init_set_ui(Fn1, 1);
	mpz_init_set_ui(Fn2, 1);
	mpz_init(Fn);
	
	int size = 0;
	unsigned int index = 2;

	while (size != digits)
	{
		mpz_add(Fn, Fn1, Fn2);
		
		char* Fn_str = mpz_get_str(NULL, 10, Fn);
		//printf("%s ", Fn_str);
		size = strlen(Fn_str);
		//printf("%d\n", size);

		mpz_set(Fn1, Fn2);
		mpz_set(Fn2, Fn);

		index++;
	}
	
	mpz_clear(Fn2);
	mpz_clear(Fn1);
	mpz_clear(Fn);	
	
	return index;
}

int main(int argc, char* argv[])
{
	printf("%u", Fibonacci(1000));

	return 0;
}
