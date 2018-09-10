#include "pila.h"
#include <stdlib.h>

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// ...

pila_t* pila_crear(void) {

	pila_t* pila = malloc(sizeof(pila_t));

	if (pila == NULL) {
        return NULL;
    }

	return pila;

}

void pila_destruir(pila_t *pila) {
	while (!pila_esta_vacia(*pila)) {


	}

	free(pila->*datos);
	free(pila);

}

bool pila_esta_vacia(const pila_t *pila) {

	if (pila->cantidad > 0) return true;

	return false;
}

bool pila_apilar(pila_t *pila, void* valor) {

	if (pila->cantidad = pila->capacidad){

		if (!pila_redimensionar(pila)) return false;
	}

	pila->datos[cantidad-1]  = valor;
	pila->cantidad ++;

}

void* pila_ver_tope(const pila_t *pila){

	if (pila_esta_vacia) return NULL;

	return pila->datos[cantidad-1];


}

void* pila_desapilar(pila_t *pila){

	if (pila_esta_vacia) return NULL;

	int valor = pila->datos[cantidad-1];
	pila->datos[cantidad-1] = NULL;
	pila->cantidad --;
	if ((pila->cantidad)/4 = pila->capacidad) pila_redimensionar(pila);

	return pila->datos[cantidad];


}