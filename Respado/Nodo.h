#pragma once
#include <iostream>;
//#include "Arbol_AVL.h"
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

	string Nombre, Usuario, Contrasena;
	int Numero;


	Nodo(string Nombre, string Usuario, string Contrasena, int Numero) {
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

	}
};

