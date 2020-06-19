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

	
	//CREAR MÉTODOS PARA FUNCIONES AUXILIARES
	NodoArbol* BuscarNodoAVL(string dato, NodoArbol* Raiz);

	int obtenerFe(NodoArbol* Nodo);
	void ActualizarAltura(NodoArbol* Nodo);
	NodoArbol* getRaiz();
	void MostrarArbol(NodoArbol* arbol, int cont);
	void MostrarActivosArbol(NodoArbol* arbol);

	void CambiarEstadoNodo(string dato,NodoArbol* Raiz);	//Cambia el estado del nodo rentado a false

	//CREAR MÉTODOS PARA ROTACIONES

	NodoArbol* SRL(NodoArbol* Nodo);		//ROTACIÓN SIMPLE A LA IZQUIERDA
	NodoArbol* SRR(NodoArbol* Nodo);		//ROTACIÓN SIMPLE A LA DERECHA
	NodoArbol* DRR(NodoArbol* Nodo);		//ROTACIÓN DOBLE A LA DERECHA
	NodoArbol* DRL(NodoArbol* Nodo);		//ROTACIÓN DEOBLE A LA IZQUIERDA

	//CREAR MÉTODOS PARA FUNCIONES PRINCIPALES

	NodoArbol* InsertarAVl(NodoArbol* Nuevo, NodoArbol* Nodo);
	void InsertarNodoAVL(string Nombre, string Descripcion, bool estado);


	//GRAFICAR
	void graficar();
	void getDot(FILE* file, NodoArbol* Raiz);

	
};