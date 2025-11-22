#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1024

int main(int argc, char *argv[])
{
        if(argc != 2){
                fprintf(stderr, "Not enough arguments provided.\n");
                return EXIT_FAILURE;
        }

        FILE *file;
        file = fopen(argv[1], "r");

        if(file == NULL){
                perror("Unable to open the file.\n");
                return EXIT_FAILURE;
        }

        char buf[MAXSIZE];
        while(fgets(buf, sizeof buf, file) != NULL){
                fputs(buf, stdout);
        }
        return EXIT_SUCCESS;
}
