/*
 * posicionArancelaria.c
 *
 *  Created on: Jun 15, 2021
 *      Author: Stefano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Dictionary.h"
#include "posicionArancelaria.h"
#include "LinkedList.h"

PosicionArancelaria* pos_new(void)
{
	return (PosicionArancelaria*) malloc(sizeof(PosicionArancelaria));
}

PosicionArancelaria* pos_newParam(int id,char* nomenclatura,float porcSeguro,float porcTasaEstadistica,float porcImportacion,int tipoLicencia)
{
	PosicionArancelaria* auxPosicionArancelaria = pos_new();
	if(auxPosicionArancelaria != NULL)
	{
		if (pos_setNomenclaturaArancelaria(auxPosicionArancelaria,nomenclatura) < 0 ||
				pos_setPorcSeguro(auxPosicionArancelaria,porcSeguro) < 0 ||
				pos_setPorcTasaEstadistica(auxPosicionArancelaria,porcTasaEstadistica) < 0 ||
				pos_setPorcImportacion(auxPosicionArancelaria,porcImportacion) < 0 ||
				pos_setId(auxPosicionArancelaria,id) < 0 ||
				pos_setTipoDeLicencia(auxPosicionArancelaria,tipoLicencia) < 0)
		{
			pos_delete(auxPosicionArancelaria);
			auxPosicionArancelaria = NULL;
		}
	}
	return auxPosicionArancelaria;;
}

int pos_delete(PosicionArancelaria* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int pos_setNomenclaturaArancelaria(PosicionArancelaria* this, char* nomenclaturaArancelaria)
{
	int retorno = -1;
	if(this != NULL && nomenclaturaArancelaria != NULL && isValidNomenclaturaArancelaria(nomenclaturaArancelaria))
	{
		strcpy(this->nomenclaturaArancelaria,nomenclaturaArancelaria);
		retorno = 0;
	}
	return retorno;
}

char* pos_getNomenclaturaArancelaria(PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	char* auxNomenclaturaArancelaria= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxNomenclaturaArancelaria= this->nomenclaturaArancelaria;
		*flagError = 0;
	}
	return auxNomenclaturaArancelaria;
}

int isValidNomenclaturaArancelaria(char* nomenclaturaArancelaria)
{
	int ret=-1;
	//esta en el utn_get
	return ret;
}

int pos_setPorcSeguro(PosicionArancelaria* this,float porcSeguro)
{
	int retorno = -1;
	if(this != NULL && isValidPorcSeguro(porcSeguro)==1)
	{
		this->porcSeguro = porcSeguro;
		retorno = 0;
	}
	return retorno;
}
float pos_getPorcSeguro(PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	float auxPorcSeguro;
	if(this != NULL && flagError != NULL )
	{
		auxPorcSeguro=this->porcSeguro;
		*flagError = 0;
	}
	return auxPorcSeguro;
}
int isValidPorcSeguro(float porcSeguro)
{
	int ret=-1;
	if(porcSeguro >= 0 && porcSeguro < 99.9)
	{
		ret=1;
	}
	return ret;
}

int pos_setPorcTasaEstadistica(PosicionArancelaria* this,float porcTasaEstadistica)
{
	int retorno = -1;
	if(this != NULL && isValidPorcTasaEstadistica(porcTasaEstadistica)==1)
	{
		this->porcTasaEstadistica = porcTasaEstadistica;
		retorno = 0;
	}
	return retorno;
}
float pos_getPorcTasaEstadistica (PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	float auxPorcTasaEstadistica;
	if(this != NULL && flagError != NULL )
	{
		auxPorcTasaEstadistica=this->porcTasaEstadistica;
		*flagError = 0;
	}
	return auxPorcTasaEstadistica;
}
int isValidPorcTasaEstadistica(float porcTasaEstadistica)
{
	int ret=-1;
	if(porcTasaEstadistica >= 0 && porcTasaEstadistica < 99.9)
	{
		ret=1;
	}
	return ret;
}

int pos_setPorcImportacion(PosicionArancelaria* this,float porcImportacion)
{
	int retorno = -1;
	if(this != NULL && isValidPorcImportacion(porcImportacion)==1)
	{
		this->porcImportacion = porcImportacion;
		retorno = 0;
	}
	return retorno;
}
float pos_getPorcImportacion(PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	float auxPorcImportacion;
	if(this != NULL && flagError != NULL )
	{
		auxPorcImportacion=this->porcImportacion;
		*flagError = 0;
	}
	return auxPorcImportacion;
}
int isValidPorcImportacion(float porcImportacion)
{
	int ret=-1;
	if(porcImportacion > 0.1 && porcImportacion < 99.9)
	{
		ret=1;
	}
	return ret;
}

int pos_setId(PosicionArancelaria* this, int id)
{
	int retorno = -1;
	if(this != NULL && isValidIdPosicionArancelaria(id) )
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int pos_getId(PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;
	if(this != NULL && flagError != NULL )
	{
		auxId=this->id;
		*flagError = 0;
	}
	return auxId;
}

int isValidIdPosicionArancelaria(int id)
{
	int ret=-1;
	if(id > 0)
	{
		ret=1;
	}
	return ret;
}

int pos_setTipoDeLicencia(PosicionArancelaria* this, int tipoDeLicencia)
{
	int retorno = -1;
	if(this != NULL && isValidTipoDeLicencia(tipoDeLicencia) )
	{
		this->tipoDeLicencia = tipoDeLicencia;
		retorno = 0;
	}
	return retorno;
}

int pos_getTipoDeLicencia(PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	int auxTipoDeLicencia = -1;
	if(this != NULL && flagError != NULL )
	{
		auxTipoDeLicencia=this->tipoDeLicencia;
		*flagError = 0;
	}
	return auxTipoDeLicencia;
}

int isValidTipoDeLicencia(int tipoDeLicencia)
{
	int ret=-1;
	if(tipoDeLicencia == 0 || tipoDeLicencia == 1)
	{
		ret=1;
	}
	return ret;
}
/********************/
/*brief carga una posicion arancelaria
 * return retorna -1(Error) 0(EXITO)
 * */
