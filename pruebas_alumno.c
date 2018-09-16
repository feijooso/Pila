#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_pila_vacia(){

	printf("PRUEBAS CON PILA VACIA\n");

	pila_t *p = pila_crear();

	print_test("La pila fue creada", p != NULL);
    print_test("La pila está vacía", pila_esta_vacia(p));
    print_test("Intento desapilar", pila_desapilar(p) == NULL);
    print_test("Intento ver tope", pila_ver_tope(p) == NULL);
    pila_destruir(p);
    print_test("La pila fue destruida", true);

}



void prueba_pila_con_elementos(){

	printf("PRUEBAS DE APILAR\n");

	pila_t *p1 = pila_crear();

    int a = 2;
    print_test("Se apilo un elemento de tipo int", pila_apilar(p1,&a));
    char b = 'b';
    print_test("Se apilo un elemento de tipo char", pila_apilar(p1,&b));
    print_test("Se apilo un elemento de tipo int", pila_apilar(p1,&a));
    print_test("Se apilo un elemento de tipo int", pila_apilar(p1,&a));
    print_test("Se apilo un elemento de tipo int", pila_apilar(p1,&a));
    print_test("Se apilo NULL", pila_apilar(p1,NULL));

    printf("PRUEBAS DE DESAPILAR\n");

    print_test("Se desapilo el tope", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("Se desapilo el tope", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("Se desapilo el tope", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("Se desapilo el tope", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("Se desapilo el tope", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("Se desapilo el tope", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("La pila está vacía", pila_esta_vacia(p1));
    print_test("Intento desapilar", pila_desapilar(p1) == NULL);
    print_test("Intento ver tope", pila_ver_tope(p1) == NULL);


}

void pruebas_pila_volumen(int volumen){

	printf("PRUEBAS VOLUMEN\n");

    int* vector = malloc(volumen * sizeof(int));

    //pruebo apilar:
    bool ok = true; 
    for(int i = 0; i < volumen; i++) {
    	vector[i] = i;
    	ok &= pila_apilar(p1, &vector[i]);
    }
    print_test("Se apilaron todos los elementos", ok);

    //pruebo desapilar:
    ok = true;
    for(int i = 0; i < volumen; i++) {
    	ok &= pila_desapilar(p1);
    }
    print_test("Se desapilaron todos los elementos", ok);

    free(vector);

    pila_destruir(p1);

}

void pruebas_pila_alumno() {

	prueba_pila_vacia();
	prueba_pila_con_elementos();
	pruebas_pila_volumen():

}
