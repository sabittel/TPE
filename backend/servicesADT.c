#include "servicesADT.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//============================================= STRUCTS =============================================

//================================= TYPES =================================
/*
    *Estructura recursiva 1
    *Donde se guarda el nombre y codigo de una queja (una linea del csv) en un str
*/

typedef struct typeNode { 
    char *code; /*codigo*/
    char *name; /*nombre real*/
    struct typeNode *next;
} typeNode;

//================================= QUERY 1 & 2 =================================

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

//================================= QUERY 3 =================================

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

//================================= Definitions =================================

typedef quadrantNode * Tquadrant;
typedef boroughNode * Tborough;
typedef typeNode * Ttype;

//================================= CDT =================================

/*
    *CDT final
    *La lista de barrios
    *La lista de cuarantes   
*/
typedef struct cityServicesCDT { 
    Ttype    types;       /* diccionario code -> name */
    Tborough boroughs;    /* estructuras para Q1 y Q2 */
    Tquadrant quadrants;  /* estructuras para Q3 */
}cityServicesCDT;

//============================================= FUNCIONES =============================================

int is_ValidAlloc(cityServicesADT adt){
    if(adt==NULL){
        fprintf(stderr, "ERROR, NO HAY MEMORIA DISPONIBLE\n");
        return 0;
    }
    return 1;
}

//================================= NEW =================================

cityServicesADT newServiceADT(){
    cityServicesADT new=calloc(1, sizeof(cityServicesCDT));
    if(!is_validAlloc(new)){
        return NULL;
    }
    return new;
}

//================================= ADD =================================

Ttype addTypesRec(Ttype types, const char* code, const char* name, int * added){
    int c;
    if (types == NULL || (c = strcasecmp(code, types->code)) < 0)
    {
        Ttype new = malloc(sizeof(typeNode));
        new->code = strdup(code);
        new->name = strdup(name);
        new->next = types;
        *added = 1;
        return new;
    }
    if(c > 0){
        types->next = addTypesRec(types->next, code, name, added);
    }
    return types;
}

int addTypes(cityServicesADT cs, const char* code, const char* name){
    int added = 0;
    cs->types = addTypesRec(cs->types, code, name, &added);
    return added;
}

