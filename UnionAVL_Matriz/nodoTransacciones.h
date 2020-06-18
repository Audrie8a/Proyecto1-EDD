#pragma once
#include <iostream>
using namespace std;
class nodoTransacciones
{
public:
	nodoTransacciones* siguiente;
	nodoTransacciones* anterior;
	string idTransaccion;	//código Alfanumérico de 15 carácteres
	string idActivo; //código Alfanumérico de 15 carácteres
	string Usuario;
	string Departamento;
	string Empresa;
	string Fecha;
	int tiempoRenta;

	nodoTransacciones(string idTransaccion, string idActivo, string Usuario, string Departamento, string Empresa, string Fecha, int tiempoRenta) {
		siguiente = nullptr;
		anterior = nullptr;
		this->idTransaccion = idTransaccion;
		this->idActivo = idActivo;
		this->Usuario = Usuario;
		this->Departamento = Departamento;
		this->Empresa = Empresa;
		this->Fecha = Fecha;
		this->tiempoRenta = tiempoRenta;
	}





};
