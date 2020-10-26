/*********************************************************
 Módulo de pruebas básicas para la parte 2 del proyecto final.
 
 * Metodologías de Programación - Curso 2019 - 2020
 * Prof. David A. Pelta
 * Grupo D
  
 *******************************************************/

#include <cmath>
#include "miniwin.h"
#include <iostream>
#include "Punto2D.h"
#include "PoliReg.h"
#include "Pintar.h"

using namespace miniwin;
using namespace std;

// Usaremos la funcion para ventanas cuadradas. (e.g: 800x800)
bool enPantalla(Punto2D punto, int radio ,int dimensiones){

	bool dentro=false;

	if(punto.Get_X()>=radio && punto.Get_Y()>=radio && punto.Get_X() <= (dimensiones-radio) && punto.Get_Y() <= (dimensiones-radio))
		dentro = true;

	return dentro;

}

bool estaDentro(Punto2D destino, Punto2D * destinos, int numPuntos){
	for(auto i=0; i<numPuntos; i++){
		if(destino.Get_X() == destinos[i].Get_X() && destinos[i].Get_Y() == destino.Get_Y())
			return true;
	}
	return false;
}


int main(){

	auto dimensiones=800, numVertices=8, radio=30;

    	vredimensiona(dimensiones, dimensiones);

	Punto2D centro(400, 400);
    	PoliReg Wally(numVertices, centro, radio);

	int numPuntos = 30, min=3000;

	Punto2D * destinos = new Punto2D [numPuntos];

	Punto2D origen, destino;

	while(numPuntos > 0){

		min = 3000;

		origen = centro;

		for(auto i=0; i<numPuntos; i++){
			if(origen.Distancia(destinos[i]) < min && enPantalla(destinos[i], radio, dimensiones)){
				min=origen.Distancia(destinos[i]);
				destino = destinos[i];
			}
		}

		if(!estaDentro(destino, destinos, numPuntos)){
			break;
		}

		//Este será el criterio para ir al punto más cercano

		//Calculo del desplazamiento
		float dx = origen.Get_X() - destino.Get_X();
		float dy = origen.Get_Y() - destino.Get_Y();
		float modulo = sqrt(dx * dx + dy * dy);

		//Desplazamientos unitarios
		dx = -dx/modulo;
		dy = -dy/modulo;


		//Tendremos que recalcular dx y dy si borramos el destino antes de llegar a este
		while(origen.Distancia(destino) > 30  && enPantalla(destino, radio, dimensiones)){


			//Asi eliminaremos aquellos puntos por los que pasemos sin fijarlos como destino
			for(auto i=0;i<numPuntos; i++){
				//cout<<" "<<i<<" "<<endl;
					if(Wally.EnRango(destinos[i]) && destinos[i].Get_X()!=destino.Get_X() && destinos[i].Get_Y() != destino.Get_Y()){
					origen.eliminarPunto(destinos[i],destinos, numPuntos);
				}
			}

			origen.Mover(10*dx, 10*dy);
			Wally.Mover(10*dx, 10*dy);
			Wally.setCentro(origen);
			borra();
			PintaPoligono(Wally, ROJO);
			
			for(auto i=0; i<numPuntos; i++){
				PintaPunto(destinos[i], VERDE);
			}

			
    			color(VERDE);
			texto(300, 40, "Fila destino: ");
			texto(390, 40, to_string(destino.Get_Y()));

			texto(300, 55, "Columna destino: ");
			texto(410, 55, to_string(destino.Get_X()));

			refresca();
			espera(100);

			centro = origen;						
			
		}

		if(origen.Distancia(destino) <= 30){
			origen.eliminarPunto(destino, destinos, numPuntos);
		}

	}


	delete []destinos;
    
    
    vcierra();
    return 0;
    
}
