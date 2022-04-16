#include <stdio.h>
#include <stdlib.h>
#include "BiblioTP_1.h"

/**************************************************************************************/
float pedirUnNumero(char mensaje[])
{
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
		while(numero < 0){
    		printf("%s", mensaje);
    		scanf("%f", &numero);
    	}


    return numero;
}

/**************************************************************************************/

float CalculadorPrecioTarjDebitoAerolineasArg(float y)
{
	//float descuento;
	float precioTotalConDescuento;

	precioTotalConDescuento = y * 0.9;
	//precioTotalConDescuento = y + descuento;

	return precioTotalConDescuento;
}

/**************************************************************************************/

float CalculadorPrecioTarjCreditoAerolineasArg(float y)
{
	//float aumento;
	float precioTotalConAumento;

	precioTotalConAumento = y * 1.25;
	//precioTotalConAumento = y + aumento;

	return precioTotalConAumento;
}

/**************************************************************************************/

float CalculadorPrecioBTCaerolineasArg(float y)
{
	float btc = 4606954.55;
	float precioConBitcoin;

	precioConBitcoin = y / btc;

	return precioConBitcoin;
}

/**************************************************************************************/

float CalculadorPrecioUnitarioAerolineasArg(float km,float y)
{
	float precioUnitario;

	precioUnitario = y / km;

	return precioUnitario;
}

/**************************************************************************************/

float CalculadorPrecioTarjDebitoLatam(float z)
{
	//float descuento;
	float precioTotalConDescuento;

	precioTotalConDescuento = z * 0.90;
	//precioTotalConDescuento = z + descuento;

	return precioTotalConDescuento;
}

/**************************************************************************************/

float CalculadorPrecioTarjCreditoLatam(float z)
{
	//float aumento;
	float precioTotalConAumento;

	precioTotalConAumento = z * 1.25;
	//precioTotalConAumento = y + aumento;

	return precioTotalConAumento;
}

/**************************************************************************************/

float CalculadorPrecioBTClatam(float z)
{
	float btc = 4606954.55;
	float precioConBitcoin;

	precioConBitcoin = z / btc;

	return precioConBitcoin;
}

/**************************************************************************************/

float CalculadorPrecioUnitarioLatam(float km,float z)
{
	float precioUnitario;

	precioUnitario = z / km;

	return precioUnitario;
}

/**************************************************************************************/

float DiferenciaDePrecio(float z, float y)
{
	float diferencia;

	if(z > y){
		diferencia = z - y;
	}
	else{
		diferencia = y - z;
	}

	return diferencia;
}
