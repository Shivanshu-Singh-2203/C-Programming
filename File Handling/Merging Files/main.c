/* Merging two files into the output file */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *first, *second, *merge;

    if (argc != 4)
    {
        printf("Usage: %s <file1> <file2> <output>\n", argv[0]);
        return EXIT_FAILURE;
    }

    first = fopen(argv[1], "r");
    if (first == NULL)
    {
        printf("Error while opening %s!\n", argv[1]);
        return EXIT_FAILURE;
    }

    second = fopen(argv[2], "r");
    if (second == NULL)
    {
        printf("Error while opening %s!\n", argv[2]);
        fclose(first);
        return EXIT_FAILURE;
    }

    merge = fopen(argv[3], "w");
    if (merge == NULL)
    {
        printf("Error while opening %s!\n", argv[3]);
        fclose(first);
        fclose(second);
        return EXIT_FAILURE;
    }

    int temp;

    while ((temp = fgetc(first)) != EOF)
        fputc(temp, merge);

    while ((temp = fgetc(second)) != EOF)
        fputc(temp, merge);

    fclose(merge);
    fclose(first);
    fclose(second);

    printf("Files %s and %s merged into %s\n", argv[1], argv[2], argv[3]);
    return EXIT_SUCCESS;
}

