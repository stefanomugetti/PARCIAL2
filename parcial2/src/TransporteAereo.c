/*
 * TransporteAereo.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Stefano
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionary.h"
#include "TransporteAereo.h"
#include "LinkedList.h"
#include "utn.h"

#define INDICE_TRANSPORTE_AEREO 0
TransporteAereo* aereo_new(void)
{
	return (TransporteAereo*) malloc(sizeof(TransporteAereo));
}

int aereo_setConstanteVolumetrica(TransporteAereo* this,float constanteVolumetrica)
{
	int retorno = -1;
	if(this != NULL && isValidConstanteVolumetrica(constanteVolumetrica)==1)
	{
		this->constanteVolumetrica = constanteVolumetrica;
		retorno = 0;
	}
	return retorno;
}
float aereo_getConstanteVolumetrica(TransporteAereo* this,int* flagError)
{
	*flagError = -1;
	float auxConstanteVolumetrica;
	if(this != NULL && flagError != NULL )
	{
		auxConstanteVolumetrica=this->constanteVolumetrica;
		*flagError = 0;
	}
	return auxConstanteVolumetrica;
}
int isValidConstanteVolumetrica(float constanteVolumetrica)
{
	int ret=-1;
	if(constanteVolumetrica > 0.1 && constanteVolumetrica < 999999.9)
	{
		ret=1;
	}
	return ret;
}

int aereo_setValorPorKg(TransporteAereo* this,float valorPorKg)
{
	int retorno = -1;
	if(this != NULL && isValidValorPorKg(valorPorKg)==1)
	{
		this->valorPorKg = valorPorKg;
		retorno = 0;
	}
	return retorno;
}
float aereo_getValorPorKg(TransporteAereo* this,int* flagError)
{
	*flagError = -1;
	float auxValorPorKg;
	if(this != NULL && flagError != NULL )
	{
		auxValorPorKg=this->valorPorKg;
		*flagError = 0;
	}
	return auxValorPorKg;
}
int isValidValorPorKg(float valorPorKg)
{
	int ret=-1;
	if(valorPorKg > 0.1 && valorPorKg < 999999.9)
	{
		ret=1;
	}
	return ret;
}

/*
 * brief pide los datos a modificar al usuario y los devuelve por param
 * return retorna -1(ERROR) o 0 (Exito)
 */
int aereo_pedirDatosAModificar(float* constanteVolumetrica,float* valorPorKg)
{
	int ret=-1;
	if(constanteVolumetrica != NULL && valorPorKg != NULL)
	{
		if(utn_getFloat(constanteVolumetrica, "Ingrese nueva constante volumetrica.\n","Constante volumetrica invalida.\n", 0, 1000000, 2)==0 &&
			utn_getFloat(valorPorKg, "Ingrese nuevo valor por kilogramo.\n", "Valor por kilogramo invalido.\n", 0, 10000, 2)==0)
		{
			ret=0;
		}
	}
	return ret;
}

/*
 * brief edita los datos del transporte aereo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int aereo_editarDatosDelTransporteAereo(TransporteAereo* transporteAereo)
{
	int retorno=-1;
	TransporteAereo pE;

	float constanteVolumetrica;
	float valorPorKg;

	if(aereo_pedirDatosAModificar(&constanteVolumetrica,&valorPorKg) == 0)
	{
		if(aereo_setConstanteVolumetrica(&pE,constanteVolumetrica) == 0 &&
			aereo_setValorPorKg(&pE,valorPorKg) == 0)
		{
			*transporteAereo=pE;
		}
			printf("Datos modificado.\n");
			retorno=0;
		}
		else
		{
			printf("Error en la modificacion de datos");
		}
	return retorno;
}
/*
 * brief imprime los datos actuales del transporte aereo de un archivo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int aereo_imprimirLista(TransporteAereo* transporteAereo)
{
	int ret=-1;
	int flagError;

	float constanteVolumetrica;
	float valorPorKg;

	if(transporteAereo != NULL)
	{
		constanteVolumetrica=aereo_getConstanteVolumetrica(transporteAereo, &flagError);
		valorPorKg=aereo_getValorPorKg(transporteAereo, &flagError);
		if(flagError != -1)
		{
			printf("Constante volumetrica\tValor por kilogramo\n");
			printf("%.3f\t\t%.3f\n",constanteVolumetrica,valorPorKg);
			ret=0;
		}
	}
	return ret;
}
/*
 * brief lee los datos del transporte aereo de un archivo
 * return retorna -1(ERROR) o 0 (Exito)
 */

int aereo_parser(char* path,TransporteAereo* this)
{
	FILE* pFile;
	int flagOnce=0;
	TransporteAereo pE;
	int indice=-1;

	char constanteVolumetricaAux[256];
	char valorPorKgAux[256];

	float constanteVolumetrica;
	float valorPorKg;

	pFile = fopen(path,"r");
	if(pFile!=NULL)
	{
		indice=0;
		do
		{
			if(fscanf(pFile,"%[^,],%[^\n]\n",constanteVolumetricaAux,valorPorKgAux)==2)
			{
				if(flagOnce!=0)
				{
					constanteVolumetrica=atof(constanteVolumetricaAux);
					valorPorKg=atof(valorPorKgAux);
					if(aereo_setConstanteVolumetrica(&pE, constanteVolumetrica) ==0 &&
						aereo_setValorPorKg(&pE, valorPorKg) == 0)
					{
						*this=pE;
						indice++;
					}
				}
			}
			else
			{
				indice=-1;
				break;
			}
			flagOnce=1;
		}
		while(feof(pFile)==0);
		fclose(pFile);
	}
	return indice; // devuelve cantidad leidos
}
/*
 * brief escribe los datos del transporte aereo en un archivo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int aereo_dump(char* path,TransporteAereo* transporteAereo)
{
	int ret=-1;
	int flagError;

	float constanteVolumetrica;
	float valorPorKg;
	FILE* pFile;

	pFile = fopen(path,"w");

	if(pFile!=NULL && transporteAereo != NULL)
	{
		fprintf(pFile,"Constante volumetrica,Valor por kilogramo\n");
		constanteVolumetrica=aereo_getConstanteVolumetrica(transporteAereo, &flagError);
		valorPorKg=aereo_getValorPorKg(transporteAereo, &flagError);
		if(flagError != -1)
		{
			fprintf(pFile,"%f,%f\n",constanteVolumetrica,valorPorKg);
			ret=0;
		}
		fclose(pFile);
	}
	return ret;
}
