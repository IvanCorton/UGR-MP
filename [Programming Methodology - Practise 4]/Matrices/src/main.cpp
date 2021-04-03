#include <iostream>
#include <cstdlib>
#include <ctime>
#include "calculo.h"

using namespace std;

void generaMatriz(int M[][COL], int &util_f, int &util_c, int minimo, int maximo){

	    // semilla del generador de números
	    time_t t;
	    srand ((int) time(&t));

	    // relleno la matriz con valores aleatorios
	    const int num_valores = maximo-minimo+1;
	    for(auto i = 0; i < FIL; i++)
		for(auto j = 0; j < COL; j++)
		    M[i][j] = (rand() % num_valores) + minimo;


	    util_f = FIL;
	    util_c = COL;


}


void muestraMatriz(int M[][COL], int util_f, int util_c){

	if(util_f>0 && util_c>0){
		
		// muestro la matriz
		for(auto i = 0; i < util_f; i++){
		   switch(i){
			case 0: cout<<"-> Enero: \n"; break;
			case 1: cout<<"-> Febrero: \n"; break;
			case 2: cout<<"-> Marzo: \n"; break;
			case 3: cout<<"-> Abril: \n"; break;
			case 4: cout<<"-> Mayo: \n"; break;
			case 5: cout<<"-> Junio: \n"; break;
			case 6: cout<<"-> Julio: \n"; break;
			case 7: cout<<"-> Agosto: \n"; break;
			case 8: cout<<"-> Septiembre: \n"; break;
			case 9: cout<<"-> Octubre: \n"; break;
			case 10: cout<<"-> Noviembre: \n"; break;
			case 11: cout<<"-> Diciembre: \n"; break;
		   }
		   for(auto j = 0; j < util_c; j++){
		       cout << "Dia "<< j+1 << ": "<<M[i][j] << "  ";
			if(j==util_c-1 || j==util_c/2) cout<<"\n";
		   }
		}
		cout<<"\n";

	}else{
		cout<<"Matriz vacia..."<<endl;
		exit(1);
	}

}


int main()
{
    int M[FIL][COL];
    int util_f, util_c, mes=0;
    int minimo=0, maximo=0;
    auto media = 0.0;

    cout<<"Generaremos una matriz de dimensiones "<<FIL<<" x "<<COL<<"\n";

    while(minimo < 0 || maximo < 0 || minimo>=maximo){

   	cout<<"Por favor, introduzca el minimo numero entero a generar aleatoriamente (>=0): ";
	cin>>minimo;

	cout<<"Por favor, introduzca el maximo numero entero a generar aleatoriamente (>=0): ";
	cin>>maximo;

	if(minimo>=maximo)
	cout<<"El minimo numero a generar aleatoriamente es mayor o igual que el maximo numero a generar..."<<"\n";
	
	if(minimo < 0 || maximo < 0)
	cout<<"No tiene sentido asignar un numero minimo o maximo de ventas negativo..."<<"\n";

    }

    generaMatriz(M, util_f, util_c, minimo, maximo);

    muestraMatriz(M, util_f, util_c);

    cout<<"\nSeleccione un mes para calcular el promedio (entre 1 y 12): ";

    cin>>mes;

    while(mes < 1 && mes > 12){
    	cout<<"\nPor favor, introduzca un mes en rango\n";
	cin>>mes;
   }

    media = mediaMensualAjustada(M, mes, maximo, minimo);

    
    
    

    
	
}
