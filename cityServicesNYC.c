#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "backend/servicesADT.h"
#include "frontend/validation.h"
#include "frontend/loadTypes.h"

int hasCSVExtension(const char *path);

int main(int argc, char * argv[]){
    if(!validation(argc, argv)){
        return 1;
    }
    const char * requestsFile=argv[1];
    const char * typesFile=argv[2];
    

    //Abro archivos
    FILE *fReq = fopen(requestsFile, "r");
    if (fReq == NULL) {
        fprintf(stderr, "Error al abrir %s\n", requestsFile);
        return 1;
    }

    FILE *fTypes = fopen(typesFile, "r");
    if (fTypes == NULL) {
        fprintf(stderr, "Error al abrir %s\n", typesFile);
        fclose(fReq);
        return 1;
    }

    cityServicesADT cityServiceNYC = newServiceADT(); /*creo el TAD para NYC*/
    if (!loadTypes(fTypes, cityServiceNYC, 0)){
        return 1;
    }
}