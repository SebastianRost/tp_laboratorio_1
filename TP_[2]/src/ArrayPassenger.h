/*
 * ArrayPassenger.h
 *
 *  Created on: 7 may. 2022
 *      Author: Sebastián
 */
#include "validations.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define LIBRE 0
#define OCUPADO 1
#define UP 1
#define DOWN 0
#define CANT 2000

typedef struct{
	int idTypePassenger;
	char description[51];
}eTypePassenger;

typedef struct{
	int statusFlight;
	char description[51];
}eStatusFlight;

typedef struct
{
	int id;
	char name[51];
	char lastname[51];
	int price;
	char flyCode[10];
	int idTypePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;

/// @fn int inicializar(eAlbum[], int)
/// @brief inicializar la estructura como libre
///
/// @param listaAlbumes estructura a inicializar
/// @param tam cantidad de elementos a recorrer
/// @return si esta inicializada o no
int initPassengers(ePassenger listaPasajeros[], int tam);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
**/
int addPassengers(ePassenger listaPasajeros[], int tam);

/// @fn int BuscarLibre(ePassenger[], int)
/// @brief Busca una posicion inicializada como libre
///
/// @param listaPasajeros variable a recorer
/// @param tam cantidad de posiciones a recorrer
/// @return posicion libre o -1 si no encuentra
int BuscarLibre(ePassenger listaPasajeros[], int tam);

/// @fn ePassenger PedirDatosPasajero(void)
/// @brief pide los datos a ingresar en la variable
///
/// @return datos del pasajero
ePassenger PedirDatosPasajero( void );

/// @fn void printPassenger(ePassenger)
/// @brief muestra los datos de un pasajero
///
/// @param unPasajero variable a recorrer para mostrar
void printPassenger(ePassenger unPasajero);

/// @fn void printPassengers(ePassenger[], int)
/// @brief print the content of passengers array
///
/// @param listaPasajeros variable a recorrer
/// @param length cantidad de posiciones en la variable a recorrer
void printPassengers(ePassenger listaPasajeros[], int length);

/// @fn void InicializarPasajeros(ePassenger[])
/// @brief hardcodeo de la lista
///
/// @param lista lista a hardcodear
void InicializarPasajeros(ePassenger lista[]);

void opcionesMenu();

void modificacion (ePassenger listapasajeros[], int tam);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param ePassenger listaPasajeros variable a recorrer
* \param len int cantidad de posiciones a recorrer
* \param id int id a buscar
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(ePassenger listaPasajeros[],int len,int id);

/// @fn void InicializarTipoPasajeros(ePassenger[])
/// @brief hardcodeo de la lista
///
/// @param lista lista a hardcodear
void InicializarTipoPasajeros(eTypePassenger lista[]);

/// @fn void InicializarEstadoVuelo(ePassenger[])
/// @brief hardcodeo de la lista
///
/// @param lista lista a hardcodear
void InicializarEstadoVuelo(eStatusFlight lista[]);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param ePassenger listapasajeros variable a recorrer
* \param len int cantidad de posiciones a recorrer
* \param id int id a remover
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger (ePassenger listapasajeros[], int len, int id);

/// @fn int baja(ePassenger[], int, int)
/// @brief
///
/// @param ePassenger listapasajeros variable a recorrer
/// @param len cantidad de posiciones a recorrer
/// @param cantidadDatos pasajeros que habia previamente
/// @return cantidad de pasajeros que quedan
int baja(ePassenger listapasajeros[], int len,int cantidadDatos);

/// @fn void mostrarPorEstadoDeVuelo(ePassenger[], int, int)
/// @brief lista por estado de vuelo
///
/// @param list variable a recorrer
/// @param len cantidad de posiciones a recorrer
/// @param fligthState estado de vuelo
void mostrarPorEstadoDeVuelo(ePassenger list[], int len,int fligthState);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param ePassenger listapasajeros variable a recorrer
* \param len int cantidad de posiciones a recorrer
* \param order int [1] indicate UP - [0] indicate DOWN
* return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengersByCode(ePassenger list[], int len, int order, int fligthState);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengers(ePassenger list[], int len, int order);

/// @fn void sortByCode(ePassenger[], int, int)
/// @brief ordena por codigo
///
/// @param list variable a recorrer
/// @param len cantidad de posiciones a recorrer
/// @param order ascendente o descendente
void sortByCode(ePassenger list[], int len, int order);

/// @fn void ordenarApellidos(ePassenger[], int, int)
/// @brief ordena ascendente o descendente por apellido
///
/// @param list variable a recorrer
/// @param len posiciones a recorrer
/// @param order ascendente o descendente
void ordenarApellidos(ePassenger list[], int len, int order);

/// @fn void mostrarPorTipo(ePassenger[], int, int)
/// @brief mostrar por pantalla ordenado por tipo de pasajero
///
/// @param list variable a recorrer
/// @param len posiciones a recorrer
/// @param type tipo de pasajero
void mostrarPorTipo(ePassenger list[], int len,int type);

/// @fn int totalImportes(ePassenger[], int)
/// @brief cantidad total de iportes
///
/// @param list variable a recorrer
/// @param tam posiciones a recorrer
/// @return acumulador de importes
int totalImportes (ePassenger list[], int tam);

/// @fn int calcularPromedio(float, int)
/// @brief calcula el promedio de lo ingresado
///
/// @param total impote total
/// @param cantidad el divisor, cantidad por la cual dividir
/// @return promedio
int calcularPromedio (float total, int cantidad);

/// @fn int contadorMayores(ePassenger[], int, int)
/// @brief cantidad de mayores al promedio
///
/// @param list variable a recorrer
/// @param promedio valor promedio
/// @param tam posiciones a recorer
/// @return cantidad de mayores
int contadorMayores (ePassenger list[], int promedio, int tam);

/// @fn void totalYPromedio(ePassenger[], int, int)
/// @brief muestra por pantalla el total y el promedio de precios
///
/// @param list variable a recorrer
/// @param tam posiciones de la variable a recorrer
/// @param cantidadDatos divisor, cantidad de pasajeros por la cual dividir el acumulador
void totalYPromedio (ePassenger list[], int tam, int cantidadDatos);

/// @fn void sort(ePassenger[], int, int, char[], int)
/// @brief ordenamiento
///
/// @param list variable a recorrer
/// @param i valor i
/// @param j valor j
/// @param auxString auxiliar de string para reemplazar en buebujeo
/// @param auxNumerico auxiliar de int para reemplazar en buebujeo
void sort(ePassenger list[],int i, int j, char auxString[], int auxNumerico);

/// @fn void menuListado(ePassenger[], int, int, int)
/// @brief menu de listado
///
/// @param listaPasajeros variable a recorrer
/// @param cantidadDatos cantidad de pasajeros activos
/// @param len posiciones a recorrer
/// @param order ascendente o descendente
void menuListado(ePassenger listaPasajeros[],int cantidadDatos,int len,int order);

/// @fn void menu()
/// @brief menu de opciones
///
void menu();

#endif /* ARRAYPASSENGER_H_ */
