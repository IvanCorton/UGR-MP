/* 
 * File:   calculo.h
 * Author: Ivan Corton da Silva
 *
 * Created on 30 de marzo de 2020
 */

#ifndef CALCULO_H
#define CALCULO_H

const int COL = 30, FIL = 12;


/*
 * @brief Calcula el valor promedio de ventas en un mes
 * @param M Matriz de valores de ventas por dia
 * @param mes Mes del que queremos obtener el promedio.
 * @return Valor promedio de ventas en un mes
 */
double mediaMensualAjustada (int M[][COL], int mes, int maximo, int minimo);






#endif

