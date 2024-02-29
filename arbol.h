#ifndef __ARBOL_H
#define __ARBOL_H

#include <stdbool.h>
#include "arbol.h"

/*      Definiciones para un Arbol binario. Un Arbol es un puntero a un NodoArbol
        - Cada nodo contiene:
                + info (un char)
                + izq (puntero a un nodoSrbol)
                + der (puntero a un nodoArbol)
*/

typedef char tipoInfo;

typedef struct NodoArbol
{
        tipoInfo info;
        struct NodoArbol *izq, *der;
} NodoArbol;

typedef NodoArbol *Arbol;

Arbol creaNodo(tipoInfo info);

void preOrden(Arbol raiz);
void enOrden(Arbol raiz);
void postOrden(Arbol raiz);
void amplitud(Arbol raiz);

int altura(Arbol raiz);
int numNodos(Arbol raiz);
Arbol anula(Arbol raiz);
int sustituye(Arbol raiz, tipoInfo x, tipoInfo y);
int numNodosHoja(Arbol raiz);
int numNodosInternos(Arbol raiz);
int numHijoUnico(Arbol raiz);
Arbol buscarMax(Arbol raiz);
Arbol buscarMin(Arbol raiz);
int similares(Arbol r1, Arbol r2);
int equivalentes(Arbol r1, Arbol r2);
Arbol especular(Arbol raiz);

bool esHoja(Arbol raiz);      // Funcion que verifica si un nodo es hoja
Arbol genArbol(char *cadena); // Funcion que genera un arbol algebraico a partir de una cadena en notación postfija
int evaluar (Arbol raiz); // Funcion que evalua un arbol algebraico

bool esOperador(char c); // Funcion que verifica si un caracter es un operador
#endif
