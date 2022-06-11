/*
 * rost.h
 *
 *  Created on: 19 may. 2022
 *      Author: Rost Sebastian
 */

#ifndef ROST_H_
#define ROST_H_

int getOption(int min, int max);

/// @fn int validarEnteros(int, int, int)
/// @brief valida que un entero se encuentre dentro del rango seleccionado
///
/// @param numero numero a comprobar
/// @param desde valor minimo
/// @param hasta valor maximo
/// @return true o false
int validarEnteros(int numero,int desde,int hasta);

/// @fn int pedirEntero(char[], int, int)
/// @brief si se encuentra dentro del rango permite continuar
///
/// @param mensaje mensaje a mostrar
/// @param desde valor minimo
/// @param hasta valor maximo
/// @return el numero
int pedirEntero(char mensaje[],int desde,int hasta);

/// @fn int validarFloat(float, float, float)
/// @brief valida que un float se encuentre dentro del rango seleccionado
///
/// @param numero numero a comprobar
/// @param desde valor minimo
/// @param hasta valor maximo
/// @return true o false
int validarFloat(float numero,float desde,float hasta);

/// @fn int pedirFloat(char[], float, float)
/// @brief si se encuentra dentro del rango permite continuar
///
/// @param mensaje mensaje a mostrar
/// @param desde valor minimo
/// @param hasta valor maximo
/// @return el numero
float pedirFloat(char mensaje[],float desde,float hasta);

/** \brief menu de opciones
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int menuOpciones();

int getPath(char* path, int maxLen);

/** \brief submenu de criterio de ordenamiento
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuCriterio();

/** \brief submenu de orden (ascendente / descendente)
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuOrden();

/** \brief submenu de modificaicon
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuModificacion();

/** \brief pide y valida una opcion
 *
 * \param min int opcion minima
 * \param max int opcion maxima
 *
 */
int getOption(int min, int max);

/** \brief Pide un nombre al usuario y lo valida
 *
 * \param nombre char* nombre
 * \param maxLen int maximo de caracteres permitidos
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int getNombre(char *nombre, int maxLen);

/** \brief Pide un apellido al usuario y lo valida
 *
 * \param apellido char* apellido
 * \param maxLen int maximo de caracteres permitidos
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int getApellido(char *apellido, int maxLen);

/** \brief Pide un codigo de vuelo al usuario y lo valida
 *
 * \param codigoVuelo char* codigo de vuelo
 * \param maxLen int maximo de caracteres permitidos
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int getCodigoVuelo(char *codigoVuelo, int maxLen);

/** \brief Pide estado de vuelo al usuario y lo valida
 *
 * \param estadoVuelo char* estado de vuelo
 * \param maxLen int maximo de caracteres permitidos
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int getEstadoVuelo(char *estadoVuelo, int maxLen);

/** \brief Pide tipo de pasajero al usuario y lo valida
 *
 * \param tipoPasajero char* tipo de pasajero
 * \param maxLen int maximo de caracteres permitidos
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int getTipoPasajero(char *tipoPasajero, int maxLen);


#endif /* ROST_H_ */
