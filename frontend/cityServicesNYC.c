#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../backend/servicesADT.h"
#include "validation.h"

int hasCSVExtension(const char *path);

int main(int argc, char * argv[]){
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
    cityServicesADT service = newServiceADT(NYC_archivo); /*creo el TAD para NYC*/
    .
}

