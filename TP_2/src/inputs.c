#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Inputs.h"


static int getInt(int* pResultado);
static int esNumerica(char* cadena);
static int myGets(char* cadena, int longitud);

/*************************************************************************************/

/// @brief lee el stdin hasta que encuentra un '\n' o hsta que haya
/// copiado en cadena un maximo de 'longitud' -1 caracteres
/// @param pResultado puntero al espacio de memoria donde se copiara
/// donde se copiara la cadena obtenida
/// @param longitud define el tamaño de la cadea
/// @return retorna 0 (exito) si se obtiene una cadena si no -1 (error)
static int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena, longitud, stdin);
	cadena[strlen(cadena)-1] = '\0';
	return 0;
}

/*************************************************************************************/

/// @brief obtiene un número entero
/// @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return retorna 0 (exito) si se obtiene una cadena si no -1 (error)
static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[4096];

	if(myGets(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString))
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}

/*************************************************************************************/

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
				if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}

/*************************************************************************************/

/// @brief verifica si la cadena ingresad es númerica
/// @param cadena de caracteres a ser analizada
/// @return retorna 1 (verdadero) si la cadena es numerica, 0 (falso) y -1 en caso de error
static int esNumerica(char* cadena)
{
	int retorno = 1;
	int i=0;

		if(cadena[0] == '-')
		{
			i = 1;
		}

		for( ; cadena[i] != '\0'; i++)
		{
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	return retorno;
}

/*************************************************************************************/

int validarCadena(char nombre[])
{
	int retorno = 1;
	int i;
		for(i=0 ; i<strlen(nombre); i++)
		{
			if(!((nombre[i]>=65 && nombre[i]<=90) || (nombre[i]>=97 && nombre[i]<=122) || (nombre[i] == ' ')))
			{
				printf("\nError, solo se admiten letras: ");
				retorno = 0;
				break;
			}
		}
	return retorno;
}

/*************************************************************************************/

void PedirCadena(char nombre[], char mensaje[])
{
	int retorno;

		do{
	         printf("\n%s", mensaje);
	         scanf("%s", nombre);
	         retorno = validarCadena(nombre);

	     }while(retorno == 0);
}

/*************************************************************************************/

int validarFloat(const char* fm, void* var)
{
    int ch;

    if(!scanf(fm, var))
    {
        while((ch = getchar()) != '\n' && ch != EOF);
        return 1;
    }

    if(getchar() != '\n')
    {
        while((ch = getchar()) != '\n' && ch != EOF);
        return 1;
    }
    return 0;
}

/*************************************************************************************/

float CalcularPromedio(float numero1, float numero2)
{
	float promedio;

		promedio = numero1 / numero2;

	return promedio;
}

/**************************************************/

int validarAlfanumerico(char variable[])
{
	int retorno = 1;
	int i;

		for(i=0 ; i<strlen(variable); i++)
		{
			if(!((variable[i]>=65 && variable[i]<=90)||	(variable[i]>=97 && variable[i]<=122)||
				(variable[i]>='0' && variable[i]<='9')))
			{
				printf("\nError ingrese un codigo de vuelo valido");
				retorno = 0;
				break;
			}
		}
	return retorno;
}

/**************************************************/

void PedirAlfanumerico(char nombre[], char mensaje[])
{
	int retorno;

		do{
	         printf("\n%s", mensaje);
	         scanf("%s",nombre);
	         retorno = validarAlfanumerico(nombre);

	     }while(retorno == 0);
}

/**************************************************/

void SeparadorConGuiones(void)
{
	printf("\n---------------------------------------------------------------------------\n");
}

/*************************************************/

void SeparadorConGuionesCorto(void)
{
	printf("\n------------------------------------------------\n");
}
