/// @brief Calcula el promedio de dos numeros
/// @param numero1 primer número ingresado
/// @param numero2 segundo número ingresado
/// @return Retorna el promedio de los dos números
float CalcularPromedio(float numero1, float numero2);

/// @brief solicita un numero al usuario, luego de verificar devuelve el resultado
/// @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje el mensaje a ser mostrado
/// @param mensajeError el mensaje de error a ser mostrado
/// @param minimo es el número maximo a ser aceptado
/// @param maximo es el número minimo a ser aceptado
/// @param reintentos la cantidad de reintentos
/// @return retorna 0 si se obtubo el número y -1 si no
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief verifica si el valor recibido contiene solo letras
/// @param array con la cadena a ser analizada
/// @return retorna 1 si contiene solo ' ' y letras, y retorna 0 si no lo es
int validarNombre(char nombre[]);

/// @brief Pide una cadena y la valida
/// @param nombre variable donde se almacenara la cadena
/// @param mensaje a mostrar al usuario
void PedirCadena(char nombre[], char mensaje[]);

/// @brief Pide una cadena
/// @param Mensaje que pide que ingrese cadena
/// @return
void PedirCadena(char variable[], char mensaje[]);

/// @brief valida si un dato es de tipo flotante o entero
/// @param fm
/// @param var
/// @return
int validarFloat(const char* fm, void* var);

/// @brief Calcula el promedio de dos numeros
/// @param numero1 primer número ingresado
/// @param numero2 segundo número ingresado
/// @return Retorna el promedio de los dos números
float CalcularPromedio(float numero1, float numero2);

/// @brief Pide un dato que contenga contiene numeros y letras
/// @param nombre variable donde se guardara la cadena
/// @param mensaje que el usuario va a mostrar
void PedirAlfanumerico(char nombre[], char mensaje[]);

/// @brief Valida si la cadena recibida es alfanumerica
/// @param variable recibida
/// @return retorna la cadena si es que es alfanumerica
int validarAlfanumerico(char variable[]);

/// @brief Crea una linea de guiones para que quede mas vistoso
void SeparadorConGuiones(void);

/// @brief Crea una linea de guiones mas corta para que quede mas vistoso
void SeparadorConGuionesCorto(void);
