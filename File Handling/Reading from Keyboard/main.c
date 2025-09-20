/* Getting input from keyboard */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* file;
	char filename[20], str[100];
	printf("Enter the filename : ");
	scanf("%s", filename);

	file = fopen(filename,"w");

	if(file == NULL)
	{
		printf("Error while opening the file!");
		return EXIT_FAILURE;	
	}

	printf("Enter the text : ");
	scanf("%s", str);

	fprintf(file, "%s",str);
	fclose(file);
	return EXIT_SUCCESS;
}

