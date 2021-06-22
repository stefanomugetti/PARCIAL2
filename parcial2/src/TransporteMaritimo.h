/*
 * TransporteMaritimo.h
 *
 *  Created on: Jun 17, 2021
 *      Author: Stefano
 */

#ifndef TRANSPORTEMARITIMO_H_
#define TRANSPORTEMARITIMO_H_

typedef struct{
	float metrosCubicos;
	float valorPorMetroCubico;
}TransporteMaritimo;

TransporteMaritimo* maritimo_new(void);

int maritimo_setMetrosCubicos(TransporteMaritimo* this,float metrosCubicos);
float maritimo_getMetrosCubicos(TransporteMaritimo* this,int* flagError);
int isValidMetrosCubicos(float metrosCubicos);

int maritimo_setValorPorMetroCubico(TransporteMaritimo* this,float valorPorMetroCubico);
float maritimo_getValorPorMetroCubico(TransporteMaritimo* this,int* flagError);
int isValidValorPorMetroCubico(float valorPorMetroCubico);

int aereo_pedirDatos(float* metrosCubicos,float* valorPorMetroCubico);
int maritimo_editarDatosDelTransporteMaritimo(TransporteMaritimo* transporteMaritimo);
int maritimo_imprimirLista(TransporteMaritimo* transporteMaritimo);
int maritimo_parser(char* path,TransporteMaritimo* this);
int maritimo_dump(char* path,TransporteMaritimo* this);

#endif /* TRANSPORTEMARITIMO_H_ */
