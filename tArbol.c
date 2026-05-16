#include <stdio.h>
#include <string.h>
#include "tArbol.h"

#include <stdlib.h>

void crearArbolVacio(tArbol *arbol) {
    *arbol = NULL;
}

void construirArbol(tArbol* arb, tArbol izq, tDios dios, tArbol der) {
    *arb = (tArbol) malloc(sizeof(tNodo));
    asignarDios(&(*arb)->dios, dios);
    (*arb)->izq = izq;
    (*arb)->der = der;
}

int existeDios(tArbol arbol, char *nombre) {
    if (arbol == NULL) {
        return 0;
    }
    if (esIgualDios(arbol->dios.nombre, nombre)) {
        return 1;
    }
    return existeDios(arbol->izq, nombre) || existeDios(arbol->der, nombre);
}

int esPadre(tArbol arbol, char *padre, char *hijo) {
    if (arbol == NULL) {
        return 0;
    }
    if (esIgualDios(arbol->dios.nombre, padre)) {
        if (arbol->izq != NULL && esIgualDios(arbol->izq->dios.nombre, hijo)) {
            return 1;
            }
        if (arbol->der != NULL && esIgualDios(arbol->der->dios.nombre, hijo)) {
            return 1;
            }
    }
    return esPadre(arbol->izq, padre, hijo) || esPadre(arbol->der, padre, hijo);
}

void mostrarElemento(tArbol arbol) {
    if (arbol != NULL) {
        printf("%s", arbol->dios.nombre);
    }
}

void imprimirPreorden(tArbol arbol) {
    if (arbol != NULL) {
        mostrarElemento(arbol);
        printf(" ");
        imprimirPreorden(arbol->izq);
        imprimirPreorden(arbol->der);
    }
}
