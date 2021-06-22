/*
 * calculos.h
 *
 *  Created on: Jun 18, 2021
 *      Author: Stefano
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
//USADO EN MARITIMO
float calculos_calcularPrecioTemp(Producto* productos,TransporteMaritimo* transporteMaritimo);
float calculos_calcularProporcionalDeTransporteMaritimo(Producto* productos,TransporteMaritimo* transporteMaritimo);
float calculos_calcularBaseImponibleMaritima(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteMaritimo* transporteMaritimo);
float calculos_calcularTasaEstadisticaMaritima(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteMaritimo* transporteMaritimo);
float calculos_calcularImportacionMaritima(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteMaritimo* transporteMaritimo);
float calculos_calcularCostoFinalMaritimo(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteMaritimo* transporteMaritimo);
//USADO EN AEREO
float calculos_calcularPrecioPorPesoReal(Producto* productos,TransporteAereo* transporteAereo);
float calculos_calcularPesoVolumetrico(Producto* productos,TransporteAereo* transporteAereo);
float calculos_calcularPrecioPorPesoVolumetrico(Producto* productos,TransporteAereo* transporteAereo);
float calculos_calcularPrecioSegunElMasPesado(Producto* productos,TransporteAereo* transporteAereo);
float calculos_calcularProporcionalDeTransporteAereo(Producto* productos,TransporteAereo* transporteAereo);
float calculos_calcularBaseImponibleAerea(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteAereo* transporteAereo);
float calculos_calcularTasaEstadisticaAerea(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteAereo* transporteAereo);
float calculos_calcularImportacionAerea(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteAereo* transporteAereo);
float calculos_calcularCostoFinalAereo(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteAereo* transporteAereo);
//USADO EN AMBOS
float calculos_calcularVolumenEnCm(Producto* productos);
float calculos_calcularVolumenEnMetros(Producto* productos);
float calculos_calcularSeguro(Producto* productos,PosicionArancelaria* posicionesArancelarias);
#endif /* CALCULOS_H_ */