int pos_alta(Dictionary* posicionArancelaria)
{
	int ret=-1;
	PosicionArancelaria* pE;

	char nomenclaturaArancelaria[LEN_NOMENCLATURA];
	float porcSeguro;
	float porcTasaEstadistica;
	float porcImportacion;
	int tipoDeLicencia;
	int idGenerado;
	char idAux[256];

	if(pos_pedirDatos(nomenclaturaArancelaria,&porcSeguro,&porcTasaEstadistica,&porcImportacion,&tipoDeLicencia)==0)
	{
		idGenerado=pos_generarId();//GENERO EL ID UNICO
		pE=pos_newParam(idGenerado,nomenclaturaArancelaria,porcSeguro,porcTasaEstadistica,porcImportacion,tipoDeLicencia);//CONSTRUYO EL ESPACIO DE MEMORIA Y LO CARGO AL ARRAY
		if(pE != NULL)
		{
			snprintf(idAux,sizeof(idAux),"%d",idGenerado);
			dict_insert(posicionArancelaria,idAux,pE);
			printf("Posicion arancelaria cargada.\n");
			ret=0;
		}
	}
	return ret;
}
/*brief modifica datos de una posicion arancelaria segun el id elegido por el usuario
 * return retorna -1(Error) 0(EXITO)
 * */
