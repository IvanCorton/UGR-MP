#include "Punto2D.h"

Punto2D::Punto2D(){

	int xRand = rand()%MIN_X;
	int yRand = rand()%MIN_Y;

	this->x = xRand;
	this->y = yRand;

}


Punto2D::Punto2D(float x, float y){

		this->x = x;
		this->y = y;

}

float Punto2D::Get_X() const{ return this->x; }
float Punto2D::Get_Y() const{ return this->y; }

void Punto2D::Set_X(float x){ this->x = x; }
void Punto2D::Set_Y(float y){ this->y = y; }



void Punto2D::eliminarPunto(Punto2D punto, Punto2D * & destinos, int & numPuntos){

	
	Punto2D * nuevo = new Punto2D[numPuntos];

	int indice;

	for(auto i=0; i<numPuntos; i++){
		if(destinos[i].Get_X() == punto.Get_X() && destinos[i].Get_Y() == punto.Get_Y()){
			indice=i;
		}
	}

	if(indice==0){
		for(auto i=0;i<numPuntos-1;i++){
			nuevo[i]=destinos[i+1];
		}

	}else if(indice==numPuntos-1){
	
		for(auto i=0; i<numPuntos-1; i++){
			nuevo[i] = destinos[i];
		}

	}else if(indice<numPuntos && indice>0){
		for(auto i=indice; i<numPuntos-1; i++){
			destinos[i] = destinos[i+1];
		}

		for(auto i=0; i<numPuntos-1; i++){
			nuevo[i] = destinos[i];
		}

	}
	
	numPuntos--;

	delete []destinos;
	destinos = new Punto2D[numPuntos];

	for(auto i=0; i<numPuntos; i++){
		destinos[i] = nuevo[i];
	}

	delete []nuevo;
	nuevo=0;

}


float Punto2D::Distancia(const Punto2D & otro){
	
	float a, b, c;

	a = this->x - otro.x;
	b = this->y - otro.y;

	c = sqrt((a*a)+(b*b));

	return c;

}


void Punto2D::Rotar(const Punto2D & centro, double rads){
	
    double deltaX = Get_X()- centro.Get_X();
    double deltaY = Get_Y() - centro.Get_Y();

    Set_X(centro.Get_X() + deltaX * cos(rads) - deltaY * sin(rads));
    Set_Y(centro.Get_Y() + deltaX * sin(rads) + deltaY * cos(rads));

}


void Punto2D::Mover(float dx, float dy){

	this->x+=dx;
	this->y+=dy;

}


// Sobrecarga del operador << para la clase PoliReg
ostream& operator <<(ostream &o, const Punto2D &p)
{
    o << "(" << p.Get_X() << ", " << p.Get_Y() << ")";
    
	return o;
}


