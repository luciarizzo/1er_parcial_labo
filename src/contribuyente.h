/*
 * contribuyente.h
 *
 *  Created on: 13 may. 2021
 *      Author: lucia
 */

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_
#define MAX 50

typedef struct {
	char nombre[MAX];
	char apellido[MAX];
	int cuil;
	int idContribuyente;
	int isEmpty;
}Contribuyente;



int inicializarContribuyente(Contribuyente arrayContribuyente[], int lengArray);
int buscarLibre(Contribuyente arrayContribuyente[], int lengArray, int *posicion);
int ingresarDatos(Contribuyente arrayContribuyente[], int lengArray, int* contadorId);


#endif /* CONTRIBUYENTE_H_ */
