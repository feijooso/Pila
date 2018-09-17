#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_pila_vacia(){

	pila_t *pila = pila_crear();

	printf("PRUEBAS CON PILA VACIA\n");

	print_test("La pila fue creada", pila != NULL);
    print_test("La pila está vacía", pila_esta_vacia(pila));
    print_test("Intento desapilar", pila_desapilar(pila) == NULL);
    print_test("Intento ver tope", pila_ver_tope(pila) == NULL);

	pila_destruir(pila);
    print_test("La pila fue destruida", true);


}



void prueba_pila_con_elementos(){

	pila_t *pila = pila_crear();


	printf("PRUEBAS DE APILAR\n");

    int a = 2;
    print_test("Se apilo un elemento de tipo int", pila_apilar(pila,&a));
    char b = 'b';
    print_test("Se apilo un elemento de tipo char", pila_apilar(pila,&b));
    print_test("Se apilo un elemento de tipo int", pila_apilar(pila,&a));
    print_test("Se apilo un elemento de tipo int", pila_apilar(pila,&a));
    print_test("Se apilo un elemento de tipo int", pila_apilar(pila,&a));
    void* c = NULL;
    print_test("Se apilo NULL", pila_apilar(pila,&c));

    printf("PRUEBAS DE DESAPILAR\n");

    print_test("Se desapilo el tope", pila_desapilar(pila) == &c);
    print_test("Veo el nuevo tope", pila_ver_tope(pila) == &a);
    print_test("Se desapilo el tope", pila_desapilar(pila) == &a);
    print_test("Veo el nuevo tope", pila_ver_tope(pila) == &a);
    print_test("Se desapilo el tope", pila_desapilar(pila) == &a);
    print_test("Veo el nuevo tope", pila_ver_tope(pila) == &a);
    print_test("Se desapilo el tope", pila_desapilar(pila) == &a);
    print_test("Veo el nuevo tope", pila_ver_tope(pila) == &b);
    print_test("Se desapilo el tope", pila_desapilar(pila) == &b);
    print_test("Veo el nuevo tope", pila_ver_tope(pila) == &a);
    print_test("Se desapilo el tope", pila_desapilar(pila) == &a);
    print_test("La pila está vacía", pila_esta_vacia(pila));
    print_test("Intento desapilar", pila_desapilar(pila) == NULL);
    print_test("Intento ver tope", pila_ver_tope(pila) == NULL);

    pila_destruir(pila);
    print_test("La pila fue destruida", true);

}

void pruebas_pila_volumen(int volumen){

	pila_t *pila = pila_crear();

	printf("PRUEBAS VOLUMEN\n");

    int* vector = malloc(volumen * sizeof(int));

    //pruebo apilar:
    bool ok = true; 
    for(int i = 0; i < volumen; i++) {
    	vector[i] = i;
    	ok &= pila_apilar(pila, &vector[i]);
    }
    print_test("Se apilaron todos los elementos", ok);

    //pruebo desapilar:
    ok = true;
    for(int i = 0; i < volumen; i++) {
    	ok &= (pila_ver_tope(pila) == pila_desapilar(pila));
    }
    print_test("Se desapilaron todos los elementos", ok);

    free(vector);

    pila_destruir(pila);
    print_test("La pila fue destruida", true);

}

void pruebas_pila_alumno() {

	prueba_pila_vacia();
    prueba_pila_con_elementos();
	pruebas_pila_volumen(100);

}
