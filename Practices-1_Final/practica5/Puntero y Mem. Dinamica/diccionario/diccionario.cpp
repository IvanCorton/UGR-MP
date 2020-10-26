#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include "diccionario.h"


/* Auto-evaluacion de funciones
CrearDiccionario: 3. Sin problema al no usar memoria dinamica
mostrarPalabras: 3. El unico problema fue el de atender a deshacer los movimientos de los punteros
mostrarDiccionario: 3. No hubo problema más alla de los problemas de "mostrarPalabras".
cuentaPalabras: 3. Mismos problemas que con "mostrarPalabras"
existe: 3. Una vez comprendida la dinamica de los punteros, sin problemas, aunque estoy seguro de que podria refinarse para conseguir un orden de complejidad polinomico. (actualmente cubico D: ).
agregaPalabra: 3. Tuve que darle bastantes vueltas para ver como reordenar tanto datos como indices, aunque finalmente lo consegui.
borraPalabra: 3. Una vez diseñado agregaPalabras, fue relativamente sencillo.

Mi nota sería: bien
*/



int numAbc = 27;	//Espacio reservado para los indices

/*void ordenarDiccionario(string * nombres, int total)
{
   string temp;
   int i, j;

   for(i=0; i < total-1; i++)
   {
      for(j=i+1; j < total; j++)
      if(nombres[i].compare(nombres[j]) > 0)
      {
         // Copia en variable temporal datos actuales
         temp = nombres[i];

         // Intercambia informacion	  
  	nombres[i] = nombres[j]; 

   	nombres[j] = temp;  
      }
   }
}*/


void crearDiccionario(string * & datos, string ** & indice, ifstream& File, int numAbc, int numPalabras, int &datosUtiles){

	indice = new string*[numAbc];
	datos = new string[numAbc*6];

	char abc='A'; datosUtiles++;
	int palabrasTotal=numPalabras+numAbc;

	for(auto i=0; i<numAbc; i++){
		datos[i] = abc;
		indice[i] = &datos[i];
		abc++;
		datosUtiles++;
	}

	indice[numAbc]=&datos[numAbc];


}



void mostrarPalabras(string **indice, string inicial){
	
	auto posicionIndice = 0, retroceso = 0;
	
	for(auto i=0; i<numAbc-1; i++){
		if(inicial[0] == (*indice[i])[0])
			posicionIndice = i;
	}


	while((*indice[posicionIndice])[0] == inicial[0]){
		cout<<*indice[posicionIndice]<<endl;
		*indice[posicionIndice]++;
		retroceso++;
	}

	for(auto i=0;i<retroceso;i++){
		*indice[posicionIndice]--;
	}
}



void mostrarDiccionario(string **indice){

	string palabra="A";

	for(auto i=0;i<numAbc;i++){

		mostrarPalabras(indice, palabra);
		palabra[0]++;
	}

	cout<<*indice[numAbc-1]<<endl;


}



int cuentaPalabras(string **indice, string inicial){

	auto posicionIndice = 0, acumulador = 0;
	
	for(auto i=0; i<numAbc-1; i++){
		if(inicial[0] == (*indice[i])[0])
			posicionIndice = i;
	}


	while((*indice[posicionIndice])[0] == inicial[0]){
		*indice[posicionIndice]++;
		acumulador++;
	}

	for(auto i=0;i<acumulador;i++){
		*indice[posicionIndice]--;
	}

	return acumulador;

}


bool existe(string ** indice, string palabra){

	int enIndices = 0, avances = 0;

	for(auto i=0;i<numAbc-1;i++){
		if((*indice[i])[0]==palabra[0]){
			enIndices = i;
			while((*indice[i])[0]==palabra[0]){
				if(*indice[enIndices]==palabra){
					for(auto i=0;i<avances; i++){
						*indice[enIndices]--;
					}					
					return true;
				}else{				
					*indice[enIndices]++;
					avances++;
				}
			}
		}
	}

	for(auto i=0;i<avances; i++){
		*indice[enIndices]--;
	}

	return false;

}



void agregaPalabra(string ** & indice, string * & datos, int &datosUtiles, string pal){

	int posicionIndices = 0, posicionDatos = 0;
	string abc = "A";

	
	if(!existe(indice, pal)){

		if(pal[0]!='Z'){

			for(auto i=0; i<numAbc-1; i++){
				if(pal[0] == (*indice[i])[0]){
					posicionIndices = i+1;
				}
			}

			//Desplazamiento de palabras a la derecha y actualizacion de punteros a letras iniciales.
			for(auto i=0;i<datosUtiles-1; i++){
				if(datos[i]==*indice[posicionIndices]){
					posicionDatos = i;
				}
			}

			for(auto i=datosUtiles; i>=posicionDatos; i--){
				datos[i] = datos[i-1];
			}

			for(auto i=0; i<numAbc-1; i++){
				for(auto j=0; j<datosUtiles;j++){
					if(datos[j] == abc){
						indice[i] = &datos[j]; abc[0]++; break;
					}		
				}
			}
			
			indice[numAbc-1] = &datos[datosUtiles];

			datos[posicionDatos] = pal;
			datosUtiles++;

		}else{
			posicionIndices = numAbc-2;
			posicionDatos = datosUtiles-2;
			
			datos[posicionDatos+1] = pal;

			indice[numAbc-1] = &datos[posicionDatos+2];
		
			datosUtiles++;


		}

	}else{
		cout<<"Palabra ya incluida en el diccionario..."<<endl;
	}


}


void borraPalabra(string ** & indice, string * & datos, int &datosUtiles, string pal){

	int posicionIndices = 0, posicionDatos = 0;
	string abc = "A";

	
	if(existe(indice, pal)){

		for(auto i=0;i<datosUtiles-1; i++){
			if(datos[i]==pal){
				posicionDatos = i;
			}
		}

		for(auto i=posicionDatos; i<=datosUtiles; i++){
				datos[i] = datos[i+1];
		}

		for(auto i=0; i<numAbc-1; i++){
				for(auto j=0; j<datosUtiles;j++){
					if(datos[j] == abc){
						indice[i] = &datos[j]; abc[0]++; break;
				}		
			}
		}	

		indice[numAbc-1] = &datos[datosUtiles];	

		datosUtiles--;

	}else{
		cout<<"Palabra no existente en el diccionario..."<<endl;
	}


}


