#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
#include "pila.h"

//
// Reserva de memoria para un nuevo nodo de árbol binario
//
Arbol creaNodo(tipoInfo info)
{
  NodoArbol *nuevo;

  //   nuevo =(NodoArbol *)calloc(1, sizeof(NodoArbol));
  if ((nuevo = (NodoArbol *)malloc(sizeof(NodoArbol))) == NULL)
    return NULL;
  else
  {
    nuevo->info = info;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
  }
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario!!!
//

void amplitud(Arbol raiz)
{
  Cola c;
  NodoArbol *nodo;
  colaCreaVacia(&c);
  nodo = raiz;
  if (raiz != NULL)
    colaInserta(nodo, &c);
  while (!colaVacia(&c))
  {
    nodo = (Arbol)colaSuprime(&c);
    printf(" %c ", nodo->info);
    if (nodo->izq != NULL)
      colaInserta(nodo->izq, &c);
    if (nodo->der != NULL)
      colaInserta(nodo->der, &c);
  }
}
//
// Recorridos en profundidad "recursivos"
//
void preOrden(Arbol raiz)
{
  if (raiz != NULL)
  {
    printf("%c ", raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
  }
}
void enOrden(Arbol raiz)
{
  if (raiz != NULL)
  {
    enOrden(raiz->izq);
    printf("%c ", raiz->info);
    enOrden(raiz->der);
  }
}
void postOrden(Arbol raiz)
{
  if (raiz != NULL)
  {
    postOrden(raiz->izq);
    postOrden(raiz->der);
    printf("%c ", raiz->info);
  }
}
//
// Altura de un árbol binario
//
int altura(Arbol raiz)
{
  int altIzq, altDer; // alturas de los subárboles izquierdo y derecho
  if (raiz == NULL)
    return -1;
  else
  {
    altIzq = altura(raiz->izq);
    altDer = altura(raiz->der);
    if (altIzq > altDer)
      return altIzq + 1;
    else
      return altDer + 1;
  }
}
//
// Número de nodos de un árbol binario
//
int numNodos(Arbol raiz)
{
  if (raiz == NULL)
    return 0;
  else
    return 1 + numNodos(raiz->izq) + numNodos(raiz->der);
}
//
// Anulación de un árbol binario
//
Arbol anula(Arbol raiz)
{
  if (raiz != NULL)
  {
    anula(raiz->izq);
    anula(raiz->der);
    free(raiz);
  }
  return NULL;
}
//
// Sustitución de un valor por otro en un árbol binario
//
int sustituye(Arbol raiz, tipoInfo x, tipoInfo y)
{
  if (raiz != NULL)
  {
    if (raiz->info == x)
    {
      raiz->info = y;
      return 1 + sustituye(raiz->izq, x, y) + sustituye(raiz->der, x, y);
    }
    else
    {
      return 0 + sustituye(raiz->izq, x, y) + sustituye(raiz->der, x, y);
    }
  }
  else
  {
    return 0;
  }
}
//
// Número de nodos hoja de un árbol binario
//
int numNodosHoja(Arbol raiz)
{
  if (raiz == NULL)
    return 0;
  else if (raiz->izq == NULL && raiz->der == NULL)
    return 1;
  else
    return numNodosHoja(raiz->izq) + numNodosHoja(raiz->der);
}
//
// Número de nodos internos de un árbol binario
//
int numNodosInternos(Arbol raiz)
{
  if (raiz == NULL)
    return 0;
  else if (raiz->izq == NULL && raiz->der == NULL)
    return 0;
  else
    return 1 + numNodosInternos(raiz->izq) + numNodosInternos(raiz->der);
}
//
// Número de nodos con un solo hijo de un árbol binario
//
int numHijoUnico(Arbol raiz)
{
  if (raiz == NULL)
    return 0;
  else if (raiz->izq == NULL && raiz->der != NULL)
    return 1 + numHijoUnico(raiz->der);
  else if (raiz->izq != NULL && raiz->der == NULL)
    return 1 + numHijoUnico(raiz->izq);
  else
    return numHijoUnico(raiz->izq) + numHijoUnico(raiz->der);
}
//
// Búsqueda del nodo con el valor máximo de un árbol binario sin ordenar
//
Arbol buscarMax(Arbol raiz)
{
  if (raiz == NULL)
    return NULL;

  Arbol max = raiz;
  Arbol max_izq = buscarMax(raiz->izq);
  Arbol max_der = buscarMax(raiz->der);

  if (max_izq != NULL && max_izq->info > max->info)
    max = max_izq;
  if (max_der != NULL && max_der->info > max->info)
    max = max_der;

  return max;
}
//
// Búsqueda del nodo con el valor mínimo de un árbol binario sin ordenar
//
Arbol buscarMin(Arbol raiz)
{
  if (raiz == NULL)
    return NULL;

  Arbol min = raiz;
  Arbol min_izq = buscarMin(raiz->izq);
  Arbol min_der = buscarMin(raiz->der);

  if (min_izq != NULL && min_izq->info < min->info)
    min = min_izq;
  if (min_der != NULL && min_der->info < min->info)
    min = min_der;

  return min;
}
//
// Comparación de dos árboles binarios
//
int similares(Arbol r1, Arbol r2)
{
  if (r1 == NULL && r2 == NULL) // Si ambos son nulos, son similares
  {
    return 1;
  }
  if (r1 != NULL && r2 != NULL) // Si ambos no son nulos comprobamos recursivamente
  {
    return similares(r1->izq, r2->izq) && similares(r1->der, r2->der);
  }
  return 0; // Si uno es nulo y el otro, no no son similares
}
//
// Comprobación de dos árboles binarios equivalentes
//
int equivalentes(Arbol r1, Arbol r2)
{
  if (r1 == NULL && r2 == NULL) // Si ambos son nulos, son equivalentes
  {
    return 1;
  }
  if (r1 != NULL && r2 != NULL) // Si ambos no son nulos comprobamos recursivamente
  {
    return r1->info == r2->info && equivalentes(r1->izq, r2->izq) && equivalentes(r1->der, r2->der);
  }
  return 0; // Si uno es nulo y el otro, no no son equivalentes
}
//
// Creación de un árbol binario especular
//
Arbol especular(Arbol raiz)
{
  if (raiz == NULL)
    return NULL;
  Arbol nuevo = creaNodo(raiz->info);
  nuevo->izq = especular(raiz->der);
  nuevo->der = especular(raiz->izq);
  return nuevo;
}
//
// Comprobación de si un nodo es hoja (Verdadero si es hoja, Falso si no lo es)
//
bool esHoja(Arbol raiz)
{
  return raiz != NULL && raiz->izq == NULL && raiz->der == NULL;
}
//
// Generación de un árbol algebraico a partir de una cadena de caracteres en notación postfija
//
Arbol genArbol(char *cadena)
{
  Pila c;
  NodoArbol *nodo;
  pilaCreaVacia(&c);
  printf(" -> Arbol algebraico: ");
  while (*cadena != '\0')
  {
    printf("%c", *cadena);
    if (!esOperador(*cadena)) // Si no es un operador, es un nodo hoja
    {
      nodo = creaNodo(*cadena);
      pilaInserta(nodo, &c); // Inserto el nodo hoja en la cola
    }
    else // Si es un operador, es un nodo interno
    {
      nodo = creaNodo(*cadena);
      nodo->der = (Arbol)pilaSuprime(&c);
      nodo->izq = (Arbol)pilaSuprime(&c);
      pilaInserta(nodo, &c); // Inserto el árbol más izquierdo en la cola para añadirlo más adelante como hijo izquierdo
    }
    cadena++; // Avanzo en la cadena de caracteres
  }
  printf(" creado.. \n");
  return (Arbol)pilaSuprime(&c); // Devuelvo el árbol resultante
}
//
// Comprobación de si un carácter es un operador
//
bool esOperador(char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}
//
// Función que evalúa un árbol algebraico dando su resultado
//
int evaluar(Arbol raiz){
  if(raiz == NULL){ // Si es un árbol vacío devuelvo cero
    return 0;
  }
  if(raiz->izq == NULL && raiz->der == NULL){ // Si es un nodo hoja devuelvo su valor
    return raiz->info - '0';
  }
  int izq = evaluar(raiz->izq);
  int der = evaluar(raiz->der);
  switch(raiz->info){
    case '+': return izq + der;
    case '-': return izq - der;
    case '*': return izq * der;
    case '/': return izq / der;
  }
  return 0;
}