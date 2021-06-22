/*
 * Producto.c
 *
 *  Created on: Jun 15, 2021
 *      Author: Stefano
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionary.h"
#include "PosicionArancelaria.h"
#include "Producto.h"
#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"
#include "calculos.h"
Producto* producto_new(void)
{
	return (Producto*) malloc(sizeof(Producto));
}

Producto* producto_newParam(char* codigo,char* paisDeFabricacion,char* descripcion,float valorFob,float alto,float ancho,float profundidad,float peso,float idPosicionArancelaria)
{
	Producto* auxProducto = producto_new();
	if(auxProducto != NULL)
	{
		if(producto_setCodigo(auxProducto,codigo) < 0 ||
			producto_setPaisDeFabricacion(auxProducto,paisDeFabricacion) < 0 ||
			producto_setDescripcion(auxProducto,descripcion) < 0 ||
			producto_setValorFob(auxProducto,valorFob) < 0 ||
			producto_setAlto(auxProducto,alto) < 0 ||
			producto_setAncho(auxProducto,ancho) < 0 ||
			producto_setProfundidad(auxProducto,profundidad) < 0 ||
			producto_setPeso(auxProducto,peso) < 0 ||
			producto_setIdPosicionArancelaria(auxProducto,idPosicionArancelaria) < 0)
		{
			producto_delete(auxProducto);
			auxProducto = NULL;
		}

	}
	return auxProducto;;
}

int producto_delete(Producto* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}


int producto_setCodigo(Producto* this, char* codigo)
{
	int retorno = -1;
	if(this != NULL && codigo != NULL && isValidCodigo(codigo))
	{
		strcpy(this->codigo,codigo);
		retorno = 0;
	}
	return retorno;
}

char* producto_getCodigo(Producto* this,int* flagError)
{
	*flagError = -1;
	char* auxCodigo= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxCodigo= this->codigo;
		*flagError = 0;
	}
	return auxCodigo;
}

int isValidCodigo(char* nombre)//valida utn_getString
{
	return 1;
}

int producto_setPaisDeFabricacion(Producto* this, char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL && isValidPaisDeFabricacion(descripcion))
	{
		strcpy(this->paisDeFabricacion,descripcion);
		retorno = 0;
	}
	return retorno;
}

char* producto_getPaisDeFabricacion(Producto* this,int* flagError)
{
	*flagError = -1;
	char* auxPaisDeFabricacion= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxPaisDeFabricacion= this->paisDeFabricacion;
		*flagError = 0;
	}
	return auxPaisDeFabricacion;
}

int isValidPaisDeFabricacion(char* paisDeFabricacion)//valida utn_getString
{
	return 1;
}

int producto_setDescripcion(Producto* this, char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL && isValidDescripcion(descripcion))
	{
		strcpy(this->descripcion,descripcion);
		retorno = 0;
	}
	return retorno;
}

char* producto_getDescripcion(Producto* this,int* flagError)
{
	*flagError = -1;
	char* auxDescripcion= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxDescripcion= this->descripcion;
		*flagError = 0;
	}
	return auxDescripcion;
}

int isValidDescripcion(char* descripcion)//valida utn_getString
{
	return 1;
}

int producto_setValorFob(Producto* this,float valorFob)
{
	int retorno = -1;
	if(this != NULL && isValidValorFob(valorFob)==1)
	{
		this->valorFob = valorFob;
		retorno = 0;
	}
	return retorno;
}
float producto_getValorFob(Producto* this,int* flagError)
{
	*flagError = -1;
	float auxValorFob;
	if(this != NULL && flagError != NULL )
	{
		auxValorFob=this->valorFob;
		*flagError = 0;
	}
	return auxValorFob;
}
int isValidValorFob(float valorFob)
{
	int ret=-1;
	if(valorFob > 0.1 && valorFob < 1000000.1)
	{
		ret=1;
	}
	return ret;
}

int producto_setAlto(Producto* this,float alto)
{
	int retorno = -1;
	if(this != NULL && isValidAlto(alto)==1)
	{
		this->alto = alto;
		retorno = 0;
	}
	return retorno;
}
float producto_getAlto(Producto* this,int* flagError)
{
	*flagError = -1;
	float auxAlto;
	if(this != NULL && flagError != NULL )
	{
		auxAlto=this->alto;
		*flagError = 0;
	}
	return auxAlto;
}
int isValidAlto(float alto)
{
	int ret=-1;
	if(alto > 0.1 && alto <100000.1)
	{
		ret=1;
	}
	return ret;
}

int producto_setAncho(Producto* this,float ancho)
{
	int retorno = -1;
	if(this != NULL && isValidAncho(ancho)==1)
	{
		this->ancho = ancho;
		retorno = 0;
	}
	return retorno;
}
float producto_getAncho(Producto* this,int* flagError)
{
	*flagError = -1;
	float auxAncho;
	if(this != NULL && flagError != NULL )
	{
		auxAncho=this->ancho;
		*flagError = 0;
	}
	return auxAncho;
}
int isValidAncho(float ancho)
{
	int ret=-1;
	if(ancho > 0.1 && ancho < 1000000.1)
	{
		ret=1;
	}
	return ret;
}

int producto_setProfundidad(Producto* this,float profundidad)
{
	int retorno = -1;
	if(this != NULL && isValidProfundidad(profundidad)==1)
	{
		this->profundidad = profundidad;
		retorno = 0;
	}
	return retorno;
}
float producto_getProfundidad(Producto* this,int* flagError)
{
	*flagError = -1;
	float auxProfundidad;
	if(this != NULL && flagError != NULL )
	{
		auxProfundidad=this->profundidad;
		*flagError = 0;
	}
	return auxProfundidad;
}
int isValidProfundidad(float profundidad)
{
	int ret=-1;
	if(profundidad > 0.1 && profundidad < 100000.1)
	{
		ret=1;
	}
	return ret;
}

int producto_setPeso(Producto* this,float peso)
{
	int retorno;
	if(this != NULL && isValidPeso(peso)==1)
	{
		this->peso = peso;
		retorno = 0;
	}
	return retorno;
}
float producto_getPeso(Producto* this,int* flagError)
{
	*flagError = -1;
	float auxPeso = -1;
	if(this != NULL && flagError != NULL )
	{
		auxPeso=this->peso;
		*flagError = 0;
	}
	return auxPeso;
}
int isValidPeso(float peso)
{
	int ret=-1;
	if(peso > 0.1 && peso < 100000.1)
	{
		ret=1;
	}
	return ret;
}

int producto_setIdPosicionArancelaria(Producto* this,int idPosicionArancelaria)
{
	int retorno = -1;
	if(this != NULL && isValidPosicionArancelaria(idPosicionArancelaria) )
	{
		this->idPosicionArancelaria = idPosicionArancelaria;
		retorno = 0;
	}
	return retorno;
}

int producto_getIdPosicionArancelaria(Producto* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;
	if(this != NULL && flagError != NULL )
	{
		auxId=this->idPosicionArancelaria;
		*flagError = 0;
	}
	return auxId;
}

int isValidPosicionArancelaria(int idPosicionArancelaria)
{
	int ret=-1;
	if(idPosicionArancelaria > 0)
	{
		ret=1;
	}
	return ret;
}

static int contador=0; // NO ES LOCAL DE LA FUNCION

void producto_setearValorInicialDeId(int id)
{
	contador = id;
}

int producto_generarId(void)
{
	contador++;
	return contador;
}

/******************/
/*
 * brief carga un producto al diccionario
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_alta(Dictionary* producto,Dictionary* posicionesArancelarias)
{
	int ret=-1;
	Producto* pE;
	PosicionArancelaria* pAranc;

	char codigo[LEN_CODIGO];
	char paisDeFabricacion[LEN_PAIS_DE_FABRICACION];
	char descripcion[LEN_DESCRIPCION];
	float valorFob;
	float alto;
	float ancho;
	float profundidad;
	float peso;
	int idPosicionArancelaria;
	char idPosicionArancelariaStr[256];

	pos_imprimirLista(posicionesArancelarias);
	if(utn_getInt("Ingrese el id de la posicion arancelaria correspondiente:\n", "Id invalido.\n", &idPosicionArancelaria, 2)==0)
	{
		snprintf(idPosicionArancelariaStr,sizeof(idPosicionArancelariaStr),"%d",idPosicionArancelaria);
		pAranc=dict_get(posicionesArancelarias, idPosicionArancelariaStr);
		if(pAranc != NULL)
		{
			if(producto_pedirDatos(codigo, paisDeFabricacion, descripcion,&valorFob,&alto,&ancho,&profundidad,&peso)==0)
			{
				pE=producto_newParam(codigo, paisDeFabricacion, descripcion,valorFob,alto,ancho,profundidad,peso,idPosicionArancelaria);//CONSTRUYO EL ESPACIO DE MEMORIA Y LO CARGO AL ARRAY
				if(pE != NULL)
				{
					if(dict_insert(producto,codigo,pE)==0)
					{
						ret=0;
					}
				}
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
 * brief pide datos al usuario y los pasa por parametros
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_pedirDatos(char* codigo,char* paisDeFabricacion,char* descripcion,float* valorFob,float* alto,float* ancho,float* profundidad,float* peso)
{
	int ret=-1;
	if(codigo != NULL && paisDeFabricacion != NULL && descripcion != NULL && valorFob != NULL && alto != NULL && ancho != NULL && profundidad != NULL && peso!= NULL )
	{
		if(utn_getStringWithNumbersAndSymbols("Ingrese codigo:\n","Codigo invalido", codigo, LEN_CODIGO, 2) == 0 &&
			utn_getString("Ingrese pais de fabricacion:\n", "Pais de fabricacion invalido.\n", paisDeFabricacion, LEN_PAIS_DE_FABRICACION, 2)==0 &&
			utn_getStringWithNumbers("Ingrese descripcion:\n", "Descripcion invalida.\n", descripcion, LEN_DESCRIPCION, 2)==0 &&
			utn_getFloat(valorFob,"Ingrese valor FOB:\n", "Valor FOB invalido.\n",0,1000000,2) == 0 &&
			utn_getFloat(alto,"Ingrese alto en centimetros:\n", "Alto invalido.\n",0,100,2) == 0 &&
			utn_getFloat(ancho,"Ingrese ancho en centimetros:\n", "Ancho invalido.\n",0,100,2) == 0 &&
			utn_getFloat(profundidad,"Ingrese la profundidad en centimetros:\n", "Profundidad invalida.\n",0,100,2) == 0 &&
			utn_getFloat(peso,"Ingrese peso en kilogramos:\n", "Peso invalido.\n",0,100,2) == 0)
		{
			ret=0;
		}
	}
	return ret;
}
/*
 * brief pide datos a modificar al usuario y los pasa por parametros
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_pedirDatosAModificar(int* idPosicionArancelaria,char* paisDeFabricacion,char* descripcion,float* valorFob,float* alto,float* ancho,float* profundidad,float* peso)
{
	int ret=-1;
	if(paisDeFabricacion != NULL && descripcion != NULL && valorFob != NULL && alto != NULL && ancho != NULL && profundidad != NULL && peso!= NULL )
	{
		if(utn_getInt("Ingrese un nuevo id de posicion arancelaria:\n", "Id invalido\n", idPosicionArancelaria, 2)==0 &&
			utn_getString("Ingrese nuevo pais de fabricacion:\n", "Pais de fabricacion invalido.\n", paisDeFabricacion, LEN_PAIS_DE_FABRICACION, 2)==0 &&
			utn_getStringWithNumbers("Ingrese nueva descripcion:\n", "Descripcion invalida.\n", descripcion, LEN_DESCRIPCION, 2)==0 &&
			utn_getFloat(valorFob,"Ingrese nuevo valor FOB:\n", "Valor FOB invalido.\n",0,1000000,2) == 0 &&
			utn_getFloat(alto,"Ingrese nuevo alto en centimetros:\n", "Alto invalido.\n",0,100,2) == 0 &&
			utn_getFloat(ancho,"Ingrese nuevo ancho en centimetros:\n", "Ancho invalido.\n",0,100,2) == 0 &&
			utn_getFloat(profundidad,"Ingrese la nueva profundidad en centimetros:\n", "Profundidad invalida.\n",0,100,2) == 0 &&
			utn_getFloat(peso,"Ingrese nuevo peso en kilogramos:\n", "Peso invalido.\n",0,100,2) == 0)
		{
			ret=0;
		}
	}
	return ret;
}
/*
 * brief modifica los datos del producto
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_modificar(Dictionary* producto,Dictionary* posicionesArancelarias)
{
	char codigoAModif[32];
	int ret=-1;
	Producto* pE;
	char paisDeFabricacion[LEN_PAIS_DE_FABRICACION];
	char descripcion[LEN_DESCRIPCION];
	float valorFob;
	float alto;
	float ancho;
	float profundidad;
	float peso;
	int idPosicionArancelaria;
	if(utn_getStringWithNumbersAndSymbols("Ingrese codigo del producto a modificar:\n","Error\n",codigoAModif,sizeof(codigoAModif),2)==0)
	{
		pE=(Producto*)dict_get(producto,codigoAModif);
		if(pE != NULL)
		{
			pos_imprimirLista(posicionesArancelarias);
			if(producto_pedirDatosAModificar(&idPosicionArancelaria,paisDeFabricacion, descripcion,&valorFob,&alto,&ancho,&profundidad,&peso)==0)
			{
				if(producto_setearDatos(pE,paisDeFabricacion, descripcion,valorFob,alto,ancho,profundidad,peso) == 0)
				{
					ret=0;
				}
			}
		}
		else
		{
			printf("No se encontro el codigo correspondiente a un producto.\n");
		}
	}
	return ret;
}
/*
 * brief setea los datos del producto pasado por parametros
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_setearDatos(Producto* pE,char* paisDeFabricacion,char* descripcion,float valorFob,float alto,float ancho,float profundidad,float peso)
{
	int ret=-1;
	if(producto_setPaisDeFabricacion(pE,paisDeFabricacion) == 0 &&
		producto_setDescripcion(pE,descripcion) == 0 &&
		producto_setValorFob(pE,valorFob) == 0 &&
		producto_setAncho(pE,ancho) == 0 &&
		producto_setProfundidad(pE,profundidad) == 0 &&
		producto_setPeso(pE,peso) == 0)
	{
		ret=0;
	}

	return ret;
}
/*
 * brief borra un producto
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_borrar(Dictionary* producto)
{
	Producto* pE;
	char codigoABorrar[32];
	int ret=-1;
	fflush(stdin);
	if(utn_getStringWithNumbersAndSymbols("Ingrese el codigo del producto a borrar:\n","Error\n",codigoABorrar,sizeof(codigoABorrar),2)==0)
	{
		pE=dict_get(producto,codigoABorrar);
		if(pE != NULL)
		{
			if(dict_remove(producto, codigoABorrar)==0)
			{
				if(producto_delete(pE)==0)
				{
					printf("Producto eliminado.\n");
					ret=0;
				}
			}
		}
		else
		{
			printf("No se encontro el producto con el codigo ingresado.\n");
		}
	}
	return ret;
}
/*
 * brief Imprime los datos del producto
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_imprimirLista(Dictionary* producto)
{
	LinkedList* auxList=NULL;
	Producto* pE;
	int ret=-1;
	int i;
	int flagError;

	char* pCodigo;
	char* pPaisDeFabricacion;
	char* pDescripcion;
	float valorFob;
	float alto;
	float ancho;
	float profundidad;
	float peso;
	int idPosicionArancelaria;

	if(producto != NULL)
	{
		auxList=dict_getValues(producto);
		if(auxList != NULL && ll_len(auxList) > 0)
		{
			ret=0;
			printf("Id pos. aranc.,Codigo,Pais de fabricacion,Descripcion,Valor FOB,Alto,Ancho,Profundidad,Peso\n");
			for(i=0;i<ll_len(auxList);i++)
			{
				pE=(Producto*)ll_get(auxList,i);
				if(pE != NULL)
				{
					idPosicionArancelaria=producto_getIdPosicionArancelaria(pE, &flagError);
					pCodigo=producto_getCodigo(pE, &flagError);
					pPaisDeFabricacion=producto_getPaisDeFabricacion(pE, &flagError);
					pDescripcion=producto_getDescripcion(pE, &flagError);
					valorFob=producto_getValorFob(pE, &flagError);
					alto=producto_getAlto(pE, &flagError);
					ancho=producto_getAncho(pE, &flagError);
					profundidad=producto_getProfundidad(pE, &flagError);
					peso=producto_getPeso(pE, &flagError);
					if(flagError != -1)
					{
						printf("%d,%s,%s,%s,%.3f,%.3f,%.3f,%.3f,%.3f\n",idPosicionArancelaria,pCodigo,pPaisDeFabricacion,pDescripcion,valorFob,alto,ancho,profundidad,peso);
					}
				}
			}
			ll_deleteLinkedList(auxList);
		}
	}
	return ret;
}

/*
 * brief lista los datos del producto ordenados por algun criterio
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_listarProductosOrdenados(LinkedList* list)
{
	int ret=-1;
	Producto* pE;
	char* pCodigo;
	char* pPaisDeFabricacion;
	char* pDescripcion;
	float valorFob;
	float alto;
	float ancho;
	float profundidad;
	float peso;
	int flagError;
	if(list != NULL && ll_len(list) > 0)
	{
		ret=0;
		printf("Codigo\t\t\tPais de fabricacion\tDescripcion\t\tValor FOB\t\tAlto\t\tAncho\t\tProfundidad\tPeso\n");
		for(int i=0;i<ll_len(list);i++)
		{
			pE=(Producto*)ll_get(list, i);
			if(pE != NULL)
			{
				pCodigo=producto_getCodigo(pE, &flagError);
				pPaisDeFabricacion=producto_getPaisDeFabricacion(pE, &flagError);
				pDescripcion=producto_getDescripcion(pE, &flagError);
				valorFob=producto_getValorFob(pE, &flagError);
				alto=producto_getAlto(pE, &flagError);
				ancho=producto_getAncho(pE, &flagError);
				profundidad=producto_getProfundidad(pE, &flagError);
				peso=producto_getPeso(pE, &flagError);
				if(flagError != -1)
				{
					printf("%-15s\t\t%-15s\t\t%-15s\t\t%-10.3f\t\t%-10.3f\t%-10.3f\t%-10.3f\t%-10.3f\n",pCodigo,pPaisDeFabricacion,pDescripcion,valorFob,alto,ancho,profundidad,peso);
				}
			}
		}
	}
	return ret;
}
/*
 * brief imprime los datos del producto con el precio final
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_imprimirListaConPrecios(Dictionary* producto,Dictionary* posicionesArancelarias,TransporteAereo* transporteAereo,TransporteMaritimo* transporteMaritimo)
{
	LinkedList* auxList=NULL;
	Producto* pE;
	PosicionArancelaria* pElemPosAranc;
	int ret=-1;
	int i;
	int flagError;

	char* pCodigo;
	char* pPaisDeFabricacion;
	char* pDescripcion;
	float valorFob;
	float alto;
	float ancho;
	float profundidad;
	float peso;
	int idPosicionArancelaria;
	char idPosicionArancelariaAux[256];
	float precioFinalMaritimo;
	float precioFinalAereo;

	if(producto != NULL)
	{
		auxList=dict_getValues(producto);
		if(auxList != NULL && ll_len(auxList) > 0)
		{
			ret=0;
			printf("Id pos aranc.,Codigo,Pais de fabricacion,Descripcion,Valor FOB,Alto,Ancho,Profundidad,Peso,Precio final maritimo,Precio final aereo\n");
			for(i=0;i<ll_len(auxList);i++)
			{
				pE=(Producto*)ll_get(auxList,i);
				if(pE != NULL)
				{
					pCodigo=producto_getCodigo(pE, &flagError);
					pPaisDeFabricacion=producto_getPaisDeFabricacion(pE, &flagError);
					pDescripcion=producto_getDescripcion(pE, &flagError);
					valorFob=producto_getValorFob(pE, &flagError);
					alto=producto_getAlto(pE, &flagError);
					ancho=producto_getAncho(pE, &flagError);
					profundidad=producto_getProfundidad(pE, &flagError);
					peso=producto_getPeso(pE, &flagError);
					idPosicionArancelaria=producto_getIdPosicionArancelaria(pE, &flagError);
					if(flagError != -1)
					{
						snprintf(idPosicionArancelariaAux,sizeof(idPosicionArancelariaAux),"%d",idPosicionArancelaria);
						pElemPosAranc=(PosicionArancelaria*)dict_get(posicionesArancelarias,idPosicionArancelariaAux);
						if(pElemPosAranc != NULL)
						{
							precioFinalMaritimo=calculos_calcularCostoFinalMaritimo(pE,pElemPosAranc,transporteMaritimo);
							precioFinalAereo=calculos_calcularCostoFinalAereo(pE, pElemPosAranc, transporteAereo);
							printf("%d,%s,%s,%s,%.3f,%.3fcm,%.3fcm,%.3fcm,%.3fkg,$%.3f,$%.3f\n",idPosicionArancelaria,pCodigo,pPaisDeFabricacion,pDescripcion,valorFob,alto,ancho,profundidad,peso,precioFinalMaritimo,precioFinalAereo);
						}
					}
				}
			}
			ll_deleteLinkedList(auxList);
		}
	}
	return ret;
}
/*
 * brief lista los datos del producto elegido por el usuario
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_listarUnProducto(Producto* producto,Dictionary* posicionesArancelarias,TransporteMaritimo* transporteMaritimo,TransporteAereo* transporteAereo)
{
	PosicionArancelaria* pElemPosAranc;
	int ret=-1;
	int flagError;

	char* pCodigo;
	char* pPaisDeFabricacion;
	char* pDescripcion;
	float valorFob;
	float alto;
	float ancho;
	float profundidad;
	float peso;
	int idPosicionArancelaria;
	char idPosicionArancelariaAux[256];
	float precioFinalMaritimo;
	float precioFinalAereo;

		if(producto != NULL && posicionesArancelarias != NULL && transporteAereo != NULL && transporteMaritimo != NULL)
		{
			ret=0;
			printf("Id pos aranc.,Codigo,Pais de fabricacion,Descripcion,Valor FOB,Alto,Ancho,Profundidad,Peso,Precio final maritimo,Precio final aereo\n");
			pCodigo=producto_getCodigo(producto, &flagError);
			pPaisDeFabricacion=producto_getPaisDeFabricacion(producto, &flagError);
			pDescripcion=producto_getDescripcion(producto, &flagError);
			valorFob=producto_getValorFob(producto, &flagError);
			alto=producto_getAlto(producto, &flagError);
			ancho=producto_getAncho(producto, &flagError);
			profundidad=producto_getProfundidad(producto, &flagError);
			peso=producto_getPeso(producto, &flagError);
			idPosicionArancelaria=producto_getIdPosicionArancelaria(producto, &flagError);
			if(flagError != -1)
			{
				snprintf(idPosicionArancelariaAux,sizeof(idPosicionArancelariaAux),"%d",idPosicionArancelaria);
				pElemPosAranc=(PosicionArancelaria*)dict_get(posicionesArancelarias,idPosicionArancelariaAux);
				if(pElemPosAranc != NULL)
				{
					precioFinalMaritimo=calculos_calcularCostoFinalMaritimo(producto,pElemPosAranc,transporteMaritimo);
					precioFinalAereo=calculos_calcularCostoFinalAereo(producto, pElemPosAranc, transporteAereo);
					printf("%d,%s,%s,%s,%.3f,%.3fcm,%.3fcm,%.3fcm,%.3fkg,$%.4f,$%.3f\n",idPosicionArancelaria,pCodigo,pPaisDeFabricacion,pDescripcion,valorFob,alto,ancho,profundidad,peso,precioFinalMaritimo,precioFinalAereo);
				}
			}
		}
	return ret;
}
/*
 * brief escribe los datos del producto en un archivo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_dump(char* path,Dictionary* productos)
{
	// serializer
	LinkedList* auxList;
	Producto* pE;
	int ret=-1;
	int i;
	int flagError;

	char* pCodigo;
	char* pPaisDeFabricacion;
	char* pDescripcion;
	float valorFob;
	float alto;
	float ancho;
	float profundidad;
	float peso;
	int idPosicionArancelaria;
	FILE* pFile;

	pFile = fopen(path,"w");
	if(pFile!=NULL)
	{
		auxList=dict_getValues(productos);
		if(auxList != NULL)
		{
			fprintf(pFile,"Codigo,Pais de fabricacion,Descripcion,Valor FOB,Alto,Ancho,Profundidad,Peso,Id posicion arancelaria\n");
			for(i=0;i<ll_len(auxList);i++)
			{
				pE=(Producto*)ll_get(auxList, i);
				if(pE != NULL)
				{
					pCodigo=producto_getCodigo(pE, &flagError);
					pPaisDeFabricacion=producto_getPaisDeFabricacion(pE, &flagError);
					pDescripcion=producto_getDescripcion(pE, &flagError);
					valorFob=producto_getValorFob(pE, &flagError);
					alto=producto_getAlto(pE, &flagError);
					ancho=producto_getAncho(pE, &flagError);
					profundidad=producto_getProfundidad(pE, &flagError);
					peso=producto_getPeso(pE, &flagError);
					idPosicionArancelaria=producto_getIdPosicionArancelaria(pE, &flagError);
					if(flagError != -1)
					{
						fprintf(pFile,"%s,%s,%s,%f,%f,%f,%f,%f,%d\n",pCodigo,pPaisDeFabricacion,pDescripcion,valorFob,alto,ancho,profundidad,peso,idPosicionArancelaria);
						ret=i;
					}
				}
				else
				{
					ret=-1;
					break;
				}
		}
		ll_deleteLinkedList(auxList);
		}
		// Escribo cada empleado en una linea del archivo
		fclose(pFile);
	}
	return ret;
}
/*
 * brief lee los datos del producto de un archivo
 * return retorna -1(ERROR) o 0 (Exito)
 */
