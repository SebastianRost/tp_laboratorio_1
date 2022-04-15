/*
 * calculos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Sebastián
 */

float calcularDeb(float total){
	return total*0.9;
}

float calcularCred(float total){
	return total*1.25;
}

float calcularBTC(float total){
	return total/4606954.55;
}

float calcularUnit(float km, float precioAerolinea){
	return precioAerolinea/km;
}

float calcularDiferencia(float totalAerolineas,float totalLatam){
	float resultado;

	if(totalLatam>totalAerolineas){
		resultado = totalLatam-totalAerolineas;
	}else{
		resultado = totalAerolineas-totalLatam;
	}
	return resultado;
}

void calculos(float totalAerolineas, float totalLatam, float kilometros){


    calcularDeb(totalAerolineas);
    calcularCred(totalAerolineas);
    calcularBTC(totalAerolineas);
    calcularDeb(totalLatam);
    calcularCred(totalLatam);
    calcularBTC(totalLatam);
    calcularUnit(kilometros, totalAerolineas);
    calcularUnit(kilometros, totalLatam);
    calcularDiferencia(totalAerolineas, totalLatam);

}
