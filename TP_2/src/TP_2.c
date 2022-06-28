/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Inputs.h"
#define T 50

int main(void) {
	setbuf(stdout, NULL);

	Passenger pasajeros[T];

	int opcion;
	int retorno;
	int cambio;
	int contadorIDs;
	contadorIDs = 3;

	retorno = initPassengers(pasajeros, T);


	 inicializarListaPasajeros(pasajeros);


		do{
			if(utn_getNumero(&opcion, "\n1-Cargar\n2-Modificar\n3-Dar de baja\n4-Informar listado\n5"
					"-Carga forzasa\n6-Salir\n\nIngrese una opcion: ",
					"\nError ingrese una opcion valida\n", 0, 6, 50) == 0){

			}

			switch(opcion)
			{
			case 1:
				contadorIDs++;
				retorno = addPassenger(pasajeros, T, contadorIDs);

					switch(retorno)
					{
					case -1:
						printf("\nNo hay mas espacio\n");
					break;
					default:
						printf("\nSe agrego al pasajero exitosamente!!!\n");
					break;
					}
			break;

			case 2:
					printf("\nQue desea modificar?\n");
					if(utn_getNumero(&opcion, "\n1-Nombre\n2-Apellido\n3-Precio\n4-Tipo de pasajero\n5-Codigo de vuelo\n\nIngrese una opcion: ",
							"\nError ingrese una opcion valdia", 0, 5, 50)==0)
					switch(opcion)
					{
					case 1:
						SeparadorConGuiones();//Modificación nombre
						printPassengers(pasajeros, T);
						SeparadorConGuiones();
						retorno = findPassengerById(pasajeros, T);
							if(retorno == -1)
							{
								printf("\nNo se econtro el pasajero\n");
							}
							else{
								cambio = ModificarNombre(pasajeros, retorno, T);
									if(cambio != -1)
									{
										printf("\nSe cambio el nombre exitosamente!!!\n");
									}
									else
									{
										printf("\nSe cancelo la operación\n");
									}

								}
					break;
					case 2:
						SeparadorConGuiones();//Modificación apellido
						printPassengers(pasajeros, T);
						SeparadorConGuiones();
						retorno = findPassengerById(pasajeros, T);
						if(retorno == -1)
						{
							printf("\nNo se econtro el pasajero\n");
						}
						else{
							cambio = ModificarApellido(pasajeros, retorno, T);
								if(cambio != -1)
								{
									printf("\nSe cambio el apellido exitosamente!!!\n");
								}
								else
								{
									printf("\nSe cancelo la operación\n");
								}

							}
					break;
					case 3:
						SeparadorConGuiones();//Modificación precio
						printPassengers(pasajeros, T);
						SeparadorConGuiones();
						retorno = findPassengerById(pasajeros, T);
						if(retorno == -1)
						{
							printf("\nNo se econtro el pasajero\n");
						}
						else{
							cambio = ModificarPrecio(pasajeros, retorno, T);
								if(cambio != -1)
								{
									printf("\nSe cambio el precio exitosamente!!!\n");
								}
								else
								{
									printf("\nSe cancelo la operación\n");
								}
							}
					break;
					case 4:
						SeparadorConGuiones();//Modificación tipo de pasajero
						printPassengers(pasajeros, T);
						SeparadorConGuiones();
						retorno = findPassengerById(pasajeros, T);
						if(retorno == -1)
						{
							printf("\nNo se econtro el pasajero\n");
						}
						else{
								cambio = ModificarTipoDePasajero(pasajeros, retorno, T);
								if(cambio != -1)
								{
									printf("\nSe cambio el tipo de pasajero exitosamente!!!\n");
								}
								else
								{
									printf("\nSe cancelo la operación\n");
								}
							}
					break;
					case 5:
						SeparadorConGuiones();
						printPassengers(pasajeros, T);
						SeparadorConGuiones();
						retorno = findPassengerById(pasajeros, T);
						if(retorno == -1)
						{
							printf("\nNo se econtro el pasajero\n");
						}
						else{
								cambio = ModificarCodigoDeVuelo(pasajeros, retorno, T);
								if(cambio != -1)
								{
									printf("\nSe cambio el codigo de vuelo exitosamente!!!\n");
								}
								else
								{
									printf("\nSe cancelo la operación\n");
								}
							}
					break;

					case 6:
					break;
					}

			break;

			case 3: //Dar de baja
				printPassengers(pasajeros, T);
				retorno = findPassengerById(pasajeros, T);
				if(retorno == -1)
				{
					printf("\nNo se econtro el pasajero\n");
				}
				else{
						cambio = removePassenger(pasajeros, retorno, T);
							if(cambio != -1)
							{
								printf("\nSe dio de baja el pasajero exitosamente!!!\n");
							}
							else
							{
								printf("\nSe cancelo la operación\n");
							}
					}
			break;

			case 4:
				printf("\nQue desea ver?\n");
				if(utn_getNumero(&opcion, "\n1-Lista ordenada por nombre\n2-Precio total y promedio\n3-Lista por codigo de vuelo y estado\n\nIngrese una opcion: ",
											"\nError ingrese una opcion valdia", 0, 3, 50)==0)
				switch(opcion)
				{
				case 1:
					SeparadorConGuiones();
					SortPassengers(pasajeros, T);
					SeparadorConGuiones();
				break;
				case 2:
					SeparadorConGuiones();
					totalYPromedio(pasajeros, T);
					SeparadorConGuiones();
				break;
				case 3:
					SeparadorConGuiones();
					listaPorCodigoDeVueloYEstado(pasajeros, T);
					SeparadorConGuiones();
				break;
				}


			break;
			case 5:
				SeparadorConGuiones();
				cargaForzada();
				SeparadorConGuiones();
			break;

			}//Termina el switch

		}while(opcion !=6);//Termina el do while

	return EXIT_SUCCESS;
}
