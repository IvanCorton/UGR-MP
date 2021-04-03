
#include <iostream>
#include <string>

using namespace std;

struct Paquete
{
    int origen;
    int destino;
    int peso; // en gramos
};

struct Contenedor
{
    static const int MAX = 50;
    Paquete lista[MAX];
    int utiles;
};


// función para devolver los datos de un paquete como un string
string paqueteToString(Paquete a)
{
    string rta;
    rta = "Orig: " + to_string(a.origen) + "\t Dest: " + to_string(a.destino) + "\tPeso:" + to_string(a.peso);
    return rta;
}


// PARA COMPLETAR
// crea una variable de tipo Paquete y la devuelve
Paquete creaPaquete(int ori, int des, int peso)
{
	Paquete Paq;
	Paq.origen = ori;
	Paq.destino = des;
	Paq.peso = peso;

	return Paq;
}


// PARA COMPLETAR
// ordena el contenedor en función del campo peso de cada paquete
void ordenar(Contenedor & c){

	
	for(int i=1; i<c.utiles; i++)
		for(int j=0;j<c.utiles-1;j++)
			if(c.lista[j].peso > c.lista[j+1].peso){		
				Paquete temp = creaPaquete(c.lista[j].origen, c.lista[j].destino, c.lista[j].peso);
				c.lista[j] = c.lista[j+1];
				c.lista[j+1]= temp;	
			}

}


// PARA COMPLETAR
// muestra el listado de paquetes
void mostrarContenedor(const Contenedor & c)
{

		for(unsigned int i=0;i<c.utiles;i++){
			cout<<"Paq: "<<i<<" "<<paqueteToString(c.lista[i])<<endl;
		}


}


// PARA COMPLETAR
// construye un nuevo contenedor con los paquetes que tienen como destino "dest"
Contenedor seleccionaPaquetes(const Contenedor & c, int dest)
{

	Contenedor auxiliar;
	auxiliar.utiles=0;
	int contador=0;


	for(int i=0;i<c.utiles;i++){
		if(c.lista[i].destino == dest){
			auxiliar.lista[contador]=creaPaquete(c.lista[i].origen, c.lista[i].destino, c.lista[i].peso);
			auxiliar.utiles++;
			contador++;
		}


	}

	return auxiliar;

}

//PARA COMPLETAR
// devuelve el nro de paquetes y su peso que tienen como destino "dest"
void contarPaquetesPeso(const Contenedor & c, int dest, int & nro, int & peso)
{

	int numPaquetes=0, pesoTotal=0;

	for(unsigned int i=0;i<c.utiles; i++){
		if(c.lista[i].destino==dest){
			numPaquetes++;
			pesoTotal+=c.lista[i].peso;
		}
	}

	peso=pesoTotal;
	nro=numPaquetes;

}


int main()
{
    Contenedor c1, otro;
    int origen, destino, peso, cant;

    // lectura de datos
    cin >> cant;

    for (int i = 0; i < cant; i++) {
        cin >> origen >> destino >> peso;
        c1.lista[i] = creaPaquete(origen, destino, peso);
    }

    c1.utiles = cant;

    // se muestra la lista de productos.
    cout << "\n ******** Prueba de funcion mostrarContenedor ******** \n";
    mostrarContenedor(c1);

    // ordena
    cout << "\n ******** Prueba de funcion ordenarContenedor ******** \n";
    ordenar(c1);
    cout << "\n ******** Muestra contenido ordenado por peso ******** \n";
    mostrarContenedor(c1);

    cout << "\n ******** Prueba de funcion contarPaquetesPeso ******** \n";
    cout << "para cada destino muestro el nro de paquetes que se envian y su peso\n";
    int nro;
    for(int dest=0; dest < 10; dest++){
        contarPaquetesPeso(c1, dest, nro, peso);
        if (nro > 0)
            cout << "Destino: " << dest << " Paquetes: " << nro << " Peso: " << peso << endl;
    }
    
    cout << "\n ******** Prueba de funcion seleccionaPaquetes ******** \n";
    cout << "Paquetes enviados a destino=2\n";
    otro = seleccionaPaquetes(c1, 2);

    //    cout << "\n ******** y mostrar nuevo Contenedor \t\t********\n\n";
    mostrarContenedor(otro);

    return (0);
}

