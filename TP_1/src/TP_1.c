/*
 ============================================================================
 Nombre      : Ismael Alejandro Frias
 Dividion    : Div B
 Nro de TP   : Trabajo Prctico Nro 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "BiblioTP_1.h"


int main(void) {
	setbuf(stdout, NULL);

	int opciones; // \brief variable,  para la elecci�n de opcines
	float km; // \brief variable flotante, para almacenar los Kilometros
	float y; // \brief variable flotante, para almacenar el precio de Aerolineas
	float z; // \brief variable flotante, para almacenar el precio de Latam
	float precioTarjDebAerolineas; // \brief variable flotante, para almacenar el retorno de la funcion "CalcularPrecioTarjetaDebitoAerolineas"
	float precioTarjCredAerolineas; // \brief variable flotante, para almacenar el retorno de la funcion "CalcularPrecioTarjetaDebitoLatam"
	float precioBTCaerolineas; // \brief variable flotante, para almacenar el retorno de la funcion "CalcularPrecioBitcoinAerolineas"
	float precioUnitarioAerolineas; // \brief variable flotante, para almacenar el retorno de la funcion "CalcularPrecioUnitarioAerolineas"

	float precioTarjDebLatam; // \brief variable flotante, para almacenar el retorno de la funcion "CalcularPrecioTarjetaDebitoLatam"
	float precioTarjCredLatam; // \brief variable flotante, para almacenar el retorno de la funcion "CalcularPrecioTarjetaCreditoLatam"
	float precioBTClatam; // \brief variable flotante, para almacenar el retorno de la funcion "CalcularPrecioBitcoinLatam"
	float precioUnitarioLatam; // \brief variable flotante, para almacenar el retorno de la funcion "CalcularPrecioUnitarioLatam"

	float diferenciaPrecio; // \brief variable flotante, para almacenar la diferencia de precio entre Aerolineas y Latam

	km = 0; // Inicializaci�n kilometros
	y = 0; // Inicializaci�n precio Aerolineas
	z = 0; // Inicializaci�n precio Latam
	precioTarjDebAerolineas = 0; // Inicializaci�n para poder validar el case 4

			do{
				printf("1)Ingresar Kil�metros: (km = %.2f)", km);
				printf("\n2)Ingresar precio de vuelos: (Aerol�neas = %.2f, Latam = %.2f)", y, z);
				printf("\n3)Calcular todos los costos.");
				printf("\n4)Informar Resultados.");
				printf("\n5)Carga forzada de datos.");
				printf("\n6)Salir.\n");

				fflush(stdin);
				scanf("%d", &opciones);

				switch(opciones){
					case 1:
						km = pedirUnNumero("Ingrese KM: ");
						printf("\n\n\n\n\n");
						break;

					case 2:
						printf("Ingresar Precio de Vuelos:\n");
						y = pedirUnNumero("- Precio vuelo Aerol�neas: ");
						z = pedirUnNumero("- Precio vuelo Latam: ");
						printf("\n\n\n\n\n");
						break;

					case 3:
						if (km == 0){
							printf("Por favor, ingrese un kilometraje antes de calcular los costos\n");
							printf("\n\n\n\n\n");
						}
						else if(y == 0 && z == 0){
							printf("No se introdujo ning�n precio en Aerolineas Arg. y Latam\n");
							printf("\n\n\n\n\n");
						}
						else{
							precioTarjDebAerolineas = CalculadorPrecioTarjDebitoAerolineasArg(y);
							precioTarjCredAerolineas = CalculadorPrecioTarjCreditoAerolineasArg(y);
							precioBTCaerolineas = CalculadorPrecioBTCaerolineasArg(y);
							precioUnitarioAerolineas = CalculadorPrecioUnitarioAerolineasArg(km, y);

							precioTarjDebLatam = CalculadorPrecioTarjDebitoLatam(z);
							precioTarjCredLatam = CalculadorPrecioTarjCreditoLatam(z);
							precioBTClatam = CalculadorPrecioBTClatam(z);
							precioUnitarioLatam = CalculadorPrecioUnitarioLatam(km, z);

							diferenciaPrecio = DiferenciaDePrecio(z, y);

							printf("Se calcularon todos los costos\n");

						}
						printf("\n\n\n\n\n");
						break;

					case 4:
						if (km == 0 && y == 0 && z == 0){
							printf("No se introdujo ning�n valor\n");
							printf("\n\n\n\n\n");
						}
						else if(precioTarjDebAerolineas == 0){
							printf("\nPor favor calcule los costos antes de informar los resultados\n");
							printf("\n\n\n\n\n");
						}
						else{
						printf("\nAerol�neas: %.2f", y);
						printf("\na) Precio con tarjeta de d�bito: %.2f", precioTarjDebAerolineas);
						printf("\nb) Precio con tarjeta de cr�dito: %.2f", precioTarjCredAerolineas);
						printf("\nc) Precio pagando con bitcoin : %f", precioBTCaerolineas);
						printf("\nd) Precio unitario: %.2f", precioUnitarioAerolineas);

						printf("\n\nLatam: %.2f", z);
						printf("\na) Precio con tarjeta de d�bito: %.2f", precioTarjDebLatam);
						printf("\nb) Precio con tarjeta de cr�dito: %.2f", precioTarjCredLatam);
						printf("\nc) Precio pagando con bitcoin : %f", precioBTClatam);
						printf("\nd) Precio unitario: %.2f\n", precioUnitarioLatam);
						printf("\nLa diferencia es: %.2f\n", diferenciaPrecio);

						printf("\n\n\n\n\n");
						}
						break;

					case 5:
						printf("Carga forzada...\n");

						km = 7090;
						y = 162965;
						z = 159339;

						precioTarjDebAerolineas = CalculadorPrecioTarjDebitoAerolineasArg(y);
						precioTarjCredAerolineas = CalculadorPrecioTarjCreditoAerolineasArg(y);
						precioBTCaerolineas = CalculadorPrecioBTCaerolineasArg(y);
						precioUnitarioAerolineas = CalculadorPrecioUnitarioAerolineasArg(km, y);

						precioTarjDebLatam = CalculadorPrecioTarjDebitoLatam(z);
						precioTarjCredLatam = CalculadorPrecioTarjCreditoLatam(z);
						precioBTClatam = CalculadorPrecioBTClatam(z);
						precioUnitarioLatam = CalculadorPrecioUnitarioLatam(km, z);

						diferenciaPrecio = DiferenciaDePrecio(z, y);

						printf("Aerol�neas: %.2f", y);
						printf("\na) Precio con tarjeta de d�bito: %.2f", precioTarjDebAerolineas);
						printf("\nb) Precio con tarjeta de cr�dito: %.2f", precioTarjCredAerolineas);
						printf("\nc) Precio pagando con bitcoin : %f", precioBTCaerolineas);
						printf("\nd) Precio unitario: %.2f", precioUnitarioAerolineas);

						printf("\nLatam: %.2f", z);
						printf("\na) Precio con tarjeta de d�bito: %.2f", precioTarjDebLatam);
						printf("\nb) Precio con tarjeta de cr�dito: %.2f", precioTarjCredLatam);
						printf("\nc) Precio pagando con bitcoin : %f", precioBTClatam);
						printf("\nd) Precio unitario: %.2f\n", precioUnitarioLatam);
						printf("\nLa diferencia es: %.2f\n", diferenciaPrecio);

						printf("\n\n\n\n\n");
						break;

					case 6:
						printf("Saliendo del men�\n");
						printf("\n\n\n\n\n");
						break;
					default:
						printf("Por favor ingrese una opcion valida");
				}


			}while(opciones != 6);



	return EXIT_SUCCESS;
}
