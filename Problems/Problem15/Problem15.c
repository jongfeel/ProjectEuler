#include <stdio.h>
#include <stdlib.h>
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
	int input;

	unsigned int gridSize = 20;
	unsigned int n = gridSize * 2;
	unsigned int r = gridSize;

	mpz_t result_n;
	mpz_t result_r;
	mpz_t result_n_minus_r;
	mpz_t result_r_mul_n_minus_r;
	mpz_t result_combination;

	mpz_init_set_ui(result_n, 1);
	mpz_init_set_ui(result_r, 1);
	mpz_init_set_ui(result_n_minus_r, 1);
	mpz_init_set_ui(result_r_mul_n_minus_r, 1);
	mpz_init_set_ui(result_combination, 1);

	// Combination: C(n,r) = n! / r!(n-r)!
	Factorial(n, result_n);
	Factorial(r, result_r);
	Factorial(n-r, result_n_minus_r);
	
	// char *result_n_str = mpz_get_str(NULL, 10, result_n);
    // printf("%s\n", result_n_str);
	// char *result_r_str = mpz_get_str(NULL, 10, result_r);
	// printf("%s\n", result_r_str);
	// char *result_n_minus_r_str = mpz_get_str(NULL, 10, result_n_minus_r);
    // printf("%s\n", result_n_minus_r_str);

	// r!(n-r)!
	mpz_mul(result_r_mul_n_minus_r, result_r, result_n_minus_r);
	
	// char *result_r_mul_n_minus_r_str = mpz_get_str(NULL, 10, result_r_mul_n_minus_r);
    // printf("%s\n", result_r_mul_n_minus_r_str);

	// n! / r!(n-r)!
	mpz_divexact(result_combination, result_n, result_r_mul_n_minus_r);

	char *result_combination_str = mpz_get_str(NULL, 10, result_combination);
    printf("%s\n", result_combination_str);
	
	mpz_clear(result_n);
	mpz_clear(result_r);
	mpz_clear(result_n_minus_r);
	mpz_clear(result_r_mul_n_minus_r);
	mpz_clear(result_combination);

	printf("To end of program, input any character and enter...");
	scanf("%d", &input);
	return 0;
}
