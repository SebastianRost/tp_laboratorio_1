/*
 * visualizar.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Sebastián
 */

void mostrar(float totalAerolineas, float totalLatam, float kilometros){

    float aeroDeb;
    float aeroCred;
    float aeroBTC;
    float latamDeb;
    float latamCred;
    float latamBTC;
    float resultadoUnitAero;
    float resultadoUnitLatam;
    float diferencia;
    aeroDeb = calcularDeb(totalAerolineas);
    aeroCred = calcularCred(totalAerolineas);
    aeroBTC = calcularBTC(totalAerolineas);
    latamDeb = calcularDeb(totalLatam);
    latamCred = calcularCred(totalLatam);
    latamBTC = calcularBTC(totalLatam);
    resultadoUnitAero = calcularUnit(kilometros, totalAerolineas);
    resultadoUnitLatam = calcularUnit(kilometros, totalLatam);
    diferencia = calcularDiferencia(totalAerolineas, totalLatam);

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

void cargaForzada(){
	float kilometros;
	float totalAerolineas;
	float totalLatam;

	kilometros = 7090;
	totalAerolineas = 162965;
	totalLatam = 159339;
	calculos(totalAerolineas, totalLatam,kilometros);
    mostrar(totalAerolineas, totalLatam,kilometros);

}

void continuar(){

    printf("Presiona Enter para regresar al menú principal...");
    getchar();
    while(getchar()!='\n');
}

