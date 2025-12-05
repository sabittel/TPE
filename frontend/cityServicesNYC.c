#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../backend/servicesADT.h"
#include "validation.h"

int hasCSVExtension(const char *path);

int main(int argc, char * argv[]){
    if(!validation(argc, argv)){
        return 1;
    }
    cityServicesADT cityService = newServiceADT(); /*creo el TAD para NYC*/
    
}