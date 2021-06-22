/*
 * TransporteMaritimo.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Stefano
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionary.h"
#include "TransporteMaritimo.h"
#include "LinkedList.h"
#include "utn.h"

#define INDICE_TRANSPORTE_MARITIMO 0

TransporteMaritimo* maritimo_new(void)
{
	return (TransporteMaritimo*) malloc(sizeof(TransporteMaritimo));
}

int maritimo_setMetrosCubicos(TransporteMaritimo* this,float metrosCubicos)
{
	int retorno = -1;
	if(this != NULL && isValidMetrosCubicos(metrosCubicos)==1)
	{
		this->metrosCubicos = metrosCubicos;
		retorno = 0;
	}
	return retorno;
}
float maritimo_getMetrosCubicos(TransporteMaritimo* this,int* flagError)
{
	*flagError = -1;
	float auxMetrosCubicos;
	if(this != NULL && flagError != NULL )
	{
		auxMetrosCubicos=this->metrosCubicos;
		*flagError = 0;
	}
	return auxMetrosCubicos;
}
int isValidMetrosCubicos(float metrosCubicos)
{
	int ret=-1;
	if(metrosCubicos > 0.1 && metrosCubicos < 999999.9)
	{
		ret=1;
	}
	return ret;
}

int maritimo_setValorPorMetroCubico(TransporteMaritimo* this,float valorPorMetroCubico)
{
	int retorno = -1;
	if(this != NULL && isValidValorPorMetroCubico(valorPorMetroCubico)==1)
	{
		this->valorPorMetroCubico = valorPorMetroCubico;
		retorno = 0;
	}
	return retorno;
}
float maritimo_getValorPorMetroCubico(TransporteMaritimo* this,int* flagError)
{
	*flagError = -1;
	float auxValorPorMetroCubico;
	if(this != NULL && flagError != NULL )
	{
		auxValorPorMetroCubico=this->valorPorMetroCubico;
		*flagError = 0;
	}
	return auxValorPorMetroCubico;
}
int isValidValorPorMetroCubico(float valorPorMetroCubico)
{
	int ret=-1;
	if(valorPorMetroCubico > 0.1 && valorPorMetroCubico < 999999.9)
	{
		ret=1;
	}
	return ret;
}
/*
 * brief pide los datos a modificar al usuario y los devuelve por param
 * return retorna -1(ERROR) o 0 (Exito)
 */
int maritimo_pedirDatos(float* metrosCubicos,float* valorPorMetroCubico)
{
	int ret=-1;
	if(metrosCubicos != NULL && valorPorMetroCubico != NULL)
	{
		if(utn_getFloat(metrosCubicos, "Ingrese nuevo metros cubicos.\n","Constante volumetrica invalida.\n", 0, 1000000, 2)==0 &&
			utn_getFloat(valorPorMetroCubico, "Ingrese nuevo valor por metro cubico\n", "Valor por kilogramo invalido.\n", 0, 10000, 2)==0)
		{
			ret=0;
		}
	}
	return ret;
}
/*
 * brief edita los datos del transporte maritimo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int maritimo_editarDatosDelTransporteMaritimo(TransporteMaritimo* transporteMaritimo)
{
	int retorno=-1;
	TransporteMaritimo pE;
	float metrosCubicos;
	float valorPorMetroCubico;

	if(maritimo_pedirDatos(&metrosCubicos,&valorPorMetroCubico)==0)
	{
		if(maritimo_setMetrosCubicos(&pE,metrosCubicos) == 0 &&
			maritimo_setValorPorMetroCubico(&pE,valorPorMetroCubico) == 0)
		{
			*transporteMaritimo=pE;
			printf("Datos modificado.\n");
			retorno=0;
		}
		else
		{
			printf("Error en la modificacion de datos.\n");
		}
	}
	return retorno;
}
/*
 * brief imprime los datos actuales del transporte maritimo de un archivo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int maritimo_imprimirLista(TransporteMaritimo* transporteMaritimo)
{
	int ret=-1;
	int flagError;

	float metrosCubicos;
	float valorPorMetroCubico;
	if(transporteMaritimo != NULL)
	{
		ret=0;
		metrosCubicos=maritimo_getMetrosCubicos(transporteMaritimo, &flagError);
		valorPorMetroCubico=maritimo_getValorPorMetroCubico(transporteMaritimo, &flagError);
		if(flagError != -1)
		{
			printf("Metros cubicos\tValor por metro cubico\n");
			printf("%.3f\t\t%.3f\n",metrosCubicos,valorPorMetroCubico);
		}
	}
	return ret;
}
/*
 * brief lee los datos del transporte maritimo de un archivo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int maritimo_parser(char* path,TransporteMaritimo* this)
{
	FILE* pFile;
	int flagOnce=0;
	TransporteMaritimo pE;
	int indice=-1;

	char constanteVolumetricaAux[256];
	char valorPorKgAux[256];

	float metrosCubicos;
	float valorPorMetroCubico;

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
					metrosCubicos=atof(constanteVolumetricaAux);
					valorPorMetroCubico=atof(valorPorKgAux);
					if(maritimo_setMetrosCubicos(&pE, metrosCubicos)==0 &&
					maritimo_setValorPorMetroCubico(&pE, valorPorMetroCubico)==0)
					{
						*this=pE;
					}
					indice++;
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
 * brief escribe los datos del transporte maritimo en un archivo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int maritimo_dump(char* path,TransporteMaritimo* transporteMaritimo)
{
	// serializer
	int ret=-1;
	int flagError;

	float metrosCubicos;
	float valorPorMetroCubico;
	FILE* pFile;

	pFile = fopen(path,"w");
	if(pFile!=NULL)
	{
		fprintf(pFile,"Metros cubicos,Valor por metro cubico\n");
			if(transporteMaritimo != NULL)
			{
				metrosCubicos=maritimo_getMetrosCubicos(transporteMaritimo, &flagError);
				valorPorMetroCubico=maritimo_getValorPorMetroCubico(transporteMaritimo, &flagError);
				if(flagError != -1)
				{
					fprintf(pFile,"%.3f,%.3f\n",metrosCubicos,valorPorMetroCubico);
				}
			}
		fclose(pFile);
	}
	return ret;
}
