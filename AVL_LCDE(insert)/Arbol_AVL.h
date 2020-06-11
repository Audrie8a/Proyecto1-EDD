#pragma once
#include <iostream>;
#include "NodoArbol.h"
using namespace std;
class Arbol_AVL
{
private:
	NodoArbol* Raiz;
	NodoArbol* Actual;

	int cont;	//contador
	int altura;
	/*
	int newdato=0;
	bool noencontrado=false;
	bool sieliminar = true;
	NodoArbol* mayorL= nullptr;
	NodoArbol* menorR= nullptr;
	*/
public:
	Arbol_AVL() {
		Raiz = nullptr;
		Actual = nullptr;
	}

	void InsertarNodo(string Nombre, string Descrip);
	void Equilibrar(NodoArbol *Nodo, string rama, bool condicion);
	void RSD(NodoArbol* Nodo);
	void RSI(NodoArbol* Nodo);
	void RDI(NodoArbol* Nodo);
	void RDD(NodoArbol* Nodo);


};