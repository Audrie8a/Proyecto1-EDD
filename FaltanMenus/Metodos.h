#pragma once
#include <iostream>
using namespace std;
class Metodos
{
public:
	//Métodos par genera ID alfanumérico de 15 caracteres
	string generarID();
	char getRandoomChar();
	char getRandoomNumber();
	string Mayor_Menor(string ID, string IDactual);

	//Método para salir

	int salir(string Pregunta);
};
