#include <stdio.h>
#include <string.h>
#include "tDios.h"

void crearDios(tDios* dios, char nombre[20], char descripcion[80]) {
    strcpy(dios->nombre, nombre);
    strcpy(dios->descripcion, descripcion);
}

void mostrarDios(const tDios *d) {
    printf("%s\n", d->nombre);
}

int esIgualDios(char* d1, char* d2) {
    return (strcmp(d1, d2) == 0);
}

void asignarDios(tDios *d1, tDios d2) {
    strcpy(d1->nombre, d2.nombre);
    strcpy(d1->descripcion, d2.descripcion);
}
