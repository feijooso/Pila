#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_pila_alumno() {

	printf("PRUEBAS CON PILA VACIA\n");

	pila_t *p = pila_crear();
	print_test("La pila fue creada", p != NULL);
    print_test("La pila está vacía", pila_esta_vacia(p));
    print_test("Intento desapilar", pila_desapilar(p) == NULL);
    print_test("Intento ver tope", pila_ver_tope(p) == NULL);
    pila_destruir(p);
    print_test("La pila fue destruida", true);

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

    print_test("Se desapilo el primer elemento", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("Se desapilo el segundo elemento", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("Se desapilo el tercer elemento", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("Se desapilo el cuarto elemento", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("Se desapilo el quinto elemento", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("Se desapilo el sexto elemento", pila_ver_tope(p1) == pila_desapilar(p1));
    print_test("La pila está vacía", pila_esta_vacia(p1));
    print_test("Intento desapilar", pila_desapilar(p1) == NULL);
    print_test("Intento ver tope", pila_ver_tope(p1) == NULL);


    printf("PRUEBAS VOLUMEN\n");

    int* vector = malloc(100 * sizeof(int));

    for(int i = 0; i < 100; i++) {
    	vector[i] = i;
    	pila_apilar(p1, &vector[i]);
    	print_test("Se apilo correctamente", pila_ver_tope(p1) == &vector[i]);
    }

    free(vector);

    pila_destruir(p1);







}
