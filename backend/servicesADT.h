#ifndef CITY_SERVICES_ADT_H
#define CITY_SERVICES_ADT_H


//TAD opaco
typedef struct cityServicesCDT *cityServicesADT;

cityServicesADT newServiceADT();

int addTypes(cityServicesADT cs, const char* code, const char* name);

#endif
