
/* 
 * File:   palabras.cpp
 * Author: David Pelta
 * 
 * Created on 6 de marzo de 2020,
 */

#include "palabras.h"
#include <iostream>

using namespace std;

int tamanio(const char s[]) {
    
	int numPalabras = cuentaPalabras(s);
	int contador=0;

	if(numPalabras==1){
		while(s[contador]!=SEP && s[contador]!=TERMINADOR){
			contador++;
		}

	}else{
		while(s[contador]!='@'){
			contador++;
		}

	}
	

	return contador;

}

// funcion "privada". j siempre esta en el rango correcto
bool empiezaPalabra(const char s[], int j) {
       
    bool es_letra_actual;
    bool hay_sep_previo = true;
    
    es_letra_actual = s[j] != SEP;
    if ( j > 0)
       hay_sep_previo = (s[j - 1] == SEP);
    
    
    return (es_letra_actual && hay_sep_previo);
}

// funcion "privada". j siempre esta en el rango correcto
// recibe el tamanio tam para evitar calcularlo internamente
bool terminaPalabra(const char s[], int j, int tam) {

    bool hay_sep_sig = true;
    bool es_letra_actual = (s[j] != SEP);
    
    if (j < (tam - 1))
        hay_sep_sig =  (s[j + 1] == SEP || s[j + 1] == TERMINADOR);

    return (es_letra_actual && hay_sep_sig);
}


int posPalabra(const char msg[], int nroPal) {
 
	int aux=0;

	for(int limitador=0, auxiliar=0; limitador!=nroPal; auxiliar++){
		if(empiezaPalabra(msg,auxiliar)){
			limitador++;
		}
		aux=auxiliar;
	}

	return aux;

}

int longPalabra(const char s[], int nroPal) {
    
	
	int posicion = posPalabra(s, nroPal);

	int contador=0;

	while(!terminaPalabra(s, posicion, tamanio(s))){
		contador++;
		posicion++;
	}
	contador++;	

	return contador;

}


int cuentaPalabras(const char msg[]) {


	int contador=0, numPalabras=0;

	while(msg[contador]!=TERMINADOR){

		if(msg[contador]==SEP){
	
			while(msg[contador]==SEP){
				contador++;
			}

		}else if(msg[contador]!=SEP){

			while(msg[contador]!=SEP && msg[contador]!=TERMINADOR){

				if(msg[contador+1]==SEP || msg[contador+1]==TERMINADOR){
					numPalabras++;
				}

			contador++;

			}

		}else{
			return numPalabras;
		}

	}

	return numPalabras;

}

void extraePalabra(const char msg[], int nroPal, char salida[]) {

	int tam=tamanio(msg);
	int nPalabras = cuentaPalabras(msg);

	if(nroPal > nPalabras){
		salida[0]='@';
	}else{

		for(int i=0;i<20;i++){
			salida[i]=' ';
		}


		int posicion = posPalabra(msg, nroPal);
		int longitud = longPalabra(msg, nroPal);

		for(int i=0;i<longitud;i++,posicion++){
			salida[i]=msg[posicion];
		}

		salida[longitud]='@';

	}
}

void delReves(const char msg[], char msg_reves[]) {


	int numPalabras = cuentaPalabras(msg), palabrasRestantes = numPalabras, centinela=0;
	char msgAux[MAX_SIZE];

	while(palabrasRestantes>0){
		
		extraePalabra(msg,palabrasRestantes,msgAux);
		palabrasRestantes--;

		int tam = tamanio(msgAux);

		for(int i=0;i<tam;i++){
			msg_reves[centinela]=msgAux[i];
			centinela++;
		}
		if(palabrasRestantes==0){
			msg_reves[centinela]=' ';
		}else{
			msg_reves[centinela]='-';
		}
		centinela++;
	}


}

void agregaPalabra(char msg[], const char pal[]) {

}
