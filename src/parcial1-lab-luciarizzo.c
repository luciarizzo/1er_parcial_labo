/*
 ============================================================================
 Name        : parcial1-lab-luciarizzo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Se necesita administrar la recaudacion de impuestos de los contribuyentes, y para ello
se deberá realizar un programa de acuerdo a lo siguiente:
Contará con el siguiente menú:
1) Alta de Contribuyente: Se da de alta un contribuyente con nombre, apellido, y c.u.i.l. Se
generará un ID único (comenzando en 1000) para este contribuyente que se imprimirá por
pantalla si el alta es correcta.
2) Modificar datos del contribuyente: Se ingresa el ID del contribuyente y se permitirá
cambiar el nombre, el apellido y el c.u.i.l.
3) Baja de contribuyente: Se ingresa el ID del contribuyente y se listarán todas las
recaudaciones de dicho contribuyente. Luego se preguntará si se quiere confirmar la
eliminación, la cual implicará la eliminación de todos las recaudaciones y del contribuyente.
4) Recaudación: Permitirá crear una nueva recaudación. Se pedirán los siguientes datos: ID
de contribuyente, mes, tipo (1-ARBA, 2-IIBB, 3-GANANCIAS) e importe. Se generará
automáticamente un identificador numérico (comenzando en 100) para la recaudación y se
imprimirá en pantalla.
5) Refinanciar Recaudación: Se pedirá el ID de la recaudación y se imprimirá la información
del contribuyente al que pertenece, luego se pedirá confirmación para cambiarse de estado y
se cambiará al estado "refinanciar".
6) Saldar Recaudación: Se pedirá el ID de la recaudación y se imprimirá la información del
contribuyente al que pertenece, luego se pedirá confirmación para cambiarse de estado y se
cambiará al estado "saldado".
7) Imprimir Contribuyentes: Se imprimirá una lista de los contribuyentes con todos sus datos
junto con las Recaudaciones que posee.
8) Imprimir Recaudación: Se imprimirá una lista de las Recaudaciones con estado
“saldadas” con todos sus datos junto con el c.u.i.l. y nombre del contribuyente
correspondiente.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "contribuyente.h"
#define TAM 50


typedef struct {
	int idContribuyente;
	int mes;
	int tipo;
	float importe;
	int isEmpty;
}Recaudacion;

int main(void) {
	int opcion;
	int id = 1000;
	Contribuyente arrayContribuyente[50];
	inicializarContribuyente(arrayContribuyente, TAM);
	do{
		printf("\n Elija una de las siguientes opciones, para salir, oprima un numero que no esté en este menú:"
				"\n 1. Alta del Contribuyente"
				"\n 2. Modificar Datos del Contribuyente"
				"\n 3. Baja de contribuyente"
				"\n 4. Creación nueva recaudación"
				"\n 5. Refinanciar recaudación"
				"\n 6. Saldar recaudación"
				"\n 7. Imprimir contribuyentes"
				"\n 8. Imprimir recaudación");
		scanf("%d", &opcion);
		switch(opcion){
		case 1:
			if(ingresarDatos(arrayContribuyente, TAM, &id) == 1){
				ingresarDatos(arrayContribuyente, TAM, &id);
			}
			else{
				break;
			}
			break;
		case 2:
			modificarDatos(arrayContribuyente, TAM);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		}
	}while(opcion > 0 && opcion < 9);

}



