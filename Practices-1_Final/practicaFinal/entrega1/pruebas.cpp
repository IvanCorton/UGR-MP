/* FUNCIONES DE PRUEBA PARA LA CLASE PoliReg
 * Metodologías de la Programació
 * Curso 2019 - 2020
 * David A. Pelta 
 */

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Punto2D.h"
#include "PoliReg.h"

using namespace std;

void mostrar(PoliReg *v, int n){
for(int i=0; i < n; i++)
    cout << v[i] << endl;
    
}
void test1(int N){
    cout << "\nTest 1: Constructor por defecto, con parámetros y asignación" << endl;
    PoliReg *v;
    
    v = new PoliReg[N];
    
    for (int i = 0; i < N ; i++){
        v[i] = PoliReg(3+rand()%5, Punto2D(), 5.0 + rand()%200);
    }

    mostrar(v, N);
    
    delete [] v;
}

void test2(int N){
    
    cout << "\nTest 2: Acumulacion de operaciones básicas sobre poligonos" << endl;
    PoliReg *v;
    
    v = new PoliReg[N];
    
    for (int i = 0; i < N ; i++){
        v[i].Mover(rand()%800, rand()%800);
    }
    
    int opcion;
    for (int repes = 0; repes < 500; repes++) {
        
        for (int i = 0; i < N; i++) {
            opcion = rand() % 5;
            switch (opcion) {
                case 0:
                {
                    v[i].AgregaVertice();
                    break;
                }
                case 1:
                {
                    v[i].EliminaVertice();
                    break;
                }
                case 2:
                {
                    v[i].Expande(60);
                    break;
                }
                case 3:
                {
                    v[i].Contrae(50);
                    break;
                }
                case 4:
                {
                    v[i].Rotar((rand() % 360) * M_PI / 180.0);
                    break;
                }

            }
        }
    }

   
   delete [] v; 
}

void test3(){
    cout << "\nTest 3: Constructor por defecto, 
                de copia, con parámetros y asignación" << endl;
    PoliReg *p1 = new PoliReg(5, Punto2D(), 100.0);
    PoliReg p2 = PoliReg(*p1);
    PoliReg p3;
    PoliReg p4(p3);
    PoliReg p5;
    p5 = p3;
    
    cout << "Poligono 1" << endl;
    cout << *p1 << endl;
    cout << "Poligono 2" << endl;
    cout << p2 << endl;
    cout << "Poligono 3" << endl;
    cout << p3 << endl;
    cout << "Poligono 4" << endl;
    cout << p4 << endl;
    cout << "Poligono 5" << endl;
    cout << p5 << endl;
    
    cout << "5 poligonos al azar" << endl;
    for(int i = 0; i < 5; i++)
        cout << PoliReg(3+rand()%5, Punto2D(), rand()%100) << endl;
    
    delete p1;
}

// implemente la función ordenar


int main(int argc, char* argv[]) {
    srand(283475321);
    int opcion = -1;
    
    if (argc<2)
        cout << "Uso: " << " pruebas < 1 | 2 | 3 > " <<endl;
     else
        opcion = atoi(argv[1]);
    
     if (opcion == 1)
        test1(10);
     else if (opcion == 2)
        test2(250);
     else if (opcion == 3)     
        test3();

return 0;

}
