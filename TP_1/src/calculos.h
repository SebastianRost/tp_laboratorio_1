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


float calcularDeb(float total);

float calcularCred(float total);

float calcularBTC(float total);

float calcularUnit(float km, float precioAerolinea);

float calcularDiferencia(float totalAerolineas,float totalLatam);

void mostrar(float totalAerolineas, float totalLatam, float kilometros, float aeroDeb, float aeroCred, float aeroBTC, float latamDeb, float latamCred, float latamBTC, float resultadoUnitAero, float resultadoUnitLatam, float diferencia);


#endif /* CALCULOS_H_ */
