#include <stdio.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Inputs.h"

/*****************************************************************************/

int initPassengers(Passenger pasajeros[], int sizePasajeros)
{
	int index;
	index = -1;

	for(int i=0; i<sizePasajeros; i++)
			{
				pasajeros[i].isEmpty = LIBRE;
				index = i;
				break;
			}
	return index;
}

/*****************************************************************************/

int addPassenger(Passenger pasajeros[], int sizePasajeros, int contadorIDs)
{
	int index;

		index = buscarLugarLibre(pasajeros, sizePasajeros);

			if(index != -1)
			{
				pasajeros[index].id = contadorIDs;
				PedirCadena(pasajeros[index].name, "\nIngrese nombre: ");
				PedirCadena(pasajeros[index].lastName, "\nIngrese apellido: ");
				do{ printf("\nIngrese precio: ");
				    }while(validarFloat("%f", &pasajeros[index].price));
				PedirAlfanumerico(pasajeros[index].flyCode, "\nIngrese codigo de vuelo: ");
				if(utn_getNumero(&pasajeros[index].typePassenger, "\nIngrese tipo de pasajero (Economico => 1 / Turista => 2 / Ejecutivo => 3): ",
						"\nError ingrese un tipo valido", 1, 3, 500)==0)
				if(utn_getNumero(&pasajeros[index].statusFlight, "\nIngrese estado de vuelo (ACTIVO => 0 / INACTIVO => 1 / DEMORADO => 2): ",
						"\nError ingrese un estado valido", 0, 2, 500)==0) //Me parece que no es así pero no sabia otra manera de implementarlo :(
				pasajeros[index].isEmpty = OCUPADO;
			}
	return index;
}

/*****************************************************************************/

int findPassengerById(Passenger pasajeros[], int sizePasajeros)
{
	int idPasajero;
	int retorno;
	retorno = -1;

			if(utn_getNumero(&idPasajero, "\nIngrese ID del pasajero a modificar: ",
					"\nError ingrese un ID, valido", 0, 10000, 50)==0)

			for(int i = 0; i<sizePasajeros; i++)
			{
				if(pasajeros[i].isEmpty == OCUPADO && pasajeros[i].id == idPasajero)
				{
					printf("\nSe encontro a el pasajero: %s %s",pasajeros[i].name, pasajeros[i].lastName);
					retorno = idPasajero;
				}
			}
	return retorno;
}

/*****************************************************************************/

int removePassenger(Passenger pasajeros[], int idPasajero, int sizePasajeros)
{
	int eliminado;
	char respuesta[5];
	eliminado = -1;

		for(int i = 0; i<sizePasajeros; i++)
		{
			if(pasajeros[i].isEmpty == OCUPADO && pasajeros[i].id == idPasajero)
			{
				fflush(stdin);
				PedirCadena(respuesta, "Seguro que desea dar de baja este pasajero?(si-no): ");
				if(strcmp(respuesta, "si")== 0){

					pasajeros[i].isEmpty = LIBRE;
					eliminado = 1;
				}
			}
		}
	return eliminado;
}

/*****************************************************************************/

int ModificarNombre(Passenger pasajeros[], int idPasajero, int sizePasajeros)
{
	char nuevoNombre[51];
	char respuesta[5];
	int retorno;
	retorno = -1;

		for(int i = 0; i<sizePasajeros; i++)
		{
			if(pasajeros[i].isEmpty == OCUPADO && pasajeros[i].id == idPasajero)
			{
				fflush(stdin);
				PedirCadena(respuesta, "\nSeguro que desea modificar el nombre?(si-no): ");
				if(strcmp(respuesta, "si")== 0){
					fflush(stdin);
					PedirCadena(nuevoNombre, "\nIngrese nuevo nombre: ");
					strcpy(pasajeros[i].name, nuevoNombre);
					fflush(stdin);
					retorno = 1;
				}
			}
		}
	return retorno;
}

/*****************************************************************************/

