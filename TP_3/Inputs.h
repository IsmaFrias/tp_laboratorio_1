#ifndef INPUTS_H_
#define INPUTS_H_

/*****************************************************************************/

/// @brief Le pide al usuario que ingrese el codigo del vuelo
///
/// @param codigoDeVuelo puntero que devuelve el codigo de vuelo ingresado
/// @param mensaje mensaje que donde se imprime la peticion
void pedirCodigoVuelo(char codigoDeVuelo[10], char* mensaje);

/*****************************************************************************/

/// @brief lee el stdin hasta que encuentra un '\n' o hsta que haya
/// copiado en cadena un maximo de 'longitud' -1 caracteres
/// @param pResultado puntero al espacio de memoria donde se copiara
/// donde se copiara la cadena obtenida
/// @param longitud define el tamaño de la cadea
/// @return retorna 0 (exito) si se obtiene una cadena si no -1 (error)
int myGets(char* cadena, int longitud);

/*****************************************************************************/

/// @brief transforma el string obtenido de esNumerica y myGets a un entero
/// @param pResultado puntero por donde se devuelve el entero obtenido
/// @return devuelve -1 si hubo un error en esta funcion o en alguna de las anteriores - 0 si esta ok
int getInt(int* pResultado);

/*****************************************************************************/

/// @brief verifica si la cadena ingresad es númerica
/// @param cadena de caracteres a ser analizada
/// @return retorna 1 (verdadero) si la cadena es numerica, 0 (falso) y -1 en caso de error
int esNumerica(char* cadena);

/*****************************************************************************/

/// @brief pide al usuario que ingrese un entero usando getInt, verifica que este dentro de los parametros establecidos
/// 	   y duevle el entero generado
/// @param pResultado puntero por el cual devuelve el entero generado
/// @param mensaje mensaje que se imprime para pedir el dato al usuario
/// @param mensajeError mensaje que se imprime si no se ingresa un entero
/// @param minimo parametro que delimita el numero minimo a ingresar
/// @param maximo parametro que delimita el numero maximo a ingresar
/// @return devuelve -1 si hubo un error - 0 si esta ok
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);

/*****************************************************************************/

/// @brief verifica el string obtenido de esNumerica y myGets
/// @param pResultado pResultado puntero por donde se devuelve el string obtenido
/// @return devuelve -1 si hubo un error en esta funcion o en alguna de las anteriores - 0 si esta ok
int getFloat(char *pResultado);

/*****************************************************************************/

/// @brief pide al usuario que ingrese un flotante usando getFloat, verifica que este dentro de los parametros establecidos
/// 	   y duevle el string generado
/// @param pResultado puntero por el cual devuelve el string generado
/// @param mensaje mensaje que se imprime para pedir el dato al usuario
/// @param mensajeError mensaje que se imprime si no se ingresa un flotante
/// @return devuelve -1 si hubo un error - 0 si esta ok
int utn_getFloat(char *pResultado, char *mensaje, char *mensajeError);

/*****************************************************************************/

/// @brief pide al usuario que ingrese un nombre, verifica que no se hayan ingresados caracteres
/// 	   que no sean letras y devuelve el nombre generado
/// @param cadena puntero por donde se devuelve el nombre generado
/// @param mensaje mensaje que se imprime para pedirle al usuario que ingrese el dato
/// @param mensajeError mensaje que se imprime si hay caracteres que no son letras
/// @return devuelve -1 si hubo un error - 0 si esta ok
int utn_getName(char* cadena, char* mensaje, char* mensajeError);

/*****************************************************************************/

/// @brief transforma toda la cadena a minuscula y solo pasa a mayuscula la inicial de cada nombre ingresado
/// @param cadena puntero por el cual devuelve la cadena con las mayusculas corregidas
void utn_corregirMayus(char* cadena);

/*****************************************************************************/

/// @brief Crea una linea de guiones para que quede mas vistoso
void SeparadorConGuiones(void);

/*****************************************************************************/

/// @brief Crea una linea de guiones mas corta para que quede mas vistoso
void SeparadorConGuionesCorto(void);

/*****************************************************************************/

/// @brief Valida si la cadena recibida es alfanumerica
/// @param variable recibida
/// @return retorna la cadena si es que es alfanumerica
int validarAlfanumerico(char variable[]);

/*****************************************************************************/

/// @brief Pide un dato que contenga contiene numeros y letras
/// @param nombre variable donde se guardara la cadena
/// @param mensaje que el usuario va a mostrar
void PedirAlfanumerico(char nombre[], char mensaje[]);

/*****************************************************************************/

#endif
