#ifndef POLIREG_H
#define POLIREG_H

#include <time.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Punto2D.h"

using namespace std;

class PoliReg{

private:
	Punto2D *vertices;
	int N;
	Punto2D centro;
	float radio;

	static const int MAX_VERT;
	static const int MIN_VERT;
	static const float MAX_RADIO;
	static const float MIN_RADIO;
	void ReservaMemoria();
	void LiberaMemoria();
	void GeneraVertices();

public:
	PoliReg();
	PoliReg(int nroLados, const Punto2D & centro, float r);
	void copiar(const PoliReg &poligono);
	PoliReg(const PoliReg &poligon);
	
	Punto2D getCentro() const;
	Punto2D & getVerticeI(int indice) const;
	int getNumVertices() const;
	float getRadio() const;

	void setCentro(Punto2D nuevo);
	
	void Mover(float dx, float dy);
	void AgregaVertice();
	void EliminaVertice();
	void Expande(int pct);
	void Contrae(int pct);
	double Perimetro() const;
	void Rotar(float rads);
	bool Colision(const PoliReg & otro) const;
	bool EnRango(const Punto2D & pto);	
	~PoliReg();
	PoliReg & operator=(const PoliReg &poligono);
	bool operator<(const PoliReg &poligono);

};

ostream& operator<<(ostream &o, const PoliReg &p);

#endif
