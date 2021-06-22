/*
 ============================================================================
 Name        : parcial2.c
 Author      : Stefano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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

int main(void){
	setbuf(stdout,NULL);
	int opcionMenu;
	Dictionary* productos=dict_new(0);
	Dictionary* posicionesArancelarias=dict_new(0);
	TransporteAereo transporteAereo;
	TransporteMaritimo transporteMaritimo;

	if(controller_validarCargaDeDatos(productos,posicionesArancelarias,&transporteAereo,&transporteMaritimo)==0)
	{
		do{
			if(utn_getIntConMinMax("\tMENU\n1)Cargar producto\n2)Modificar producto\n3)Eliminar producto\n4)Listar productos\n5)Listar un producto\n6)Cargar datos de posiciones aranceralias\n7)Modificar posiciones arancelarias\n8)Borrar posiciones arancelarias\n9)Listar posiciones arancelarias\n10)Listar una posicion arancelaria\n11)Modificar datos del transporte\n12)Imprimir datos actuales del transporte aereo\n13)Imprimir datos actuales del transporte maritimo \n14)Listar productos con precio final\n15)Listar productos ordenados\n16)Listar posiciones arancelarias ordenadas\n17)Salir\n","Opcion invalida.\n", &opcionMenu,1,17,2)==0)
			{
				switch(opcionMenu)
				{
				case 1:
					controller_agregarProducto(productos,posicionesArancelarias);
					break;
				case 2:
					controller_modificarProducto(productos,posicionesArancelarias);
					break;
				case 3:
					controller_eliminarProducto(productos);
					break;
				case 4:
					controller_listarProductos(productos);
					break;
				case 5:
					controller_listarUnProducto(productos, posicionesArancelarias, &transporteAereo, &transporteMaritimo);
					break;
				case 6:
					controller_agregarPosArancelaria(posicionesArancelarias);
					break;
				case 7:
					controller_modificarPosArancelaria(posicionesArancelarias);
					break;
				case 8:
					controller_eliminarPosArancelaria(posicionesArancelarias);
					break;
				case 9:
					controller_listarPosArancelaria(posicionesArancelarias);
					break;
				case 10:
					controller_listarUnaPosicionArancelaria(posicionesArancelarias);
					break;
				case 11:
					controller_modificarDatosTransporte(&transporteAereo, &transporteMaritimo);
					break;
				case 12:
					controller_imprimirValorDelTransporteAereo(&transporteAereo);
					break;
				case 13:
					controller_imprimirValorDelTransporteMaritimo(&transporteMaritimo);
					break;
				case 14:
					controller_listarProductosConPrecios(productos, posicionesArancelarias, &transporteAereo, &transporteMaritimo);
					break;
				case 15:
					controller_menuListarProductosEnOrden(productos);
					break;
				case 16:
					controller_menuListarPosicionesArancelariasEnOrden(posicionesArancelarias);
					break;
				}
			}
		}while(opcionMenu != 17);
	}
	return EXIT_SUCCESS;
}


