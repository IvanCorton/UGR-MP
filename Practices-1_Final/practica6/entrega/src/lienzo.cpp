#include "lienzo.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


void reservaMemoria(char** & m, int nf, int nc){

	m = new char*[nf];
	for(auto i=0; i<nf; i++)
		m[i] = new char[nc];

}


void liberaMemoria(char** & m, int nf, int nc){

	for(auto i=0;i<nf;i++)
		delete m[i];

	delete[] m;
}



void rellenar(char **m, int nf, int nc, char simbolo){

	for(auto i=0;i<nf;i++){
		for(auto j=0; j<nc; j++){
			m[i][j] = simbolo;
		}
	}

}


void imprime(char **m, int nf, int nc){

	for(auto i=0;i<nf;i++){
		for(auto j=0; j<nc; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}

}


void dibujarCuadrado(char **m, int nf, int nc, int x, int y, int lado){

	auto contador = 0, contadorj = 0;

	if(x < nf && y < nc){

		if(x<0 && y<0){
			x=0; y=0;
		}else if(x<0 && y>=0){
			x=0;
		}else  if(x>=0 && y<0){
			y=0;
		}
		


		for(auto i=x;contador<lado && i<nf;i++){
			contadorj=0;			
			for(auto j=y;j<nc && contadorj < lado;j++){
				m[i][j] = '*';
				contadorj++;
			}
			contador++;
		}
	}

}


char **extrae(char **m, int ori_x, int ori_y, int nf, int nc){

	char **submatriz;

	int contadorx = 0, contadory = 0;
	int hastaX = ori_x +nf, hastaY = ori_y + nc;

	reservaMemoria(submatriz, nf, nc);

	for(auto i=ori_x; i<hastaX; i++){
		contadory = 0;
		for(auto j=ori_y; j<hastaY; j++){
			submatriz[contadorx][contadory] = m[i][j];
			contadory++;
		}
		contadorx++;
	}

	return submatriz;
}



char** combinar(char **A, int nf_A, int nc_A, char **B, int nf_B, int nc_B, int & nf_C, int & nc_C){

	char ** matrizC;

	int nfC = 0, ncC = nc_A + nc_B;

	if(nf_A >= nf_B){
		nfC =nf_A;
	}else{
		nfC = nf_B;
	}

	nf_C = nfC;
	nc_C = ncC;

	reservaMemoria(matrizC, nfC, ncC);

	rellenar(matrizC, nfC, ncC, '-');

	for(auto i=0;i<nf_A;i++){
		for(auto j=0; j<nc_A; j++){
			matrizC[i][j] = A[i][j];
		}
	}	

	int hastaI = nf_B, hastaJ = nc_B;
	int contI;

	for(auto i=0; i<hastaI; i++){	
		contI = nf_A;
		for(auto j=0; j<hastaJ; j++){
			matrizC[i][contI] = B[i][j];
			contI++;
		}
	}

	return matrizC;

}



