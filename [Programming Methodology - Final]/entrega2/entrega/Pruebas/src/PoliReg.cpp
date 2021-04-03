#include "PoliReg.h"

const float PoliReg::MAX_RADIO = 150.0;
const float PoliReg::MIN_RADIO = 15.0;
const int PoliReg::MAX_VERT = 200;
const int PoliReg::MIN_VERT = 3;


void PoliReg::ReservaMemoria(){
	
	if(this->N > MIN_VERT)
	this->vertices = new Punto2D[this->N];
	else
	this->vertices = new Punto2D[MIN_VERT];

}

void PoliReg::LiberaMemoria(){

	if(vertices!=0){
		delete[] vertices;
		this->vertices = 0;
	}

}

void PoliReg::GeneraVertices(){

	float grados = 360/getNumVertices();
	float alpha = grados * (M_PI / 180.0);

	float X = getCentro().Get_X() + getRadio(), Y = getCentro().Get_Y();

	for(auto i=0; i<getNumVertices(); i++){
		getVerticeI(i).Set_X(getCentro().Get_X() + getRadio());
		getVerticeI(i).Set_Y(getCentro().Get_Y());
		getVerticeI(i).Rotar(getCentro(), alpha*i);
	}	

}


PoliReg::~PoliReg(){
	LiberaMemoria();
	Punto2D centro(0,0);
	this->centro = centro;
	this->N = 0;
	this->radio = 0;
}


PoliReg::PoliReg(){

	Punto2D centro(0,0);

	this->vertices = 0;
	this->centro = centro;
	this->N = MIN_VERT;
	this->radio = MIN_RADIO;

	ReservaMemoria();
	GeneraVertices();
	

}

void PoliReg::copiar(const PoliReg &poligono){



	this->N = poligono.getNumVertices();
	this->vertices = 0;
	this->centro = poligono.getCentro();
	this->radio = poligono.getRadio();
	
	ReservaMemoria();
	GeneraVertices();


}

PoliReg::PoliReg(const PoliReg &poligon){
	
	copiar(poligon);

}


PoliReg::PoliReg(int nroLados, const Punto2D & centro, float r){

	this->vertices = 0;

	if(r<MIN_RADIO || r>MAX_RADIO){
		this->radio = MIN_RADIO;
	}else{
		this->radio = r;
	}

		this->centro = centro;
		this->N = nroLados;
		ReservaMemoria();
		GeneraVertices();

	
}

Punto2D PoliReg::getCentro() const{ return this->centro; }

Punto2D & PoliReg::getVerticeI(int indice) const{ return this->vertices[indice]; }

int PoliReg::getNumVertices() const { return this->N; }

float PoliReg::getRadio() const{ return this->radio; }

void PoliReg::setCentro(Punto2D nuevo){
	this->centro = nuevo;
}


void PoliReg::AgregaVertice(){

	if(getNumVertices() < MAX_VERT){
		this->N++;		
		LiberaMemoria();
		ReservaMemoria();
		GeneraVertices();
	}

}

void PoliReg::EliminaVertice(){

	if(getNumVertices() > MIN_VERT){
		this->N--;	
		LiberaMemoria();
		ReservaMemoria();
		GeneraVertices();
	}

}

void PoliReg::Expande(int pct){

	double anteriorRadio = getRadio();
	double porcentaje = ((double) pct/100);
	double nuevoRadio = anteriorRadio + (anteriorRadio * porcentaje);

	if(nuevoRadio>MAX_RADIO){
		this->radio = MAX_RADIO;
	}else{
		this->radio = nuevoRadio;
	}
	
	GeneraVertices();

}


void PoliReg::Contrae(int pct){

	float nuevoRadio = getRadio() - (getRadio() * ((double) pct/100));
	
	if(nuevoRadio<MIN_RADIO){
		this->radio = MIN_RADIO;
	}else{
		this->radio = nuevoRadio;
	}

	GeneraVertices();

}


double PoliReg::Perimetro() const{

	double perimetro=0.0;
	double distanciaInicial = this->vertices[0].Distancia(this->vertices[1]);

	perimetro = distanciaInicial * getNumVertices();

	return perimetro;

}


void PoliReg::Rotar(float rads){

	for(auto i=0; i<getNumVertices(); i++){
		getVerticeI(i).Rotar(getCentro(), rads);
	}

}



bool PoliReg::Colision(const PoliReg & otro) const{

	double distanciaEntreCentros = (getCentro()).Distancia(otro.getCentro());
	double r1 = getRadio();
	double r2 = otro.getRadio();
	double sumaRadios = r1+r2;

	// Si tiene distinto centro 
	// quiere decir que no son el mismo poligono en el espacio.
	
	// Si sobrecargaramos el operador !=, unicamente
	// tendriamos que hacer this!=otro.
	
	if(getCentro().Get_X()!=otro.getCentro().Get_X() && getCentro().Get_Y()!=otro.getCentro().Get_Y()){
		if(distanciaEntreCentros<=sumaRadios){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}

}

void PoliReg::Mover(float dx, float dy){

	Punto2D nuevo(0,0);

	nuevo.Mover(dx, dy);

	setCentro(nuevo);

	for(auto i=0; i<getNumVertices(); i++){
		getVerticeI(i).Mover(dx, dy);	
	}
}

// true si pto dentro de circunferencia actual.
bool PoliReg::EnRango(const Punto2D & pto){

	double distanciaEntre = this->getCentro().Distancia(pto);

	if(distanciaEntre <= getRadio()){
		return true;
	}else{
		return false;
	}
}



bool PoliReg::operator<(const PoliReg &poligono){

	return (this->Perimetro()<poligono.Perimetro());

}


// Sobrecarga del operador de asignacion =
PoliReg & PoliReg::operator=(const PoliReg & poligono){

	if(&poligono != this){
		LiberaMemoria();
		copiar(poligono);
	}

	return *this;

}

// Sobrecarga del operador << para la clase PoliReg
ostream& operator<<(ostream &o, const PoliReg &p){

    o << "Polig. de "<<p.getNumVertices()<<". Centro: "<<p.getCentro()<<" Perim: "<<p.Perimetro()<<" Puntos: ";
	for(auto i=0;i<p.getNumVertices()-1; i++){
		o << p.getVerticeI(i) <<", ";
	}

	o << p.getVerticeI(p.getNumVertices()-1);	
    
	return o;
}





