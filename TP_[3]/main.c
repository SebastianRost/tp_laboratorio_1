/*
 *
 *  Created on: 19 may. 2022
 *      Author: Rost Sebastian
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "rost.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{

	setbuf(stdout, NULL);
    char salir;
    int flagFile = 1;
    char path[20];
    int opcion;
    int criterio;
    int orden;

    LinkedList* listaPasajeros = ll_newLinkedList();

    //Si es NULL salgo del programa
    if(listaPasajeros == NULL)
    {
        printf("ERROR: No se ha podido crear la nomina de pasajeros\n");
        exit(EXIT_FAILURE);
    }
    do{
    	opcion=menuOpciones();
        switch(opcion)
        {

            case 1:
        		if(flagFile){
                    getPath(path,20);
					if(controller_loadFromText(path,listaPasajeros)){
                        printf("La lista se ha cargado exitosamente \n\n");
						flagFile = 0;
					}else
					{
						printf("ERROR: Ha ocurrido un error al cargar los pasajeros\n\n");
					}
				}
				else
				{
					printf("Ya existe un archivo cargado.\n\n");
				}
				break;

            case 2:  // Cargar los datos de los pasajeros desde el archivo modo binario
                if(flagFile){
                    getPath(path,20);
                    if(controller_loadFromBinary(path, listaPasajeros)){
                        printf("Carga de pasajeros exitosa \n\n");
                        flagFile = 0;
                        //flagparaleerbinario
                    }
                    else
                    {
                        printf("ERROR: Ha ocurrido un error al cargar los pasajeros\n\n");
                    }
                }
                else
                {
                    printf("Ya existe un archivo cargado.\n");
                }
                break;
               case 3:
					   if(controller_addPassenger(listaPasajeros))
					   {
						   printf("Alta de pasajero exitosa\n\n");
					   }
					   else
					   {
						   printf("ERROR: No se ha podido dar de alta el pasajero\n\n");
					   }
            	   break;
               case 4:
                   if(ll_len(listaPasajeros) > 0)
                   {
                       if(controller_editPassenger(listaPasajeros)){
                           printf("Modificacion de pasajero exitosa\n\n");
                       }
                       else
                       {
                           printf("ERROR: No se ha podido modificar el pasajero\n\n");
                       }
                   }
                   else
                   {
                       printf("ERROR: No hay pasajeros cargados\n\n");
                   }
                   break;

               case 5:
                   if(ll_len(listaPasajeros) > 0)
                   {
                       if(controller_removePassenger(listaPasajeros))
                       {
                           printf("Baja de pasajero exitosa\n\n");
                       }
                       else
                       {
                           printf("ERROR: No se ha podido dar de baja el pasajero\n\n");
                       }
                   }
                   else
                   {
                       printf("ERROR: No hay pasajeros cargados\n\n");
                   }
                   break;
               case 6:
            	   if(!controller_ListPassenger(listaPasajeros)){
                       printf("No hay pasajeros para mostrar\n\n");
            	   }
            	   break;
               case 7: // Ordenar pasajeros
                   if(ll_len(listaPasajeros) > 0)
                   {
                       criterio = submenuCriterio();
                       orden = submenuOrden()-1;
                       if(controller_sortPassenger(listaPasajeros, criterio, orden))
                       {
                           printf("Lista ordenada exitosamente\n\n");
                       }
                       else
                           {
                           printf("ERROR: No se ha podido ordenar la lista\n\n");
                       }
                   }
                   else
                   {
                       printf("ERROR: No hay pasajeros cargados\n\n");
                   }
                   break;
               case 8: //Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
                    if(flagFile == 0)
                    {
                        getPath(path,20);
                        if(controller_saveAsText(path,listaPasajeros)){
                            printf("La lista se ha guardado exitosamente \n\n");
                        }
                        else
                        {
                            printf("ERROR: Ha ocurrido un problema al guardar los pasajeros\n\n");
                        }
                    }
                    else
                    {
                            printf("ERROR: Primero debe cargar los datos desde algun archivo\n\n");
                    }
                    break;

                case 9: // Guardar los datos de los pasajeros en el archivo data.bin (modo binario).
                    if(flagFile == 0)
                    {
                        getPath(path,20);
                        if(controller_saveAsBinary(path,listaPasajeros)){
                            printf("La lista se ha guardado exitosamente\n\n");
                        }
                        else
                        {
                            printf("ERROR: Ha ocurrido un problema al guardar los pasajeros\n\n");
                        }
                    }
                    else
                    {
                            printf("ERROR: Primero debe cargar los datos desde algun archivo\n\n");
                    }
                    break;

            case 10:
                printf("Esta seguro de que desea salir (s/n)?\n");
                fflush(stdin);
                salir = getchar();
                printf("\n");
                if(salir == 's')
                {
                    controller_deletePassenger(listaPasajeros); //borra las estructuras
                    ll_deleteLinkedList(listaPasajeros); //elimina la linked list
                    printf("Programa finalizado\n\n");
                }
                break;
        }
    }while(salir != 's');
    return 0;
}

