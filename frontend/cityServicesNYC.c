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
    if (!loadTypes(fTypes, cityServiceNYC)){
        return 1;
    }
}

int loadTypes(FILE *fTypes, cityServicesADT cs) {
    char *line = NULL;
    size_t len = 0;
    int read;

    /* 1) Leer y descartar la línea de encabezado */
    read = getline(&line, &len, fTypes);
    if (read == -1) {          // archivo vacío o error
        free(line);
        fprintf(stderr, "Error: archivo vacio");
        return 1;
    }

    /* 2) Leer cada línea de datos */
    while ((read = getline(&line, &len, fTypes)) != -1) {
        // Sacar el '\n' o '\r\n' del final
        line[strcspn(line, "\r\n")] = '\0';

        // Si la línea quedó vacía, la salto
        if (line[0] == '\0')
            continue;

        // Separo por ';'
        char *field1 = strtok(line, ";");
        char *field2 = strtok(NULL, ";");

        if (field1 == NULL || field2 == NULL) {
            // Línea mal formada, la ignoramos
            continue;
        }

        // Según el formato:
        // field1 = nombre, field2 = código
        const char *name = field1;
        const char *code = field2;

        // Si tu CSV tiene el orden CODE;NAME, cambiás estas dos líneas:
        // const char *code = field1;
        // const char *name = field2;

        if (!addType(cs, code, name)) {
            // Error de memoria en el backend
            free(line);
            return 0;
        }
    }

    free(line);
    return 0;
}