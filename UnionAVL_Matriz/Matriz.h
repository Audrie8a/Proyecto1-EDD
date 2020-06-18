#pragma once
#include "Nodo.h"
#include "Arbol_AVL.h"
using namespace std;

class Matriz
{
public:
	Nodo* Cabecera;
	Nodo* Usuario;
	Matriz() {
		Cabecera = new Nodo("Audrie_del_Cid", "Administrador", "201801263", -1,nullptr);
		Usuario = nullptr;
	}
	
	void InsertarElemento(string nombre, string usuario, string contrasena, int numero, string empresa, string departamento);
	Nodo* crearEmpresa(string empresa);
	Nodo* crearDepartamento(string depaartamento);

	Nodo* buscarEmpresa(string empresa, Nodo* Inicio);
	Nodo* buscarDepa(string departamento, Nodo* Inicio);

	bool VerificarEmpresa(string Empresa, Nodo* Inicio, Nodo* USR);
	bool VerificarDepartamento(string Departamento, Nodo* Inicio, Nodo* USR);

	void RegistroUsuario();
	Nodo* BuscarUsuario(string usuario, string contrasena, string Empresa, string Departamento);

	void graficar();
	void getDot(FILE* file, Nodo* Cabeza);

	void setUsuario(Nodo* user) {
		this->Usuario = user;
	}

	Nodo* getUsuario() {
		return this->Usuario;
	}

	//MENÚ
	void MenuUsuario();

};
