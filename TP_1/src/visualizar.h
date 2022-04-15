/*
 * visualizar.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Sebastián
 */

#ifndef VISUALIZAR_H_
#define VISUALIZAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"

/// @fn void mostrar(float, float, float)
/// @brief funcion para mostrar el resultado de los calculos
///
/// @param totalAerolineas valor de la primer empresa
/// @param totalLatam valor de la segunda empresa
/// @param kilometros kilometros totales
void mostrar(float totalAerolineas, float totalLatam, float kilometros);

/// @fn void cargaForzada()
/// @brief funcion que devuelve la carga forzada de datos hardcodeados, los calcula y muestra por pantalla
///
void cargaForzada();

/// @fn void continuar()
/// @brief funcion para mostrar continuar al menu hasta presionar enter
///
void continuar();


#endif /* VISUALIZAR_H_ */
