/*
 * funciones.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Sebastián
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "visualizar.h"


/// @fn float calcularDeb(float)
/// @brief funcion para saber el precio de un producto al pagar con tarjeta de debito
///
/// @param precio es el precio del producto
/// @return precio del producto pagando con debito
float calcularDeb(float precio);

/// @fn float calcularCred(float)
/// @brief funcion para saber el precio de un producto al pagar con tarjeta de credito
///
/// @param precio es el precio del producto
/// @return precio del producto pagando con credito
float calcularCred(float precio);

/// @fn float calcularBTC(float)
/// @brief funcion para saber el precio de un producto al pagar con bitcoin
///
/// @param precio es el precio del producto
/// @return precio del producto pagando con bitcoin
float calcularBTC(float precio);

/// @fn float calcularUnit(float, float)
/// @brief funcion para saber el valor unitario del producto
///
/// @param km kilometros totales
/// @param precioAerolinea el precio del vuelo
/// @return valor unitario
float calcularUnit(float km, float precioAerolinea);

/// @fn float calcularDiferencia(float, float)
/// @brief  funcion para calcular la diferencia de precio entre dos valores
///
/// @param totalAerolineas valor de la primer empresa
/// @param totalLatam valor de la segunda empresa
/// @return diferencia de precios
float calcularDiferencia(float totalAerolineas,float totalLatam);

/// @fn void calculos(float, float, float)
/// @brief  funcion para realizar todos los cálculos
///
/// @param totalAerolineas valor de la primer empresa
/// @param totalLatam valor de la segunda empresa
/// @param kilometros kilometros totales
void calculos(float totalAerolineas, float totalLatam, float kilometros);



#endif /* CALCULOS_H_ */
