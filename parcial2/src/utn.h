/*
 * utn.h
 *
 *  Created on: Oct 6, 2020
 *      Author: toty
 */

#ifndef UTN_H_
#define UTN_H_


int utn_getFloat(float* pNumero,char* pTexto,char* pError,int min,int max,int reintentos);
int utn_getFloatConMinMax(char*, char*, float*, float, float, int);
int utn_getInt(char*, char*, int*, int);
int utn_getIntConMinMax(char*, char*, int*, int, int, int);
int utn_isIntNumber(char*);
int utn_isFloatNumber(char *);
int utn_isAlphabetic(char*);
int utn_isNumeric(char*);
int utn_isAlphanumeric(char*);
int utn_getString(char*, char*, char*, int, int);
int utn_getStringWithNumbers(char*, char*, char*, int, int);
int utn_getStringWithOnlyNumbers(char*, char*, char*, int, int);
int utn_getStringWithNumbersAndSymbols(char*, char*, char*, int, int);
int myGets(char*, int);
int get_float(float* pResultado,int len,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos,int flagSigned);


#endif /* UTN_H_ */
