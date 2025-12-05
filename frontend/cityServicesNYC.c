#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../backend/servicesADT.h"

int hasCSVExtension(const char *path);

int main(){
    if(){ /*validar que se pasen los csv*/
        .
    }
    cityServicesADT service = newServiceADT(NYC_archivo); /*creo el TAD para NYC*/
    .
}

int hasCSVExtension(const char *path) {
    const char *dot = strrchr(path, '.');
    if (dot == NULL)
        return 0;
    return strcmp(dot, ".csv") == 0;
}