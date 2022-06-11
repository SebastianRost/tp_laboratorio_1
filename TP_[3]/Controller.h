


#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "rost.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Alta de pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/** \brief Ordenar pasajeros por criterios
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger, int criterio, int orden);

/** \brief Guarda los datos de los pasajeros en un archivo (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en un archivo (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Calcula el proximo ID a ser asignado
 *
 * \param pArrayListPassenger LinkedList* lista
 * \param nextId int*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_getId(LinkedList * pArrayListPassenger, int *nextId);

/** \brief Borra pasajeros de una lista y borra la lista
 *
 * \param pArrayListPassenger LinkedList* lista
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_deletePassenger(LinkedList* pArrayListPassenger);

#endif
