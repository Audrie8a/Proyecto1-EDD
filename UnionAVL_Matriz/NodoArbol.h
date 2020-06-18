#pragma once
#include <iostream>
using namespace std;
class NodoArbol
{
public:
	NodoArbol(string id, string nom, string Desc, NodoArbol* pa = nullptr, NodoArbol* izq = nullptr, NodoArbol* der = nullptr) :
		ID(id), Nombre(nom), Descripcion(Desc), Padre(pa), izquierda(izq), derecha(der), FE(0) {}
	//Atributos Activo
	string Nombre;
	string Descripcion;
	string ID;

	//Punteros
	NodoArbol* izquierda;
	NodoArbol* derecha;
	NodoArbol* Padre;
	int FE;


};