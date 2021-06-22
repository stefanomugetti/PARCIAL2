/*
 * Controller.h
 *
 *  Created on: Jun 17, 2021
 *      Author: Stefano
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "TransporteAereo.h"
#include "TransporteMaritimo.h"

int controller_agregarProducto(Dictionary* productos,Dictionary* posicionesArancelarias);
int controller_modificarProducto(Dictionary* productos,Dictionary* posicionesArancelarias);
int controller_eliminarProducto(Dictionary* productos);
int controller_listarProductos(Dictionary* productos);
int controller_listarUnProducto(Dictionary* productos,Dictionary* posicionesArancelarias,TransporteAereo* transporteAereo,TransporteMaritimo* transporteMaritimo);
int controller_listarProductosConPrecios(Dictionary* productos,Dictionary* posicionesArancelarias,TransporteAereo* transporteAereo,TransporteMaritimo* transporteMaritimo);
int controller_agregarPosArancelaria(Dictionary* posicionArancelaria);
int controller_modificarPosArancelaria(Dictionary* posicionArancelaria);
int controller_eliminarPosArancelaria(Dictionary* posicionArancelaria);
int controller_listarPosArancelaria(Dictionary* posicionArancelaria);
int controller_listarUnaPosicionArancelaria(Dictionary* posicionesArancelarias);
int controller_validarCargaDeDatos(Dictionary* productos,Dictionary* posicionesArancelarias,TransporteAereo* transporteAereo,TransporteMaritimo* transporteMaritimo);
int controller_modificarDatosTransporte(TransporteAereo* transporteAereo,TransporteMaritimo* transporteMaritimo);
int controller_imprimirValorDelTransporteAereo(TransporteAereo* transporteAereo);
int controller_imprimirValorDelTransporteMaritimo(TransporteMaritimo* transporteMaritimo);
int controller_menuListarProductosEnOrden(Dictionary* productos);
int controller_menuListarPosicionesArancelariasEnOrden(Dictionary* posicionesArancelarias);


//extras
#endif /* CONTROLLER_H_ */