int pos_modificar(Dictionary* producto)
{
	PosicionArancelaria* pE;
	int ret=-1;

	float porcSeguro;
	float porcTasaEstadistica;
	float porcImportacion;
	int tipoDeLicencia;
	char nomenclaturaArancelaria[256];
	int idABorrar;
	char idABorrarAux[256];

	if(utn_getInt("Ingrese el id de la posicion arancelaria a modificar:","Error",&idABorrar,2)==0)
	{
		snprintf(idABorrarAux,sizeof(idABorrarAux),"%d",idABorrar);
		pE=(PosicionArancelaria*)dict_get(producto,idABorrarAux);
		if(pE != NULL)
		{
			if(pos_pedirDatosAModificar(nomenclaturaArancelaria,&porcSeguro,&porcTasaEstadistica,&porcImportacion,&tipoDeLicencia)==0)
			{
				if(pos_setNomenclaturaArancelaria(pE,nomenclaturaArancelaria) == 0 &&
					pos_setPorcSeguro(pE,porcSeguro) == 0 &&
					pos_setPorcTasaEstadistica(pE,porcTasaEstadistica) == 0 &&
					pos_setPorcImportacion(pE,porcImportacion) == 0 &&
					pos_setTipoDeLicencia(pE,tipoDeLicencia) == 0)
				{
					printf("Posicion arancelaria modificada.\n");
					ret=0;
				}
			}
		}
		else
		{
			printf("No se encontro una posicion arancelaria con el id ingresada.\n");
		}
	}

	return ret;
}
/*brief borra una posicion arancelaria segun el id elegido por el usuario
 * return retorna -1(Error) 0(EXITO)
 *
 * */
int pos_borrar(Dictionary* posicionArancelaria)
{
	PosicionArancelaria* pE;
	int ret=-1;
	int idABorrar;
	char idABorrarAux[256];

	if(utn_getInt("Ingrese el id de la posicion arancelaria a eliminar:","Error",&idABorrar,2)==0)
	{
		snprintf(idABorrarAux,sizeof(idABorrarAux),"%d",idABorrar);
		pE=(PosicionArancelaria*)dict_get(posicionArancelaria, idABorrarAux);
		if(pE != NULL)
		{
			if(dict_remove(posicionArancelaria,idABorrarAux)==0)
			{
				pos_delete(pE);
				printf("Posicion arancelaria eliminada.\n");
				ret=0;
			}
		}
		else
		{
			printf("No se encontro una posicion arancelaria con el id ingresado.\n");
		}
	}
	return ret;
}
/*
 * brief imprime la lista de posiciones arancelarias
 * retunr retorna -1(ERROR) o 0 (EXITO)
 */
int pos_imprimirLista(Dictionary* posicionArancelaria)
{
	LinkedList* auxList=NULL;
	PosicionArancelaria* pE;
	int ret=-1;
	int i;
	int flagError;

	char* nomenclaturaArancelaria;
	float porcSeguro;
	float porcTasaEstadistica;
	float porcImportacion;
	int tipoDeLicencia;
	int idPosicionArancelaria;

	char* tipoDeLicenciaAux;

	if(posicionArancelaria != NULL)
	{
		auxList=dict_getValues(posicionArancelaria);
		if(auxList != NULL && ll_len(auxList) > 0)
		{
			ret=0;
			printf("Id\tNomenclatura arancelaria\t\tPorcentaje de seguro\tPorcentaje de tasa estadistica\tPorcentaje de importacion\tTipo de licencia\n");
			for(i=0;i<ll_len(auxList);i++)
			{
				pE=(PosicionArancelaria*)ll_get(auxList,i);
				if(pE != NULL)
				{
					idPosicionArancelaria=pos_getId(pE, &flagError);
					nomenclaturaArancelaria=pos_getNomenclaturaArancelaria(pE, &flagError);
					porcSeguro=pos_getPorcSeguro(pE, &flagError);
					porcTasaEstadistica=pos_getPorcTasaEstadistica(pE, &flagError);
					porcImportacion=pos_getPorcImportacion(pE, &flagError);
					tipoDeLicencia=pos_getTipoDeLicencia(pE, &flagError);
					if(tipoDeLicencia == 1)
					{
						tipoDeLicenciaAux="Automatica";
					}
					else
					{
						tipoDeLicenciaAux="No automatica";
					}
					if(flagError != -1)
					{

						printf("%-10d%-10s\t\t\t\t%-10.3f\t\t%-10.3f\t\t\t%-10.3f\t\t\t%s\n",idPosicionArancelaria,nomenclaturaArancelaria,porcSeguro,porcTasaEstadistica,porcImportacion,tipoDeLicenciaAux);
					}
				}
			}
			ll_deleteLinkedList(auxList);
		}
	}
	return ret;
}
/*
 * brief imprime una posicion arancelaria elegida por el usuario
 * retunr retorna -1(ERROR) o 0 (EXITO)
 */
