/*
 * calculos.c
 *
 *  Created on: Jun 18, 2021
 *      Author: Stefano
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Dictionary.h"
#include "Controller.h"
#include "posicionArancelaria.h"
#include "Producto.h"
#include "TransporteAereo.h"
#include "TransporteMaritimo.h"
#include "calculos.h"

/*
 * brief calcula el volumen en metros cubicos
 * param producto Producto*
 * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularVolumenEnMetros(Producto* productos)
{
	float ancho;
	float alto;
	float profundidad;

	float volumenMts=-1;
	int flagError;

	if(productos != NULL)
	{
		ancho=producto_getAncho(productos, &flagError);
		alto=producto_getAlto(productos, &flagError);
		profundidad=producto_getProfundidad(productos, &flagError);
		if(flagError != -1)
		{
			volumenMts=(ancho*alto*profundidad)/(100*100*100);
		}
	}
	return volumenMts;
}
/*
 * brief calcula el volumen en cm cubicos
 * param producto Producto*
 * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularVolumenEnCm(Producto* productos)
{
	float ancho;
	float alto;
	float profundidad;

	float volumenCm=-1;
	int flagError;

	if(productos != NULL)
	{
		ancho=producto_getAncho(productos, &flagError);
		alto=producto_getAlto(productos, &flagError);
		profundidad=producto_getProfundidad(productos, &flagError);
		if(flagError != -1)
		{
			volumenCm=(ancho*alto*profundidad);
		}
	}
	return volumenCm;
}
/*
 * brief calcula el precio temporal
 * param transporteMaritimo transporteMaritimo*
 * param producto Producto*
 * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularPrecioTemp(Producto* productos,TransporteMaritimo* transporteMaritimo)
{
	int flagError;
	int metrosCubicos=-1;
	float precioPorMetroCubico;
	int precioTotalPorMetroCubico;

	if(productos != NULL && transporteMaritimo != NULL)
	{
		precioPorMetroCubico=maritimo_getValorPorMetroCubico(transporteMaritimo, &metrosCubicos);
		metrosCubicos=maritimo_getMetrosCubicos(transporteMaritimo, &flagError);
		if(flagError != -1)
		{
			precioTotalPorMetroCubico=metrosCubicos/precioPorMetroCubico;
		}
	}
	return precioTotalPorMetroCubico;
}
/*
 * brief calcula el proporcional de  trans. maritimo
 * param transporteMaritimo transporteMaritimo*
 * param producto Producto*
 * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularProporcionalDeTransporteMaritimo(Producto* productos,TransporteMaritimo* transporteMaritimo)
{
	float proporcionalDeTransporte;
	float volumen;
	float precioTemp;

	if(productos != NULL && transporteMaritimo != NULL)
	{
		precioTemp=calculos_calcularPrecioTemp(productos, transporteMaritimo);
		volumen=calculos_calcularVolumenEnMetros(productos);
		proporcionalDeTransporte=volumen*precioTemp;
	}
	return proporcionalDeTransporte;
}
/*
 * brief calcula el valor del porcentaje del seguro
 * param posicionesArancelarias PosicionArancelaria*
 * param producto Producto*
 * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularSeguro(Producto* productos,PosicionArancelaria* posicionesArancelarias)
{
	float valorFob;
	float porcSeguro;
	float valorSeguro=-1;
	int flagError;
	if(productos != NULL && posicionesArancelarias != NULL)
	{
		valorFob=producto_getValorFob(productos, &flagError);
		porcSeguro=pos_getPorcSeguro(posicionesArancelarias, &flagError);
		if(flagError != -1)
		{
			valorSeguro=(porcSeguro*valorFob)/100;
		}
	}
	return valorSeguro;
}
/*
 * brief calcula el valor de la  base imponible maritima
 * param posicionesArancelarias PosicionArancelaria*
 * param transporteMaritimo TransporteMaritimo*
 * param producto Producto*
 * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularBaseImponibleMaritima(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteMaritimo* transporteMaritimo)
{
	float baseImponible=-1;
	float seguro;
	float valorFob;
	float proporcionalDeTransporte;
	int flagError;

	if(productos != NULL && posicionesArancelarias != NULL && transporteMaritimo != NULL)
	{
		valorFob=producto_getValorFob(productos, &flagError);
		if(flagError != -1)
		{
			seguro=calculos_calcularSeguro(productos, posicionesArancelarias);
			proporcionalDeTransporte=calculos_calcularProporcionalDeTransporteMaritimo(productos, transporteMaritimo);
			baseImponible=valorFob+seguro+proporcionalDeTransporte;
		}
	}
	return baseImponible;
}

/*
 * brief calcula el valor de la tasa estadistica maritima
 * param producto Producto*
 * param posicionesArancelarias PosicionArancelaria*
 * param transporteMaritimo TransporteMaritimo*
 * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularTasaEstadisticaMaritima(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteMaritimo* transporteMaritimo)
{
	float valorTasaEstadistica=-1;
	float porcTasaEstadistica;
	float baseImponible;
	int flagError;
	if(productos != NULL && posicionesArancelarias != NULL && transporteMaritimo != NULL)
	{
		porcTasaEstadistica=pos_getPorcTasaEstadistica(posicionesArancelarias,&flagError);
		if(flagError != -1)
		{
			baseImponible=calculos_calcularBaseImponibleMaritima(productos, posicionesArancelarias, transporteMaritimo);
			valorTasaEstadistica=(porcTasaEstadistica*baseImponible)/100;
		}
	}
	return valorTasaEstadistica;
}
/*
 * brief calcula el valor de la importacion maritima
 * param posicionesArancelarias PosicionArancelaria*
 * param transporteMaritimo TransporteMaritimo*
 * param producto Producto*
 * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularImportacionMaritima(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteMaritimo* transporteMaritimo)
{
	float valorImportacion=-1;
	float porcImportacion;
	float baseImponible;
	int flagError;
	if(productos != NULL && posicionesArancelarias != NULL && transporteMaritimo != NULL)
	{
		porcImportacion=pos_getPorcImportacion(posicionesArancelarias,&flagError);
		if(flagError != -1)
		{
			baseImponible=calculos_calcularBaseImponibleMaritima(productos, posicionesArancelarias, transporteMaritimo);
			valorImportacion=(porcImportacion*baseImponible)/100;
		}
	}
	return valorImportacion;
}
/*
 * brief calcula el costo final del producto por transporte maritimo
 * param posicionesArancelarias PosicionArancelaria*
 * param transporteMaritimo TransporteMaritimo*
 * param producto Producto*
 * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularCostoFinalMaritimo(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteMaritimo* transporteMaritimo)
{
	float costoFinal=-1;
	float baseImponible;
	float valorImportacion;
	float valorTasaEstadistica;

	if(productos != NULL && posicionesArancelarias != NULL && transporteMaritimo != NULL)
	{
		baseImponible=calculos_calcularBaseImponibleMaritima(productos, posicionesArancelarias, transporteMaritimo);
		valorImportacion=calculos_calcularImportacionMaritima(productos, posicionesArancelarias, transporteMaritimo);
		valorTasaEstadistica=calculos_calcularTasaEstadisticaMaritima(productos, posicionesArancelarias, transporteMaritimo);
		costoFinal=baseImponible+valorImportacion+valorTasaEstadistica;
	}
	return costoFinal;
}
/*
 * brief calcula el precio por peso real
 * param productos Producto*
 * param transporteAereo TransporteAereo*
 *  * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularPrecioPorPesoReal(Producto* productos,TransporteAereo* transporteAereo)
{
	float precioPorPesoReal=-1;
	float peso;
	float valorPorKg;
	int flagError;
	if(productos != NULL && transporteAereo != NULL)
	{
		peso=producto_getPeso(productos, &flagError);
		valorPorKg=aereo_getValorPorKg(transporteAereo, &flagError);
		if(flagError != -1)
		{
			precioPorPesoReal=peso*valorPorKg;
		}
	}
	return precioPorPesoReal;
}
/*
 * brief calcula el peso volumetrico
 * param productos Producto*
 * param transporteAereo TransporteAereo*
 *  * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularPesoVolumetrico(Producto* productos,TransporteAereo* transporteAereo)
{
	float volumenEnCm;
	float pesoVolumetrico=-1;
	float constanteVolumetrica;
	int flagError;
	if(productos != NULL && transporteAereo != NULL)
	{
		volumenEnCm=calculos_calcularVolumenEnCm(productos);
		constanteVolumetrica=aereo_getConstanteVolumetrica(transporteAereo, &flagError);
		if(flagError != -1)
		{
			pesoVolumetrico=volumenEnCm/constanteVolumetrica;
		}
	}
	return pesoVolumetrico;
}
/*
 * brief calcula el precio por peso volumetrico
 * param productos Producto*
 * param transporteAereo TransporteAereo*
 *  * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularPrecioPorPesoVolumetrico(Producto* productos,TransporteAereo* transporteAereo)
{
	float precioPorPesoVolumetrico=-1;
	float pesoVolumetrico;
	float valorPorKg;
	int flagError;
	if(productos != NULL && transporteAereo != NULL)
	{
		pesoVolumetrico=calculos_calcularPesoVolumetrico(productos, transporteAereo);
		valorPorKg=aereo_getValorPorKg(transporteAereo, &flagError);
		if(flagError != -1)
		{
			precioPorPesoVolumetrico=pesoVolumetrico*valorPorKg;
		}
	}
	return precioPorPesoVolumetrico;
}
/*
 * brief calcula el proporcional de transporte aereo
 * param productos Producto*
 * param transporteAereo TransporteAereo*
 *  * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularProporcionalDeTransporteAereo(Producto* productos,TransporteAereo* transporteAereo)
{
	float proporcionalDeTransporteAereo=-1;
	float precioPorPesoVolumetrico;
	float precioPorPesoReal;

	if(productos != NULL && transporteAereo != NULL)
	{
		precioPorPesoVolumetrico=calculos_calcularPrecioPorPesoVolumetrico(productos, transporteAereo);
		precioPorPesoReal=calculos_calcularPrecioPorPesoReal(productos, transporteAereo);
		if(precioPorPesoVolumetrico >= precioPorPesoReal)
		{
			proporcionalDeTransporteAereo=precioPorPesoVolumetrico;
		}
		if(precioPorPesoReal > precioPorPesoVolumetrico)
		{
			proporcionalDeTransporteAereo=precioPorPesoReal;
		}
	}
	return proporcionalDeTransporteAereo;
}
/*
 * brief calcula el valor de la base imponible aerea
 * param productos Producto*
 * param transporteAereo TransporteAereo*
 * param PosicionArancelaria* posicionesArancelarias
 *  * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularBaseImponibleAerea(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteAereo* transporteAereo)
{
	float baseImponibleAerea=-1;
	float seguro;
	float valorFob;
	float proporcionalDeTransporte;
	int flagError;

	if(productos != NULL && posicionesArancelarias != NULL && transporteAereo != NULL)
	{
		valorFob=producto_getValorFob(productos, &flagError);
		if(flagError != -1)
		{
			seguro=calculos_calcularSeguro(productos, posicionesArancelarias);
			proporcionalDeTransporte=calculos_calcularProporcionalDeTransporteAereo(productos, transporteAereo);
			baseImponibleAerea=valorFob+seguro+proporcionalDeTransporte;
		}
	}
	return baseImponibleAerea;
}
/*
 * brief calcula el valor de la tasa estadistica aerea
 * param productos Producto*
 * param transporteAereo TransporteAereo*
 * param PosicionArancelaria* posicionesArancelarias
 *  * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularTasaEstadisticaAerea(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteAereo* transporteAereo)
{
	float valorTasaEstadistica=-1;
	float porcTasaEstadistica;
	float baseImponible;
	int flagError;
	if(productos != NULL && posicionesArancelarias != NULL && transporteAereo != NULL)
	{
		porcTasaEstadistica=pos_getPorcTasaEstadistica(posicionesArancelarias,&flagError);
		if(flagError != -1)
		{
			baseImponible=calculos_calcularBaseImponibleAerea(productos, posicionesArancelarias, transporteAereo);
			valorTasaEstadistica=(porcTasaEstadistica*baseImponible)/100;
		}
	}
	return valorTasaEstadistica;
}
/*
 * brief calcula el valor de la importacion aerea
 * param productos Producto*
 * param transporteAereo TransporteAereo*
 * param PosicionArancelaria* posicionesArancelarias
 *  * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularImportacionAerea(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteAereo* transporteAereo)
{
	float valorImportacion=-1;
	float porcImportacion;
	float baseImponible;
	int flagError;
	if(productos != NULL && posicionesArancelarias != NULL && transporteAereo != NULL)
	{
		porcImportacion=pos_getPorcImportacion(posicionesArancelarias,&flagError);
		if(flagError != -1)
		{
			baseImponible=calculos_calcularBaseImponibleAerea(productos, posicionesArancelarias, transporteAereo);
			valorImportacion=(porcImportacion*baseImponible)/100;
		}
	}
	return valorImportacion;
}
/*
 * brief calcula el costo final deel producto por transporte aereo
 * param productos Producto*
 * param transporteAereo TransporteAereo*
 * param PosicionArancelaria* posicionesArancelarias
 *  * return retorna-1(ERROR) o != -1 (Exito)
 */
float calculos_calcularCostoFinalAereo(Producto* productos,PosicionArancelaria* posicionesArancelarias,TransporteAereo* transporteAereo)
{
	float costoFinal=-1;
	float baseImponible;
	float valorImportacion;
	float valorTasaEstadistica;

	if(productos != NULL && posicionesArancelarias != NULL && transporteAereo != NULL)
	{
		baseImponible=calculos_calcularBaseImponibleAerea(productos, posicionesArancelarias, transporteAereo);
		valorImportacion=calculos_calcularImportacionAerea(productos, posicionesArancelarias, transporteAereo);
		valorTasaEstadistica=calculos_calcularTasaEstadisticaAerea(productos, posicionesArancelarias, transporteAereo);
		costoFinal=baseImponible+valorImportacion+valorTasaEstadistica;
	}
	return costoFinal;
}
