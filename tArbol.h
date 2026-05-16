#ifndef UNTITLED6_TARBOL_H
#define UNTITLED6_TARBOL_H
#include "tDios.h"

typedef struct Nodo {
    tDios dios;
    struct Nodo *izq;
    struct Nodo *der;
} tNodo;

typedef tNodo* tArbol;

void crearArbolVacio(tArbol *arbol);

void construirArbol(tArbol* arb, tArbol izq, tDios dios, tArbol der);

int existeDios(tArbol arbol, char *nombre);

int esPadre(tArbol arbol, char *padre, char *hijo);

void mostrarElemento(tArbol arbol);

void imprimirPreorden(tArbol arbol);

#endif
