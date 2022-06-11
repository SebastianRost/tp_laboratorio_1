/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Rost Sebastian
 */


#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* newPassenger = (Passenger*) malloc(sizeof(Passenger));
    return newPassenger;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr,char* estadoVuelo){

	Passenger* unPasajero;
	unPasajero = Passenger_new();
	if(unPasajero!=NULL){
	Passenger_setId(unPasajero,atoi(idStr));
	Passenger_setNombre(unPasajero, nombreStr);
	Passenger_setApellido(unPasajero, apellidoStr);
	Passenger_setPrecio(unPasajero, atof(precioStr));
	Passenger_setCodigoVuelo(unPasajero, codigoVueloStr);
	Passenger_setEstadoVuelo(unPasajero, estadoVuelo);
	Passenger_setTipoPasajero(unPasajero, tipoPasajeroStr);
	}

	return unPasajero;
}

void Passenger_delete(Passenger* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int Passenger_print(LinkedList * this,int index){
    int retorno = 0;
    Passenger* pasajero;

    if(this != NULL && index>=0){
    	pasajero = (Passenger*)ll_get(this, index);
    	if(pasajero!=NULL){
        printf(" %4d  %16s %16s      %10.2f %16s %16s %16s\n", pasajero->id, pasajero->nombre, pasajero->apellido, pasajero->precio, pasajero->codigoVuelo, pasajero->tipoPasajero, pasajero->estadoVuelo);
        retorno = 1;
    	}
    }
    return retorno;
}

//GETTER Y SETTER ID
int Passenger_setId(Passenger* this,int id)
{
    int retorno=0;
    if(this != NULL && id > 0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}


int Passenger_getId(Passenger* this,int* id)
{
    int retorno=0;
    if( this != NULL && id != NULL)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER PRECIO
int Passenger_setPrecio(Passenger* this,float precio)
{
    int retorno=0;
    if(this != NULL && precio > 0)
    {
        this->precio=precio;
        retorno=1;
    }
    return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
    int retorno=0;
    if( this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER TIPO PASAJERO
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
    int retorno=0;
    if(this != NULL && tipoPasajero!=NULL)
    {
        strcpy(this->tipoPasajero ,tipoPasajero );
        retorno=1;
    }
    return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
    int retorno=0;
    if( this != NULL && tipoPasajero != NULL)
    {
        strcpy(tipoPasajero, this->tipoPasajero);
    }
    return retorno;
}


//GETTER Y SETTER ESTADO DE VUELO
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
    int retorno=0;
    if(this != NULL && estadoVuelo!=NULL)
    {
        strcpy(this->estadoVuelo, estadoVuelo);
    }
    return retorno;
}

int Passenger_GetEstadoVuelo(Passenger* this,char* estadoVuelo)
{
    int retorno=0;
    if( this != NULL && estadoVuelo!=NULL )
    {
        strcpy(estadoVuelo, this->estadoVuelo);
    }

    return retorno;
}

//GETTER Y SETTER APELLIDO
int Passenger_setApellido(Passenger* this,char* apellido)
{
    int retorno=0;
    if(this != NULL && apellido!=NULL)
    {
        strcpy(this->apellido, apellido);
        retorno=1;
    }
    return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
    int retorno=0;
    if( this != NULL && apellido!=NULL )
    {
        strcpy(apellido, this->apellido);
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER CODIGO DE VUELO
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
    int retorno=0;
    if(this != NULL && codigoVuelo!=NULL)
    {
        strcpy(this->codigoVuelo, codigoVuelo);
        retorno=1;
    }
    return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
    int retorno=0;
    if( this != NULL && codigoVuelo!=NULL )
    {
        strcpy(codigoVuelo, this->codigoVuelo);
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER NOMBRE
int Passenger_setNombre(Passenger* this,char* nombre)
{
    int retorno=0;
    if(this != NULL && nombre!=NULL)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
    int retorno=0;
    if( this != NULL && nombre!=NULL )
    {
        strcpy(nombre, this->nombre);
        retorno=1;
    }
    return retorno;
}

//comparison
int Passenger_compareId(void* a,void* b)
{
    int retorno = 0;
    Passenger * pass1 = NULL;
    Passenger * pass2 = NULL;

    if( a != NULL && b != NULL)
    {
    	pass1 = (Passenger*) a;
    	pass2 = (Passenger*) b;

        if(pass1->id > pass2 -> id)
        {
            retorno = 1;
        }
        else if(pass1-> id < pass2 -> id)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int Passenger_compareNombre(void* a,void* b)
{
    int retorno = 0;
    Passenger * pass1 = NULL;
    Passenger * pass2 = NULL;

    if( a != NULL && b != NULL)
    {
    	pass1 = (Passenger*) a;
    	pass2 = (Passenger*) b;

        if(stricmp(pass1-> nombre, pass2-> nombre) == 1)
        {
            retorno = 1;
        }
        else if(stricmp(pass1-> nombre, pass2-> nombre) == -1)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int Passenger_compareApellido(void* a,void* b)
{
    int retorno = 0;
    Passenger * pass1 = NULL;
    Passenger * pass2 = NULL;

    if( a != NULL && b != NULL)
    {
    	pass1 = (Passenger*) a;
    	pass2 = (Passenger*) b;

        if(stricmp(pass1->apellido, pass2->apellido) == 1)
        {
            retorno = 1;
        }
        else if(stricmp(pass1->apellido, pass2->apellido) == -1)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int Passenger_comparePrecio(void* a,void* b)
{
    int retorno = 0;
    Passenger * pass1 = NULL;
    Passenger * pass2 = NULL;

    if( a != NULL && b != NULL)
    {
    	pass1 = (Passenger*) a;
    	pass2 = (Passenger*) b;

        if(pass1->precio > pass2 ->precio)
        {
            retorno = 1;
        }
        else if(pass1->precio < pass2 ->precio)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int Passenger_compareTipoPasajero(void* a,void* b)
{
    int retorno = 0;
    Passenger * pass1 = NULL;
    Passenger * pass2 = NULL;

    if( a != NULL && b != NULL)
    {
    	pass1 = (Passenger*) a;
    	pass2 = (Passenger*) b;

        if(stricmp(pass1->tipoPasajero, pass2->tipoPasajero) == 1)
        {
            retorno = 1;
        }
        else if(stricmp(pass1->tipoPasajero, pass2->tipoPasajero) == -1)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int Passenger_compareEstadoVuelo(void* a,void* b)
{
    int retorno = 0;
    Passenger * pass1 = NULL;
    Passenger * pass2 = NULL;

    if( a != NULL && b != NULL)
    {
    	pass1 = (Passenger*) a;
    	pass2 = (Passenger*) b;

        if(stricmp(pass1->estadoVuelo, pass2->estadoVuelo) == 1)
        {
            retorno = 1;
        }
        else if(stricmp(pass1->estadoVuelo, pass2->estadoVuelo) == -1)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int Passenger_compareCodigoVuelo(void* a,void* b)
{
    int retorno = 0;
    Passenger * pass1 = NULL;
    Passenger * pass2 = NULL;

    if( a != NULL && b != NULL)
    {
    	pass1 = (Passenger*) a;
    	pass2 = (Passenger*) b;

        if(stricmp(pass1->codigoVuelo, pass2->codigoVuelo) == 1)
        {
            retorno = 1;
        }
        else if(stricmp(pass1->codigoVuelo, pass2->codigoVuelo) == -1)
        {
            retorno = -1;
        }
    }
    return retorno;
}
