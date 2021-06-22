/*
 * Controller.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Stefano
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Dictionary.h"
#include "posicionArancelaria.h"
#include "Producto.h"
#include "Controller.h"
#include "TransporteAereo.h"
#include "TransporteMaritimo.h"
#include <string.h>


/*brief valida que los datos leidos en todos los .csv sean validos
 * param Dictionary* productos
 * param Dictionary* posicionesArancelarias
 * param TransporteAereo* transporteAereo puntero a var
 * param TransporteMaritimo* transporteMaritimo	puntero a var
 * return int (0) OK // -1 ERROR
 * */
int controller_validarCargaDeDatos(Dictionary* productos,Dictionary* posicionesArancelarias,TransporteAereo* transporteAereo,TransporteMaritimo* transporteMaritimo)
{
	int ret=-1;
	if(producto_parser("productos.csv",productos) != -1 &&
		pos_parser("posicionesArancelarias.csv", posicionesArancelarias) != -1 &&
		maritimo_parser("transporteMaritimo.csv",transporteMaritimo) != -1 &&
		aereo_parser("transporteAereo.csv",transporteAereo) != -1 )
	{
		ret=0;
	}
	return ret;
}

/** \brief Agrega a un producto y lo guarda en el archivo .csv
 *
 * \param productos Dictionary*
 * \param posicionesArancelarias Dictionary*
 * \return int (0) OK // -1 ERROR
 */
int controller_agregarProducto(Dictionary* productos,Dictionary* posicionesArancelarias)
{
	int ret=-1;
	if(productos != NULL)
	{
		if(posicionesArancelarias->size > 0)
		{
			if(producto_alta(productos,posicionesArancelarias)==0)
			{
				printf("Producto cargado.\n");
				if(producto_dump("productos.csv", productos) > 0)
				{
					ret=0;
				}
			}
		}
	}
	return ret;
}

/** \brief Lista,Modifica y escribe en el .csv los nuevos datos del producto
 * \param productos Dictionary*
 * \return int (0) OK // -1 ERROR
 */
int controller_modificarProducto(Dictionary* productos,Dictionary* posicionesArancelarias)
{
	int ret=-1;
	if(productos != NULL && productos->size > 0)
	{
		producto_imprimirLista(productos);
		if(producto_modificar(productos,posicionesArancelarias)==0)
		{
			printf("Producto modificado.\n");
			if(producto_dump("productos.csv", productos) > 0)
			{
				ret=0;
			}
		}
		else
		{
			printf("Error en la modificacion de datos.\n");
		}

	}
	return ret;
}

/** \brief imprime, da a elegir x producto,Lo elimina, y guarda los datos en el .csv
 * \param productos Dictionary*
 * \return int (0) OK // -1 ERROR
 */
int controller_eliminarProducto(Dictionary* productos)
{
	int ret=-1;
	if(productos != NULL && productos->size > 0)
	{
		producto_imprimirLista(productos);
		if(producto_borrar(productos)==0)
		{
			if(producto_dump("productos.csv", productos) > 0)
			{
				ret=0;
			}
		}
	}
	return ret;
}

/** \brief Lista todos los productos existentes
 * \param productos Dictionary*
 * \return int (0) OK // -1 ERROR
 */
int controller_listarProductos(Dictionary* productos)
{
	int ret=-1;
	if(productos != NULL && productos->size > 0)
	{
		if(producto_imprimirLista(productos)==0)
		{
			ret=0;
		}
	}
	return ret;
}

/*brief lista un producto elegido por el usuario
* param Dictionary* productos
 * param Dictionary* posicionesArancelarias
 * param TransporteAereo* transporteAereo puntero a var
 * param TransporteMaritimo* transporteMaritimo	puntero a var
 * return int (0) OK // -1 ERROR
 */
int controller_listarUnProducto(Dictionary* productos,Dictionary* posicionesArancelarias,TransporteAereo* transporteAereo,TransporteMaritimo* transporteMaritimo)
{
	int ret=-1;
	Producto* pE;
	char codigo[256];
	if(productos != NULL)
	{
		if(utn_getStringWithNumbersAndSymbols("Ingrese el codigo del producto:\n", "Codigo invalido\n", codigo, sizeof(codigo), 2)==0)
		{
			pE=(Producto*)dict_get(productos,codigo);
			if(pE != NULL)
			{
				if(producto_listarUnProducto(pE,posicionesArancelarias,transporteMaritimo,transporteAereo)==0)
				{
					ret=0;
				}
			}
			else
			{
				printf("No se encontro el producto.\n");
			}
		}
	}
	return ret;
}

