#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tDios.h"
#include "tArbol.h"

int main(void) {
    tArbol vacio, raiz, izq, der;
    crearArbolVacio(&vacio);
    tDios d;

    crearDios(&d, "Dedalo", "fundador de Atenas");
    construirArbol(&izq, vacio, d, vacio);

    crearDios(&d, "Atenea", "diosa de la civilización, la sabiduría, la razón, la inteligencia y la estrategia de combate");
    construirArbol(&raiz, izq, d, vacio);

    crearDios(&d, "Orfeo", "músico y poeta legendario, considerado uno de los músicos más talentosos de la mitología griega");
    construirArbol(&izq, vacio, d, vacio);

    crearDios(&d, "Aristeo", "semidiós asociado con la agricultura, la apicultura y la cría de animales");
    construirArbol(&der, vacio, d, vacio);

    crearDios(&d, "Apolo", "dios del sol");
    construirArbol(&der, izq, d, der);

    crearDios(&d, "Zeus", "dios supremo, líder de los 12 dioses olímpicos");
    construirArbol(&raiz, raiz, d, der);

    crearDios(&d, "Hefeso", "dios de la forja y del fuego, de los herreros, de los artesanos y los escultores");
    construirArbol(&izq, vacio, d, vacio);

    crearDios(&d, "Ares", "dios de la guerra, de la brutalidad y los horrores de las batallas");
    construirArbol(&der, vacio, d, vacio);

    crearDios(&d, "Hera", "diosa del matrimonio, las mujeres, el cielo y las estrellas");
    construirArbol(&der, izq, d, der);

    crearDios(&d, "Cronos", "dios del tiempo");
    construirArbol(&raiz, raiz, d, der);


    printf("Introduce el nombre del dios que quieres buscar: ");
    char nombre[20];
    fgets(nombre, 20, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    if (existeDios(raiz, nombre)) {
        printf("El dios %s SI existe\n", nombre);
    }
    else printf("El dios %s NO existe\n", nombre);

    char padre[20], hijo[20];
    printf("\nComprueba si un dios es padre/madre de otro dios\n");
    printf("Nombre padre: ");
    fgets(padre, 20, stdin);
    padre[strcspn(padre, "\n")] = '\0';
    printf("Nombre hijo: ");
    fgets(hijo, 20, stdin);
    hijo[strcspn(hijo, "\n")] = '\0';
    if (esPadre(raiz, padre, hijo)) {
        printf("%s SI es padre de %s\n", padre, hijo);
    }
    else printf("%s NO es padre de %s\n", padre, hijo);

    imprimirPreorden(raiz);

    return 0;
}
