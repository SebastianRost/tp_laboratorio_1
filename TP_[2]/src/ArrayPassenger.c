/*
 * ArrayPassenger.c
 *
 *  Created on: 7 may. 2022
 *      Author: Sebastián
 */
#include "validations.h"
#include "ArrayPassenger.h"

static int idIncremental = 1;
static int obtenerID ();
static int
obtenerID ()
{
  return idIncremental++;
}

void InicializarTipoPasajeros(eTypePassenger lista[])
{
	eTypePassenger carga[]={
                        {1,"Turista"},
                        {2,"Ejecutivo"}
                    };

    for(int i = 1; i<3; i++)
    {
        lista[i] = carga[i];
    }
}

void InicializarEstadoVuelo(eStatusFlight lista[])
{
	eStatusFlight carga[]={
                        {1,"Activo"},
                        {2,"Demorado"},
                        {3,"Cancelado"}
                    };

    for(int i = 1; i<4; i++)
    {
        lista[i] = carga[i];
    }
}

int InicializarPasajeros(ePassenger lista[],int cantidadDatos)
{
	ePassenger carga[]={
                        {1,"Pepe","Argento",10,"latam",2,1,OCUPADO},
                        {2,"Coqui","Argento",50,"american",1,1,OCUPADO},
                        {3,"M Elena","Fuseneco",40,"gold",2,2,OCUPADO},
                        {4,"Dardo","Fuseneco",20,"american",1,3,OCUPADO},
                        {5,"Paola","Argento",30,"gold",2,1,OCUPADO}
                    };

    for(int i = 0; i<5; i++)
    {
        lista[i] = carga[i];
    }
    return cantidadDatos+5;
}

int initPassengers (ePassenger listaPasajeros[], int tam)
{
  int rtn = -1;
  int i;
  if (listaPasajeros != NULL)
    {
      if (tam >= 0)
	{
	  for (i = 0; i < tam; i++)
	    {
	      //INICIALIZO ESTRUCTURA - LIBRE 0 - OCUPADO 1
		  listaPasajeros[i].isEmpty = LIBRE;
	    }
	  rtn = 0;
	}
    }
  return rtn;
}

int BuscarLibre(ePassenger listaPasajeros[], int tam)
{
    int index;
    index = -1;
    for(int i=0; i<tam; i++)
    {
       if(listaPasajeros[i].isEmpty==LIBRE)
       {
           index = i;
           break;
       }
    }

    return index;
}

int addPassengers(ePassenger listaPasajeros[], int tam)
{
int rtn = -1;
  int indiceLibre;
  ePassenger auxiliar;

  if (listaPasajeros != NULL)
    {
      if (tam >= 0)
	{
	  indiceLibre = BuscarLibre(listaPasajeros, tam);
	  if (indiceLibre >= 0)
	    {
	      auxiliar = PedirDatosPasajero();
	      auxiliar.id = obtenerID ();
	      auxiliar.isEmpty = OCUPADO;
	      listaPasajeros[indiceLibre] = auxiliar;

	      rtn = 0;
	    }
	}
    }
  return rtn;
}

ePassenger PedirDatosPasajero( void )
{
	ePassenger unPasajero;
	char nombre[51];
	char apellido[51];
	int validarPrecio = 0;
	float precio = 0;

	printf("Ingrese el nombre del pasajero: ");
	fflush(stdin);
	gets(nombre);
	validarPalabra(nombre);
	strcpy(unPasajero.name, nombre);


	printf("Ingrese el apellido del pasajero: ");
	fflush(stdin);
	gets(apellido);
	validarPalabra(apellido);
	strcpy(unPasajero.lastname, apellido);

	printf("Ingrese precio: ");
	validarPrecio = scanf("%f", &precio);
	validarFloat(validarPrecio, &precio);
	unPasajero.price = precio;

	printf("Ingrese codigo de vuelo: ");
	fflush(stdin);
	scanf("%[^\n]", unPasajero.flyCode);

	unPasajero.idTypePassenger = pedirEntero("Ingrese el tipo de pasajero (1-turista / 2-ejecutivo): ",1,2);

	unPasajero.statusFlight = pedirEntero("Ingrese estado del vuelo (1-activo / 2-demorado / 3-cancelado): ",1,3);

	unPasajero.isEmpty = OCUPADO;

	return unPasajero;
}

