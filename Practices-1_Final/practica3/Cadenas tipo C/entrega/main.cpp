
#include <iostream>
#include "palabras.h"

using namespace std;

int main() {
    
    char frase[MAX_SIZE];
    char palabra[MAX_SIZE];
    int total_u = 0;
    char letra;

    cout << "Ingrese la frase. @ para terminar: ";
    letra = cin.get();
    while (letra != '@') {
        frase[total_u] = letra;
        total_u++;
        letra = cin.get();
    }

    frase[total_u] = TERMINADOR;

	//AL FINAL ENCONTRAMOS @
    
    cout << "\nLA FRASE LEIDA ES: " <<  frase << endl;
    int n = tamanio(frase);
    int pals = cuentaPalabras(frase);
    cout << "Tiene " << n << " caracteres y " << pals << " palabras " << endl;

    cout << "\nDESCOMPOSICION EN PALABRAS nro -> palabra (long.)" << endl;
    int nro = 1;
    extraePalabra(frase, nro, palabra);
    while(tamanio(palabra) > 0){
           cout << nro << " -> " << palabra << " (" << tamanio(palabra) << ")\n";
           nro++;
           extraePalabra(frase, nro, palabra);
    }


    char reves[MAX_SIZE];
    cout << "\nFRASE INVERSA " << endl;
    delReves(frase, reves);
    cout << "Frase Original: " << frase;
    cout << "\nFrase al Reves: " << reves << endl;

    return (0);
}






