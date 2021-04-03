#include <iostream>
#include <cstdlib>
#include <ctime>
#include "calculo.h"

using namespace std;

double mediaMensualAjustada (int M[][COL], int mes, int maximo, int minimo){

	auto costeAcumulado = 0.0;
	auto cuentaDias = 0;

	if(mes-1>=0 && mes-1 <FIL){
		cout<<"Mes elegido: ";		
		switch(mes-1){
			case 0: cout<<"-> Enero \n"; break;
			case 1: cout<<"-> Febrero \n"; break;
			case 2: cout<<"-> Marzo \n"; break;
			case 3: cout<<"-> Abril \n"; break;
			case 4: cout<<"-> Mayo \n"; break;
			case 5: cout<<"-> Junio \n"; break;
			case 6: cout<<"-> Julio \n"; break;
			case 7: cout<<"-> Agosto \n"; break;
			case 8: cout<<"-> Septiembre \n"; break;
			case 9: cout<<"-> Octubre \n"; break;
			case 10: cout<<"-> Noviembre \n"; break;
			case 11: cout<<"-> Diciembre \n"; break;
		}

		for(auto j=0;j<COL;j++){

			if(M[mes-1][j]!=minimo || M[mes-1][j]!=maximo){		
				costeAcumulado+=M[mes-1][j];
				cuentaDias++;			
			}


		}

		costeAcumulado/=cuentaDias;
		cout<<"Media de ventas: "<<costeAcumulado<<"\n";

	}else{
		exit(1);
	}

}


