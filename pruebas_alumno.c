#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

/* Pruebas para una pila de TAM_INICIAL 0 */

void pruebas_pila_nula(){
    printf("INICIO DE PRUEBAS CON PILA DE TAMANIO 0\n");

    /* Declaro las variables a utilizar, elijo variables de distintos tipos*/
    pila_t* pila = pila_crear();
    
    char cadena = "Esto es una prueba\n";
    char *pcadena;
    pcadena = &cadena;
    int numero = 137;
    int *pnumero;
    pnumero = &numero;
    int array[3];
    int *parray;
    parray = &array;
    
    /* Inicio de pruebas */
    print_test("Crear pila con tamanio 0", pila != NULL);
    print_test("Preguntar si la pila esta vacia", pila_esta_vacia(pila) == 0);
    print_test("Ver el tope de una pila con tamanio 0", pila_ver_tope(pila) == NULL);
    
    /* Pruebo que guardar algo en una pila de capacidad 0 de false*/
    print_test("Guardar char en una pila de tamanio 0", pila_apilar(pila,&pcadena))
    print_test("Guardar int en una pila de tamanio 0", pila_apilar(pila,&pnumero))
	print_test("Guardar array de int en una pila de tamanio 0", pila_apilar(pila,&parray))
	
	/* Pruebo desapilar una pila de capacidad 0 */
	print_test("Desapilar en una pila de tamanio 0",pila_desapilar(pila) == NULL)
 }

/* Ejecutar las pruebas */
int main(){
	pruebas_pila_nula();
	
	return failure_count() > 0;
}	
