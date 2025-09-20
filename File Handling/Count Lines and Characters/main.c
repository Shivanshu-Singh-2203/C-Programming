#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char filename[80];
	FILE* fp;
	int character_count = 0;
	int line_count = 0;

	printf("Enter the filename : ");
	scanf("%s", filename);

	fp = fopen(filename,"r");

	if(fp == NULL)
	{
		printf("Error while opening the file.\n");
		exit(1);
	}

	char ch = fgetc(fp);
	while(ch!= EOF)
	{
		if(ch == '\n')
		{
			line_count ++;
		}
		character_count ++;
		ch = fgetc(fp);
	}

	printf("Number of lines in the file : %d\n", character_count);
	printf("Number of lines in the file : %d\n", line_count);
	return 0;
}
