void printPassenger(ePassenger unPasajero)
{
	printf("%2d\t%4s\t%10s\t%.2f%8d \t%10s\t%2d\n",unPasajero.id,
									   unPasajero.name,
			                           unPasajero.lastname,
			                           unPasajero.price,
									   unPasajero.idTypePassenger,
									   unPasajero.flyCode,
									   unPasajero.statusFlight
									   );
}

void printPassengers(ePassenger listaPasajeros[], int length){

	printf("\n ID  |  Nombre  |  Apellido  |  Precio  |  Tipo  |  Codigo  |  Estado  \n");
	printf("_________________________________________________________________________\n");
	for(int i=0; i<length; i++ )
	{
		if(listaPasajeros[i].isEmpty == OCUPADO)
		{
			printPassenger(listaPasajeros[i]);
		}
	}
}

void opcionesMenu(){
	printf("1. Alta");
	printf("\n2. Modificar");
	printf("\n3. Baja");
	printf("\n4. Listar");
	printf("\n5. Carga forzada");
	printf("\n6. Salir");
}

void
modificacion (ePassenger listapasajeros[], int tam)
{
  int opcionModificar;
  int id;
  char seguir='s';
	char nombre[51];
	char apellido[51];
	int validarPrecio = 0;
	float precio = 0;
  printPassengers(listapasajeros,tam);
  id = pedirEntero("Id de pasajero a modificar:",1,2000);
  id = findPassengerById(listapasajeros,tam,id);
  for(int i=0;i<tam;i++){
	  if(listapasajeros[i].id==id){
		  do
		    {
		      printf ("Menu Modificar: \n");
		      printf ("1. Nombre\n");
		      printf ("2. Apellido\n");
		      printf ("3. Precio\n");
		      printf ("4. Codigo de vuelo\n");
		      printf ("5. Tipo de pasajero\n");
		      printf ("6. Estado de vuelo\n");
		      printf ("7. Salir\n");
		      opcionModificar = pedirEntero("Opcion: \n",1,7);

		      switch (opcionModificar)
			{
			case 1:
				printf("Ingrese el nombre del pasajero: ");
				fflush(stdin);
				gets(nombre);
				validarPalabra(nombre);
				strcpy(listapasajeros[i].name, nombre);
			  break;
			case 2:
				printf("Ingrese el nombre del pasajero: ");
				fflush(stdin);
				gets(apellido);
				validarPalabra(apellido);
				strcpy(listapasajeros[i].lastname, apellido);
			  break;
			case 3:
				printf("\nIngrese precio: ");
				validarPrecio = scanf("%f", &precio);
				validarFloat(validarPrecio, &precio);
				listapasajeros[i].price = precio;
			  break;
			case 4:
			  printf ("4. Codigo de vuelo: ");
			  scanf ("%s", listapasajeros[i].flyCode);
			  break;
			case 5:
			    listapasajeros[i].idTypePassenger = pedirEntero("5. Tipo de pasajero: ",1,2);
			  break;
			case 6:
				listapasajeros[i].statusFlight = pedirEntero("6. Estado de vuelo: ",1,3);
			  break;
			case 7:
				seguir = salir(seguir);
			  break;
			}
		    }
		  while (seguir == 's');
		  break;
	  }
  }
}

int findPassengerById(ePassenger listaPasajeros[],int len,int id){
	int rtn;
	  for (int i = 0; i < len; i++)
	    {
	      if (listaPasajeros[i].id == id && listaPasajeros[i].isEmpty == OCUPADO){
	    	  rtn=id;
	    	  break;
	      }else{
	    	  rtn=-1;
	      }
	    }
	  return rtn;
}

int removePassenger (ePassenger listapasajeros[], int len, int id)
{
  char confirmar;
  int rtn;

      if (id>0)
	{
	  system ("cls");
	  fflush (stdin);
	  printf ("\n\tDar de baja? [S|N]:\n");
	  scanf (" %c", &confirmar);
	  for(int i=0;i<len;i++){
		 if(listapasajeros[i].id==id){
			 if (confirmar == 's' || confirmar == 'S' )
			 {
				 listapasajeros[i].isEmpty = -1;
				 rtn = 0;
			 }
		 }
	 }
	}
      else
	{
	  id = pedirEntero("No existe ese codigo, ingrese otro: \n",1,2000);
	  id = findPassengerById(listapasajeros,len,id);
	  rtn=-1;
	}
  return rtn;
}

