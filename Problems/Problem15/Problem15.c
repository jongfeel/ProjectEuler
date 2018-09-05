#include <stdio.h>

unsigned long Factorial(int n)
{
	int start = 2;
	unsigned long value = 1;
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

	printf("%lu\n", Factorial(40));
	
	printf("To end of program, input any character and enter...");
	scanf("%d", &input);
	return 0;
}
