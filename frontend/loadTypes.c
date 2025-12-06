#include <stdio.h>
#include <ctype.h>
#include "../backend/servicesADT.h"

int loadTypes(FILE *fTypes, cityServicesADT cs, const size_t id) {
    char *line = NULL;
    size_t len = 0;
    int read;

    /* 1) Leer y descartar la línea de encabezado */
    read = getline(&line, &len, fTypes);
    if (read == -1) {          // archivo vacío o error
        free(line);
        return 0;
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
        const char *name;
        const char *code;
        if (id==0)
        {
            name = field1;
            code = field2;
        }
        else{
            name = field2;
            code = field1;
        }
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
    return 1;
}