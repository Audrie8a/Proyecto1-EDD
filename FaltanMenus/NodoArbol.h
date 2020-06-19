#pragma once
#include <iostream>
using namespace std;
class NodoArbol
{
public:
	NodoArbol(string id, string nom, string Desc,bool Estado, NodoArbol* pa = nullptr, NodoArbol* izq = nullptr, NodoArbol* der = nullptr) :
		ID(id), Nombre(nom), Descripcion(Desc), Padre(pa), izquierda(izq), derecha(der), FE(0),Estado(true) {}
	//Atributos Activo
	string Nombre;
	string Descripcion;
	string ID;
	bool Estado;	//Activo= true; Inactivo= false;

	//Punteros
	NodoArbol* izquierda;
	NodoArbol* derecha;
	NodoArbol* Padre;
	int FE;

	void setEstado(bool estado) {
		this->Estado = estado;
	}

	bool getEstaod() {
		return this->Estado;
	}

};