#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

/* Pruebas para una pila de TAM_INICIAL 0 */

void pruebas_pila_alumno(){
    printf("INICIO DE PRUEBAS CON PILA DE TAMANIO 0\n");

    /* Declaro las variables a utilizar, elijo variables de distintos tipos*/
    pila_t* pila = pila_crear();
    int a[1];
    int b[2];
    int c[3];
    int d[4];
    int e[5];
    int f[6];
    int g[7];
    int h[8];
    int i[9];
    char j[1];
    char k[1];
    
    /* Inicio de pruebas */
    print_test("Crear pila con tamanio 10", pila != NULL);
    print_test("Preguntar si la pila esta vacia", pila_esta_vacia(pila) == 1);
    print_test("El tope de una pila vacia es NULL", pila_ver_tope(pila) == NULL);
    
    /* Pruebo que guardar algo en una pila de capacidad 10*/
    print_test("Guardar int", pila_apilar(pila,a));
    mostrar_capacidad_cantidad(pila);
    print_test("Guardar int", pila_apilar(pila,b));
    mostrar_capacidad_cantidad(pila);
    print_test("Guardar int", pila_apilar(pila,c));
	mostrar_capacidad_cantidad(pila);
    print_test("Guardar int", pila_apilar(pila,d));
    mostrar_capacidad_cantidad(pila);
    print_test("Guardar int", pila_apilar(pila,e));
    mostrar_capacidad_cantidad(pila);
    print_test("Guardar int", pila_apilar(pila,f));
    mostrar_capacidad_cantidad(pila);
    print_test("Guardar int", pila_apilar(pila,g));
    mostrar_capacidad_cantidad(pila);
    print_test("Guardar int", pila_apilar(pila,h));
    mostrar_capacidad_cantidad(pila);
    print_test("Guardar int", pila_apilar(pila,i));
    mostrar_capacidad_cantidad(pila);
    print_test("Guardar char", pila_apilar(pila,j));
    mostrar_capacidad_cantidad(pila);
	
	/* Pruebo agregar un elemento mas para ver si cambia la capacidad */
	print_test("Guardar char", pila_apilar(pila,k));
    mostrar_capacidad_cantidad(pila);
    
    /* Pruebo ver el primer elemento y verifico que no lo desapile.*/
    print_test("Ver primer elemento de la pila",pila_ver_tope(pila));
    mostrar_capacidad_cantidad(pila);
	
	/* Pruebo desapilar un elemento de una pila vacia */
	print_test("Desapilar un elemento",pila_desapilar(pila) == k);
	mostrar_capacidad_cantidad(pila);
	print_test("Desapilar un elemento",pila_desapilar(pila) == j);
	mostrar_capacidad_cantidad(pila);
	print_test("Desapilar un elemento",pila_desapilar(pila) == i);
	mostrar_capacidad_cantidad(pila);
	print_test("Desapilar un elemento",pila_desapilar(pila) == h);
	mostrar_capacidad_cantidad(pila);
	print_test("Desapilar un elemento",pila_desapilar(pila) == g);
	mostrar_capacidad_cantidad(pila);
	print_test("Desapilar un elemento",pila_desapilar(pila) == f);
	mostrar_capacidad_cantidad(pila);
	print_test("Desapilar un elemento",pila_desapilar(pila) == e);
	mostrar_capacidad_cantidad(pila);
	print_test("Desapilar un elemento",pila_desapilar(pila) == d);
	mostrar_capacidad_cantidad(pila);
	print_test("Desapilar un elemento",pila_desapilar(pila) == c);
	mostrar_capacidad_cantidad(pila);
	print_test("Desapilar un elemento",pila_desapilar(pila) == b);
	mostrar_capacidad_cantidad(pila);
	print_test("Desapilar un elemento",pila_desapilar(pila) == a);
	mostrar_capacidad_cantidad(pila);

	/* Pruebo que no se pueda desapilar una pila vacia*/
	print_test("Desapilar un elemento de una pila vacia da false",pila_desapilar(pila) == 0);
	mostrar_capacidad_cantidad(pila);
	
	/* Pruebo destruir la pila*/
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
}