int pos_imprimirUnaPosicionArancelaria(PosicionArancelaria* posicionArancelaria)
{
	int ret=-1;
	int flagError;

	char* nomenclaturaArancelaria;
	float porcSeguro;
	float porcTasaEstadistica;
	float porcImportacion;
	int tipoDeLicencia;
	int idPosicionArancelaria;
	char* tipoDeLicenciaAux;

	if(posicionArancelaria != NULL)
	{
		idPosicionArancelaria=pos_getId(posicionArancelaria, &flagError);
		nomenclaturaArancelaria=pos_getNomenclaturaArancelaria(posicionArancelaria, &flagError);
		porcSeguro=pos_getPorcSeguro(posicionArancelaria, &flagError);
		porcTasaEstadistica=pos_getPorcTasaEstadistica(posicionArancelaria, &flagError);
		porcImportacion=pos_getPorcImportacion(posicionArancelaria, &flagError);
		tipoDeLicencia=pos_getTipoDeLicencia(posicionArancelaria, &flagError);
		if(tipoDeLicencia == 1)
		{
			tipoDeLicenciaAux="Automatica";
		}
		else
		{
			tipoDeLicenciaAux="No automatica";
		}
		if(flagError != -1)
		{
			printf("Id\tNomenclatura arancelaria\t\tPorcentaje de seguro\tPorcentaje de tasa estadistica\tPorcentaje de importacion\tTipo de licencia\n");
			printf("%-10d%-10s\t\t\t\t%-10.3f\t\t%-10.3f\t\t\t%-10.3f\t\t\t%s\n",idPosicionArancelaria,nomenclaturaArancelaria,porcSeguro,porcTasaEstadistica,porcImportacion,tipoDeLicenciaAux);
			ret=0;
		}
	}
	return ret;
}
/*
 * brief imprime la lista ordenada
 * retunr retorna -1(ERROR) o 0 (EXITO)
 */
int pos_imprimirListaOrdenada(LinkedList* posicionesArancelarias)
{
	PosicionArancelaria* pE;
	int ret=-1;
	int i;
	int flagError;

	char* nomenclaturaArancelaria;
	float porcSeguro;
	float porcTasaEstadistica;
	float porcImportacion;
	int tipoDeLicencia;
	int idPosicionArancelaria;
	char* tipoDeLicenciaAux;

	if(posicionesArancelarias != NULL)
	{
		if(posicionesArancelarias != NULL && ll_len(posicionesArancelarias) > 0)
		{
			ret=0;
			printf("Id\tNomenclatura arancelaria\t\tPorcentaje de seguro\tPorcentaje de tasa estadistica\tPorcentaje de importacion\tTipo de licencia\n");
			for(i=0;i<ll_len(posicionesArancelarias);i++)
			{
				pE=(PosicionArancelaria*)ll_get(posicionesArancelarias,i);
				if(pE != NULL)
				{
					idPosicionArancelaria=pos_getId(pE, &flagError);
					nomenclaturaArancelaria=pos_getNomenclaturaArancelaria(pE, &flagError);
					porcSeguro=pos_getPorcSeguro(pE, &flagError);
					porcTasaEstadistica=pos_getPorcTasaEstadistica(pE, &flagError);
					porcImportacion=pos_getPorcImportacion(pE, &flagError);
					tipoDeLicencia=pos_getTipoDeLicencia(pE, &flagError);
					if(tipoDeLicencia == 1)
					{
						tipoDeLicenciaAux="Automatica";
					}
					else
					{
						tipoDeLicenciaAux="No automatica";
					}
					if(flagError != -1)
					{
						printf("%-10d%-15s\t\t\t%-10.3f\t\t%-10.3f\t\t\t%-10.3f\t\t\t%s\n",idPosicionArancelaria,nomenclaturaArancelaria,porcSeguro,porcTasaEstadistica,porcImportacion,tipoDeLicenciaAux);
					}
				}
			}
		}
	}
	return ret;
}
/*
 * brief pide los datos al usuario y los devuelve por parametros
 * retunr retorna -1(ERROR) o 0 (EXITO)
 */