/** \brief agrega una posicion arancelaria y la guarda en el archivo
 * \param posicionArancelaria Dictionary*
 * \return int (0) OK // -1 ERROR
 */
int controller_agregarPosArancelaria(Dictionary* posicionArancelaria)
{
	int ret=-1;
	if(posicionArancelaria != NULL)
	{
		if(pos_alta(posicionArancelaria)==0)
		{
			if(pos_dump("posicionesArancelarias.csv", posicionArancelaria) > 0)
			{
				ret=0;
			}
		}
	}
	return ret;
}

/** \brief Lista,Modifica y escribe en el .csv los nuevos datos de la posicion arancelaria
 * \param posicionArancelaria Dictionary*
 * \return int (0) OK // -1 ERROR
 */
int controller_modificarPosArancelaria(Dictionary* posicionArancelaria)
{
	int ret=-1;

	if(posicionArancelaria != NULL && posicionArancelaria->size > 0)
	{
		pos_imprimirLista(posicionArancelaria);
		if(pos_modificar(posicionArancelaria)==0)
		{
			if(pos_dump("posicionesArancelarias.csv",posicionArancelaria) != -1)
			{
				ret=0;
			}
		}
	}
	return ret;
}

/** \brief imprime, pide elegir x pos. aranc.,Elimina una posicion arancelaria y guarda los cambios en el .csv
 * \param posicionArancelaria Dictionary*
 * \return int (0) OK // -1 ERROR
 */
int controller_eliminarPosArancelaria(Dictionary* posicionArancelaria)
{
	int ret=-1;
	if(posicionArancelaria != NULL && posicionArancelaria)
	{
		pos_imprimirLista(posicionArancelaria);
		if(pos_borrar(posicionArancelaria)==0)
		{
			if(pos_dump("posicionesArancelarias.csv",posicionArancelaria) != -1)
			{
				ret=0;
			}
		}
	}
	return ret;
}

/** \brief Lista todos las posiciones arancelarias existentes
 * \param productos Dictionary*
 * \return int (0) OK // -1 ERROR
 */
int controller_listarPosArancelaria(Dictionary* posicionArancelaria)
{
	int ret=-1;
	if(posicionArancelaria != NULL && posicionArancelaria->size > 0 )
	{
		if(pos_imprimirLista(posicionArancelaria)==0)
		{
			ret=0;
		}
	}
	return ret;
}
/*brief lista una posicion arancelaria elegida por el usuario
 * param Dictionary* posicionesArancelarias
 * return int (0) OK // -1 ERROR
 */
int controller_listarUnaPosicionArancelaria(Dictionary* posicionesArancelarias)
{
	int ret=-1;
	PosicionArancelaria* pE;
	int id;
	char idAux[256];
	if(posicionesArancelarias != NULL)
	{
		if(utn_getInt("Ingrese el id de la posicion arancelaria:\n", "Codigo invalido\n",&id,2)==0)
		{
			snprintf(idAux,sizeof(idAux),"%d",id);
			pE=(PosicionArancelaria*)dict_get(posicionesArancelarias,idAux);
			if(pE != NULL)
			{
				if(pos_imprimirUnaPosicionArancelaria(pE)==0)
				{
					ret=0;
				}
			}
			else
			{
				printf("No se encontro la posicion arancelaria.\n");
			}
		}
	}
	return ret;
}


/** \brief Modifica datos actuales del transporte a elegir
 * \param transporteAereo TransporteAereo* puntero a var
 * \param transporteMaritimo TransporteMaritimo* puntero a var
 * \return int (0) OK // -1 ERROR
 */
int controller_modificarDatosTransporte(TransporteAereo* transporteAereo,TransporteMaritimo* transporteMaritimo)
{
	int ret=-1;
	int opcion;
	if(transporteAereo != NULL && transporteMaritimo != NULL)
	{
		if(utn_getIntConMinMax("Elija transporte a modificar:\n1)Aereo\n2)Maritimo\n", "Opcion invalida.\n", &opcion, 1, 2, 2)==0)
		{
			if(opcion == 1)
			{
				aereo_editarDatosDelTransporteAereo(transporteAereo);
				aereo_dump("transporteAereo.csv", transporteAereo);
				ret=0;
			}
			else if(opcion == 2)
			{
				maritimo_editarDatosDelTransporteMaritimo(transporteMaritimo);
				maritimo_dump("transporteMaritimo.csv",transporteMaritimo);
				ret=0;
			}
		}
	}
	return ret;
}


