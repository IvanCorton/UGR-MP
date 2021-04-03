#ifndef PUNTO2D_H
#define PUNTO2D_H

#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MIN_X = 800, MIN_Y = 800;

class Punto2D{

private:
	float x,y;
public:
	Punto2D();
	Punto2D(float x, float y);
	float Get_X() const;
	float Get_Y() const;
	void Set_X(float x);
	void Set_Y(float y);
	float Distancia(const Punto2D & otro);
	void eliminarPunto(Punto2D punto, Punto2D * & destinos,int &numPuntos);
	void Rotar(const Punto2D & centro, double rads);
	void Mover(float dx, float dy);	
};

ostream& operator <<(ostream &o, const Punto2D &p);	


#endif