int pos_pedirDatos(char* nomenclaturaArancelaria,float* porcSeguro,float* porcTasaEstadistica,float* porcImportacion,int* tipoDeLicencia)
{
	int ret=-1;
	if(nomenclaturaArancelaria != NULL && porcSeguro != NULL && porcTasaEstadistica != NULL && porcImportacion != NULL && tipoDeLicencia != NULL)
	{
		if(utn_getStringWithNumbersAndSymbols("Ingrese nomenclatura arancelaria:\n","Nomenclatura arancelaria invalida.\n",nomenclaturaArancelaria,15, 2)==0 &&
				utn_getFloat(porcSeguro,"Ingrese porcentaje de seguro:\n", "Porcentaje de seguro invalido.\n",  0, 100, 2) == 0 &&
				utn_getFloat(porcTasaEstadistica,"Ingrese porcentaje de tasa estadistica:\n", "Porcentaje de tasa estadistica invalido.\n",  0,100, 2)==0 &&
				utn_getFloat(porcImportacion,"Ingrese porcentaje de importacion:\n", "Porcentaje de importacion invalido.\n",  0, 100, 2)==0 &&
				utn_getIntConMinMax( "Elija tipo de licencia...\n1)Automatica\n2)No automatica\n", "Tipo de licencia invalida.",tipoDeLicencia, 1, 2, 2)==0)
		{
			ret=0;
		}
	}
	return ret;
}
/*
 * brief pide los datos a modificar al usuario y los devuelve por parametros
 * retunr retorna -1(ERROR) o 0 (EXITO)
 */
int pos_pedirDatosAModificar(char* nomenclaturaArancelaria,float* porcSeguro,float* porcTasaEstadistica,float* porcImportacion,int* tipoDeLicencia)
{
	int ret=-1;
	if(porcSeguro != NULL && porcTasaEstadistica != NULL && porcImportacion != NULL && tipoDeLicencia != NULL)
	{
		if(utn_getStringWithNumbersAndSymbols("Ingrese nomenclatura arancelaria:\n","Nomenclatura arancelaria invalida.\n",nomenclaturaArancelaria,15, 2)==0 &&
				utn_getFloat(porcSeguro,"Ingrese nuevo porcentaje de seguro:\n", "Porcentaje de seguro invalido.\n",  0,100, 2) == 0 &&
				utn_getFloat(porcTasaEstadistica,"Ingrese nuevo porcentaje de tasa estadistica:\n", "Porcentaje de tasa estadistica invalido.\n",  0,100, 2)==0 &&
				utn_getFloat(porcImportacion,"Ingrese nuevo porcentaje de importacion:\n", "Porcentaje de importacion invalido.\n",  0,100, 2)==0 &&
				utn_getIntConMinMax( "Elija nuevo tipo de licencia...\n1)Automatica\n2)No automatica\n", "Tipo de licencia invalida.\n",tipoDeLicencia, 1, 2, 2)==0)
		{
			ret=0;
		}
	}
	return ret;
}

