#include "TransaccionLCDE.h"
#include <iostream>
#include "Metodos.h"

using namespace std;

void TransaccionLCDE::InsertarTransaccion(string IdActivo, string Usuario, string Departamento, string Empresa, string fecha, int tiempo) {
	string IDaux, ID;
	Metodos* m = new Metodos();
	nodoTransacciones* nuevo;

	IDaux = m->generarID();
	ID = comprobarIdentificacion(IDaux);
	nuevo = new nodoTransacciones(ID, IdActivo, Usuario, Departamento, Empresa, fecha, tiempo);
	if (Inicio == nullptr) {
		Inicio = nuevo;
		Fin = nuevo;
		Inicio->siguiente = Inicio;
		Inicio->anterior = Fin;

		setInicio(Inicio);
	}
	else {
		Fin->siguiente = nuevo;
		nuevo->anterior = Fin;
		nuevo->siguiente = Inicio;
		Fin = nuevo;
		Inicio->anterior = Fin;
		setInicio(Inicio);
	}
	cout << "Transacción Registrada" << endl;
}


bool TransaccionLCDE::buscarTransaccion(string ID)
{
	bool condicion = false;
	nodoTransacciones* actual;
	actual = Inicio;
	if (actual != nullptr) {
		while (actual != Inicio) {
			if (actual->idTransaccion == ID) {
				condicion = true;
				break;
			}
			actual = actual->siguiente;
		}
	}

	return condicion;

}

void TransaccionLCDE::graficar() {
	FILE* file;
	errno_t err;
	err = fopen_s(&file, "Transacciones.dot", "w+");
	if (err != 0) {
		printf("Archivo no Abierto \n");
	}
	else {
		if (!file) {
			cout << "Error al escribir dot" << endl;
		}
		else {
			fprintf(file, "digraph G{\n");
			getDot(file, Inicio);
			fprintf(file, "}");
			fclose(file);

			system("dot -Tpng Transacciones.dot -o TransaccionesI.jpg");

			//system("nohup display ruta_y_nombre_de_imagen_generada.png &");x
			system("start cmd /c \"TransaccionesI.jpg \"");
		}
	}


}

void TransaccionLCDE::getDot(FILE* file, nodoTransacciones* nodo) {
	nodoTransacciones* aux = nodo;
	const string espacio = ", ";
	if (aux == nullptr) {
		return;
	}
	do {
		string label = aux->Usuario + "[label=\"" + aux->idTransaccion + espacio + aux->idActivo + espacio + aux->Usuario + "\"];\n";
		const char* clabel = label.c_str();
		fprintf(file, clabel);

		string enlaces = aux->Usuario + "->" + aux->siguiente->Usuario + "\n";
		enlaces += aux->Usuario + "->" + aux->anterior->Usuario + "\n";
		const char* cEnlaces = enlaces.c_str();
		fprintf(file, cEnlaces);

		aux = aux->siguiente;


	} while (aux != Inicio);
}

string TransaccionLCDE::comprobarIdentificacion(string ID)
{
	if (!buscarTransaccion(ID)) {
		return ID;
	}
	else {

		Metodos* m = new Metodos();
		ID = m->generarID();
		comprobarIdentificacion(ID);
	}
}

nodoTransacciones* TransaccionLCDE::buscarNodoTransaccion(string ID)
{
	nodoTransacciones* actual;
	actual = Inicio;
	if (actual != nullptr) {
		while (actual != Inicio) {
			if (actual->idTransaccion == ID) {
				return actual;
			}
			actual = actual->siguiente;
		}
	}

	return nullptr;
}
