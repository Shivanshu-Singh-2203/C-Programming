#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{       if(argc != 2){
                fprintf(stderr, "Not enough arguments given.\n");
                return EXIT_FAILURE;
        }

        FILE* file;
        file = fopen(argv[1], "r");
        if (file == NULL) {
                perror("Unable to open the file.\n");
                return EXIT_FAILURE;
        }
        
        int ch;
        while ((ch = fgetc(file)) != EOF){
                putchar(ch);
        }

        fclose(file);
        return EXIT_SUCCESS;
}
