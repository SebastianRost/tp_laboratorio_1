/*
 * validations.c
 *
 *  Created on: 7 may. 2022
 *      Author: Sebastián
 */
#include "validations.h"
#include "ArrayPassenger.h"


int validarEnteros(int numero,int desde,int hasta){
    int rtn=0;
    if(numero >= desde && numero <= hasta){
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
        printf("\nError! El numero ingresado no se corresponde con los permitidos. Por favor ingrese uno nuevo: ");
        scanf("%d",&numero);
        validar=validarEnteros(numero,desde,hasta);
    }
    return numero;
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
