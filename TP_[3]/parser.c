#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	char idStr[51];
	char nombreStr[51];
	char apellidoStr[51];
	char precioStr[51];
	char codigoVueloStr[51];
	char estadoVueloStr[51];
	char tipoPasajeroStr[51];
	    int cant;
	    Passenger * aux = NULL;

	    if(pArrayListPassenger != NULL && pFile != NULL)
	    {
	        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,estadoVueloStr,tipoPasajeroStr);
	        do
	        {
	            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,estadoVueloStr,tipoPasajeroStr);
	            if(cant == 7)
	            {
	                aux=Passenger_newParametros(idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,estadoVueloStr,tipoPasajeroStr);
	                if(aux!=NULL)
	                {
	                    ll_add(pArrayListPassenger,aux);
	                }
	                else
	                {
	                    printf("No se pudo cargar el pasajero\n");
	                }
	                retorno=1;
	            }
	            else
	            {
	                printf("Ha ocurrido un error al leer los datos\n");
	            }
	        }
	        while(feof(pFile)==0);
	    }
	    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
    int retorno = 0;
    int cant;
    Passenger * aux = NULL;

    if(pArrayListPassenger != NULL)
    {
        while(!feof(pFile))
        {
            aux=Passenger_new();
            if (aux != NULL)
            {
                cant = fread(aux, sizeof(Passenger), 1, pFile);
                if(cant==1)
                {
                    ll_add(pArrayListPassenger,aux);
                    aux=NULL;
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}
