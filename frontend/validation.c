#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"

int validation(int argc, char * argv[]){
    if(argc!=3){
            fprintf(stderr, "Error: Expected %d .csv files, but %d arguments were provided.\n", 2, argc-1);
            return 1;
    }
    const char * requestFile = argv[1];
    const char * typesFile = argv[2];
    if(!hasCSVExtension(requestFile) || !hasCSVExtension(typesFile)){ /*validar que se pasen los csv*/
        fprintf(stderr, "Error: An argument is not a .csv file.\n");
        return 1;
    }
    return 0;
}
int hasCSVExtension(const char *path) {
    const char *dot = strrchr(path, '.');
    if (dot == NULL)
        return 0;
    return strcmp(dot, ".csv") == 0;
}