#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

void Factorial(unsigned int n, mpz_t result)
{
	int start = 2;
	while (start <= n)
	{
		mpz_mul_ui(result, result, start);
		start++;
	}
}

int main(int argc, char* argv[])
{
	unsigned int n = 100;

	mpz_t result_factorial_n;

	mpz_init_set_ui(result_factorial_n, 1);

	Factorial(n, result_factorial_n);
	
	char *result_factorial_n_str = mpz_get_str(NULL, 10, result_factorial_n);
    //printf("%s\n", result_factorial_n_str);

	int size = strlen(result_factorial_n_str);
	int sumOfFactorial = 0;
	for (int i=0; i<size; i++)
	{
		//printf("%c", result_factorial_n_str[i]);
		sumOfFactorial += result_factorial_n_str[i] - '0';
	}

	printf("%d\n", sumOfFactorial);
	
	mpz_clear(result_factorial_n);
	free(result_factorial_n_str);

	return 0;
}
