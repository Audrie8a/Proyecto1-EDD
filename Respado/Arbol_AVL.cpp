#include <iostream>
#include "Arbol_AVL.h"
#include "Metodos.h"
#include <algorithm>
using namespace std;


NodoArbol* Arbol_AVL::InsertarAVl(NodoArbol* Nuevo, NodoArbol* Nodo)
{
	Metodos* m = new Metodos();
	NodoArbol* nuevoPadre = Nodo;
	//m->Mayor_Menor(Nuevo->ID , Nodo->ID) == "Menor"
	//m->Mayor_Menor(Nuevo->ID,Nodo->derecha->ID)=="Mayor"
	if (m->Mayor_Menor(Nuevo->ID, Nodo->ID) == "Menor") {			 //Si es menor, insertar a la izquierda
		if (Nodo->izquierda == nullptr) {
			Nodo->izquierda = Nuevo;
		}
		else {
			Nodo->izquierda = InsertarAVl(Nuevo, Nodo->izquierda);
			if ((obtenerFe(Nodo->izquierda) - obtenerFe(Nodo->derecha)) == 2) {
				if (Nuevo->ID < Nodo->izquierda->ID) {
					nuevoPadre = SRL(Nodo);
				}
				else {
					nuevoPadre = DRL(Nodo);
				}
			}
		}
	}
	else if (m->Mayor_Menor(Nuevo->ID, Nodo->ID) == "Mayor") {		//Si es menor, insertar a la izquierda
		if (Nodo->derecha == nullptr) {
			Nodo->derecha = Nuevo;
		}
		else {
			Nodo->derecha = InsertarAVl(Nuevo, Nodo->derecha);
			if ((obtenerFe(Nodo->derecha) - obtenerFe(Nodo->izquierda)) == 2) {
				if (m->Mayor_Menor(Nuevo->ID, Nodo->derecha->ID) == "Mayor") {
					nuevoPadre = SRR(Nodo);
				}
				else {
					nuevoPadre = DRR(Nodo);
				}
			}
		}
	}
	else {		//Aceptamos duplicados
		if (Nodo->derecha == nullptr) {
			Nodo->derecha = Nuevo;
		}
		else {
			Nodo->derecha = InsertarAVl(Nuevo, Nodo->derecha);
			if ((obtenerFe(Nodo->derecha) - obtenerFe(Nodo->izquierda)) == 2) {
				if (m->Mayor_Menor(Nuevo->ID, Nodo->derecha->ID) == "Mayor") {
					nuevoPadre = SRR(Nodo);
				}
				else {
					nuevoPadre = DRR(Nodo);
				}
			}
		}
	}

	ActualizarAltura(Nodo);
	return nuevoPadre;
}

void Arbol_AVL::InsertarNodoAVL(string Nombre, string Descripcion)
{
	Metodos* m = new Metodos();
	string ID_Activo;
	ID_Activo = m->generarID();
	NodoArbol* nuevo = new NodoArbol(ID_Activo, Nombre, Descripcion);
	if (Raiz == nullptr) {
		Raiz = nuevo;
	}
	else {
		Raiz = InsertarAVl(nuevo, Raiz);
	}
}

NodoArbol* Arbol_AVL::BuscarNodoAVL(string dato, NodoArbol* Raiz)
{
	NodoArbol* aux = Raiz;
	if (aux == nullptr) {
		return nullptr;
	}
	else if (aux->ID == dato) {
		return aux;
	}
	else if (aux->ID < dato) {
		return BuscarNodoAVL(dato, aux->derecha);
	}
	else {
		return BuscarNodoAVL(dato, aux->izquierda);
	}
}

int Arbol_AVL::obtenerFe(NodoArbol* Nodo)
{
	if (Nodo == nullptr) {
		return -1;
	}
	else {
		return Nodo->FE;
	}
}

void Arbol_AVL::ActualizarAltura(NodoArbol* Nodo)
{
	if ((Nodo->izquierda == nullptr) && (Nodo->derecha != nullptr)) {
		Nodo->FE = Nodo->derecha->FE + 1;
	}
	else if ((Nodo->derecha == nullptr) && (Nodo->izquierda != nullptr)) {
		Nodo->FE = Nodo->izquierda->FE + 1;
	}
	else {
		Nodo->FE = max(obtenerFe(Nodo->izquierda), obtenerFe(Nodo->derecha)) + 1;
	}
}

NodoArbol* Arbol_AVL::getRaiz()
{
	return Raiz;
}

