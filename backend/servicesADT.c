#include "servicesADT.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct typeNode { /*por cada linea del Types.csv creo un nodo (es como un diccionario)*/
    char *code; /*codigo*/
    char *name; /*nombre real*/
    struct typeNode *next;
} typeNode;

typedef struct typeCountNode { /*cuantas quejas hay por tipo en el barrio (Query 1)*/
    char *typeCode; /*tipo*/
    size_t count; /*contador*/
    struct typeCountNode *next;
} typeCountNode;

typedef struct boroughNode {
    char *borough; /*nombre del barrio*/
    typeCountNode *types;      /* para Query 1 */
    size_t closedByHour[24];   /* para Query 2, cantidad de reclamos cerrados en este barrio a las n horas */
    struct boroughNode *next;
} boroughNode;

typedef struct typeListNode { /*lista de tipos usados por cuadrante*/
    char *typeCode;            /* código de tipo (distinto) */
    struct typeListNode *next;
} typeListNode;

typedef struct quadrantNode { /*representa un cuadrante*/
    int quadLat;
    int quadLon;
    typeListNode *openTypes;   /* lista de tipos abiertos distintos */
    struct quadrantNode *next;
} quadrantNode;

struct cityServicesCDT { 
    typeNode    *types;       /* diccionario code -> name */
    boroughNode *boroughs;    /* estructuras para Q1 y Q2 */
    quadrantNode *quadrants;  /* estructuras para Q3 */
};

