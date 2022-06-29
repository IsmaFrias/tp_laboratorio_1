#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*************************************************************************************/

void pedirCodigoVuelo(char codigoVuelo[10], char* mensaje)
{
	printf(mensaje);
	fflush(stdin);
	gets(codigoVuelo);
}

/*************************************************************************************/

int myGets(char *cadena, int longitud)
{
	int retorno = -1;
	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

/*************************************************************************************/

int esNumerica(char *cadena)
{
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0)
	{
		while (cadena[i] != '\0')
		{
			if (isalpha(cadena[i]) != 0)
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

/*************************************************************************************/

int getInt(int *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/*************************************************************************************/

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo)
{
	int bufferInt;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0)
		{
			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

/*************************************************************************************/

int getFloat(char *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			strcpy(pResultado,buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/*************************************************************************************/

int utn_getFloat(char *pResultado, char *mensaje, char *mensajeError)
{
	char bufferFloat[64];
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getFloat(bufferFloat) == 0)
		{
			strcpy(pResultado,bufferFloat);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

/*************************************************************************************/

void utn_corregirMayus(char* cadena)
{
	strlwr(cadena);

	cadena[0] = toupper(cadena[0]);

	for(int i = 0; i < strlen(cadena); i++)
	{
		if (cadena[i] == ' ')
		{
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}
}

/*************************************************************************************/

int utn_getName(char* cadena, char* mensaje, char* mensajeError)
{
	int retorno = -1;

	while(retorno != 0)
	{
		printf(mensaje);
		fflush(stdin);
		gets(cadena);
		for (int i = 0; i < strlen(cadena); i++)
		{
			if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0 && cadena[i] != 'ñ')
			{
				retorno = -1;
				printf(mensajeError);
				break;
			}
			retorno = 0;
		}
	}

	utn_corregirMayus(cadena);

	return retorno;
}

/*************************************************************************************/

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

/*************************************************************************************/

void PedirAlfanumerico(char nombre[], char mensaje[])
{
	int retorno;

		do{
	         printf("\n%s", mensaje);
	         scanf("%s",nombre);
	         retorno = validarAlfanumerico(nombre);

	     }while(retorno == 0);
}

/*************************************************************************************/

void SeparadorConGuiones(void)
{
	printf("\n------------------------------------------------------------------------------------------------\n");
}

/*************************************************************************************/

void SeparadorConGuionesCorto(void)
{
	printf("\n------------------------------------------------\n");
}


