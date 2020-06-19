#pragma once
#include <iostream>;
#include "NodoArbol.h"
using namespace std;
class Arbol_AVL
{
public:
	NodoArbol* Raiz;
	NodoArbol* Actual;

	int cont;	//contador
	int altura;

public:
	Arbol_AVL() {
		Raiz = nullptr;
		Actual = nullptr;
	}

	
	//CREAR M�TODOS PARA FUNCIONES AUXILIARES
	NodoArbol* BuscarNodoAVL(string dato, NodoArbol* Raiz);

	int obtenerFe(NodoArbol* Nodo);
	void ActualizarAltura(NodoArbol* Nodo);
	NodoArbol* getRaiz();
	void MostrarArbol(NodoArbol* arbol, int cont);
	void MostrarActivosArbol(NodoArbol* arbol);

	void CambiarEstadoNodo(string dato,NodoArbol* Raiz);	//Cambia el estado del nodo rentado a false

	//CREAR M�TODOS PARA ROTACIONES

	NodoArbol* SRL(NodoArbol* Nodo);		//ROTACI�N SIMPLE A LA IZQUIERDA
	NodoArbol* SRR(NodoArbol* Nodo);		//ROTACI�N SIMPLE A LA DERECHA
	NodoArbol* DRR(NodoArbol* Nodo);		//ROTACI�N DOBLE A LA DERECHA
	NodoArbol* DRL(NodoArbol* Nodo);		//ROTACI�N DEOBLE A LA IZQUIERDA

	//CREAR M�TODOS PARA FUNCIONES PRINCIPALES

	NodoArbol* InsertarAVl(NodoArbol* Nuevo, NodoArbol* Nodo);
	void InsertarNodoAVL(string Nombre, string Descripcion, bool estado);


	//GRAFICAR
	void graficar();
	void getDot(FILE* file, NodoArbol* Raiz);

	
};