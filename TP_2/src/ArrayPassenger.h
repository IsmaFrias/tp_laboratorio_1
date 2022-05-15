#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1
#define Economico 1
#define Turista 2
#define Ejecutivo 3
#define ACTIVO 0
#define INACTIVO 1
#define DEMORADO 2


typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

///@brief To indicate that all position in the array are empty,
///this function put the flag (isEmpty) in TRUE in all
///position of the array
///@param list Passenger* Pointer to array of passenger
///@param len int Array length
///@return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initPassengers(Passenger pasajeros[], int sizePasajeros);

///@brief: add in a existing list of passengers the values received as parameters
///in the first empty position
///@param list passenger
///@param length of the list
///@param id counter
///@return int Return (-1) if Error [Invalid length or NULL pointer or without
///free space] - (0) if Ok
int addPassenger(Passenger pasajeros[], int sizePasajeros, int contadorIDs);

///@brief find a Passenger by Id en returns the index position in array.
///@param list Passenger
///@param length of the list
///@return Return passenger index position or (-1) if [Invalid length or
///NULL pointer received or passenger not found]
int findPassengerById(Passenger pasajeros[], int sizePasajeros);

///@brief Remove a Passenger by Id (put isEmpty Flag in 1)
///@param list Passenger
///@param id int
///@return int Return (-1) if Error [Invalid length or NULL pointer or if can't
///find a passenger] - (0) if Ok
int removePassenger(Passenger pasajeros[], int idPasajero, int sizePasajeros);

/// @brief modifica el nombre del id que viene por parametro
/// @param lista de pasajeros
/// @param id que viene por parametro
/// @param largo de la lista
/// @return retorna -1 si se cancelo la operacion o 1 si fue exitosa
int ModificarNombre(Passenger pasajeros[], int idNombre, int sizePasajeros);

///@brief print the content of passengers array
///@param list Passenger*
///@param length int
void printPassengers(Passenger pasajeros[], int sizePasajeros);

/// @brief inicializa la lista con los pasajeros hardcodeados
/// @param lista de pasajeros
void inicializarListaPasajeros(Passenger pasajeros[]);

/// @brief busca si hay espacio libre en la lista antes de agregar un nuevo pasajero
/// @param lista pasajeros
/// @param largo de la lisa
/// @return retorna -1 no hay espacio o la posicion libre si es que lo hay
int buscarLugarLibre(Passenger pasajeros[], int sizePasajeros);

/// @brief modifica el apellido del id que viene por parametro
/// @param lista de pasajeros
/// @param id que viene por parametro
/// @param largo de la lista
/// @return retorna -1 si se cancelo la operacion o 1 si fue exitosa
int ModificarApellido(Passenger pasajeros[], int idNombre, int sizePasajeros);

/// @brief modifica el precio del id que viene por parametro
/// @param lista pasajeros
/// @param id que viene por parametro
/// @param largo de la lista
/// @return retorna -1 si se cancelo la operacion o 1 si fue exitosa
int ModificarPrecio(Passenger pasajeros[], int idPasajero, int sizePasajeros);

///// @brief muestra una lista de id, nombre y apellido
///// @param pasajeros
//void MostrarIDNomYApellTipo(Passenger pasajeros);

/// @brief modifica el tipo de pasajero del id que viene por parametro
/// @param lista pasajeros
/// @param id que viene por parametro
/// @param largo de la lista
/// @return retorna -1 si se cancelo la operacion o 1 si fue exitosa
int ModificarTipoDePasajero(Passenger pasajeros[], int idPasajero, int sizePasajeros);

/// @brief modifica el codigo de vuelo del id que viene por parametro
/// @param lista de pasajeros
/// @param id que viene por parametro
/// @param largo de la lista
/// @return retorna -1 si se cancelo la operacion o 1 si fue exitosa
int ModificarCodigoDeVuelo(Passenger pasajeros[], int idPasajero, int sizePasajeros);

///@brief Sort the elements in the array of passengers, the argument order
///indicate UP or DOWN order
///@param list Passenger*
///@param len int
///@param order int [1] indicate UP - [0] indicate DOWN
///@return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
void SortPassengers(Passenger pasajeros[], int sizePasajeros);

/// @brief  muestra una lista de nombre y tipo de pasajero
/// @param lista depasajeros
/// @param largo de la lista
void mostrarNombreYTipoDePasajero(Passenger pasajeros[], int sizePasajeros);

/// @brief calcula el precio total y el promedio
/// @param lista de pasajeros
/// @param largo de la lista
void totalYPromedio(Passenger pasajeros[], int sizePasajeros);

/// @brief muestra una lista de codigo de vuelo y estado ACTIVO
/// @param lista de pasajeros
/// @param largo de la lista
void listaPorCodigoDeVueloYEstado(Passenger pasajeros[], int sizePasajeros);
