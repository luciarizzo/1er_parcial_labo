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
//void mostrarunContribuyente(Contribuyente arrayContribuyente[]);
int buscarContribuyente(Contribuyente arrayContribuyente[], int lengArray);
int modificarDatos(Contribuyente arrayContribuyente[], int lengArray);


#endif /* CONTRIBUYENTE_H_ */
