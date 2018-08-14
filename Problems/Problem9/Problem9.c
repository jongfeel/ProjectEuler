#include <stdio.h>

int main(int argc, char* argv[])
{
	int input;

	for (int a=1; a<=332; a++)
	{
		for (int b=a+1; b<=499 && b < c; b++)
		{
			int c = 1000 - b - a;

			if (a*a + b*b == c*c)
			{                     
				printf("a=%d, b=%d, c=%d\n", a, b, c);
				printf("%d\n", a * b * c);
				goto end;
			}
		}
	}

	end:
	printf("To end of program, input any character and enter...");
	scanf("%d", &input);
	return 0;
}
