/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "rost.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char estadoVuelo[50];
	char codigoVuelo[50];
}Passenger;

/** \brief Crea un pasajero con los campos vacios
 *
 * \return Passenger* retorna la direccion de memoria del pasajero
 */
Passenger* Passenger_new();

/** \brief Crea un pasajero con los campos pasados por parametro
 *
 * \param idStr char* string de ID
 * \param nombreStr char* string de nombre
 * \param apellidoStr char* string de apellido
 * \param precioStr char* string de precio
 * \param codigoVueloStr char* string de codigo de vuelo
 * \param tipoPasajeroStr char* string de tipo de pasajero
 * \param estadoVuelo char* string de estado de vuelo
 * \return Passenger* retorna la direccion de memoria del pasajero
 *
 */
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVuelo);

/** \brief Elimina un pasajero, liberando su espacio en memoria
 *
 * \return void
 *
 */
void Passenger_delete(Passenger* this);

/** \brief Imprime todos los campos de un pasajero
 *
 * \param this Linkedlist* pasajero
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_print(LinkedList * this,int index);

/** \brief Setea el ID de un pasajero
 *
 * \param this Passenger* pasajero
 * \param id int
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_setId(Passenger* this,int id);


/** \brief Obtiene el ID de un pasajero
 *
 * \param this Passenger* pasajero
 * \param id int*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_getId(Passenger* this,int* id);

/** \brief Setea el ID de un pasajero
 *
 * \param this Passenger* pasajero
 * \param nombre char*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_setNombre(Passenger* this,char* nombre);


/** \brief Obtiene el nombre de un pasajero
 *
 * \param this Passenger* pasajero
 * \param nombre char* nombre
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_getNombre(Passenger* this,char* nombre);

/** \brief Setea el apelido de un pasajero
 *
 * \param this Passenger* pasajero
 * \param apellido char* apellido
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/** \brief Obtiene el apellido de un pasajero
 *
 * \param this Passenger* pasajero
 * \param apellido char* apellido
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/** \brief Setea el codigo de vuelo de un pasajero
 *
 * \param this Passenger* pasajero
 * \param codigoVuelo char* cod de vuelo
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/** \brief Obtiene el cod de vuelo de un pasajero
 *
 * \param this Passenger* pasajero
 * \param codigoVuelo char* cod de vuelo
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/** \brief Setea el tipo de pasajero de un pasajero
 *
 * \param this Passenger* pasajero
 * \param tipoPasajero char* tipo de pasajero
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);

/** \brief Obtiene el tipo de pasajero de un pasajero
 *
 * \param this Passenger* pasajero
 * \param tipoPasajero char* tipo de pasajero
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

/** \brief Setea el estado de vuelo
 *
 * \param this Passenger* pasajero
 * \param estadoVuelo char* estado de vuelo
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);

/** \brief Obtiene el estado de vuelo
 *
 * \param this Passenger* pasajero
 * \param estadoVuelo char* estado de vuelo
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_GetEstadoVuelo(Passenger* this,char* estadoVuelo);

/** \brief Setea el precio de un pasaje
 *
 * \param this Passenger* pasajero
 * \param precio float* precio de un pasaje
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_setPrecio(Passenger* this,float precio);

/** \brief Obtiene el tipo de pasajero de un pasajero
 *
 * \param this Passenger* pasajero
 * \param precio float* precio de un pasaje
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/** \brief Compara ID de dos pasajeros
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int devuelve 1 si el ID del pasajero A es mayor al del pasajero B, -1 si es menor y 0 si son iguales
 *
 */
int Passenger_compareId(void* a,void* b);

/** \brief Compara nombres de dos pasajeros
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int devuelve 1 si el nombre del pasajero A es mayor al del pasajero B, -1 si es menor y 0 si son iguales
 *
 */
int Passenger_compareNombre(void* a,void* b);


/** \brief Compara apellido de dos pasajeros
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int devuelve 1 si el apellido del pasajero A es mayor al del pasajero B, -1 si es menor y 0 si son iguales
 *
 */
int Passenger_compareApellido(void* a,void* b);

/** \brief Compara precio de dos vuelos
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int devuelve 1 si el precio del vuelo A es mayor al del vuelo B, -1 si es menor y 0 si son iguales
 *
 */
int Passenger_comparePrecio(void* a,void* b);

/** \brief Compara codigo de vuelo de dos pasajeros
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int devuelve 1 si el codigo de vuelo del pasajero A es mayor al del pasajero B, -1 si es menor y 0 si son iguales
 *
 */
int Passenger_compareCodigoVuelo(void* a,void* b);

/** \brief Compara estado de dos vuelos
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int devuelve 1 si el estado del vuelo A es mayor al del vuelo B, -1 si es menor y 0 si son iguales
 *
 */
int Passenger_compareEstadoVuelo(void* a,void* b);

/** \brief Compara tipo de dos pasajeros
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int devuelve 1 si el tipo del pasajero A es mayor al del pasajero B, -1 si es menor y 0 si son iguales
 *
 */
int Passenger_compareTipoPasajero(void* a,void* b);

/** \brief Setea el nuevo id
 *
 * \param path char* path de donde toma el nuevo id
 * \param id int* id a setear
 *
 */
void Passenger_setNuevoId(char* path, int id);

/** \brief Obtiene el nuevo id
 *
 * \param path char* path de odnde obtiene el nuevo id
 * \return int devuelve el id si lo obtuvo y 0 si no lo consiguio
 *
 */
int Passenger_getNuevoId(char* path);


#endif /* PASSENGER_H_ */
