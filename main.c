#include <stdlib.h>
#include <string.h>
#include "library.h"

int main(int argc, char **argv ) {
    char bookFile[40];
    char userFile[40];
    if( argc != 3)
    {
        // use the error message
        printf("Error\nExpected use: ./library books.txt user.txt \n");
        // exit the application if there is an error
        exit(0);
    }
    strcpy(bookFile,argv[1]);
    strcpy(userFile,argv[2]);

    run_library(bookFile,userFile);
    return 0;
}
