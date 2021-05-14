/*
 * contribuyente.c
 *
 *  Created on: 13 may. 2021
 *      Author: lucia
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include "contribuyente.h"


int inicializarContribuyente(Contribuyente arrayContribuyente[], int lengArray)
{
	int i;
	int retorno;
	retorno = -1;
	if (arrayContribuyente != NULL){
		for(i=0; i < lengArray; i++){
			arrayContribuyente[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarLibre(Contribuyente arrayContribuyente[], int lengArray, int *posicion){
	int retorno;
	if(arrayContribuyente != NULL && posicion != NULL && lengArray > 0){
		int i;
		for(i=0; i < lengArray; i++){
			if (arrayContribuyente[i].isEmpty == 1){
				*posicion = i;
				retorno = 0;
				break;
			} else {
				retorno = -1;
			}
		}
	}
	return retorno;
}


//void mostrarunContribuyente(Contribuyente arrayContribuyente[])

int ingresarDatos(Contribuyente arrayContribuyente[], int lengArray, int* contadorId){
	int posicion;
	char continuar;
	int flag = 0;
	int retorno;
	int i = buscarLibre(arrayContribuyente, MAX, &posicion);
	if (arrayContribuyente != NULL && lengArray > 0 && contadorId != NULL){
			printf("Ingrese nombre contribuyente: \n");
			__fpurge(stdin);
			fgets(arrayContribuyente[i].nombre, 20, stdin);
			printf("Ingrese apellido del contribuyente:\n");
			__fpurge(stdin);
			fgets(arrayContribuyente[i].apellido, 20, stdin);
			printf("Ingrese cuil del contribuyente: \n");
			scanf("%d", &arrayContribuyente[i].cuil);
			arrayContribuyente[i].isEmpty = 0;
			if(flag == 0){
				arrayContribuyente[i].idContribuyente = *contadorId;
			}
			printf(" Alta realizada correctamente");
			printf("Los datos son: \n ID: %d \n NOMBRE: %s \n APELLIDO: %s \n CUIL: %d",
					arrayContribuyente[i].idContribuyente,
					arrayContribuyente[i].nombre,
					arrayContribuyente[i].apellido,
					arrayContribuyente[i].cuil);
			printf("\n ¿Continuará ingresando contribuyentes? S/N\n");
			__fpurge(stdin);
			scanf("%c", &continuar);
			if(continuar == 's'){
				flag = 1;
				(*contadorId)++;
				arrayContribuyente[i].idContribuyente = *contadorId;
				retorno = 1;
			} else {
				retorno = 0;
			}

	}
	return retorno;
}

int buscarContribuyente(Contribuyente arrayContribuyente[], int lengArray)
{
	int retorno = -1;
	int i;
	int id;
	if(arrayContribuyente!=NULL && lengArray>0)
	{
		printf("Ingrese ID");
		scanf("%d", &id);
		for(i=0; i<lengArray; i++)
		{
			if(arrayContribuyente[i].idContribuyente==id && arrayContribuyente[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
			else
			{
				printf("El numero de ID %d no existe", id);
				break;
			}
		}
	}
	return retorno;
}

int modificarDatos(Contribuyente arrayContribuyente[], int lengArray){
	int retorno;
	char respuesta;
	char nuevoNombre[20];
	char nuevoApellido[20];
	int nuevoCuil;
	int i = buscarContribuyente(arrayContribuyente, MAX);
	printf("Los datos son: \n ID: %d \n NOMBRE: %s \n APELLIDO: %s \n CUIL: %d",
			arrayContribuyente[i].idContribuyente,
			arrayContribuyente[i].nombre,
			arrayContribuyente[i].apellido,
			arrayContribuyente[i].cuil);
	printf("¿Qué dato desea cambiar? Ingrese 'N' para Nombre, 'A' para Apellido o 'C' para Cuil:\n");
	__fpurge(stdin);
	scanf("%c", &respuesta);
	if(respuesta == 'N'){
		printf("Ingrese el nuevo nombre: ");
		__fpurge(stdin);
		fgets(nuevoNombre, 20, stdin);
		strcpy(nuevoNombre, arrayContribuyente[i].nombre);
		}
	if(respuesta == 'A'){
		printf("Ingrese el nuevo Apellido: ");
		__fpurge(stdin);
		fgets(nuevoApellido, 20, stdin);
		strcpy(nuevoApellido, arrayContribuyente[i].nombre);
		}
	if(respuesta== 'C'){
		printf("Ingrese el nuevo cuil: ");
		scanf("%d", &nuevoCuil);
		nuevoCuil = arrayContribuyente[i].cuil;
	}

	retorno = 1;
	return retorno;
}


