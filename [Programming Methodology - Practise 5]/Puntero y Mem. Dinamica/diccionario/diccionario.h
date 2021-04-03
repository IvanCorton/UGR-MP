/* CLASE DICCIONARIO */

#ifndef __DICCIONARIO_H
#define __DICCIONARIO_H

using namespace std;

//void ordenarDiccionario(string * nombres, int total);

void crearDiccionario(string * & datos, string ** & indice, ifstream& File, int numAbc, int numPalabras, int &datosUtiles);

void mostrarPalabras(string **indice, string inicial);

void mostrarDiccionario(string **indice);

int cuentaPalabras(string **indice, string inicial);

bool existe(string ** indice, string palabra);

void agregaPalabra(string ** & indice, string * & datos, int &datosUtiles, string pal);

void borraPalabra(string ** & indice, string * & datos, int &datosUtiles, string pal);

#endif
