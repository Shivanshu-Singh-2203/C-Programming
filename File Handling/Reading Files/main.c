/* read a file character by character and display it simultaneously on the screen */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fp;
	int ch;
	char filename[40];
	printf("Enter the file name : ");
	scanf("%s", filename);

	fp = fopen(filename,"r");
	if(fp == NULL)
	{
		printf("Error while opening the file.\n");
		exit(1);
	}

	ch = fgetc(fp);
	while(ch != EOF)
	{
		putchar(ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	return 0;
}
