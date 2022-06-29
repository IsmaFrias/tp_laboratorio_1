/********************************************************************************************************
   Programa: TP 3

	Objetivo:
		Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo, para lo cual
			se deberá desarrollar una solución implementando la biblioteca LinkedList.

		El sistema deberá tener el siguiente menú de opciones:
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
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Inputs.h"
#include "Passenger.h"
#include "parser.h"

int main()
{
    setbuf(stdout, NULL);

    int option;
    int guardado = 1;
    int len;
    int cargarDatos = 0;
    int contadorPasajerosAgregados = 0;
    int pasajerosAgregadosAntesDeGuardar = 0;
    int pasajerosEliminados = 0;
    int pasajerosEliminadosDespues = 0;
    int errorEdit;
    int errorRemover;
    int opcinesDelSort;
    int controlId = 0;
    int listaDeCantidadPasajeros = 0;
    int ultimoId;

		LinkedList* listaPasajeros = ll_newLinkedList();

		do{
			utn_getInt(&option, "\n\nMenu Principal:\n"
			"  1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
			"  2- Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
			"  3- Alta de pasajero\n"
			"  4- Modificar datos de pasajero\n"
			"  5- Baja de pasajero\n"
			"  6- Listar pasajeros\n"
			"  7- Ordenar pasajeros\n"
			"  8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
			"  9- Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
			"  10- Salir\n"
			"Elija una opción: ", "\nError eliga una opcion valida", 1, 10);

    	len = ll_len(listaPasajeros);
        switch(option)
        {
          case 1:
        	  if(cargarDatos == 0)
        	  {
				if(controller_loadFromText("data.csv",listaPasajeros) == 0)
				{
					cargarDatos = 1;
					printf("\nSe cargaron exitosamente los datos desde el modo texto\n");
					if(contadorPasajerosAgregados != 0 && controlId == 0)
					{
						if(controller_controlarId("data.csv", listaPasajeros, contadorPasajerosAgregados, pasajerosEliminados, &ultimoId) != -1)
						{
							printf("\nSe corrigieron los id de los pasajeros agregados anteriormente correctamente.\n");
							controlId = 1;
						}
						else
						{
							printf("\nNo se pudieron corregir los id de los pasajeros agregados anteriormente.\n");
						}
					}
					else
					{
						controller_controlarRepetidos(listaPasajeros, pasajerosAgregadosAntesDeGuardar);
					}
				}
				else
				{
					printf("\nNo se puedieron cargar los datos\n");
				}
            }
            else
            {
            	printf("\nDatos cargados!!!\n");
            }
            break;

            case 2:
            	if(cargarDatos == 0)
            	{
					if(controller_loadFromBinary("data.bin",listaPasajeros) == 0)
					{
						cargarDatos = 1;
						printf("\nSe cargaron exitosamente los datos desde el modo binario.\n");
						if(contadorPasajerosAgregados != 0 && controlId == 0)
						{
							if(controller_controlarId("data.csv", listaPasajeros, contadorPasajerosAgregados, pasajerosEliminados, &ultimoId) != -1)
							{
								printf("\nSe corrigieron los id de los pasajeros agregados anteriormente correctamente.\n");
								controlId = 1;
							}
							else
							{
								printf("\nNo se pudieron corregir los id de los pasajeros agregados anteriormente.\n");
							}
						}
						else
						{
							controller_controlarRepetidos(listaPasajeros, pasajerosAgregadosAntesDeGuardar);
						}
					}
					else
					{
						printf("\nNo se pudieron cargar los datos\n");
					}
            	}
            	else
            	{
            		printf("\nDatos cargados!!!\n");
            	}
            break;

            case 3:
            	if(controller_addPassenger(listaPasajeros, pasajerosEliminados, pasajerosEliminadosDespues, listaDeCantidadPasajeros, controlId, ultimoId, cargarDatos) == 0)
            	{
            		printf("\nSe ha agregado correctamente el pasajero!!!\n");
					guardado = 0;
					contadorPasajerosAgregados++;
					if(cargarDatos != 1)
					{
						pasajerosAgregadosAntesDeGuardar++;
					}
            	}
            	else
            	{
            		printf("\nNo se pudo agregar al pasajero.\n");
            	}
            	printf("\nVolviendo al menu...");
				break;

            case 4:
            	if(len != 0)
            	{
            		errorEdit = controller_editPassenger(listaPasajeros);

            		switch(errorEdit)
            		{
            		case -1:
            			printf("\nHubo un error en la lista.\n");
            		break;

            		case -2:
            			printf("Error el id no existe\n");
            		break;

            		case -3:
            			printf("Hubo un error al intentar obtener los datos del pasajero\n");
            		break;

            		default:
            			guardado = 0;
            		}
            	}
            	else
            	{
            		printf("\nNo se ingresó ningún pasajero.\n");
            	}
            	printf("\nVolviendo al menu...");
				break;

            case 5:
            	errorRemover = controller_removePassenger(listaPasajeros);
            	switch(errorRemover)
            	{
					case 0:
						pasajerosEliminados++;
						printf("\nSe dio de baja correctamente al pasajero de la lista.\n");
						if(controlId == 2)
						{
							pasajerosEliminadosDespues++;
						}
						guardado = 0;
					break;

					case -1:
						printf("\nError la lista esta vacia.\n");
					break;

					case -2:
						printf("\nError el id ingresado no existe\n");
					break;

					case -3:
						printf("\nSe cancelo la operacion.\n");
					break;
            	}
            	printf("\nVolviendo al menu...");
				break;
            case 6:
            	SeparadorConGuiones();
            	if(controller_ListPassenger(listaPasajeros) != 0)
            	{
            		printf("\nError la lista esta vacía\n");
					printf("\nVolviendo al menu...");
            	}
            	SeparadorConGuiones();
			break;
            case 7:
            	opcinesDelSort = controller_sortPassenger(listaPasajeros);

            	switch(opcinesDelSort)
            	{
					case 1:
						printf("\nSe ordenó correctamente los pasajeros por id.\n");
					break;

					case 2:
						printf("\nSe ordenó correctamente los pasajeros por apellido.\n");
					break;

					case 3:
						printf("\nSe ordenó correctamente los pasajeros por tipo de pasajero.\n");
					break;

					case 4:
						printf("\nSe ordenó correctamente los pasajeros por codigo de vuelo.\n");
					break;

					default:
						printf("\nNo se pudo ordenar correctamente los pasajeros.\n");
            	}
				break;

            case 9:
            	if(cargarDatos == 0 && controlId == 0)
            	{
            		listaDeCantidadPasajeros = controller_controlarId("data.csv", listaPasajeros, contadorPasajerosAgregados, pasajerosEliminados, &ultimoId);
            		if(listaDeCantidadPasajeros != -1)
            		{
						controlId = 2;
            		}
            		else
            		{
            			printf("\nNo se pudo corregir los id de los nuevos pasajeros ingresados\n");
            		}
            	}
            	ll_sort(listaPasajeros, Passenger_sortById, 1);
            	if(controller_saveAsText("data.csv", listaPasajeros, cargarDatos) == 0)
            	{
            		if(controller_saveAsBinary("data.bin", listaPasajeros, cargarDatos) == 0)
            		{
						printf("\nSe guardaron los datos de los pasajeros con exito en el archivo data.csv.\n");
						guardado = 1;
            		}
            	}
            	else
            	{
					printf("\nNo se pudo guardar los datos de los pasajeros en el archivo data.csv.\n");
            	}
				break;

            	default:
					if(guardado == 0)
					{
						printf("\nError guarde los datos antes de cerrar el sistema\n");
					}
					else
					{
						printf("\nCerrando sistema.\n");
					}
        }
    }while(option != 10 || guardado != 1);

    return 0;
}