int producto_parser(char* path,Dictionary* productos)
{
	FILE* pFile;
	int flagOnce=0;
	Producto* pE;
	int indice=-1;

	char codigoAux[256];
	char paisDeFabricacionAux[256];
	char descripcionAux[256];
	char valorFobAux[256];
	char altoAux[256];
	char anchoAux[256];
	char profundidadAux[256];
	char pesoAux[256];
	char idPosicionArancelariaAux[256];
	float valorFob;
	float alto;
	float ancho;
	float profundidad;
	float peso;
	int idPosicionArancelaria;
	int maxIdAux;

	pFile = fopen(path,"r");
	if(pFile!=NULL)
	{
		indice=0;
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",codigoAux,paisDeFabricacionAux,descripcionAux,valorFobAux,altoAux,anchoAux,profundidadAux,pesoAux,idPosicionArancelariaAux)==9)
			{
				if(flagOnce!=0)
				{
					valorFob=atof(valorFobAux);
					alto=atof(altoAux);
					ancho=atof(anchoAux);
					profundidad=atof(profundidadAux);
					peso=atof(pesoAux);
					idPosicionArancelaria=atoi(idPosicionArancelariaAux);
					pE = producto_newParam(codigoAux,paisDeFabricacionAux,descripcionAux,valorFob,alto,ancho,profundidad,peso,idPosicionArancelaria);
					if(pE != NULL)
					{
						dict_insert(productos,codigoAux, pE);
						if(indice==0)
						{
							maxIdAux=idPosicionArancelaria;
						}
						if(indice > 0 && idPosicionArancelaria > maxIdAux)
						{
							maxIdAux=idPosicionArancelaria;
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
		producto_setearValorInicialDeId(maxIdAux);
	}
	return indice; // devuelve cantidad leidos
}


static int fncCriterioValorFob(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	Producto* pE;
	Producto* pE2;

	float valorFob;
	float valorFob2;

	pE=(Producto*)p1;
	pE2=(Producto*)p2;

	valorFob=producto_getValorFob(pE, &flagError);
	valorFob2=producto_getValorFob(pE2, &flagError);
	if(flagError != -1)
	{
		if(valorFob == valorFob2)
		{
			ret=0;
		}
		else if(valorFob > valorFob2)
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
static int fncCriterioAlto(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	Producto* pE;
	Producto* pE2;

	float alto;
	float alto2;

	pE=(Producto*)p1;
	pE2=(Producto*)p2;

	alto=producto_getAlto(pE, &flagError);
	alto2=producto_getAlto(pE2, &flagError);
	if(flagError != -1)
	{
		if(alto == alto2)
		{
			ret=0;
		}
		else if(alto > alto2)
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

static int fncCriterioAncho(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	Producto* pE;
	Producto* pE2;

	float ancho;
	float ancho2;

	pE=(Producto*)p1;
	pE2=(Producto*)p2;

	ancho=producto_getAncho(pE, &flagError);
	ancho2=producto_getAncho(pE2, &flagError);
	if(flagError != -1)
	{
		if(ancho == ancho2)
		{
			ret=0;
		}
		else if(ancho > ancho2)
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
static int fncCriterioProfundidad(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	Producto* pE;
	Producto* pE2;

	float profundidad;
	float profundidad2;

	pE=(Producto*)p1;
	pE2=(Producto*)p2;

	profundidad=producto_getProfundidad(pE, &flagError);
	profundidad2=producto_getProfundidad(pE2, &flagError);
	if(flagError != -1)
	{
		if(profundidad == profundidad2)
		{
			ret=0;
		}
		else if(profundidad > profundidad2)
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

static int fncCriterioPeso(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	Producto* pE;
	Producto* pE2;

	float peso;
	float peso2;

	pE=(Producto*)p1;
	pE2=(Producto*)p2;

	peso=producto_getProfundidad(pE, &flagError);
	peso2=producto_getProfundidad(pE2, &flagError);
	if(flagError != -1)
	{
		if(peso == peso2)
		{
			ret=0;
		}
		else if(peso > peso2)
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
static int fncCriterioDescripcion(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	Producto* pE;
	Producto* pE2;

	char* descripcion;
	char* descripcion2;

	pE=(Producto*)p1;
	pE2=(Producto*)p2;

	descripcion=producto_getDescripcion(pE, &flagError);
	descripcion2=producto_getDescripcion(pE2, &flagError);

	if(flagError != -1)
	{
		ret=strcmp(descripcion,descripcion2);
	}
	return ret;
}
static int fncCriterioPais(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	Producto* pE;
	Producto* pE2;

	char* paisDeFabricacion;
	char* paisDeFabricacion2;

	pE=(Producto*)p1;
	pE2=(Producto*)p2;

	paisDeFabricacion=producto_getPaisDeFabricacion(pE, &flagError);
	paisDeFabricacion2=producto_getPaisDeFabricacion(pE2, &flagError);

	if(flagError != -1)
	{
		ret=strcmp(paisDeFabricacion,paisDeFabricacion2);
	}
	return ret;
}
static int fncCriterioCodigo(void* p1,void* p2)
{
	int ret=-1;
	int flagError;

	Producto* pE;
	Producto* pE2;

	char* codigo;
	char* codigo2;

	pE=(Producto*)p1;
	pE2=(Producto*)p2;

	codigo=producto_getCodigo(pE, &flagError);
	codigo2=producto_getCodigo(pE2, &flagError);

	if(flagError != -1)
	{
		ret=strcmp(codigo,codigo2);
	}
	return ret;
}




int producto_ordenarPorDescripcion(Dictionary* productos)
{
	int ret=-1;
	LinkedList* auxList;

	if(productos != NULL)
	{
		auxList=dict_getValues(productos);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioDescripcion,0);
			if(producto_listarProductosOrdenados(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}
int producto_ordenarPorPais(Dictionary* productos)
{
	int ret=-1;
	LinkedList* auxList;

	if(productos != NULL)
	{
		auxList=dict_getValues(productos);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioPais,0);
			if(producto_listarProductosOrdenados(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}

int producto_ordenarPorCodigo(Dictionary* productos)
{
	int ret=-1;
	LinkedList* auxList;

	if(productos != NULL)
	{
		auxList=dict_getValues(productos);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioCodigo,0);
			if(producto_listarProductosOrdenados(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}

int producto_ordenarPorValorFob(Dictionary* productos)
{
	int ret=-1;
	LinkedList* auxList;


	if(productos != NULL)
	{
		auxList=dict_getValues(productos);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioValorFob,0);
			if(producto_listarProductosOrdenados(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}
int producto_ordenarPorAlto(Dictionary* productos)
{
	int ret=-1;
	LinkedList* auxList;


	if(productos != NULL)
	{
		auxList=dict_getValues(productos);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioAlto,0);
			if(producto_listarProductosOrdenados(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}

int producto_ordenarPorAncho(Dictionary* productos)
{
	int ret=-1;
	LinkedList* auxList;

	if(productos != NULL)
	{
		auxList=dict_getValues(productos);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioAncho,0);
			if(producto_listarProductosOrdenados(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}

int producto_ordenarPorProfundidad(Dictionary* productos)
{
	int ret=-1;
	LinkedList* auxList;

	if(productos != NULL)
	{
		auxList=dict_getValues(productos);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioProfundidad,0);
			if(producto_listarProductosOrdenados(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}
int producto_ordenarPorPeso(Dictionary* productos)
{
	int ret=-1;
	LinkedList* auxList;

	if(productos != NULL)
	{
		auxList=dict_getValues(productos);
		if(auxList != NULL)
		{
			ll_sort(auxList,fncCriterioPeso,0);
			if(producto_listarProductosOrdenados(auxList)==0)
			{
				ll_deleteLinkedList(auxList);
				ret=0;
			}
		}
	}
	return ret;
}
