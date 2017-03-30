#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM_INICIAL 10

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
bool pila_redimensionar(pila_t *pila, size_t tam_nuevo);

pila_t* pila_crear(void){
	pila_t* pila = malloc(sizeof(pila_t));
	if (pila == NULL){
		return NULL;
	}
	pila->datos = malloc(TAM_INICIAL * sizeof(void*));
	if (pila->datos == NULL){
		free(pila);
		return NULL;
	}
	pila->cantidad = 0;
	pila->capacidad = TAM_INICIAL;
	return pila;
}

void pila_destruir(pila_t *pila){
	free(pila->datos);
	free(pila);
}

bool pila_esta_vacia(const pila_t *pila){
	if (pila->cantidad == 0){
		return true;
	}
	return false;
}

bool pila_apilar(pila_t *pila, void* valor){
	if (valor == NULL){
		return true;
	}
	if (pila->capacidad == 0){
		return false;
	}
	if ((pila->cantidad) >= pila->capacidad){
		pila_redimensionar(pila, 2);
	}
	pila->datos[pila->cantidad-1] = valor;
	pila->cantidad += 1;
	return true;
}

void* pila_ver_tope(const pila_t *pila){
	if (pila->cantidad == 0){
		return NULL;
	}
	void *tope = pila->datos[pila->cantidad - 1];
	return tope;
}

void* pila_desapilar(pila_t *pila){
	if (pila->cantidad == 0){
		return NULL;
	}
	void *valor = pila->datos[pila->cantidad-1];
	pila->datos[pila->cantidad-1] = NULL;
	pila->cantidad -= 1;
	if (pila->cantidad <= (pila->capacidad)/4){
		pila_redimensionar(pila,1/4);
	}
	return valor;
}

bool pila_redimensionar(pila_t *pila, size_t tam_nuevo){
	size_t tamanio = TAM_INICIAL * tam_nuevo;
	void **aux = realloc(pila->datos, tamanio * sizeof(void*));
	if (aux == NULL){
		return false;
	}
	pila->datos = aux;
	pila->capacidad = tamanio;
	return true;
}

/* Funciones que no pertenecen al TDA Pila. Usadas para las pruebas*/

void mostrar_capacidad_cantidad(pila_t *pila){
	printf("Capacidad: %zu\nCantidad: %zu\n", pila->capacidad, pila->cantidad);
	return;
}
