#include <string>
#include <iostream>
#include <fstream>
#include "diccionario.h"

using namespace std;

const int numAbc = ('Z'-'A')+1;	//Espacio a tener en cuenta en indices

int main(int argc,char *argv[]){

	if(argc!=2){
    		printf("Necesito un fichero de entrada para el diccionario... e.g: ./ejecutable diccionario.txt\n");
    		exit(1); 
	}

	string file_name = argv[1];

	ifstream File;
	File.open("../datos/"+file_name);	

	if(File.fail()){
		cout<<"Error al abrir el archivo, por favor, compruebe el nombre del fichero de entrada..."<<endl;
		exit(1);
	}else{

		auto numPalabras=0, datosUtiles=0;

		string palabra;

		File >> numPalabras;	

		string * datos;	//Contiene todas las palabras con el abecedario.
		string ** indice; //Contiene todos los indices que apuntan a cada letra del abecedario.

		//Rellenar diccionario de datos e indices con el fichero de entrada.
		crearDiccionario(datos, indice, File, numAbc, numPalabras, datosUtiles);

		cout<<"Mostrando diccionario vacio: "<<endl;
		mostrarDiccionario(indice);

		File >> palabra;

		while(!File.eof()){
			agregaPalabra(indice, datos, datosUtiles, palabra);
			File >> palabra;		
		}

		cout<<"Insercion completada..."<<endl;
		cout<<"Mostrando diccionario tras insercion: "<<endl;
		mostrarDiccionario(indice);

		cout<<"Palabras en el diccionario empezadas por B: "<<endl;

		mostrarPalabras(indice, "B");

		cout<<"Numero de palabras empezadas por B: "<<cuentaPalabras(indice, "B")<<endl;

		cout<<endl;

		cout<<"¿Existe la palabra BAMBA en el diccionario? "<<existe(indice, "BAMBA")<<"\n¿Y la palabra ZAPATO? "<<existe(indice, "ZAPATO")<<endl;
		
		cout<<endl;		

		cout<<"Palabras en el diccionario empezadas por E: "<<endl;

		mostrarPalabras(indice, "E");

		cout<<"Borrando la palabra ELEFANTE del diccionario..."<<endl;		

		borraPalabra(indice, datos, datosUtiles, "ELEFANTE");

		cout<<"Palabras en el diccionario empezadas por E: "<<endl;

		mostrarPalabras(indice, "E");
		
		cout<<endl;

		cout<<"Mostrando diccionario tras borrado: "<<endl;
	
		mostrarDiccionario(indice);

		cout<<"Borrando la palabra PRIMATE del diccionario..."<<endl;
	
		borraPalabra(indice, datos, datosUtiles, "PRIMATE");
		
		
	}

}
