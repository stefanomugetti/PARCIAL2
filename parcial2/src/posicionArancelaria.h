/*
 * posicionArancelaria.h
 *
 *  Created on: Jun 15, 2021
 *      Author: Stefano
 */

#ifndef POSICIONARANCELARIA_H_
#define POSICIONARANCELARIA_H_

#define LEN_NOMENCLATURA 12
typedef struct{
	int id;
	char nomenclaturaArancelaria[LEN_NOMENCLATURA];
	float porcSeguro;
	float porcTasaEstadistica;
	float porcImportacion;
	int tipoDeLicencia;
}PosicionArancelaria;

PosicionArancelaria* pos_new(void);
PosicionArancelaria* pos_newParam(int id,char* nomenclatura,float porcSeguro,float porcTasaEstadistica,float porcImportacion,int tipoLicencia);
int pos_delete(PosicionArancelaria* this);

int pos_setNomenclaturaArancelaria(PosicionArancelaria* this, char* nomenclaturaArancelaria);
char* pos_getNomenclaturaArancelaria(PosicionArancelaria* this,int* flagError);
int isValidNomenclaturaArancelaria(char* nomenclaturaArancelaria);

int pos_setPorcSeguro(PosicionArancelaria* this,float porcSeguro);
float pos_getPorcSeguro(PosicionArancelaria* this,int* flagError);
int isValidPorcSeguro(float porcSeguro);

int pos_setPorcTasaEstadistica(PosicionArancelaria* this,float porcTasaEstadistica);
float pos_getPorcTasaEstadistica (PosicionArancelaria* this,int* flagError);
int isValidPorcTasaEstadistica(float porcTasaEstadistica);

int pos_setPorcImportacion(PosicionArancelaria* this,float porcImportacion);
float pos_getPorcImportacion(PosicionArancelaria* this,int* flagError);
int isValidPorcImportacion(float porcImportacion);

int pos_setId(PosicionArancelaria* this, int id);
int pos_getId(PosicionArancelaria* this,int* flagError);
int isValidIdPosicionArancelaria(int id);

int pos_setTipoDeLicencia(PosicionArancelaria* this, int tipoDeLicencia);
int pos_getTipoDeLicencia(PosicionArancelaria* this,int* flagError);
int isValidTipoDeLicencia(int tipoDeLicencia);

int pos_alta(Dictionary* posicionArancelaria);
int pos_modificar(Dictionary* producto);
int pos_borrar(Dictionary* posicionArancelaria);
int pos_imprimirLista(Dictionary* posicionArancelaria);
int pos_imprimirUnaPosicionArancelaria(PosicionArancelaria* posicionArancelaria);
int pos_dump(char* path,Dictionary* posicionArancelaria);
int pos_parser(char* path,Dictionary* posicionArancelaria);

//EXTRASSSS
int pos_pedirDatos(char* nomenclaturaArancelaria,float* porcSeguro,float* porcTasaEstadistica,float* porcImportacion,int* tipoDeLicencia);
int pos_pedirDatosAModificar(char* nomenclaturaArancelaria,float* porcSeguro,float* porcTasaEstadistica,float* porcImportacion,int* tipoDeLicencia);
int pos_generarId(void);
void pos_setearValorInicialDeId(int id);
int pos_ordenarPorNomenclatura(Dictionary* posicionesArancelarias);
int pos_ordenarPorPorcSeguro(Dictionary* posicionesArancelarias);
int pos_ordenarPorPorcTasaEstadistica(Dictionary* posicionesArancelarias);
int pos_ordenarPorPorcImportacion(Dictionary* posicionesArancelarias);

#endif /* POSICIONARANCELARIA_H_ */
