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
#include "visualizar.h"

int main(void) {

	int flag = 0;
    int opcion;
    float kilometros;
    float totalAerolineas;
    float totalLatam;
    char seguir= 's';
    char siNo;

    setbuf(stdout, NULL);
    do{
        system("cls");
        printf("\t*******************\tMenu de opciones\t*******************\n\n");
        flag<1 ? printf("\t    1. Ingresar Kilometros: ( km=x)\n") : printf("\t    1. Ingresar Kilometros ( km= %.2f )\n", kilometros);
        flag<2 ? printf("\t    2. Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)\n") : printf("\t    2. Ingresar Precio de Vuelos: ( Aerolineas=%.2f, Latam=%.2f )\n", totalAerolineas,totalLatam);
        printf("\t    3. Calcular todos los costos: \n\t\ta) Tarjeta de debito ( descuento 10 ) \n\t\tb) Tarjeta de credito ( interes 25 ) \n\t\tc) Bitcoin ( 1BTC -> 4606954.55 Pesos Argentinos ) \n\t\td) Mostrar precio por km ( precio unitario ) \n\t\te) Mostrar diferencia de precio ingresada ( Latam - Aerolineas ) \n");
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
            printf("\n\n\tIngresar Kilometros: \t");
            scanf("%f", &kilometros);
            while(kilometros<1){
                printf("\n\n\tDebe ingresar un valor mayor a 0. Ingresar Kilometros: \t");
                scanf("%f", &kilometros);
            }
            flag=1;
            break;
        case 2:
            if(flag!=1)
            {
                printf("\n\n\tPrimero ingrese los kilometros\n\n");
                continuar();
            }
            else
            {
                system("cls");
                printf("\n\n\t-Ingresar precio de vuelo de Aerolineas: \t");
                scanf("%f", &totalAerolineas);
                while(totalAerolineas<1){
                    printf("\n\n\tDebe ingresar un valor mayor a 0. Ingresar precio de vuelo de Aerolineas: \t");
                    scanf("%f", &totalAerolineas);
                }
                printf("\n\n\t-Ingresar precio de vuelo de Latam: \t");
                scanf("%f", &totalLatam);
                while(totalLatam<1){
                    printf("\n\n\tDebe ingresar un valor mayor a 0. Ingresar precio de vuelo de Latam: \t");
                    scanf("%f", &totalLatam);
                }
                flag++;
            }

            break;
        case 3:
            if(flag!=2)
            {
                printf("\n\n\tNo se puede realizar la opcion sin ingresar los kilometros y los precios, ingreselos y vuelva a intentar\n\n");
                continuar();
            }
            else
            {
                system("cls");
                calculos(totalAerolineas, totalLatam, kilometros);
                printf("\n\n\tSe ha realizado el calculo de las operaciones\t\n\n");
                flag++;
                continuar();
            }
            break;
        case 4:
            flag!=3 ? printf("\n\n\tNo se pueden mostrar los resultados sin ingresar los datos o realizar el calculo con anterioridad\n\n") :
            mostrar(totalAerolineas, totalLatam,kilometros);
            continuar();
            break;
        case 5:
        	cargaForzada();
            continuar();
            flag=0;
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
            continuar();

            break;

        }

    }while(seguir=='s');

	return EXIT_SUCCESS;
}
