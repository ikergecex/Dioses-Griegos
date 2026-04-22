#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tDios.h"
#include "tArbol.h"

int main(void) {
    tArbol nodos[10];
    tDios dioses[10] = {
        {"Cronos", "dios del tiempo"},
        {"Zeus", "dios supremo, líder de los 12 dioses olímpicos"},
        {"Hera", "diosa del matrimonio, las mujeres, el cielo y las estrellas"},
        {"Ares", "dios de la guerra, de la brutalidad y los horrores de las batallas"},
        {"Hefeso", "dios de la forja y del fuego, de los herreros, de los artesanos y los escultores"},
        {"Apolo", "dios del sol"},
        {"Atenea", "diosa de la civilización, la sabiduría, la razón, la inteligencia y la estrategia de combate"},
        {"Orfeo", "músico y poeta legendario, considerado uno de los músicos más talentosos de la mitología griega"},
        {"Aristeo", "semidiós asociado con la agricultura, la apicultura y la cría de animales"},
        {"Dédalo", "fundador de Atenas"}
    };

    for (int i = 0; i < 10; i++) {
        crearArbolVacio(&nodos[i]);
    }

    construirArbol(&nodos[7], NULL, dioses[7], NULL); // Orfeo
    construirArbol(&nodos[8], NULL, dioses[8], NULL); // Aristeo
    construirArbol(&nodos[9], NULL, dioses[9], NULL); // Dédalo

    construirArbol(&nodos[6], nodos[9], dioses[6], NULL); // Atenea
    construirArbol(&nodos[5], nodos[7], dioses[5], nodos[8]); // Apolo
    construirArbol(&nodos[1], nodos[6], dioses[1], nodos[5]); // Zeus

    construirArbol(&nodos[4], NULL, dioses[4], NULL); //Hefeso
    construirArbol(&nodos[3], NULL, dioses[3], NULL); //Ares

    construirArbol(&nodos[2], nodos[4], dioses[2], nodos[3]); // Hera
    construirArbol(&nodos[0], nodos[1], dioses[0], nodos[2]); // Cronos

    tArbol arbol = nodos[0];

    printf("Introduce el nombre del dios que quieres buscar: ");
    char nombre[20];
    fgets(nombre, 20, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    if (existeDios(arbol, nombre)) {
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
    if (esPadre(arbol, padre, hijo)) {
        printf("%s SI es padre de %s\n", padre, hijo);
    }
    else printf("%s NO es padre de %s\n", padre, hijo);

    imprimirPreorden(arbol);

    return 0;
}