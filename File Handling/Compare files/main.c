/* Compare two files till there characters matches */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	FILE* file1,* file2;

	char firstFile[80]; 
	char secondFile[80];

	printf("Enter the first file name : ");
	scanf("%s", firstFile);

	printf("Enter the second file name : ");
	scanf("%s", secondFile);

	file1 = fopen(firstFile,"r");
	file2 = fopen(secondFile,"r");

	if(file1 == NULL )
	{
		printf("Error opening file %s!",firstFile);
		exit(1);
	}

	if (file2 == NULL)
	{
		printf("Error opening file %s!",secondFile);
		exit(1);
	}

	char firstChar, secondChar;
	firstChar = fgetc(file1);
	secondChar = fgetc(file2);
	int count = 0;
	while (firstChar != EOF && secondChar != EOF && firstChar == secondChar)
	{
		count ++;
		firstChar = fgetc(file1);
		secondChar = fgetc(file2);
	}

	if(secondChar == firstChar)
	{
		printf("Files are identical.\n");
	}
	else {
		printf("Files differ from character count %d .\n", count);
	}
	return 0;
}
