
#include <iostream>
using namespace std;
const int MAX_SIZE = 100;


void leerFrase(char frase[], int totalUsados){

	char decode[MAX_SIZE];
	const char blanco = ' ', salto = '\n';
	int enUso = 1;

	if(totalUsados!=0){

	decode[0]=frase[0];

	for(int i=1; i<totalUsados; i++){
		if(frase[i]==blanco || frase[i]==salto){
			decode[enUso] = frase[i-1];
			enUso++;
			if((frase[i+1]!=salto || frase[i+1]!=blanco) && i!=totalUsados-1){
			decode[enUso] = frase[i+1];
			enUso++;
			}
		}
	}

	for(int i=0; i<enUso; i++){
		cout << decode[i];
	}

	cout<<endl;

	}else{

		cout<<"··· Abortando ejecucion (Frase vacia)···"<<endl;
	}
}


void ordenarPorIndices(int miVector[], int totalUsados){


	int indiceMinimo=0, usadosIndice=1, aux=0;
	int vecOrdenado[totalUsados];
	int vecIndices[totalUsados];

	// 1º Ordenar vector, despues guardarlo ordenado en otro vector 
	// y por ultimo asignar a cada valor el indice que le corresponde

	for (int i = 0;i < totalUsados; i++){	
		vecOrdenado[i]=miVector[i];
	}

	for (int i = 0;i < totalUsados; i++){
		for (int j = 0; j< totalUsados - 1; j++){
			if (vecOrdenado[j] > vecOrdenado[j+1]){ 
			aux = vecOrdenado[j]; 
			vecOrdenado[j] = vecOrdenado[j+1]; 
			vecOrdenado[j+1] = aux;
			}
		}
	}

	for(int i=0;i<totalUsados; i++){
		for(int j=0; j<totalUsados; j++){
			if(miVector[i]==vecOrdenado[j]){
				miVector[i]=j;
			}
		}
	}

	cout<<endl<<"------------------------------------"<<endl;
	
	cout<<"Vector ordenado: ";

	for(int i=0;i<5; i++){
		cout<<vecOrdenado[i]<<" ";
	}

	cout<<endl<<"------------------------------------"<<endl;

	cout<<"Vector por indices: ";

	for(int i=0;i<5; i++){
		cout<<miVector[i]<<" ";
	}
	cout<<endl<<"------------------------------------"<<endl;


}


int main(){
	char frase[MAX_SIZE];
	int total_u = 0;
	char letra;
	

	cout<<"---------------------------------------------------------"<<endl;

	cout<< "Practica 3.- Ejercicio 1: Modulo descrifra "<<endl;
	
	cout<< "··············································"<<endl;

	cout << "Ingrese la frase. @ para terminar: ";
	letra = cin.get();
	while (letra != '@'){
		frase[total_u] = letra;
		total_u++;
		letra = cin.get();
	}
	
	cout<<endl;
	leerFrase(frase, total_u);

	cout<<endl;

	int miVector[MAX_SIZE]={8,3,9,1,5};
		     	     // 3, 1, 4, 0, 2
	total_u = 5;

	cout<<"---------------------------------------------------------"<<endl;

	cout<< "Practica 3.- Ejercicio 2: Ordenando mediante indices "<<endl;
	
	cout<< "··············································"<<endl;

	cout<<"Mi vector: ";

	for(int i=0;i<total_u;i++){
		cout<<miVector[i]<<" ";
	}
	cout<<endl;
	

	ordenarPorIndices(miVector, total_u);
	



	return(0);
}