void printPassengers(Passenger pasajeros[], int sizePasajeros)
{
	for(int i=0; i<sizePasajeros; i++)
	{
		if(pasajeros[i].isEmpty == OCUPADO)
		{
			if(pasajeros[i].typePassenger == 1)
			{
				printf("Numero ID: %2d %10s %4s    Ejecutivo     Codigo de vuelo: %s\n", pasajeros[i].id, pasajeros[i].name, pasajeros[i].lastName, pasajeros[i].flyCode);
			}
			else if(pasajeros[i].typePassenger == 2)
			{
				printf("Numero ID: %2d %10s %4s    Turista     Codigo de vuelo: %s\n", pasajeros[i].id, pasajeros[i].name, pasajeros[i].lastName, pasajeros[i].flyCode);
			}
			else if(pasajeros[i].typePassenger == 3)
			{
				printf("Numero ID: %2d %10s %4s    Economico     Codigo de vuelo: %s\n", pasajeros[i].id, pasajeros[i].name, pasajeros[i].lastName, pasajeros[i].flyCode);
			}
		}
	}
}

/*****************************************************************************/

void inicializarListaPasajeros(Passenger pasajeros[])
{
	Passenger auxiliar[3] = {{1,"Josema","Gomez", 1000.00, "ac34cd", 3, 0, OCUPADO},
							 {2,"Manuel","Diaz", 1500.23, "a1vp6f", 1, 1, OCUPADO},
							 {3,"Samuel","Sanchez", 2000.45, "s6vs3v", 2, 0, OCUPADO}};

		for(int i=0; i<3; i++)
		{
				pasajeros[i] = auxiliar[i];
		}
}

/*****************************************************************************/

int buscarLugarLibre(Passenger pasajeros[], int sizePasajeros)
{
	int index;
	index = -1;

	for(int i=0; i<sizePasajeros; i++)
	{
		if(pasajeros[i].isEmpty == LIBRE)
		{
			index = i;
			break;
		}
	}
	return index;
}

/*****************************************************************************/

int ModificarApellido(Passenger pasajeros[], int idPasajero, int sizePasajeros)
{
	char nuevoApellido[100];
	char respuesta[5];
	int retorno;
	retorno = -1;

		for(int i = 0; i<sizePasajeros; i++)
		{
			if(pasajeros[i].isEmpty == OCUPADO && pasajeros[i].id == idPasajero)
			{
				fflush(stdin);
				PedirCadena(respuesta, "\nSeguro que desea modificar el apellido?(si-no): ");
				if(strcmp(respuesta, "si")== 0){
					fflush(stdin);
					PedirCadena(nuevoApellido, "\nIngrese nuevo apellido: ");
					strcpy(pasajeros[i].lastName, nuevoApellido);
					fflush(stdin);
					retorno = 1;
				}
			}
		}
	return retorno;
}

/*****************************************************************************/

int ModificarPrecio(Passenger pasajeros[], int idPasajero, int sizePasajeros)
{
		char respuesta[5];
		int retorno;
		retorno = -1;

			for(int i = 0; i<sizePasajeros; i++)
			{
				if(pasajeros[i].isEmpty == OCUPADO && pasajeros[i].id == idPasajero)
				{
					fflush(stdin);
					PedirCadena(respuesta, "\nSeguro que desea modificar el precio?(si-no): ");
					if(strcmp(respuesta, "si")== 0){
						fflush(stdin);
						do{ printf("\nIngrese nuevo precio: ");
						  }while(validarFloat("%f", &pasajeros[i].price));
	    			   	fflush(stdin);
						retorno = 1;
					}
				}
			}
		return retorno;
}

/*****************************************************************************/

int ModificarTipoDePasajero(Passenger pasajeros[], int idPasajero, int sizePasajeros)
{
	char respuesta[5];
	int retorno;
	retorno = -1;

			for(int i = 0; i<sizePasajeros; i++)
			{
				if(pasajeros[i].isEmpty == OCUPADO && pasajeros[i].id == idPasajero)
				{
					fflush(stdin);
					PedirCadena(respuesta, "\nSeguro que desea modificar el tipo de pasajero?(si-no): ");
					if(strcmp(respuesta, "si")== 0)
					{
						fflush(stdin);
						if(utn_getNumero(&pasajeros[i].typePassenger, "\nIngrese el nuevo tipo de pasajero (Economico => 1 / Turista => 2 / Ejecutivo => 3): ",
							"\nError ingrese un tipo valido", 1, 3, 50)==0)
	    			   	fflush(stdin);
						retorno = 1;
					}
				}
			}
	return retorno;
}

/*****************************************************************************/