NodoArbol* Arbol_AVL::SRL(NodoArbol* Nodo)
{
	NodoArbol* aux = Nodo->izquierda;
	Nodo->izquierda = aux->derecha;
	aux->derecha = Nodo;
	Nodo->FE = max(obtenerFe(Nodo->izquierda), obtenerFe(Nodo->derecha)) + 1;
	aux->FE = max(obtenerFe(aux->izquierda), obtenerFe(aux->derecha)) + 1;

	return aux;
}

NodoArbol* Arbol_AVL::SRR(NodoArbol* Nodo)
{
	NodoArbol* aux = Nodo->derecha;
	Nodo->derecha = aux->izquierda;
	aux->izquierda = Nodo;
	Nodo->FE = max(obtenerFe(Nodo->izquierda), obtenerFe(Nodo->derecha)) + 1;
	aux->FE = max(obtenerFe(aux->izquierda), obtenerFe(aux->derecha)) + 1;

	return aux;
}

NodoArbol* Arbol_AVL::DRR(NodoArbol* Nodo)
{
	NodoArbol* aux;
	Nodo->derecha = SRL(Nodo->derecha);
	aux = SRR(Nodo);
	return aux;
}

NodoArbol* Arbol_AVL::DRL(NodoArbol* Nodo)
{
	NodoArbol* aux;
	Nodo->izquierda = SRR(Nodo->izquierda);
	aux = SRL(Nodo);
	return aux;
}

void Arbol_AVL::MostrarArbol(NodoArbol* arbol, int cont) {
	if (arbol == nullptr) {
		return;
	}
	else {
		MostrarArbol(arbol->izquierda, cont + 1);
		for (int i = 0; i < cont; i++) {
			cout << "	";
		}
		cout << arbol->ID << endl;
		MostrarArbol(arbol->derecha, cont + 1);
	}
}

void Arbol_AVL::MenuUsuario() {
	int opcion, contador = 0;
	string Nombre, Descripcion, Pregunta;
	Metodos* metodo = new Metodos();
	do {
		cout << "----------Men�----------" << endl;
		cout << "Opci�n 1: Agregar Activo" << endl;
		cout << "Opci�n 2: Eliminar Activo" << endl;
		cout << "Opci�n 3: Modificar Activo" << endl;
		cout << "Opci�n 4: Rentar Activo" << endl;
		cout << "Opci�n 5: Mis Activos Rentados" << endl;
		cout << "Opci�n 6: Cerrar Sesion" << endl;
		cin >> opcion;
		Raiz = nullptr; //Se reinicia el nodo ra�z para realizar nueva inserci�n 
		//En vez de reiniciar Raiz debo buscar un m�todo que busq
		switch (opcion)
		{
		case 1:
			while (opcion == 1) {
				cout << "Ingrese Nombre del Activo" << endl;
				cin >> Nombre;
				cout << "Ingrese Descripcion" << endl;
				cin >> Descripcion;
				InsertarNodoAVL(Nombre, Descripcion);
				cout << "Activo Agregado" << endl;
				cout << "�Desea Agregar otro Activo?	s/n" << endl;
				cin >> Pregunta;
				opcion = metodo->salir(Pregunta);
			}
			if (Raiz != nullptr) {
				MostrarArbol(Raiz, contador);
				system("pause");
			}
			break;
		case 2:
			break;
		case 4:
			break;
		case 5:
			break;
		}

	} while (opcion != 6);
	system("cls");
}

void Arbol_AVL::graficar()
{
	FILE* file;
	errno_t err;
	err = fopen_s(&file, "AVL.dot", "w+");
	if (err != 0) {
		printf("Archivo no Abierto \n");
	}
	else {
		if (!file) {
			cout << "Error al escribir dot" << endl;
		}
		else {
			fprintf(file, "digraph G{\n");
			getDot(file, Raiz);
			fprintf(file, "}");
			fclose(file);

			system("dot -Tpng AVL.dot -o AVLI.jpg");

			system("start cmd /c \"AVLI.jpg \"");
		}
	}
}

void Arbol_AVL::getDot(FILE* file, NodoArbol* Raiz)
{
	NodoArbol* aux = Raiz;
	const string espacio = ", ";
	if (aux == nullptr) {
		return;
	}
	else {
		MostrarArbol(Raiz->izquierda, cont + 1);
		for (int i = 0; i < cont; i++) {
			cout << "	";
		}
		string label = aux->ID + "[label=\"" + aux->ID + espacio + aux->Nombre + espacio + "\"];\n";
		const char* clabel = label.c_str();
		fprintf(file, clabel);
		MostrarArbol(Raiz->derecha, cont + 1);
	}
}
