/* Copying character with multiple character at a time */ 

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* source, *destination;

	char src[80];
	char dest[80];

	printf("Enter the source file name : ");
	scanf("%s", src);

	printf("Enter the destination file name : ");
	scanf("%s", dest);

	source = fopen(src,"r");
	destination = fopen(dest,"w");

	if(source == NULL)
	{
		printf("Error while opening the source file %s.!\n", src);
		exit(1);
	}
	
	if( destination== NULL)
	{
		printf("Error while opening the destination file %s.!\n", dest);
		exit(1);
	}
	char str[80];
	while(fgets(str, 80, source)!= NULL)
	{
		fputs(str, destination);
	}
	fclose(source);
	fclose(destination);
	return 0;
}