int ModificarCodigoDeVuelo(Passenger pasajeros[], int idPasajero, int sizePasajeros)
{
	char respuesta[5];
		int retorno;
		retorno = -1;

				for(int i = 0; i<sizePasajeros; i++)
				{
					if(pasajeros[i].isEmpty == OCUPADO && pasajeros[i].id == idPasajero)
					{
						fflush(stdin);
						PedirCadena(respuesta, "\nSeguro que desea modificar el codigo de vuelo?(si-no): ");
						if(strcmp(respuesta, "si")== 0)
						{
							fflush(stdin);
							PedirAlfanumerico(pasajeros[i].flyCode, "\nIngrese nuevo codigo de vuelo: ");
		    			   	fflush(stdin);
							retorno = 1;
						}
					}
				}
		return retorno;
}

/*****************************************************************************/

void SortPassengers(Passenger pasajeros[], int sizePasajeros)
{
	Passenger auxiliarPasajero;
		for(int i = 0; i < sizePasajeros-1; i++)
		{
			for(int j = i+1; j<sizePasajeros; j++)
			{
				if(strcmp(pasajeros[j].name,pasajeros[i].name)<0)
				{
					auxiliarPasajero = pasajeros[j];
					pasajeros[j] = pasajeros[i];
					pasajeros[i] = auxiliarPasajero;
				}
			}
		}
		mostrarNombreYTipoDePasajero(pasajeros, sizePasajeros);
}

/*****************************************************************************/

void mostrarNombreYTipoDePasajero(Passenger pasajeros[], int sizePasajeros)
{
		for(int i=0; i<sizePasajeros; i++)
		{
			if(pasajeros[i].isEmpty == OCUPADO)
			{
				if(pasajeros[i].typePassenger == 1)
				{
					printf("%s  Economico\n", pasajeros[i].name);
				}
				else if(pasajeros[i].typePassenger == 2)
				{
					printf("%s  Turista\n", pasajeros[i].name);
				}
				else{
					printf("%s  Ejecutivo\n", pasajeros[i].name);
				}
			}
		}
}

/*****************************************************************************/

void totalYPromedio(Passenger pasajeros[], int sizePasajeros)
{
	float contadorPrecios;
	int contadorPasajeros;
	float promedio = 0;
	int cantidadPasajMayorAlPromedio;
	contadorPrecios = 0;
	contadorPasajeros = -1;
	cantidadPasajMayorAlPromedio = 0;

	for(int i=0; i<sizePasajeros; i++)
	{
		if(pasajeros[i].isEmpty == OCUPADO)
		{
			contadorPasajeros++;
			contadorPrecios = contadorPrecios + pasajeros[i].price;
		}
	}
	promedio = contadorPrecios / contadorPasajeros;

	printf("\nEl precio total de los pasajes es: %.2f\n\nEl promedio total es: %.2f\n", contadorPrecios, promedio);

		for(int j=0; j<sizePasajeros; j++)
		{
			if(pasajeros[j].isEmpty == OCUPADO)
			{
				if(pasajeros[j].price > promedio)
				{
					cantidadPasajMayorAlPromedio++;
				}
			}
		}
		printf("\nLa cantidad de personas que superan al promedio es: %d\n", cantidadPasajMayorAlPromedio);
}

/*****************************************************************************/

void listaPorCodigoDeVueloYEstado(Passenger pasajeros[], int sizePasajeros)
{
	for(int i=0; i<sizePasajeros; i++)
	{
		if(pasajeros[i].isEmpty == OCUPADO)
		{
			if(pasajeros[i].statusFlight == ACTIVO)
			{
				printf("\nCodigo de vuelo: %s   Estado de vuelo: Activo    Nombre : %s\n", pasajeros[i].flyCode, pasajeros[i].name);
			}
		}
	}
}

/*****************************************************************************/

void cargaForzada()
{
	printf("\nNombre: Daniel  Apellido: Rodriguez  Codigo de vuelo: asd124  Tipo: Ejecutivo\n");
	printf("\nNombre: Ismael  Apellido: Frias  Codigo de vuelo: djk456 Tipo: Turista\n");
	printf("\nNombre: Fabricio  Apellido: Roman  Codigo de vuelo: qwe123 Tipo: Economico\n");
	printf("\nNombre: Agustin  Apellido: Benitez  Codigo de vuelo: laks012 Tipo: Turista\n");
	printf("\nNombre: Matias  Apellido: Cardozo  Codigo de vuelo: erty126 Tipo: Ejecutivo\n");
}
