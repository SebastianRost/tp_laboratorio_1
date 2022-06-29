/*
 * validations.c
 *
 *  Created on: 19 may. 2022
 *      Author: Rost Sebastian
 */
#include "validations.h"
#include "ArrayPassenger.h"
#include <ctype.h>


int validarEnteros(int numero,int desde,int hasta){
    int rtn=0;
    if((numero >= desde && numero <= hasta) ){
        rtn=1;
    }
    return rtn;
}

int pedirEntero(char mensaje[],int desde,int hasta){
    int numero;
    int validar;
    printf("%s",mensaje);
    scanf("%d",&numero);
    validar=validarEnteros(numero,desde,hasta);
    while(validar!=1){
    	fflush(stdin);
        printf("\nError! El numero ingresado no se corresponde con los permitidos. Por favor ingrese uno nuevo: ");
        scanf("%d",&numero);
        validar=validarEnteros(numero,desde,hasta);
    }
    return numero;
}

int getString(char* mensaje, char pResultado[])
{
    int retorno = -1;
    char auxCad[100];
    if(mensaje != NULL && pResultado != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(auxCad);
        while(strlen(auxCad) > 50 || strlen(auxCad) < 1 || isdigit(*auxCad) || !isalpha(*auxCad))
        {
            printf("Error. Ingrese solo caracteres: ");
            fflush(stdin);
            gets(auxCad);
        }

        strcpy(pResultado,auxCad);
        retorno = 0;
    }

    return retorno;
}

int validarAlta(ePassenger listaPasajeros[],int tam,int cantidadDatos){
    int retorno;
    retorno = addPassengers(listaPasajeros, tam);
	    switch(retorno)
	    {
	        case -1:
	            printf("No hay espacio!!!!\n");
				continuar();
	        break;
	        default:
	            printf("Pasajero cargado!!!\n");
	            cantidadDatos++;
				continuar();
	        break;
	    }
	    return cantidadDatos;
}

void
continuar ()
{

  printf ("Presiona Enter para regresar al menu principal...");
  getchar ();
  while (getchar () != '\n');
  system ("cls");
}

char salir(char seguir){
    char siNo;
    system("cls");
    fflush(stdin);
    printf("\n\n\tRealmente desea salir? (s / n)\n\n");
    scanf(" %c",&siNo);
    if(siNo=='s' || siNo=='S'){
        seguir='n';
    }
    return seguir;
}

int seguirCargando(char mensaje[]){
    int seguir=0;
    char siNo;
    printf("Desea ingresar otro %s ? ( s/n ) \n",mensaje);
    scanf(" %c",&siNo);
    if(siNo=='s' || siNo=='S'){
        seguir=1;
    }
    return seguir;
}

int validarPalabra(char* palabra)
{
	int todoOk = -1;

	for(int i = 0; i < strlen(palabra); i++)
	{
		while((palabra == NULL) || (strlen(palabra) < 2) || (strlen(palabra) > 49)
			|| ((!(palabra[i] >= 65 && palabra[i] <= 90)) && (!(palabra[i] >= 97 && palabra[i] <= 122))))
		{
			printf("Nombre inválido. Debe ingresar entre 2-49 caracteres. Sólo letras, sin tildes ni espacios \n");
			printf("Reingrese: ");
			fflush(stdin);
			gets(palabra);
		}

		todoOk = 1;
	}

	return todoOk;
}


int validarInt(int validarInt, int* pNum)
{
	int todoOk = 0;
	int num;
	num = *pNum;

	while(validarInt != 1 || pNum == NULL || num <= 0)
	{
		printf("Error, debe ingresar un número entero mayor a 0. Reingrese número: ");
		fflush(stdin);
		validarInt = scanf("%d", &num);
	}

	*pNum = num;
	return todoOk;
}


int validarFloat(int validarFloat, float* pNum)
{
	int todoOk = 0;
	float num;
	num = *pNum;

	while(validarFloat != 1 || pNum == NULL  || num <= 0)
	{
		printf("Error, debe ingresar un precio numérico y mayor a 0. Reingrese precio: ");
		fflush(stdin);
		validarFloat = scanf("%f", &num);
	}

	*pNum = num;
	return todoOk;
}
