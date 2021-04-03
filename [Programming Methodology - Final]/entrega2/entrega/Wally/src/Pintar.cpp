#include "Pintar.h"

void PintaPunto(const Punto2D& P, Color c) {
    color(c);
    circulo_lleno(P.Get_X(), P.Get_Y(), RADIO);

}

void pintaLinea(const Punto2D& a, const Punto2D& b, Color c) {
    color(c);
    linea(a.Get_X(), a.Get_Y(), b.Get_X(), b.Get_Y());
}



void rotar(Punto2D &p, double rads, Punto2D origen) {
    
	p.Rotar(origen, rads);

}


void PintaPoly(PoliReg& poligono){

	for(auto i=0; i<poligono.getNumVertices(); i++){
		PintaPunto(poligono.getVerticeI(i), ROJO);
	}		

	for(auto i=0; i<poligono.getNumVertices()-1;i++){
		pintaLinea(poligono.getVerticeI(i), poligono.getVerticeI(i+1), BLANCO);
	}

	pintaLinea(poligono.getVerticeI(0), poligono.getVerticeI(poligono.getNumVertices()-1), BLANCO);

}


void PintaPoligono(PoliReg &p, Color c){

	for(auto i=0; i<p.getNumVertices(); i++){
		PintaPunto(p.getVerticeI(i), c);
	}		

	for(auto i=0; i<p.getNumVertices()-1;i++){
		pintaLinea(p.getVerticeI(i), p.getVerticeI(i+1), c);
	}

	pintaLinea(p.getVerticeI(0), p.getVerticeI(p.getNumVertices()-1), c);
}
