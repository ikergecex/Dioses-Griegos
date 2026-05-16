#ifndef UNTITLED6_TDIOS_H
#define UNTITLED6_TDIOS_H

typedef struct tDios {
    char nombre[20];
    char descripcion[80];
} tDios;

void crearDios(tDios* dios, char* nombre, char* descripcion);

void mostrarDios(const tDios *d);

int esIgualDios(char* d1, char* d2);

void asignarDios(tDios *d1, tDios d2);

#endif
