/*
 * validations.h
 *
 *  Created on: 19 may. 2022
 *      Author: Rost Sebastián
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"

/// @fn int validarEnteros(int, int, int)
/// @brief valida que un entero se encuentre dentro del rango seleccionado
///
/// @param numero numero a comprobar
/// @param desde valor minimo
/// @param hasta valor maximo
/// @return true o false
int validarEnteros(int numero,int desde,int hasta);

/// @fn int pedirEntero(char[], int, int)
/// @brief si se encuentra dentro del rango permite continuar
///
/// @param mensaje mensaje a mostrar
/// @param desde valor minimo
/// @param hasta valor maximo
/// @return el numero
int pedirEntero(char mensaje[],int desde,int hasta);


/// @fn int validarAlta(ePassenger[], int, int)
/// @brief validar el alta de pasajeros
///
/// @param listaPasajeros variable a recorrer
/// @param tam posiciones a recorrer
/// @param cantidadDatos cantidad de pasajeros activos
/// @return
int validarAlta(ePassenger listaPasajeros[],int tam,int cantidadDatos);

/// @fn void continuar()
/// @brief permite continuar luego de una pausa y un mensaje
///
void continuar();

/// @fn char salir(char)
/// @brief verifica que realmente quiera salir
///
/// @param seguir saber si continua o no
/// @return salida del programa o vuelta al menu
char salir(char seguir);

/// @fn int seguirCargando(char[])
/// @brief valida que quiera o no seguir cargando datos
///
/// @param mensaje mensaje a mostrar
/// @return si sigue cargando o no
int seguirCargando(char mensaje[]);

int getString(char* mensaje, char pResultado[]);

/// @brief Valida que una cadena sea de sólo letras, sin tildes ni espacios,
/// y que tenga un mínimo y un máximo de caracteres.
///
/// @param auxCad recibe la cadena escrita la cual se va a validar
/// @return retorna 1 cuando finalice la función
int validarPalabra(char* auxCad);


/// @brief Valida que el caracter ingresado sea un número entero,
/// y que esté entre un mínimo y un máximo si es necesario.
///
/// @param validarInt recibe 1 si lo recibido es un entero, o un 0 si no lo es
/// @param num recibe la ddm de un número el cual se va a validar
/// @return retorna 1 cuando finalice la función
int validarInt(int validarInt, int* num);


/// @brief Valida que el caracter ingresado sea un número float,
/// y que esté entre un mínimo y un máximo si es necesario.
///
/// @param validarFloat recibe 1 si lo recibido es un float, o un 0 si no lo es
/// @param num recibe la ddm de un float el cual se va a validar
/// @return retorna 1 cuando finalice la función
int validarFloat(int validarFloat, float* num);


#endif /* VALIDATIONS_H_ */
