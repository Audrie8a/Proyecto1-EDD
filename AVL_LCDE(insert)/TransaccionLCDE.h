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
	void InsertarTransaccion(string ID, string IdActivo, string Usuario, string Departamento, string Empresa, string fecha, int tiempo);
	
};