static int contador=0;
void pos_setearValorInicialDeId(int id)//setea un valir inicial del id
{
	contador = id;
}
//GENERADOR DE IDS UNICOS
int pos_generarId(void)
{
	contador++;
	return contador;
}
/*
 * brief escribe los datos de las posiciones arancelarias de un archivo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int pos_dump(char* path,Dictionary* posicionArancelaria)
{
	// serializer
	LinkedList* auxList;
	PosicionArancelaria* pE;
	int ret=-1;
	int i;
	int flagError;

	char* nomenclaturaArancelaria;
	float porcSeguro;
	float porcTasaEstadistica;
	float porcImportacion;
	int idPosicionArancelaria;
	int tipoDeLicencia;
	char tipoDeLicenciaStr[256];
	FILE* pFile;

	pFile = fopen(path,"w");
	if(pFile!=NULL)
	{
		fprintf(pFile,"Id,Nomenclatura arancelaria,Porcentaje de seguro,Porcentaje de tasa estadistica,Porcentaje de importacion,Tipo de licencia\n");
		auxList=dict_getValues(posicionArancelaria);

		for(i=0;i<ll_len(auxList);i++)
		{
			pE=(PosicionArancelaria*)ll_get(auxList, i);

			if(auxList != NULL && pE != NULL)
			{
				idPosicionArancelaria=pos_getId(pE, &flagError);
				nomenclaturaArancelaria=pos_getNomenclaturaArancelaria(pE, &flagError);
				porcSeguro=pos_getPorcSeguro(pE, &flagError);
				porcTasaEstadistica=pos_getPorcTasaEstadistica(pE, &flagError);
				porcImportacion=pos_getPorcImportacion(pE, &flagError);
				tipoDeLicencia=pos_getTipoDeLicencia(pE, &flagError);
				if(flagError != -1)
				{
					if(tipoDeLicencia == 2)
					{
						strcpy(tipoDeLicenciaStr,"No automatica");
					}
					else if(tipoDeLicencia == 1)
					{
						strcpy(tipoDeLicenciaStr,"Automatica");
					}
					fprintf(pFile,"%d,%s,%f,%f,%f,%s\n",idPosicionArancelaria,nomenclaturaArancelaria,porcSeguro,porcTasaEstadistica,porcImportacion,tipoDeLicenciaStr);
					ret=i;
				}
			}
		}
		ll_deleteLinkedList(auxList);
		fclose(pFile);
	}
	return ret;
}
/*
 * brief lee los datos de las posiciones arancelarias de un archivo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int pos_parser(char* path,Dictionary* posicionArancelaria)
{
	FILE* pFile;
	int flagOnce=0;
	PosicionArancelaria* pE;
	int indice=-1;

	char idPosicionArancelariaAux[256];
	char nomenclaturaArancelariaAux[256];
	char porcSeguroAux[256];
	char porcTasaEstadisticaAux[256];
	char porcImportacionAux[256];
	char tipoDeLicenciaAux[256];

	int idPosicionArancelaria;
	float porcSeguro;
	float porcTasaEstadistica;
	float porcImportacion;
	int tipoDeLicencia;
	int idMax;

	pFile = fopen(path,"r");
	if(pFile!=NULL)
	{
		indice=0;
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idPosicionArancelariaAux,nomenclaturaArancelariaAux,porcSeguroAux,porcTasaEstadisticaAux,porcImportacionAux,tipoDeLicenciaAux)==6)
			{
				if(flagOnce!=0)
				{
					idPosicionArancelaria=atoi(idPosicionArancelariaAux);
					porcSeguro=atof(porcSeguroAux);
					porcTasaEstadistica=atof(porcTasaEstadisticaAux);
					porcImportacion=atof(porcImportacionAux);
					if(strcmp(tipoDeLicenciaAux,"No automatica")==0)
					{
						tipoDeLicencia=2;
					}
					else if(strcmp(tipoDeLicenciaAux,"Automatica")==0)
					{
						tipoDeLicencia=1;
					}
					pE = pos_newParam(idPosicionArancelaria,nomenclaturaArancelariaAux,porcSeguro,porcTasaEstadistica,porcImportacion,tipoDeLicencia);
					if(pE != NULL)
					{
						dict_insert(posicionArancelaria,idPosicionArancelariaAux,pE);
						if(indice == 0)
						{
							idMax=idPosicionArancelaria;
						}
						else if(indice > 0 && idPosicionArancelaria > idMax)
						{
							idMax=idPosicionArancelaria;
						}
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
		pos_setearValorInicialDeId(idMax);
	}
	return indice; // devuelve cantidad leidos
}
static int fncCriterioNomenclatura(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	PosicionArancelaria* pE;
	PosicionArancelaria* pE2;

	char* nomenclatura;
	char* nomenclatura2;

	pE=(PosicionArancelaria*)p1;
	pE2=(PosicionArancelaria*)p2;

	nomenclatura=pos_getNomenclaturaArancelaria(pE, &flagError);
	nomenclatura2=pos_getNomenclaturaArancelaria(pE2, &flagError);

	if(flagError != -1)
	{
		ret=strcmp(nomenclatura,nomenclatura2);
	}
	return ret;
}
static int fncCriterioPorcSeguro(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	PosicionArancelaria* pE;
	PosicionArancelaria* pE2;

	float porcSeguro;
	float porcSeguro2;

	pE=(PosicionArancelaria*)p1;
	pE2=(PosicionArancelaria*)p2;

	porcSeguro=pos_getPorcSeguro(pE, &flagError);
	porcSeguro2=pos_getPorcSeguro(pE2, &flagError);
	if(flagError != -1)
	{
		if(porcSeguro == porcSeguro2)
		{
			ret=0;
		}
		else if(porcSeguro > porcSeguro2)
		{
			ret=1;
		}
		else
		{
			ret=-1;
		}
	}
	return ret;
}
static int fncCriterioPorcImportacion(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	PosicionArancelaria* pE;
	PosicionArancelaria* pE2;

	float porcImportacion;
	float porcImportacion2;

	pE=(PosicionArancelaria*)p1;
	pE2=(PosicionArancelaria*)p2;

	porcImportacion=pos_getPorcImportacion(pE, &flagError);
	porcImportacion2=pos_getPorcImportacion(pE2, &flagError);
	if(flagError != -1)
	{
		if(porcImportacion == porcImportacion2)
		{
			ret=0;
		}
		else if(porcImportacion > porcImportacion2)
		{
			ret=1;
		}
		else
		{
			ret=-1;
		}
	}
	return ret;
}
static int fncCriterioPorcTasaEstadistica(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	PosicionArancelaria* pE;
	PosicionArancelaria* pE2;

	float porcTasaEstadistica;
	float procTasaEstadistica;

	pE=(PosicionArancelaria*)p1;
	pE2=(PosicionArancelaria*)p2;

	porcTasaEstadistica=pos_getPorcTasaEstadistica(pE, &flagError);
	procTasaEstadistica=pos_getPorcTasaEstadistica(pE2, &flagError);

	if(flagError != -1)
	{
		if(porcTasaEstadistica == procTasaEstadistica)
		{
			ret=0;
		}
		else if(porcTasaEstadistica > procTasaEstadistica)
		{
			ret=1;
		}
		else
		{
			ret=-1;
		}
	}
	return ret;
}

int pos_ordenarPorNomenclatura(Dictionary* posicionesArancelarias)
{
	int ret=-1;
	LinkedList* auxList;

	if(posicionesArancelarias != NULL)
	{
		auxList=dict_getValues(posicionesArancelarias);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioNomenclatura,0);
			if(pos_imprimirListaOrdenada(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}

int pos_ordenarPorPorcSeguro(Dictionary* posicionesArancelarias)
{
	int ret=-1;
	LinkedList* auxList;

	if(posicionesArancelarias != NULL)
	{
		auxList=dict_getValues(posicionesArancelarias);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioPorcSeguro,0);
			if(pos_imprimirListaOrdenada(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}

int pos_ordenarPorPorcImportacion(Dictionary* posicionesArancelarias)
{
	int ret=-1;
	LinkedList* auxList;

	if(posicionesArancelarias != NULL)
	{
		auxList=dict_getValues(posicionesArancelarias);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioPorcImportacion,0);
			if(pos_imprimirListaOrdenada(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}

int pos_ordenarPorPorcTasaEstadistica(Dictionary* posicionesArancelarias)
{
	int ret=-1;
	LinkedList* auxList;

	if(posicionesArancelarias != NULL)
	{
		auxList=dict_getValues(posicionesArancelarias);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioPorcTasaEstadistica,0);
			if(pos_imprimirListaOrdenada(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}
