#pragma once
#include <iostream>
#include "Metodos.h"
#include "Matriz.h";
#include "Arbol_AVL.h"
#include "TransaccionLCDE.h"
using namespace std;
class Menu
{
public:
	Matriz* matrix = new Matriz();
	Arbol_AVL* arbol = new Arbol_AVL();
	Metodos* metodos = new Metodos();
	TransaccionLCDE* LCD = new TransaccionLCDE();
	void MenuPrincipal();
	void iniciarSesion();
	void iniciarSesionAdmin();
	bool logicaLogin(string usuario, string contrasena, string empresa, string departamento);
	void ReporteActivoUsuario();
};