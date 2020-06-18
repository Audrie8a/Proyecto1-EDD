#pragma once
#include "Arbol_AVL.h"
#include <iostream>;
using namespace std;

class Nodo
{
public:
	Nodo* Siguiente;
	Nodo* Anterior;
	Nodo* Arriba;
	Nodo* Abajo;
	Nodo* Adelante;
	Nodo* Atras;
	Arbol_AVL* AVL;

	string Nombre, Usuario, Contrasena;
	int Numero;


	Nodo(string Nombre, string Usuario, string Contrasena, int Numero, Arbol_AVL* AVL) {
		Siguiente = nullptr;
		Anterior = nullptr;
		Arriba = nullptr;
		Abajo = nullptr;
		Adelante = nullptr;
		Atras = nullptr;
		this->Nombre = Nombre;
		this->Usuario = Usuario;
		this->Contrasena = Contrasena;
		this->Numero = Numero;
		this->AVL = AVL;
	}

	void setAVL(Arbol_AVL* Arbol) {
		this->AVL = Arbol;
	}

	Arbol_AVL* getAVL() {
		return this->AVL;
	}
};