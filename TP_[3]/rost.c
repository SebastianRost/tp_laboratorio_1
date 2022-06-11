/*
 * rost.c
 *
 *  Created on: 19 may. 2022
 *      Author: Rost Sebastian
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rost.h"

int getOption(int min, int max)
{
	int opcion;
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<min||opcion>max)
    {
        printf("Opcion invalida. Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    printf("\n");
    return opcion;
}


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
int validarFloat(float numero,float desde,float hasta){
    int rtn=0;
    if(numero >= desde && numero <= hasta){
        rtn=1;
    }
    return rtn;
}

float pedirFloat(char mensaje[],float desde,float hasta){
    float numero;
    int validar;
    printf("%s",mensaje);
    scanf("%f",&numero);
    validar=validarFloat(numero,desde,hasta);
    while(validar!=1){
        printf("\nError! El numero ingresado no se corresponde con los permitidos. Por favor ingrese uno nuevo: ");
        scanf("%f",&numero);
        validar=validarFloat(numero,desde,hasta);
    }
    return numero;
}

int menuOpciones()
{
    int opcion;
    printf("\n                             NOMINA DE PASAJEROS\n");
    printf("  __________________________________________________________________________\n\n");
    printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n");
    printf("3. Alta de pasajero\n");
    printf("4. Modificar datos de pasajero\n");
    printf("5. Baja de pasajero\n");
    printf("6. Listar pasajeros\n");
    printf("7. Ordenar pasajeros\n");
    printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario)\n");
    printf("10. Salir\n\n");
    opcion=getOption(1,10);
    return opcion;
}

int getPath(char* path, int maxLen)
{
    int retorno = 0;
    char aux[maxLen + 5];
    if(path!=NULL && maxLen > 0 && maxLen < maxLen + 5)
    {
        printf("Ingrese path: ");
        fflush(stdin);
        fgets(aux,maxLen+5,stdin);
        while(strlen(aux) > maxLen)
        {
            printf("El maximo numero de caracteres permitidos es %d. Reingrese nombre: ",maxLen);
            fflush(stdin);
            fgets(aux,maxLen+5,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(path, aux);
        retorno=1;
    }
    return retorno;
}

int submenuCriterio()
{
    int opcion;
    printf("1. Ordenar por ID.\n");
    printf("2. Ordenar por nombre.\n");
    printf("3. Ordenar por apellido.\n");
    printf("4. Ordenar por precio.\n");
    printf("5. Ordenar por codigo de vuelo.\n");
    printf("6. Ordenar por estado de vuelo.\n");
    printf("7. Ordenar por tipo de pasajero.\n\n");
    opcion=getOption(1,3);
    return opcion;
}

int submenuOrden()
{
    int opcion;
    printf("1. Descendente\n");
    printf("2. Ascendente.\n\n");
    opcion=getOption(1,2);
    return opcion;
}

int submenuModificacion()
{
    int opcion;
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Precio\n");
    printf("4. Tipo de pasajero\n");
    printf("5. Estado de vuelo\n");
    printf("6. Codigo de vuelo\n\n");
    opcion=getOption(1,6);
    return opcion;
}


int getNombre(char *nombre, int maxLen)
{
    int retorno=0;
    char aux[maxLen+5];
    if(nombre!=NULL && maxLen>0 && maxLen<maxLen+5)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        fgets(aux,maxLen+5,stdin);
        while(strlen(aux)>maxLen)
        {
            printf("El maximo numero de caracteres permitidos es %d. Reingrese nombre: ",maxLen);
            fflush(stdin);
            fgets(aux,maxLen+5,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(nombre, aux);
        retorno=1;
    }
    return retorno;
}

int getApellido(char *apellido, int maxLen)
{
    int retorno=0;
    char aux[maxLen+5];
    if(apellido!=NULL && maxLen>0 && maxLen<maxLen+5)
    {
        printf("Ingrese apellido: ");
        fflush(stdin);
        fgets(aux,maxLen+5,stdin);
        while(strlen(aux)>maxLen)
        {
            printf("El maximo numero de caracteres permitidos es %d. Reingrese apellido: ",maxLen);
            fflush(stdin);
            fgets(aux,maxLen+5,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(apellido, aux);
        retorno=1;
    }
    return retorno;
}

int getEstadoVuelo(char *estadoVuelo, int maxLen)
{
    int retorno=0;
    char aux[maxLen+5];
    if(estadoVuelo!=NULL && maxLen>0 && maxLen<maxLen+5)
    {
        printf("Ingrese estado de vuelo: ");
        fflush(stdin);
        fgets(aux,maxLen+5,stdin);
        while(strlen(aux)>maxLen)
        {
            printf("El maximo numero de caracteres permitidos es %d. Reingrese codigo de vuelo: ",maxLen);
            fflush(stdin);
            fgets(aux,maxLen+5,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(estadoVuelo, aux);
        retorno=1;
    }
    return retorno;
}

int getTipoPasajero(char *tipoPasajero, int maxLen)
{
    int retorno=0;
    char aux[maxLen+5];
    if(tipoPasajero!=NULL && maxLen>0 && maxLen<maxLen+5)
    {
        printf("Ingrese tipo de pasajero: ");
        fflush(stdin);
        fgets(aux,maxLen+5,stdin);
        while(strlen(aux)>maxLen)
        {
            printf("El maximo numero de caracteres permitidos es %d. Reingrese codigo de vuelo: ",maxLen);
            fflush(stdin);
            fgets(aux,maxLen+5,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(tipoPasajero, aux);
        retorno=1;
    }
    return retorno;
}

int getCodigoVuelo(char *codigoVuelo, int maxLen)
{
    int retorno=0;
    char aux[maxLen+5];
    if(codigoVuelo!=NULL && maxLen>0 && maxLen<maxLen+5)
    {
        printf("Ingrese codigo de vuelo: ");
        fflush(stdin);
        fgets(aux,maxLen+5,stdin);
        while(strlen(aux)>maxLen)
        {
            printf("El maximo numero de caracteres permitidos es %d. Reingrese codigo de vuelo: ",maxLen);
            fflush(stdin);
            fgets(aux,maxLen+5,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(codigoVuelo, aux);
        retorno=1;
    }
    return retorno;
}

