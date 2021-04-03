#ifndef PINTAR_H
#define PINTAR_H

#include <iostream>
#include <cmath>
#include <string>
#include "miniwin.h"
#include "Punto2D.h"
#include "PoliReg.h"

const int RADIO = 10;

using namespace std;
using namespace miniwin;

void PintaPunto(const Punto2D& P, Color c);
void pintaLinea(const Punto2D& a, const Punto2D& b, Color c);
void rotar(Punto2D &p, double rads, Punto2D origen);

void PintaPoly(PoliReg& poligono);  
void PintaPoligono(PoliReg &p, Color c);

#endif
