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

void mostrar(float totalAerolineas, float totalLatam, float kilometros, float aeroDeb, float aeroCred, float aeroBTC, float latamDeb, float latamCred, float latamBTC, float resultadoUnitAero, float resultadoUnitLatam, float diferencia){

    system("cls");
    printf("\n\t-------------------------------------------------------------\n\n");
    printf("\t\t\t\tResultados\n");
    printf("\t\t\t\t----------\n\n");
    printf("\t\t-----KMs Ingresados: %.2f km-----\n\n", kilometros);
    printf("\t\t\t-----AEROLINEAS-----\n\n");
    printf("\t\tPrecio de aerolineas: $ %.2f\n", totalAerolineas);
    printf("\t\ta) Precio con tarjeta de débito: $ %.2f\n", aeroDeb);
    printf("\t\tb) Precio con tarjeta de crédito: $ %.2f\n", aeroCred);
    printf("\t\tc) Precio pagando con bitcoin: %.6f BTC\n", aeroBTC);
    printf("\t\td) Mostrar precio unitario: $ %.2f\n", resultadoUnitAero);
    printf("\n\t\t\t-----LATAM-----\n\n");
    printf("\t\tPrecio de Latam: %.2f\n", totalLatam);
    printf("\t\ta) Precio con tarjeta de débito: $ %.2f\n", latamDeb);
    printf("\t\tb) Precio con tarjeta de crédito: $ %.2f\n", latamCred);
    printf("\t\tc) Precio pagando con bitcoin: %.6f BTC\n", latamBTC);
    printf("\t\td) Mostrar precio unitario: $ %.2f\n", resultadoUnitLatam);
    printf("\n\t\t\t------------------\n\n");
    printf("\t\tLa diferencia de precio entre las aerolineas es: $ %.2f\n", diferencia);
    printf("\n\t-------------------------------------------------------------\n\n");
}
