#include <stdio.h>

long double Factorial(unsigned int n)
{
	int start = 2;
	long double value = 1;
	while (start <= n)
	{
		value *= start;
		start++;
	}

	return value;
}

int main(int argc, char* argv[])
{
	int input;

	unsigned int gridSize = 20;
	unsigned int n = gridSize * 2;
	unsigned int r = gridSize;

	// Combination: C(n,r) = n! / r!(n-r)!
	printf("%LE\n", Factorial(n) / (Factorial(r) * Factorial(n-r)));
	
	printf("To end of program, input any character and enter...");
	scanf("%d", &input);
	return 0;
}
