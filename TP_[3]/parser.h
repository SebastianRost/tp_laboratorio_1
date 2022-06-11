
/** \brief Parsea los datos los datos de los pasjeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
