#include <iostream>
#include "Arbol_AVL.h"
#include "Metodos.h"
using namespace std;

void Arbol_AVL::InsertarNodo(string Nombre, string Descripcion) {
	NodoArbol* padre = nullptr;
	Metodos* m = new Metodos();
	string ID_Activo;
	ID_Activo = m->generarID();
	Actual = Raiz;
	while (Actual != nullptr && ID_Activo!= Actual->ID) {
		padre = Actual;
		if (m->Mayor_Menor(ID_Activo,Actual->ID)=="Mayor") {
			Actual = Actual->derecha;
		}
		else if (m->Mayor_Menor(ID_Activo, Actual->ID) == "Menor") {
			Actual = Actual->izquierda;
		}
	}

	if (Actual!=nullptr) {
		return;
	}

	if (padre==nullptr) {		//Si el árbol está vacío se inserta el nuevo nodo como raíz
		Raiz = new NodoArbol(ID_Activo,Nombre,Descripcion);
	}
	else if(m->Mayor_Menor(ID_Activo,padre->ID)=="Menor"){		//Si el nuevo nodo es menor al nodo padre, se inserta a la izquierda
		padre->izquierda = new NodoArbol(ID_Activo, Nombre, Descripcion, padre);
		Equilibrar(padre,"IZQUIERDO",true);
	}
	else if (m->Mayor_Menor(ID_Activo, padre->ID)=="Mayor") {	//Si el nuevo nodo es mayor que el nodo padre
		padre->derecha = new NodoArbol(ID_Activo, Nombre, Descripcion,padre);
		Equilibrar(padre, "DERECHO",true);
	}

}

void Arbol_AVL::Equilibrar(NodoArbol *Nodo, string rama, bool condicion) {
	bool condicionSalida = false;

	while(Nodo && !condicionSalida){
		if (condicion) {
			if (rama == "IZQUIERDO") {
				Nodo->FE--;
			}
			else {
				Nodo->FE++;
			}
		}
		else {
			if (rama=="IZQUIERDO") {
				Nodo->FE++;
			}
			else {
				Nodo->FE--;
			}
		}
		if (Nodo->FE==0) {
			condicionSalida == true;	//Sale de equilibrar
		}
		else if (Nodo->FE==-2) {		//Filtro para RSD y RDD
			if (Nodo->izquierda->FE==1) {	//RDD
				RDD(Nodo);
			}
			else           //Si no es RDD tiene que ser RSD
			{
				RSD(Nodo);
			}
			condicionSalida = true;		//Sale de equilibrar
		}
		else if (Nodo->FE==2) {			//Filtro para RSI y RDI
			if (Nodo->derecha->FE==-1) {	//RDI
				RDI(Nodo);
			}
			else {
				RSI(Nodo);
			}
			condicionSalida = true;		//Sale de equilibrar
		}
		if (Nodo->Padre) {
			if (Nodo->Padre->derecha==Nodo) {
				rama = "DERECHO";	
			}
			else {
				rama = "IZQUIERDO";
			}
		}
		Nodo = Nodo->Padre;
	}
}

void Arbol_AVL::RSD(NodoArbol* Nodo) {
	NodoArbol* padre = Nodo->Padre;
	NodoArbol *P = Nodo;
	NodoArbol *L = P->izquierda;
	NodoArbol *R = L->derecha;

	if (padre) {
		if (padre->derecha==P) {
			padre->derecha = L;
		}
		else {
			padre->izquierda = L;
		}
	}
	else {
		Raiz = L;
	}
	P->izquierda = R;
	L->derecha = P;

	P->Padre = L;
	if (R) {
		R->Padre = P;
	}
	L->Padre = padre;

	P->FE = 0;
	L->FE = 0;
	
}
void Arbol_AVL::RSI(NodoArbol* Nodo) {
	NodoArbol *padre = Nodo->Padre;
	NodoArbol *P = Nodo;
	NodoArbol* L = P->derecha;
	NodoArbol* R = L->izquierda;

	if (padre) {
		if (padre->derecha == P) {
			padre->derecha = L;
		}
		else {
			padre->izquierda = L;
		}
	}
	else {
		Raiz = L;
	}
	P->derecha = R;
	L->izquierda = P;

	P->Padre = L;
	if (R) {
		R->Padre = P;
	}
	L->Padre = padre;

	P->FE = 0;
	L->FE = 0;
}
void Arbol_AVL::RDI(NodoArbol* Nodo) {
	NodoArbol *padre = Nodo->Padre;
	NodoArbol *P = Nodo;
	NodoArbol *Q = P->derecha;
	NodoArbol *R = Q->izquierda;
	NodoArbol *B = R->izquierda;
	NodoArbol *C = R->derecha;

	if (padre) {
		if (padre->derecha==Nodo) {
			padre->derecha = R;
		}
		else {
			padre->izquierda=R;
		}
	}
	else {
		Raiz = R;
	}
	P->derecha = B;
	Q->izquierda = C;
	R->izquierda = P;
	R->derecha = Q;

	R->Padre = padre;
	P->Padre = Q->Padre = R;
	if (B) {
		B->Padre = P;
	}
	if (C) {
		C->Padre = Q;
	}

	switch (R->FE)
	{
	case -1:
		P->FE = 0;
		Q->FE = -1;
		break;
	case 0:
		P->FE = 0;
		Q->FE = 0;
		break;
	case 1:
		P->FE = -1;
		Q->FE = 0;
		break;
	}
	R->FE = 0;

}
void Arbol_AVL::RDD(NodoArbol* Nodo) {
	NodoArbol* padre = Nodo->Padre;
	NodoArbol* P = Nodo;
	NodoArbol* Q = P->izquierda;
	NodoArbol* R = Q->derecha;
	NodoArbol* B = R->izquierda;
	NodoArbol* C = R->derecha;

	if (padre) {
		if (padre->derecha == Nodo) {
			padre->derecha = R;
		}
		else {
			padre->izquierda = R;
		}
	}
	else {
		Raiz = R;
	}
	Q->derecha = B;
	P->izquierda = C;
	R->izquierda = Q;
	R->derecha = P;

	R->Padre = padre;
	P->Padre = Q->Padre = R;
	if (B) {
		B->Padre = Q;
	}
	if (C) {
		C->Padre = P;
	}

	switch (R->FE)
	{
	case -1:
		Q->FE = 0;
		P->FE = 1;
		break;
	case 0:
		P->FE = 0;
		Q->FE = 0;
		break;
	case 1:
		Q->FE = -1;
		P->FE = 0;
		break;
	}
	R->FE = 0;
}

