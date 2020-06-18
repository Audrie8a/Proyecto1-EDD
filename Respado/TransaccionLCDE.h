#pragma once
#include "nodoTransacciones.h";

using namespace std;
class TransaccionLCDE
{
public:
	nodoTransacciones* Inicio;
	nodoTransacciones* Fin;
	TransaccionLCDE() {
		Inicio = nullptr;
		Fin = nullptr;
	}
	void InsertarTransaccion(string IdActivo, string Usuario, string Departamento, string Empresa, string fecha, int tiempo);
	bool buscarTransaccion(string ID);
	void graficar();
	void getDot(FILE* file, nodoTransacciones* Cabeza);
	string comprobarIdentificacion(string ID);
};

