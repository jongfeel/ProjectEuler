#include <stdio.h>
#include <string.h>

int IsPalindrome(int number)
{
	char originNumber[10];
	sprintf(originNumber, "%d", number);
	//printf("%s\n", originNumber);

	char sourceNumber[10];
	strcpy(sourceNumber, originNumber);

	char* targetNumber = strrev(sourceNumber);
	//printf("%s\n", targetNumber);

	return strcmp(originNumber, targetNumber);
}

int main(int argc, char* argv[])
{
	int candidatePalindrome;
	int isPalindrome;

	int input;

	for (int i=999; i>=900; i--)
	{
		for (int j=999; j>900; j--)
		{
			candidatePalindrome = i * j;
			isPalindrome = IsPalindrome(candidatePalindrome);
			if (isPalindrome == 0)
			{
				printf("%d x %d = %d\n", i, j, candidatePalindrome);
				goto end;
			}
		}
	}

	end:
	printf("To end of program, input any character and enter...");
	scanf("%d", &input);
	return 0;
}
