#include "TransaccionLCDE.h"
#include "nodoTransacciones.h"
#include <iostream>
using namespace std;

void TransaccionLCDE::InsertarTransaccion(string ID, string IdActivo, string Usuario, string Departamento, string Empresa, string fecha, int tiempo) {
	nodoTransacciones* nuevo;
	nuevo = new nodoTransacciones(ID, IdActivo, Usuario, Departamento, Empresa, fecha, tiempo);
	if (Inicio == nullptr) { 
		Inicio = nuevo;
		Fin = nuevo;
		Inicio->siguiente = Inicio;
		Inicio->anterior = Fin;
	}else{
		Fin->siguiente = nuevo;
		nuevo->anterior = Fin;
		nuevo->siguiente = Inicio;
		Fin = nuevo;
		Inicio->anterior = Fin;
	}
	cout << "Transacción Registrada" << endl;
}

