#pragma once
#include <iostream>
using namespace std;
class Metodos
{
public:
	//M�todos par genera ID alfanum�rico de 15 caracteres
	string generarID();
	char getRandoomChar();
	char getRandoomNumber();
	string Mayor_Menor(string ID, string IDactual);

	//M�todo para salir

	int salir(string Pregunta);
};


