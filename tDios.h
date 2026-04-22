#ifndef UNTITLED6_TDIOS_H
#define UNTITLED6_TDIOS_H

typedef struct tDios {
    char nombre[20];
    char descripcion[80];
} tDios;

void crearDios(tDios* dios, char* nombre, char* descripcion);

int esIgualDios(char* d1, char* d2);

#endif