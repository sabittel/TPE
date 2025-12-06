#include "servicesADT.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//============================================= STRUCTS =============================================

/*
    *Estructura recursiva 1
    *Donde se guarda el nombre y codigo de una queja (una linea del csv) en un str
*/

typedef struct typeNode { 
    char *code; /*codigo*/
    char *name; /*nombre real*/
    struct typeNode *next;
} typeNode;

/*
    *Estructura recursiva 2 
    *Donde se guarda el tipo de reclamo -> str;
    *Cuantas quejas hay por tipo en el barrio   (Query 1)
*/
typedef struct typeCountNode { 
    char *typeCode; /*tipo*/
    size_t count; /*contador*/
    struct typeCountNode *next;
} typeCountNode;

/*
    *Estructura de un barrio recursiva
    *El nombre del barrio para luego hacer la lista alfabetcamente
    *Una lista de tipos de quejas y su cantTot, --> Query 1
    *Un vec para las 24 hs, donde el indice representa una hora y en c/u se guardan el total de reclamos cerrados de ese barrio --> Query 2
*/
typedef struct boroughNode {
    char *borough; /*nombre del barrio*/
    typeCountNode *types;      /* para Query 1 */
    size_t closedByHour[24];   /* para Query 2*/
    struct boroughNode *next;
} boroughNode;

/*
    *
*/
typedef struct typeListNode { /*lista de tipos usados por cuadrante*/
    char *typeCode;            /* código de tipo (distinto) */
    struct typeListNode *next;
} typeListNode;

/*
    *Estructura de un cuadrante recursiva
    *Se guarda la latitud y longitud
    *Una lista con los tipos distintos de reclamos abiertos --> Query 3

*/
typedef struct quadrantNode { 
    int quadLat;
    int quadLon;
    typeListNode *openTypes;   
    struct quadrantNode *next;
} quadrantNode;

/*
    *CDT final
    *La lista de barrios
    *La lista de cuarantes   
*/
typedef struct cityServicesCDT { 
    typeNode    *types;       /* diccionario code -> name */
    boroughNode *boroughs;    /* estructuras para Q1 y Q2 */
    quadrantNode *quadrants;  /* estructuras para Q3 */
}cityServicesCDT;

//============================================= FUNCIONES =============================================

int is_ValidAlloc(cityServicesADT adt){
    if(adt==NULL){
        fprintf(stderr, "ERROR, NO HAY MEMORIA DISPONIBLE\n");
        return 0;
    }
    return 1;
}

cityServicesADT newServiceADT(){
    cityServicesADT new=calloc(1, sizeof(cityServicesCDT));
    if(!is_validAlloc(new)){
        return NULL;
    }
    return new;
}

int addTypes(cityServicesADT cs, const char* code, const char* name){
    
}

