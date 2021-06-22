/*
 * TransporteAereo.h
 *
 *  Created on: Jun 17, 2021
 *      Author: Stefano
 */

#ifndef TRANSPORTEAEREO_H_
#define TRANSPORTEAEREO_H_

typedef struct{
	float constanteVolumetrica;
	float valorPorKg;
}TransporteAereo;

TransporteAereo* aereo_new(void);

int aereo_setConstanteVolumetrica(TransporteAereo* this,float constanteVolumetrica);
float aereo_getConstanteVolumetrica(TransporteAereo* this,int* flagError);
int isValidConstanteVolumetrica(float constanteVolumetrica);

int aereo_setValorPorKg(TransporteAereo* this,float valorPorKg);
float aereo_getValorPorKg(TransporteAereo* this,int* flagError);
int isValidValorPorKg(float valorPorKg);

int aereo_editarDatosDelTransporteAereo(TransporteAereo* transporteAereo);
int aereo_pedirDatosAModificar(float* constanteVolumetrica,float* valorPorKg);
int aereo_parser(char* path,TransporteAereo* this);
int aereo_imprimirLista(TransporteAereo* transporteAereo);
int aereo_dump(char* path,TransporteAereo* transporteAereo);


#endif /* TRANSPORTEAEREO_H_ */


