#include <stdio.h>
#include <string.h>
#include "arbol.h"

int main(void)
{
  Arbol arbol;
  char ex_postfija[10];

  /* Generación del árbol algebraico */
  strcpy(ex_postfija, "AB+CDE+**\0");

  printf(" ============== Generacion del arbol algeebraico: AB+CDE+** ==============\n");
  arbol = genArbol(ex_postfija);

  /* Recorrido en amplitud o por niveles del árbol algebraico generado*/
  printf("Recorrido en amplitud: ");
  amplitud(arbol);
  printf("\n");
  /* Aplicación de algunas operaciones y recorridos al árbol ejemplo */
  printf("Recorrido en PRE_ORDEN: ");
  preOrden(arbol);
  printf("\n");
  printf("Recorrido en ORDEN: ");
  enOrden(arbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(arbol);
  printf("\n");
  printf("Debe coinicidir con la expresion postfija inicial\n");

  printf("El arbol tiene %d nodos \n", numNodos(arbol));
  printf("y altura: %d\n", altura(arbol));

  printf("El arbol tiene %d nodos\n", numNodos(arbol));
  arbol = anula(arbol);
  printf("Despues de anula el arbol queda vacio, por tanto la altura ser� 0.\n");
  if (altura(arbol) != -1) // Cuidado con definici�n de altura
    printf("El �rbol no se ha anulado correctamente\n");
  else
    printf("O.K. Parece que la operaci�n anula funciona!!!\n");

  /* Evaluación de un árbol algebraico: operandos entre '0' y '9'*/

  strcpy(ex_postfija, "23+713+**\0");
  arbol = genArbol(ex_postfija);
  printf("Evalua: %d\n", evaluar(arbol));
  printf("Recorrido en PRE_ORDEN (prefija): ");
  preOrden(arbol);
  printf("\n");
  printf("Recorrido en ORDEN(infija): ");
  enOrden(arbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN(postfija): ");
  postOrden(arbol);
  printf("\n");

  /* Aplicar a este arbol las funciones del ejercicio 2 */

  return 1;
}