int baja(ePassenger listapasajeros[], int len,int cantidadDatos){
	int id;
	int idBorrar;
	int borrar;
	printPassengers(listapasajeros,len);
	id = pedirEntero("Id de pasajero a borrar:",1,2000);
	idBorrar = findPassengerById(listapasajeros,len,id);
	borrar = removePassenger(listapasajeros,len,idBorrar);
	if(borrar==0){
		printf ("Los datos han sido borrados.\n");
	  	    cantidadDatos--;
	}else{
		printf ("Los datos no han sido borrados...\n");
		    }
	return cantidadDatos;
}

void mostrarPorEstadoDeVuelo(ePassenger list[], int len, int fligthState){

	printf("\n ID  |  Nombre  |  Apellido  |  Precio  |  Tipo  |  Codigo  |  Estado  \n");
	for(int i = 0 ; i<len ; i++){
		if(list[i].statusFlight==fligthState && list[i].isEmpty == OCUPADO){
			printPassenger(list[i]);
		}
	}
}

void sortByCode(ePassenger list[], int len, int order){
	int auxNumerico=0;
    char auxString[30];

		for(int i=0;i<len-1; i++){

			for(int j=i+1;j<len; j++){

				if(order==1){
					if( stricmp(list[i].flyCode,list[j].flyCode ) > 0){
						sort(list,i,j,auxString,auxNumerico);
				}
				}else{
					if( stricmp(list[i].flyCode,list[j].flyCode ) < 0){
						sort(list,i,j,auxString,auxNumerico);
				}

			}
		}
	}
}

int sortPassengersByCode(ePassenger list[], int len, int order,int fligthState){
	int rtn=-1;
	sortByCode(list,len,order);
	mostrarPorEstadoDeVuelo(list,len,fligthState);
	rtn=0;
	return rtn;
}

void ordenarApellidos(ePassenger list[], int len,int order){
	int auxNumerico=0;
    char auxString[30];

		for(int i=0;i<len-1; i++){

			for(int j=i+1;j<len; j++){

				if(order==1){
					if( stricmp(list[i].lastname,list[j].lastname ) > 0){
						sort(list,i,j,auxString,auxNumerico);
				}
				}else{
					if( stricmp(list[i].lastname,list[j].lastname ) < 0){
						sort(list,i,j,auxString,auxNumerico);
				}

			}
	}
}
}

void sort(ePassenger list[],int i, int j, char auxString[], int auxNumerico){

strcpy(auxString,list[i].flyCode);
strcpy(list[i].flyCode,list[j].flyCode);
strcpy(list[j].flyCode,auxString);
strcpy(auxString,list[i].name);
strcpy(list[i].name,list[j].name);
strcpy(list[j].name,auxString);
strcpy(auxString,list[i].lastname);
strcpy(list[i].lastname,list[j].lastname);
strcpy(list[j].lastname,auxString);
auxNumerico=list[i].id;
list[i].id=list[j].id;
list[j].id=auxNumerico;
auxNumerico=list[i].statusFlight;
list[i].statusFlight=list[j].statusFlight;
list[j].statusFlight=auxNumerico;
}

void mostrarPorTipo(ePassenger list[], int len,int type){

	printf("\n ID  |  Nombre  |  Apellido  |  Precio  |  Tipo  |  Codigo  |  Estado  \n");
	printf("_________________________________________________________________________\n");
	for(int i = 0 ; i<len ; i++){
		if(list[i].idTypePassenger==type && list[i].isEmpty==OCUPADO){
			printPassenger(list[i]);
		}
	}
}

int sortPassengers(ePassenger list[], int len, int order){

	int rtn=-1;
	printf("\n\tTuristas: \n");
	printf("-------------------------------------------------------------------------\n");
	ordenarApellidos(list,len,order);
	mostrarPorTipo(list,len,1);
	printf("-------------------------------------------------------------------------\n");

	printf("\n\tEjecutivos: \n");
	printf("-------------------------------------------------------------------------\n");
	mostrarPorTipo(list,len,2);
	printf("-------------------------------------------------------------------------\n");


	rtn=0;
	return rtn;
}

