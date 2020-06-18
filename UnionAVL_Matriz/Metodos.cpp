#include "Metodos.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <string>
using namespace std;

static const char pool[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"01234567890";
int sizePool = sizeof(pool) - 1;

static const char pool2[] =
"0123456789";
int sizePool2 = sizeof(pool2) - 1;


//Método para returnar caracteres aleatorios
char Metodos::getRandoomChar() {
	return pool[rand() % sizePool];
}
char Metodos::getRandoomNumber() {
	return pool2[rand() % sizePool2];
}

string Metodos::generarID() {
	string ID = " ";
	int longID = 10;
	srand(time(0));
	for (int j = 0; j < 5; j++) {
		ID += getRandoomNumber();
	}
	for (int i = 0; i < longID; i++) {
		ID += getRandoomChar();
	}

	return ID;
}

string Metodos::Mayor_Menor(string ID, string IDactual) {
	string Dato;
	string DatoActual;
	for (int i = 0; i <= 5; i++) {
		Dato += ID[i];
	}
	int Numero = stoi(Dato, nullptr, 10);
	for (int j = 0; j <= 5; j++) {
		DatoActual += IDactual[j];
	}
	int NumeroActual = stoi(DatoActual, nullptr, 10);
	if (Numero > NumeroActual) {
		return "Mayor";
	}
	else if (Numero < NumeroActual) {
		return "Menor";
	}
	else if (Numero = NumeroActual) {
		Numero = Numero + 1;

		string IDaux = to_string(Numero);
		string IDactualAux = to_string(NumeroActual);
		Mayor_Menor(IDaux, IDactualAux);
	}



}



int Metodos::salir(string Pregunta) {
	int opcion;
	string Respuesta;
	if (Pregunta == "s" || Pregunta == "S") {
		opcion = 1;
		return opcion;
	}
	else if (Pregunta == "N" || Pregunta == "n") {
		opcion = 2;
		cout << endl;
		return opcion;
	}
	else {
		cout << "Tecla incorrecta. Favor ingrese s/n" << endl;
		cin >> Respuesta;
		salir(Respuesta);

	}
}