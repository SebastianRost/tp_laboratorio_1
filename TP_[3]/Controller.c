
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	if(pArrayListPassenger != NULL && path !=NULL){
		FILE* file = fopen(path, "r");
		 if(file == NULL)
		        {
		            printf("No se pudo abrir el archivo\n");
		        }
		        else
		        {
		            if(parser_PassengerFromText(file, pArrayListPassenger))
		            {
		                retorno = 1;
		            }
		        }
		        fclose(file);
	}

    return retorno;
}

int controller_getId(LinkedList * pArrayListPassenger, int *nextId){
    int retorno = 0;
    int mayorId = 0;
    Passenger * pas = NULL;

    if(pArrayListPassenger != NULL){
        for(int i=0; i<ll_len(pArrayListPassenger);i++){
        	pas = ll_get(pArrayListPassenger, i);
            if(pas->id > mayorId)
            {
               mayorId = pas->id;
            }
        }
        *nextId = mayorId + 1;
        retorno = 1;
    }
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = 0;

    if(pArrayListPassenger != NULL && path != NULL)
    {
        FILE* f = fopen(path, "rb");

        if(f==NULL)
        {
            printf("No se pudo abrir el archivo\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            if(parser_PassengerFromBinary(f, pArrayListPassenger))
            {
                retorno = 1;
            }
        }
        fclose(f);
    }
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	 int retorno = 0;
	    Passenger * aux =  NULL;
	    int id;
	    char nombre[51];
	    char apellido[51];
	    float precio;
		char tipoPasajero[50];
	    char estadoVuelo[51];
	    char codigoVuelo[51];
	    int caso;

	    if(pArrayListPassenger != NULL)
	    {
	        aux =  Passenger_new();
	        if(aux != NULL)
	        {
	        	id = Passenger_getNuevoId("id.txt");
	        	Passenger_setId(aux, id);
	            getNombre(nombre, 51);
	            Passenger_setNombre(aux,nombre);
	            getApellido(apellido, 51);
	            Passenger_setApellido(aux,apellido);
	            precio = pedirFloat("Ingrese precio del pasaje: ", 0, 200000);
	            Passenger_setPrecio(aux, precio);
	            caso = pedirEntero("Ingrese el tipo de pasajero ( 1-EconomyClass ,2-ExecutiveClass ,3-FirstClass )", 1, 3);
	            switch(caso){
	            case 1:
	            	strcpy(tipoPasajero,"EconomyClass");
	            	break;
	            case 2:
	            	strcpy(tipoPasajero,"ExecutiveClass");
	            	break;
	            case 3:
	            	strcpy(tipoPasajero,"FirstClass");
	            	break;
	            }
	            Passenger_setTipoPasajero(aux, tipoPasajero);
	            caso = pedirEntero("Ingrese estado de vuelo (1-Aterrizado, 2-En Horario, 3-Demorado, 4-En vuelo) ",1,4);
	            switch(caso){
	            case 1:
	            	strcpy(estadoVuelo,"Aterrizado");
	            	break;
	            case 2:
	            	strcpy(estadoVuelo,"En Horario");
	            	break;
	            case 3:
	            	strcpy(estadoVuelo,"Demorado");
	            	break;
	            case 4:
	            	strcpy(estadoVuelo,"En vuelo");
	            	break;
	            }
	            Passenger_setEstadoVuelo(aux, estadoVuelo);
	            getCodigoVuelo(codigoVuelo, 51);
	            Passenger_setCodigoVuelo(aux, codigoVuelo);
	            printf("\n");
	            ll_add(pArrayListPassenger, aux);
	            id++;
	            Passenger_setNuevoId("id.txt",id);
	            retorno = 1;
	        }
	    }
	    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = 0;
    Passenger* pas =  NULL;
    char nombre[51];
    char apellido[51];
    char codigoVuelo[51];
    int precio;
    char tipoPasajero[51];
    char estadoVuelo[51];
    int id;
    int indice = -1;
    int tam;


    if(pArrayListPassenger != NULL)
    {
        tam = ll_len(pArrayListPassenger);
        pas =  Passenger_new();
        controller_ListPassenger(pArrayListPassenger);

        if(pas != NULL && tam > 0)
        {
            printf("Ingrese ID del pasajero a modificar: ");
            scanf("%d", &id);
            printf("\n");

            for(int i=0; i<ll_len(pArrayListPassenger); i++)
            {
            	pas = ll_get(pArrayListPassenger,i);
                if(pas->id == id)
                {
                    indice = i;
                    break;
                }
            }
            if(indice != -1)
            {
                switch(submenuModificacion())
                {
                case 1:
                    getNombre(nombre, 51);
                    if(Passenger_setNombre(pas,nombre))
                    {
                        retorno = 1;
                    }
                    break;
                case 2:
                    getApellido(apellido, 51);
                    if(Passenger_setApellido(pas,apellido))
                    {
                        retorno = 1;
                    }
                    break;
                case 3:
                	precio = pedirFloat("Ingrese nuevo precio: ", 0, 200000);
                    if(Passenger_setPrecio(pas,precio)){
                        retorno = 1;
                    }
                    break;
                case 4:
                	getEstadoVuelo(estadoVuelo, 51);
                    if(Passenger_setTipoPasajero(pas,tipoPasajero)){
                        retorno = 1;
                    }
                	break;
                case 5:
                	getTipoPasajero(tipoPasajero, 51);
                    if(Passenger_setEstadoVuelo(pas,estadoVuelo)){
                        retorno = 1;
                    }
                	break;
                case 6:
                	getCodigoVuelo(codigoVuelo, 51);
                    if(Passenger_setCodigoVuelo(pas,codigoVuelo))
                    {
                        retorno = 1;
                    }
                	break;
                }
            }
            else
            {
                printf("No se ha encontrado el pasajero con ID %d.", id);
            }
            printf("\n");
        }
    }
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int retorno = 0;
    Passenger * pas = NULL;
    int indice = -1;
    int id;
    char salir;

    if(pArrayListPassenger != NULL)
    {
        controller_ListPassenger(pArrayListPassenger);
        printf("Ingrese ID del pasajero a borrar: ");
        scanf("%d", &id);

        for(int i=0; i<ll_len(pArrayListPassenger); i++)
        {
        	pas = ll_get(pArrayListPassenger,i);
            if(pas->id == id)
            {
                indice = i;
                break;
            }
        }
        printf("\n");

        if(indice != -1)
        {
            printf("Esta seguro de que desea eliminar el pasajero (s/n) ?\n");
            fflush(stdin);
            salir = getchar();
            if(tolower(salir) == 's')
            {
                Passenger_delete(pas);
                ll_remove(pArrayListPassenger, indice);
                retorno = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n\n");
            }
        }
        else
        {
            printf("No se ha encontrado el pasajero con ID %d\n\n", id);
        }
    }
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int retorno=0;
    int tam = ll_len(pArrayListPassenger);

    printf("   ID       NOMBRE        APELLIDO       PRECIO\n");
    if(pArrayListPassenger != NULL )
    {
        if(tam > 0)
        {
            for(int i=0;i<tam;i++)
            {
                Passenger_print(pArrayListPassenger,i);
            }
            printf("\n\n");
        }
        else
        {
            printf("No hay pasajeros para mostrar\n\n");
        }
        retorno = 1;
    }
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger, int criterio, int orden)
{
    int retorno = 0;

    if(pArrayListPassenger != NULL)
    {
        switch(criterio)
        {
            case 1:
                if(ll_sort(pArrayListPassenger,Passenger_compareId,orden))
                {
                    retorno = 1;
                }
                break;
            case 2:
                if(ll_sort(pArrayListPassenger,Passenger_compareNombre,orden))
                {
                    retorno = 1;
                }
                break;
            case 3:
                if(ll_sort(pArrayListPassenger,Passenger_compareApellido, orden))
                {
                    retorno = 1;
                }
                break;
            case 4:
                if(ll_sort(pArrayListPassenger,Passenger_comparePrecio, orden))
                {
                    retorno = 1;
                }
                break;
            case 5:
                if(ll_sort(pArrayListPassenger,Passenger_compareCodigoVuelo, orden))
                {
                    retorno = 1;
                }
                break;
            case 6:
                if(ll_sort(pArrayListPassenger,Passenger_compareEstadoVuelo, orden))
                {
                    retorno = 1;
                }
                break;
            case 7:
                if(ll_sort(pArrayListPassenger,Passenger_compareTipoPasajero, orden))
                {
                    retorno = 1;
                }
                break;
        }
        retorno = 1;
    }
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno=0;
    int tam;
    int cant;

    Passenger * this = NULL;

    FILE* f = fopen(path, "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        if(pArrayListPassenger != NULL && path != NULL)
        {
            tam = ll_len(pArrayListPassenger);
            int id;
            char nombre[51];
            char apellido[51];
            float precio;
            char codigoVuelo[51];
            char tipoPasajero[51];
            char estadoVuelo[51];
            for(int i=0;i<tam;i++)
            {
                this=ll_get(pArrayListPassenger, i);
                if(this != NULL){
                	Passenger_getId(this, &id);
                	Passenger_getNombre(this, nombre);
                	Passenger_getApellido(this, apellido);
                	precio = Passenger_setPrecio(this, precio);
                	Passenger_getCodigoVuelo(this, codigoVuelo);
                	Passenger_getTipoPasajero(this, tipoPasajero);
                	Passenger_setEstadoVuelo(this, estadoVuelo);
                    cant = fprintf(f,"%d,%s,%s,%f,%s,%s,%s\n",id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
                    if(cant < 7)
                    {
                        break;
                    }
                }
                retorno = 1;
            }
        }
    }
    fclose(f);
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = 0;
    int tam;
    int cant;
    Passenger * aux = NULL;

    FILE* f=fopen(path, "wb");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        if(pArrayListPassenger != NULL && path != NULL)
        {
            tam = ll_len(pArrayListPassenger);
            for(int i=0;i<tam;i++){
                aux=ll_get(pArrayListPassenger, i);
                if(aux != NULL){
                    cant = fwrite(aux, sizeof(Passenger), 1, f);
                    if(cant < 1){
                        break;
                    }
                }
                retorno = 1;
            }
        }
    }
    fclose(f);
    return retorno;
}

int controller_deletePassenger(LinkedList* pArrayListPassenger)
{
    int retorno = 0;
    Passenger* aux = NULL;

    if(pArrayListPassenger != NULL)
    {
        for(int i=0; i<ll_len(pArrayListPassenger);i++)//libera el espacio en memoria de todos los pasajeros
        {
            aux =ll_get(pArrayListPassenger,i);
            Passenger_delete(aux);
        }
    }

    return retorno;
}

void Passenger_setNuevoId(char* path, int id){

	FILE* file;
	file=fopen(path,"w");
	if(file!=NULL){
		fprintf(file, "%d", id);
		fclose(file);
	}

}

int Passenger_getNuevoId(char* path){

	char id[20];
	FILE* file;
	int retorno=0;

	file=fopen(path,"r");
	if(file!=NULL){
	fscanf(file, "%[^\n]",id);
	retorno= atoi(id);
	fclose(file);
	}

	return retorno;
}