float totalImportes (ePassenger list[], int tam)
{
  float acumImportes = 0;
  for (int i = 0; i < tam; i++)
    {
      if (list[i].isEmpty == OCUPADO)
	{
	  acumImportes = acumImportes + list[i].price;
	}
    }
  return acumImportes;
}

float
calcularPromedio (float total, int cantidad)
{
  return (float)(total / cantidad);
}

int
contadorMayores (ePassenger list[], float promedio, int tam)
{
  int contadorImportesMayores = 0;
  for (int i = 0; i < tam; i++)
    {
      if (list[i].price > promedio && list[i].isEmpty==OCUPADO)
	{
	  contadorImportesMayores++;
	}
    }
  return contadorImportesMayores;
}

void totalYPromedio (ePassenger list[], int tam, int cantidadDatos)
{
  int total;
  float promedio;
  int cantidadMayores;

  total = totalImportes (list, tam);
  promedio= calcularPromedio (total, cantidadDatos);
  cantidadMayores = contadorMayores (list, promedio, tam);
  printf ("\nImporte total | Promedio de importes | Cantidad de vuelos mas caros que el promedio \n");
  printf ("\n%6d\t%20.2f\t%20d\n", total, promedio, cantidadMayores);
}

void menuListado(ePassenger listaPasajeros[],int cantidadDatos,int len,int order){
	int opcionListado;
	char seguir='s';
	if( cantidadDatos > 0 )
	{
		do{
	        system("cls");
		printf("\n\tInformes: \n\t1-Listado de pasajeros ordenado por apellido y tipo: \n\t2-Total y promedio de precios y cantidad de pasajes que lo superan: \n\t3-Listado de pasajeros por codigo de vuelo, solo los activos: \n\t4-Volver al menu principal: ");
		opcionListado = pedirEntero("\nIngrese opcion a listar: ",1,4);
		switch(opcionListado){
			case 1:
				sortPassengers(listaPasajeros, cantidadDatos,order);
				continuar();
			break;
			case 2:
				totalYPromedio(listaPasajeros,len,cantidadDatos);
				continuar();
			break;
			case 3:
				sortPassengersByCode(listaPasajeros,cantidadDatos,order,1);
				continuar();
			break;
			case 4:
				seguir = salir(seguir);
			break;
		}
		}while(seguir=='s');
		seguir='s';
	}
	else
	{
		printf("No hay datos cargados...");
		continuar();
	}
}

void menu(){

	ePassenger  listaPasajeros[CANT];
	eTypePassenger tipoPasajero[CANT];
	eStatusFlight estadoVuelo[CANT];
	InicializarEstadoVuelo(estadoVuelo);
	InicializarTipoPasajeros(tipoPasajero);
	initPassengers(listaPasajeros,CANT);
	int opcion,
	cantidadDatos = 0;
	char seguir = 's';

	do{
		fflush (stdin);
        system("cls");
		opcionesMenu();
		opcion = pedirEntero("\nOpcion: ",1,6);
		switch(opcion){
			case 1:
				  //InicializarPasajeros(listaPasajeros);
			system ("cls");
				  cantidadDatos = validarAlta(listaPasajeros,CANT,cantidadDatos);
				break;
			case 2:
				if( cantidadDatos > 0 )
				{
			        system("cls");
					modificacion(listaPasajeros,CANT);
					continuar();
				}
				else
				{
					printf("No hay datos cargados...");
					continuar();
				}
				break;
			case 3:
				if( cantidadDatos > 0 )
				{
			        system("cls");

      		  	    cantidadDatos = baja(listaPasajeros,CANT,cantidadDatos);
					continuar();
				}
				else
				{
					printf("No hay datos cargados...");
					continuar();
				}
				break;
			case 4:
				if( cantidadDatos > 0 )
				{
				menuListado(listaPasajeros,cantidadDatos,CANT,UP);
				continuar();
				}
				else
				{
					printf("No hay datos cargados...");
					continuar();
				}
			break;
			case 5:
				cantidadDatos = InicializarPasajeros(listaPasajeros,cantidadDatos);
				if(cantidadDatos>0){
					printf("\nSe realizo la carga forzada\n");
					continuar();
				}else{
					printf("\nNo se pudo realizar la carga forzada\n");
					continuar();
				}
			break;
			case 6:
		        system("cls");
				seguir = salir(seguir);
				break;
			default:
				continuar();
				break;
		}

	}while(seguir=='s');
}