/** \brief Imprime datos actuales del transporte Aereo
 * \param transporteAereo TransporteAereo* puntero a var
 * \return int (0) OK // -1 ERROR
 */
int controller_imprimirValorDelTransporteAereo(TransporteAereo* transporteAereo)
{
	int ret=-1;

	if(transporteAereo != NULL)
	{
		if(aereo_imprimirLista(transporteAereo)==0)
		{
			ret=0;
		}
	}
	return ret;
}

/** \brief Imprime datos actuales del transporte Maritimo
 * \param transporteMaritimo TransporteMaritimo* puntero a var
 * \return int (0) OK // -1 ERROR
 */
int controller_imprimirValorDelTransporteMaritimo(TransporteMaritimo* transporteMaritimo)
{
	int ret=-1;

	if(transporteMaritimo != NULL)
	{
		if(maritimo_imprimirLista(transporteMaritimo)==0)
		{
			ret=0;
		}
	}

	return ret;
}

/*brief lista los productos con su precios finales
 * param Dictionary* productos
 * param Dictionary* posicionesArancelarias
 * param TransporteAereo* transporteAereo puntero a var
 * param TransporteMaritimo* transporteMaritimo	puntero a var
 * return int (0) OK // -1 ERROR
 * */
int controller_listarProductosConPrecios(Dictionary* productos,Dictionary* posicionesArancelarias,TransporteAereo* transporteAereo,TransporteMaritimo* transporteMaritimo)
{
	int ret=-1;
	if(productos != NULL)
	{
		if(producto_imprimirListaConPrecios(productos, posicionesArancelarias, transporteAereo, transporteMaritimo)==0)
		{
			ret=0;
		}
	}
	return ret;
}


/*brief submenu de listar los productos con un orden a elegir
 * param Dictionary* productos
 * return int (0) OK // -1 ERROR
 * */
int controller_menuListarProductosEnOrden(Dictionary* productos)
{
	int ret=-1;
	int opcion;

	if(productos != NULL)
	{
		do{
			if(utn_getIntConMinMax("Ingrese una opcion:\n1)Lista de productos ordenada por codigo\n2)Lista de productos ordenada por descripcion\n3)Lista de productos ordenada por pais de fabricacion\n4)Lista de productos ordenada por valor FOB\n5)Lista de productos ordenada por alto\n6)Lista de productos ordenada por ancho\n7)Lista de productos ordenada por profundidad\n8)Lista de productos ordenada por peso\n9)Salir\n", "Opcion invalida.\n", &opcion, 1, 9, 2)==0)
			{
				ret=0;
				switch(opcion)
				{
					case 1:
						producto_ordenarPorCodigo(productos);
						break;
					case 2:
						producto_ordenarPorDescripcion(productos);
						break;
					case 3:
						producto_ordenarPorPais(productos);
						break;
					case 4:
						producto_ordenarPorValorFob(productos);
						break;
					case 5:
						producto_ordenarPorAlto(productos);
						break;
					case 6:
						producto_ordenarPorAncho(productos);
						break;
					case 7:
						producto_ordenarPorProfundidad(productos);
						break;
					case 8:
						producto_ordenarPorPeso(productos);
						break;
				}
			}
		}while(opcion != 9);
	}
	return ret;
}

/*brief submenu de listar las posicionesArancelarias con un orden a elegir
 * param Dictionary* posicionesArancelarias
 * return int (0) OK // -1 ERROR
 * */
int controller_menuListarPosicionesArancelariasEnOrden(Dictionary* posicionesArancelarias)
{
	int ret=-1;
	int opcion;

	if(posicionesArancelarias != NULL)
	{
		do{
			if(utn_getIntConMinMax("Ingrese una opcion:\n1)Lista de posiciones arancelarias ordenadas por nomenclatura arancelaria\n2)Lista de posiciones arancelarias ordenadas por porcentaje de seguro\n3)Lista de posiciones arancelarias ordenadas por porcentaje de tasa estaditisca\n4)Lista de posiciones arancelarias ordenadas por porcentaje de importacion\n5)Salir\n", "Opcion invalida.\n", &opcion, 1, 9, 2)==0)
			{
				ret=0;
				switch(opcion)
				{
					case 1:
						pos_ordenarPorNomenclatura(posicionesArancelarias);
						break;
					case 2:
						pos_ordenarPorPorcSeguro(posicionesArancelarias);
						break;
					case 3:
						pos_ordenarPorPorcTasaEstadistica(posicionesArancelarias);
						break;
					case 4:
						pos_ordenarPorPorcImportacion(posicionesArancelarias);
						break;
				}
			}
		}while(opcion != 5);
	}
	return ret;
}
