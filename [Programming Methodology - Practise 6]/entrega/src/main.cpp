#include <iostream>
#include <climits>
#include <string>
#include <cmath>
#include "lienzo.h"

using namespace std;

int main() {

    // declara las matrices que hagan falta
    // recuerda reservar y liberar la memoria
    char ** m;

    // matriz m
    int nf = 10;
    int nc = 10;

    reservaMemoria(m, nf, nc);

    rellenar(m, nf, nc, '-');
    cout << "\n DIBUJAR CUADRADOS \n";
    dibujarCuadrado(m, nf, nc, -1, -1, 4);
    dibujarCuadrado(m, nf, nc, 4, 4, 3);
    dibujarCuadrado(m, nf, nc, 7, 7, 10);
    imprime(m, nf, nc);
    cout << endl;

    cout << "\n EXTRAE MATRIZ sm1 de 5X5" << endl;
    // matriz sm1;
    int nf1 = 5, nc1 = 5;
    char ** sm1 = extrae(m, 3, 3, nf1, nc1);
    imprime(sm1, nf1, nc1);
    cout << endl;

    cout << "\n EXTRAE MATRIZ sm2 de 2X2" << endl;
    //matriz sm2;
    int nf2 = 2, nc2 = 2;
    char ** sm2 = extrae(m, 1, 1, nf2, nc2);
    imprime(sm2, nf2, nc2);
    cout << endl;

    cout << "\n COMBINA 2 MATRICES sm1, sm2 EN sm3" << endl;
    //matriz sm3;
    int nf3, nc3;
    char ** sm3 = combinar(sm1, nf1, nc1, sm2, nf2, nc2, nf3, nc3);
    imprime(sm3, nf3, nc3);
    cout << endl;

    cout << "\n COMBINA 2 MATRICES sm2, sm1 EN sm4" << endl;
    //matriz sm4;
    int nf4, nc4;
    char ** sm4 = combinar(sm2, nf2, nc2, sm1, nf1, nc1, nf4, nc4);
    imprime(sm4, nf4, nc4);
    cout << endl;

	//Liberar memoria de matrices utilizadas
	liberaMemoria(m, nf, nc);
	liberaMemoria(sm1, nf1, nc1);
	liberaMemoria(sm2, nf2, nc2);
	liberaMemoria(sm3, nf3, nc3);
	liberaMemoria(sm4, nf4, nc4);

}
