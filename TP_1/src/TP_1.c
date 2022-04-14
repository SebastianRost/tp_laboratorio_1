/*
 ============================================================================
 Name        : TP_1.c
 Author      : Rost Sebastian Gabriel
 Version     : 1
 Copyright   : Your copyright notice
 Description : TP 1 Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"

int main(void) {

	int flagKilometros = 1;
	int flagPrecios = 1;
    int opcion;
    int flagCalculo=1;
    float kilometros;
    float totalAerolineas;
    float totalLatam;
    float aeroDeb;
    float aeroCred;
    float aeroBTC;
    float latamDeb;
    float latamCred;
    float latamBTC;
    float resultadoUnitAero;
    float resultadoUnitLatam;
    float diferencia;
    char seguir= 's';
    char siNo;

    setbuf(stdout, NULL);
    do{
        system("cls");
        printf("\t*******************\tMenu de opciones\t*******************\n\n");
        flagKilometros ? printf("\t    1. Ingresar Kilómetros: ( km=x)\n") : printf("\t    1. Ingresar el primer operando (A= %.2f)\n", kilometros);
        flagPrecios ? printf("\t    2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n") : printf("\t    2. Ingresar Precio de Vuelos: (Aerolíneas=%.2f, Latam=%.2f)\n", totalAerolineas,totalLatam);
        printf("\t    3. Calcular todos los costos: \n\t\ta) Tarjeta de débito ( descuento 10 ) \n\t\tb) Tarjeta de crédito ( interés 25 ) \n\t\tc) Bitcoin ( 1BTC -> 4606954.55 Pesos Argentinos ) \n\t\td) Mostrar precio por km ( precio unitario ) \n\t\te) Mostrar diferencia de precio ingresada ( Latam - Aerolíneas ) \n");
        printf("\t    4. Informar resultados\n");
        printf("\t    5. Carga forzada de datos\n");
        printf("\t    6. Salir\n\n");
        printf("\t*******************************************************************\n\n");

        printf("\n    Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
        	system("cls");
            printf("\n\n\tIngresar Kilómetros: \t");
            scanf("%f", &kilometros);
            while(kilometros<1){
                printf("\n\n\tDebe ingresar un valor mayor a 0. Ingresar Kilómetros: \t");
                scanf("%f", &kilometros);
            }
            flagKilometros=0;
            flagCalculo=1;
            break;

        case 2:
            if(flagKilometros)
            {
                printf("\n\n\tPrimero ingrese el primer operando\n\n");
                printf("Press Enter para continuar...");
                getchar();
                while(getchar()!='\n');
            }
            else
            {
                system("cls");
                printf("\n\n\tIngresar precio de vuelo de Aerolineas: \t");
                scanf("%f", &totalAerolineas);
                while(totalAerolineas<1){
                    printf("\n\n\tDebe ingresar un valor mayor a 0. Ingresar precio de vuelo de Aerolineas: \t");
                    scanf("%f", &totalAerolineas);
                }
                printf("\n\n\tIngresar precio de vuelo de Latam: \t");
                scanf("%f", &totalLatam);
                while(totalLatam<1){
                    printf("\n\n\tDebe ingresar un valor mayor a 0. Ingresar precio de vuelo de Latam: \t");
                    scanf("%f", &totalLatam);
                }
                flagPrecios=0;
                flagCalculo=1;
            }

            break;
        case 3:
            if(flagPrecios)
            {
                printf("\n\n\tNo se puede realizar la opcion sin ingresar los kilometrosy los precios, ingreselos y vuelva a intentar\n\n");

                printf("Presiona Enter para continuar...");
                getchar();
                while(getchar()!='\n');
            }
            else
            {
                system("cls");
                aeroDeb = calcularDeb(totalAerolineas);
                aeroCred = calcularCred(totalAerolineas);
                aeroBTC = calcularBTC(totalAerolineas);
                latamDeb = calcularDeb(totalLatam);
                latamCred = calcularCred(totalLatam);
                latamBTC = calcularBTC(totalLatam);
                resultadoUnitAero = calcularUnit(kilometros, totalAerolineas);
                resultadoUnitLatam = calcularUnit(kilometros, totalLatam);
                diferencia = calcularDiferencia(totalAerolineas, totalLatam);

                printf("\n\n\tSe ha realizado el calculo de las operaciones\t\n\n");
                flagCalculo=0;
                printf("Presiona Enter para continuar...");
                getchar();
                while(getchar()!='\n');
            }
            break;
        case 4:
            flagCalculo ? printf("\n\n\tNo se pueden mostrar los resultados sin realizar el calculo con anterioridad\n\n") :
            mostrar(totalAerolineas, totalLatam,kilometros,aeroDeb,aeroCred,aeroBTC,latamDeb,latamCred,latamBTC,resultadoUnitAero,resultadoUnitLatam,diferencia);
            printf("Press Enter para continuar...");
            getchar();
            while(getchar()!='\n');
            break;


        case 6:

            system("cls");
            fflush(stdin);
            printf("\n\n\tRealmente desea salir? (s / n)\n\n");
            scanf(" %c",&siNo);
            if(siNo=='s' || siNo=='S' ){
                seguir='n';
            }
            break;
        default:

            printf("\n\n\tno es una opcion valida\n\n");
            printf("Press Enter para continuar...");
            getchar();
            while(getchar()!='\n');

            break;

        }

    }while(seguir=='s');

	return EXIT_SUCCESS;
}
