#ifndef CITY_SERVICES_ADT_H
#define CITY_SERVICES_ADT_H


//TAD opaco
typedef struct cityServicesCDT *cityServicesADT;

/*
    *Crea un CSADT
*/
cityServicesADT newServiceADT();

/*
    *Recibe un csADT, el nombre y codigo de un reclamo, 
    *Debe agregarlo de manera alfabetica y retornar 1 si lo agrego, sino 0
*/
int addTypes(cityServicesADT cs, const char* code, const char* name);

#endif
