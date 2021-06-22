/*
 * Producto.h
 *
 *  Created on: Jun 15, 2021
 *      Author: Stefano
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include "TransporteAereo.h"
#include "TransporteMaritimo.h"

#define LEN_CODIGO						 15
#define LEN_PAIS_DE_FABRICACION 		 15
#define LEN_DESCRIPCION  				 20

typedef struct{
	char codigo[LEN_CODIGO];
	char paisDeFabricacion[LEN_PAIS_DE_FABRICACION];
	char descripcion[LEN_DESCRIPCION];
	float valorFob;
	float alto;
	float ancho;
	float profundidad;
	float peso;
	int idPosicionArancelaria;
}Producto;

Producto* producto_new(void);
Producto* producto_newParam(char* codigo,char* paisDeFabricacion,char* descripcion,float valorFob,float alto,float ancho,float profundidad,float peso,float idPosicionArancelaria);
int producto_delete(Producto* this);


int producto_setCodigo(Producto* this, char* codigo);
char* producto_getCodigo(Producto* this,int* flagError);
int isValidCodigo(char* codigo);

int producto_setPaisDeFabricacion(Producto* this,char* paisDeFabricacion);
char* producto_getPaisDeFabricacion(Producto* this,int* flagError);
int isValidPaisDeFabricacion(char* paisDeFabricacion);

int producto_setDescripcion(Producto* this,char* descripcion);
char* producto_getDescripcion(Producto* this,int* flagError);
int isValidDescripcion(char* descripcion);

int producto_setValorFob(Producto* this,float valorFob);
float producto_getValorFob(Producto* this,int* flagError);
int isValidValorFob(float valorFob);

int producto_setAlto(Producto* this,float alto);
float producto_getAlto(Producto* this,int* flagError);
int isValidAlto(float alto);

int producto_setAncho(Producto* this,float ancho);
float producto_getAncho(Producto* this,int* flagError);
int isValidAncho(float ancho);

int producto_setProfundidad(Producto* this,float profundidad);
float producto_getProfundidad(Producto* this,int* flagError);
int isValidProfundidad(float profundidad);

int producto_setPeso(Producto* this,float peso);
float producto_getPeso(Producto* this,int* flagError);
int isValidPeso(float peso);

int producto_setIdPosicionArancelaria(Producto* this,int idPosicionArancelaria);
int producto_getIdPosicionArancelaria(Producto* this,int* flagError);
int isValidPosicionArancelaria(int idPosicionArancelaria);

int producto_alta(Dictionary* producto,Dictionary* posicionesArancelarias);
int producto_modificar(Dictionary* producto,Dictionary* posicionesArancelarias);
int producto_borrar(Dictionary* producto);
int producto_imprimirLista(Dictionary* producto);
int producto_imprimirListaConPrecios(Dictionary* producto,Dictionary* posicionesArancelarias,TransporteAereo* transporteAereo,TransporteMaritimo* transporteMaritimo);
int producto_listarUnProducto(Producto* producto,Dictionary* posicionesArancelarias,TransporteMaritimo* transporteMaritimo,TransporteAereo* transporteAereo);
int producto_dump(char* path,Dictionary* posicionArancelaria);
int producto_parser(char* path,Dictionary* productos);

//EXTRASSS
int producto_pedirDatos(char* codigo,char* paisDeFabricacion,char* descripcion,float* valorFob,float* alto,float* ancho,float* profundidad,float* peso);
int producto_pedirDatosAModificar(int* idPosicionArancelaria,char* paisDeFabricacion,char* descripcion,float* valorFob,float* alto,float* ancho,float* profundidad,float* peso);
int producto_setearDatos(Producto* pE,char* paisDeFabricacion,char* descripcion,float valorFob,float alto,float ancho,float profundidad,float peso);
int producto_listarProductosOrdenados(LinkedList* list);
int producto_ordenarPorCodigo(Dictionary* productos);
int producto_ordenarPorPais(Dictionary* productos);
int producto_ordenarPorDescripcion(Dictionary* productos);
int producto_ordenarPorValorFob(Dictionary* productos);
int producto_ordenarPorAlto(Dictionary* productos);
int producto_ordenarPorAncho(Dictionary* productos);
int producto_ordenarPorProfundidad(Dictionary* productos);
int producto_ordenarPorPeso(Dictionary* productos);





#endif /* PRODUCTO_H_ */
