#include "Matriz.h"
#include "Metodos.h"
using namespace std;


void Matriz::InsertarElemento(string nombre, string usuario, string contrasena, int numero, string empresa, string departamento) {
	Nodo* NodoUrs;
	Nodo* NodoDepa;
	Nodo* NodoEmpresa;
	NodoUrs = new Nodo(nombre, usuario, contrasena, numero,nullptr);

	//SE COMPRUEBA LA EXISTENCIA DE ENCABEZADOS	
	NodoDepa = buscarDepa(departamento, Cabecera);
	NodoEmpresa = buscarEmpresa(empresa, Cabecera);
	if (NodoDepa == nullptr) {
		NodoDepa = crearDepartamento(departamento);
	}
	if (NodoEmpresa == nullptr) {
		NodoEmpresa = crearEmpresa(empresa);
	}
	//Insertar En Nodo Departamento
		//insertar al inicio
	if (NodoDepa->Abajo == nullptr) {
		NodoDepa->Abajo = NodoUrs;
		NodoUrs->Arriba = NodoDepa;
	}
	else if (NodoEmpresa->Abajo == nullptr)	//Condición para saber si se inserta al final
	{
		Nodo* aux = NodoDepa->Abajo;

		while (aux->Abajo != nullptr) {
			aux = aux->Abajo;
		}
		if (!VerificarEmpresa(empresa, aux, NodoUrs)) {
			aux->Abajo = NodoUrs;
			NodoUrs->Arriba = aux;

		}
	}
	else {	//insertar en medio
		Nodo* aux = NodoDepa;
		do {
			aux = aux->Abajo;
			if (!VerificarEmpresa(empresa, aux, NodoUrs)) {
				Nodo* auxEmpr = aux->Anterior;
				while (auxEmpr->Anterior != nullptr) {
					auxEmpr = auxEmpr->Anterior;
				}
				while (auxEmpr->Arriba != nullptr) {
					if (auxEmpr->Nombre == empresa) {
						NodoUrs->Abajo = aux;
						NodoUrs->Arriba = aux->Arriba;

						aux->Arriba->Abajo = NodoUrs;
						aux->Arriba = NodoUrs;
						break;
					}

					auxEmpr = auxEmpr->Arriba;
				}
			}

		} while (aux->Abajo != nullptr && NodoUrs->Arriba == nullptr);

		if (NodoUrs->Arriba == nullptr && NodoUrs->Adelante == nullptr) {
			aux->Abajo = NodoUrs;
			NodoUrs->Arriba = aux;
		}
	}
	if (NodoUrs->Adelante != nullptr) {
		return;
	}



	//Insertar en Nodo Empresa
		//insertar al inicio
	if (NodoEmpresa->Siguiente == nullptr) {
		NodoEmpresa->Siguiente = NodoUrs;
		NodoUrs->Anterior = NodoEmpresa;
	}
	else if (NodoDepa->Siguiente == nullptr) {	 //Insertar al final
		Nodo* aux = NodoEmpresa->Siguiente;
		while (aux->Siguiente != nullptr) {
			aux = aux->Siguiente;
		}
		if (!VerificarDepartamento(departamento, aux, NodoUrs)) {
			aux->Siguiente = NodoUrs;
			NodoUrs->Anterior = aux;
		}
	}
	else {	//Insertar en medio
		Nodo* aux = NodoEmpresa;
		do {
			aux = aux->Siguiente;
			if (!VerificarDepartamento(departamento, aux, NodoUrs)) {
				Nodo* auxDepa = aux->Arriba;
				while (auxDepa->Arriba != nullptr) {
					auxDepa = auxDepa->Arriba;

				}
				while (auxDepa->Anterior != nullptr) {
					if (auxDepa->Nombre == departamento) {
						NodoUrs->Siguiente = aux;
						NodoUrs->Anterior = aux->Anterior;

						aux->Anterior->Siguiente = NodoUrs;
						aux->Anterior = NodoUrs;
						break;
					}
					auxDepa = auxDepa->Anterior;
				}
			}
		} while (aux->Siguiente != nullptr && NodoUrs->Anterior == nullptr);

		if (NodoUrs->Anterior == nullptr && NodoUrs->Adelante == nullptr) {
			aux->Siguiente = NodoUrs;
			NodoUrs->Anterior = aux;
		}
	}



}
//----------------------------------------------------------------------------
Nodo* Matriz::crearEmpresa(string Emp) {
	Nodo* Empresa;
	Empresa = new Nodo(Emp, "Empresa", Emp, -1,nullptr);
	Nodo* aux = Cabecera;
	while (aux->Abajo != nullptr) {
		aux = aux->Abajo;
	}
	aux->Abajo = Empresa;
	Empresa->Arriba = aux;
	return Empresa;
}

Nodo* Matriz::crearDepartamento(string departamento) {
	Nodo* depa;
	depa = new Nodo(departamento, "Departamento", departamento, -1,nullptr);
	Nodo* aux = Cabecera;
	while (aux->Siguiente != nullptr) {
		aux = aux->Siguiente;
	}
	aux->Siguiente = depa;
	depa->Anterior = aux;
	return depa;
}
//---------------------------------------------------------------------------
Nodo* Matriz::buscarEmpresa(string empresa, Nodo* inicio) {
	Nodo* aux = inicio;
	while (aux != nullptr) {
		if (aux->Nombre == empresa) {
			return aux;
		}
		aux = aux->Abajo;
	}
	return nullptr;
}

Nodo* Matriz::buscarDepa(string departamento, Nodo* inicio) {
	Nodo* aux = inicio;
	while (aux != nullptr) {
		if (aux->Nombre == departamento) {
			return aux;
		}
		aux = aux->Siguiente;
	}
	return nullptr;
}

//---------------------------------------------------------------------------

bool Matriz::VerificarEmpresa(string empresa, Nodo* Inicio, Nodo* Usr) {
	Nodo* auxEmp = Inicio->Anterior;
	while (auxEmp->Anterior != nullptr) {
		auxEmp = auxEmp->Anterior;
	}

	if (auxEmp->Nombre == empresa) {	//No recorremos y lo insertamos en frente
		while (Inicio->Atras != nullptr) {
			Inicio = Inicio->Atras;
			/*if (Inicio->Nombre==Usr->Nombre) {		//minuto 22:37 P2
				return NULL;
			}*/
		}
		Inicio->Atras = Usr;
		Usr->Adelante = Inicio;
		return true;
	}
	return false;
}

bool Matriz::VerificarDepartamento(string departamento, Nodo* Inicio, Nodo* Usr) {
	Nodo* auxDep = Inicio->Arriba;

	while (auxDep->Arriba != nullptr) {
		auxDep = auxDep->Arriba;
	}

	if (auxDep->Nombre == departamento) {	//No recorremos y lo insertamos en frente
		while (Inicio->Atras != nullptr) {
			Inicio = Inicio->Atras;
		}
		Inicio->Atras = Usr;
		Usr->Adelante = Inicio;

		return true;
	}
	return false;
}

//---------------------------------------------------------------------------

void Matriz::RegistroUsuario() {		//Menú para el registro de usuarios.
	Metodos* metodo = new Metodos();
	int opcion = 1;
	string Usuario, Nombre, contrasena, Departamento, Empresa, Pregunta;
	while (opcion == 1) {
		cout << "------------REGISTRAR USUARIO----------------" << endl;
		cout << "Ingrese Usuario" << endl;
		cin >> Usuario;
		cout << "Ingrese Nombre completo del Usuario" << endl;
		cin >> Nombre;
		cout << "Ingrese Contraseña del Usuario" << endl;
		cin >> contrasena;
		cout << "Ingrese Empresa a la que pertenece el Usuario" << endl;
		cin >> Empresa;
		cout << "Ingrese Departamento al que pertenece el Usuario" << endl;
		cin >> Departamento;
		InsertarElemento(Nombre, Usuario, contrasena, 2, Empresa, Departamento);
		cout << "Usuario Agregado" << endl;
		cout << "¿Desea Agregar otro Usuario?	s/n" << endl;
		cin >> Pregunta;
		opcion = metodo->salir(Pregunta);
	}
}

Nodo* Matriz::BuscarUsuario(string usuario, string contrasena, string Empresa, string Departamento)
{
	int contador = 0;
	Nodo* Respuesta = nullptr;
	Nodo* Aux = Cabecera;
	try {
		if (Aux != nullptr) {
			if (Cabecera->Usuario == usuario && Cabecera->Contrasena == contrasena) {		//El administrador es el que se está buscando
				return Cabecera;
			}
			else {
				Aux = Aux->Siguiente;
				do {
					if (Aux->Nombre == Departamento) {		//Encuentra departamento
						Nodo* Aux2 = Cabecera->Abajo;
						do {
							contador++;
							if (Aux2->Nombre == Empresa) {		//Encuentra Empresa
								while (contador != 0) {
									contador--;
									Aux = Aux->Abajo;
								}
								do {
									if (Aux->Usuario == usuario && Aux->Contrasena == contrasena) {		//Es la primer posición del eje z
										return Respuesta = Aux;
									}
									else if (Aux->Atras != nullptr) {		//Recorre el eje z
										do {
											if (Aux->Usuario == usuario && Aux->Contrasena == contrasena) {
												return Respuesta = Aux;
											}
											else {
												cout << "No se encontró ningún usuario con ese nombre de usuario y contraseña" << endl;
												return Respuesta = nullptr;

											}
											Aux = Aux->Atras;
										} while (Aux != nullptr);
									}
									else {			//no encontró nada en el eje z
										return Respuesta = nullptr;

									}
									Aux = Aux->Abajo;
								} while (Aux != nullptr);
							}
							Aux2 = Aux2->Abajo;
						} while (Aux2 != nullptr);

					}
					Aux = Aux->Siguiente;
				} while (Aux != nullptr);
			}

		}
		else if (Aux->Siguiente == nullptr && Aux->Abajo == nullptr) {			//En caso que la matriz aún este vacía
			cout << "Aún no se han registrado Usuarios, ingrese correctamente con el Administrador" << endl;
		}
	}
	catch (exception) { cout << "No se ingresaron correctamento los datos" << endl; }
	

	return Respuesta;
}

void Matriz::graficar()
{
	FILE* file;
	errno_t err;
	err = fopen_s(&file, "Matriz.dot", "w+");
	if (err != 0) {
		printf("Archivo no Abierto \n");
	}
	else {
		if (!file) {
			cout << "Error al escribir dot" << endl;
		}
		else {
			std::fprintf(file, "digraph G{\n");
			getDot(file, Cabecera);
			std::fprintf(file, "}");
			fclose(file);

			std::system("dot -Tpng Matriz.dot -o MatrizI.jpg");

			//system("nohup display ruta_y_nombre_de_imagen_generada.png &");x
			std::system("start cmd /c \"MatrizI.jpg \"");
		}
	}
}

void Matriz::getDot(FILE* file, Nodo* Cabeza)
{
	const string espacio = ", ";

	//---------------------------------------------------------------------------Graficar Departamentos
	Nodo* aux = Cabeza;
	if (aux == nullptr) {
		return;
	}
	do {

		string departamentos = aux->Nombre + "[label=\"" + aux->Nombre + "\"];\n";
		const char* cDepa = departamentos.c_str();
		std::fprintf(file, cDepa);

		string enlacesDepa = aux->Nombre + "->" + aux->Siguiente->Nombre + "\n";
		enlacesDepa += aux->Siguiente->Nombre + "->" + aux->Nombre + "\n";
		const char* cEnlaces = enlacesDepa.c_str();
		std::fprintf(file, cEnlaces);

		aux = aux->Siguiente;
	} while (aux->Siguiente != nullptr);
	//---------------------------------------------------------------------------Graficar Empresas
	Nodo* auxEmp = Cabeza;

	if (auxEmp == nullptr) {
		return;
	}
	do {

		string empresas = auxEmp->Nombre + "[label=\"" + auxEmp->Nombre + "\"];\n";
		const char* cEmp = empresas.c_str();
		std::fprintf(file, cEmp);

		string enlacesEmp = auxEmp->Nombre + "->" + auxEmp->Abajo->Nombre + "\n";
		enlacesEmp += auxEmp->Abajo->Nombre + "->" + auxEmp->Nombre + "\n";
		const char* cEnlaces = enlacesEmp.c_str();
		std::fprintf(file, cEnlaces);

		auxEmp = auxEmp->Abajo;
	} while (auxEmp->Abajo != nullptr);
	//---------------------------------------------------------------------------Graficar Nodos

	Nodo* auxNodo = Cabeza->Siguiente->Abajo;

	if (auxNodo == nullptr) {
		return;
	}

	if (auxNodo->Abajo == nullptr) {
		Nodo* auxNodoSiguiente = auxNodo;

		string Usuarios = auxNodo->Nombre + "[label=\"" + auxNodo->Nombre + "\"];\n";
		const char* cEmp = Usuarios.c_str();
		std::fprintf(file, cEmp);

		if (auxNodoSiguiente->Siguiente != nullptr) {
			do {
				string enlacesUsr = auxNodoSiguiente->Nombre + "->" + auxNodoSiguiente->Siguiente->Nombre + "\n";
				enlacesUsr += auxNodoSiguiente->Siguiente->Nombre + "->" + auxNodoSiguiente->Nombre + "\n";
				enlacesUsr = auxNodoSiguiente->Nombre + "->" + auxNodoSiguiente->Arriba->Nombre + "\n";
				enlacesUsr += auxNodoSiguiente->Arriba->Nombre + "->" + auxNodoSiguiente->Nombre + "\n";
				const char* cEnlaces = enlacesUsr.c_str();
				std::fprintf(file, cEnlaces);

				if (auxNodoSiguiente->Anterior->Anterior == nullptr) {
					enlacesUsr += auxNodoSiguiente->Nombre + "->" + auxNodoSiguiente->Anterior->Nombre + "\n";
					enlacesUsr += auxNodoSiguiente->Anterior->Nombre + "->" + auxNodoSiguiente->Nombre + "\n";
					const char* cEnlaces = enlacesUsr.c_str();
					std::fprintf(file, cEnlaces);
				}



				auxNodoSiguiente = auxNodoSiguiente->Siguiente;
			} while (auxNodoSiguiente->Siguiente != nullptr);

		}
	}
	else if (auxNodo->Abajo != nullptr) {
		while (auxNodo->Abajo != nullptr) {

			Nodo* auxNodoSiguiente = auxNodo;

			if (auxNodoSiguiente->Siguiente != nullptr) {
				do {
					string enlacesUsr = auxNodoSiguiente->Nombre + "->" + auxNodoSiguiente->Siguiente->Nombre + "\n";
					enlacesUsr += auxNodoSiguiente->Siguiente->Nombre + "->" + auxNodoSiguiente->Nombre + "\n";
					enlacesUsr += auxNodoSiguiente->Nombre + "->" + auxNodoSiguiente->Arriba->Nombre + "\n";
					enlacesUsr += auxNodoSiguiente->Arriba->Nombre + "->" + auxNodoSiguiente->Nombre + "\n";

					if (auxNodoSiguiente->Anterior->Anterior == nullptr) {
						enlacesUsr += auxNodoSiguiente->Nombre + "->" + auxNodoSiguiente->Anterior->Nombre + "\n";
						enlacesUsr += auxNodoSiguiente->Anterior->Nombre + "->" + auxNodoSiguiente->Nombre + "\n";
						const char* cEnlaces = enlacesUsr.c_str();
						std::fprintf(file, cEnlaces);
					}
					else {
						const char* cEnlaces = enlacesUsr.c_str();
						std::fprintf(file, cEnlaces);
					}

					auxNodoSiguiente = auxNodoSiguiente->Siguiente;

				} while (auxNodoSiguiente->Siguiente != nullptr);

				string enlacesUsr = auxNodoSiguiente->Nombre + "->" + auxNodoSiguiente->Arriba->Nombre + "\n";
				enlacesUsr += auxNodoSiguiente->Arriba->Nombre + "->" + auxNodoSiguiente->Nombre + "\n";

				const char* cEnlaces = enlacesUsr.c_str();
				std::fprintf(file, cEnlaces);

				auxNodo = auxNodo->Abajo;
			}
			else {
				string Usuarios = auxNodoSiguiente->Nombre + "[label=\"" + auxNodoSiguiente->Nombre + "\"];\n";
				const char* cEmp = Usuarios.c_str();
				std::fprintf(file, cEmp);

				string enlacesUsr = auxNodoSiguiente->Nombre + "->" + auxNodoSiguiente->Arriba->Nombre + "\n";
				enlacesUsr += auxNodoSiguiente->Arriba->Nombre + "->" + auxNodoSiguiente->Nombre + "\n";
				enlacesUsr += auxNodoSiguiente->Nombre + "->" + auxNodoSiguiente->Anterior->Nombre + "\n";
				enlacesUsr += auxNodoSiguiente->Anterior->Nombre + "->" + auxNodoSiguiente->Nombre + "\n";

				auxNodo = auxNodo->Abajo;
			}
		}

		if (auxNodo->Siguiente != nullptr) {
			do {
				string enlacesUsr = auxNodo->Nombre + "->" + auxNodo->Siguiente->Nombre + "\n";
				enlacesUsr += auxNodo->Siguiente->Nombre + "->" + auxNodo->Nombre + "\n";
				enlacesUsr += auxNodo->Nombre + "->" + auxNodo->Arriba->Nombre + "\n";
				enlacesUsr += auxNodo->Arriba->Nombre + "->" + auxNodo->Nombre + "\n";

				if (auxNodo->Anterior->Anterior == nullptr) {
					enlacesUsr += auxNodo->Nombre + "->" + auxNodo->Anterior->Nombre + "\n";
					enlacesUsr += auxNodo->Anterior->Nombre + "->" + auxNodo->Nombre + "\n";
					const char* cEnlaces = enlacesUsr.c_str();
					std::fprintf(file, cEnlaces);
				}
				else {
					const char* cEnlaces = enlacesUsr.c_str();
					std::fprintf(file, cEnlaces);
				}

				auxNodo = auxNodo->Siguiente;

			} while (auxNodo->Siguiente != nullptr);

			string enlacesUsr = auxNodo->Nombre + "->" + auxNodo->Arriba->Nombre + "\n";
			enlacesUsr += auxNodo->Arriba->Nombre + "->" + auxNodo->Nombre + "\n";

			const char* cEnlaces = enlacesUsr.c_str();
			std::fprintf(file, cEnlaces);
		}
		else {
			string Usuarios = auxNodo->Nombre + "[label=\"" + auxNodo->Nombre + "\"];\n";
			const char* cEmp = Usuarios.c_str();
			std::fprintf(file, cEmp);

			string enlacesUsr = auxNodo->Nombre + "->" + auxNodo->Arriba->Nombre + "\n";
			enlacesUsr += auxNodo->Arriba->Nombre + "->" + auxNodo->Nombre + "\n";
			enlacesUsr += auxNodo->Nombre + "->" + auxNodo->Anterior->Nombre + "\n";
			enlacesUsr += auxNodo->Anterior->Nombre + "->" + auxNodo->Nombre + "\n";

			auxNodo = auxNodo->Abajo;
		}
	}



}


void Matriz::MenuUsuario(){
	int opcion, contador = 0;
	int Respuesta2;		//SOLO LA USO PARA PRUEBAS
	int Respuesta,  tiempo;
	string Identificador, Fecha, TiempoRenta;

	string Nombre, Descripcion, Pregunta;
	Metodos* metodo = new Metodos();
	Arbol_AVL* arbol = getUsuario()->getAVL();
	if (arbol==NULL) {
		getUsuario()->setAVL(new Arbol_AVL());		
		arbol = getUsuario()->getAVL();
		arbol->Raiz = nullptr;
	}
	else {
		arbol = getUsuario()->getAVL();
	}
	
	
	do {
		cout << "----------Menú----------" << endl;
		cout << "Opción 1: Agregar Activo" << endl;
		cout << "Opción 2: Eliminar Activo" << endl;
		cout << "Opción 3: Modificar Activo" << endl;
		cout << "Opción 4: Rentar Activo" << endl;
		cout << "Opción 5: Mis Activos Rentados" << endl;
		cout << "Opción 6: Cerrar Sesion" << endl;
		cout << "Opción 19: Cargar Activos Prueba" << endl;
		cin >> opcion;

		
		switch (opcion) {
		case 1:
			while (opcion == 1) {
				cout << "Ingrese Nombre del Activo" << endl;
				cin >> Nombre;
				cout << "Ingrese Descripcion" << endl;
				cin >> Descripcion;
				arbol->InsertarNodoAVL(Nombre, Descripcion, true);				
				cout << "Activo Agregado" << endl;
				cout << "¿Desea Agregar otro Activo?	s/n" << endl;
				cin >> Pregunta;
				opcion = metodo->salir(Pregunta);
			}
			if (arbol->Raiz != nullptr) {
				arbol->MostrarArbol(arbol->Raiz, contador);
				std::system("pause");
			}
			break;
		case 2:
			break;
		case 4:
			cout << "%%%%%%%%%%%%%%%%%%% CATALOGO ACTIVOS %%%%%%%%%%%%%%%%%%%%%%" << endl;
			ListarActivosDisponibles();
			cout << "----------Menú----------" << endl;
			cout << "Opción 1: Rentar Activo" << endl;
			cout << "Opción 2: Regresar a Menú" << endl;
			cin >> Respuesta;
			if (Respuesta==1) {				
				cout << "------------Rentando Activo----------" << endl;
				cout << "Ingrese el ID del activo a rentar:" << endl;
				cin >> Identificador;
				BuscarArbol(Identificador);
				cout << "Ingrese la fecha en la que se está rentando" << endl;
				cin >> Fecha;
				cout << "Ingrese número de días que desea rentar" << endl;
				cin >> tiempo;
				LCD->InsertarTransaccion(Identificador,getUsuario()->Usuario,BuscarDepartamentoUsuario(getUsuario()), BuscarEmpresaUsuario(getUsuario()),Fecha,tiempo );
				MenuUsuario();
				LCD->graficar();
			}
			else if(Respuesta==2){
				MenuUsuario();
			}
			else {
				cout << "Opción no válida" << endl;
				MenuUsuario();
			}

			break;
		}

	} while (opcion != 6);
	std::system("cls");
}

void Matriz::ListarActivosDisponibles()
{
	Nodo* Aux = Cabecera;
	Nodo* Aux2;
	Nodo* AuxAbajo = Cabecera;
	NodoArbol* NodoAVL = nullptr;
	if (Aux->Siguiente->Abajo!=nullptr) {
		Aux = Aux->Siguiente->Abajo;
		do {
			Aux2 = Aux;
			do {
				constructorAVL = Aux2->getAVL();
				if (constructorAVL!=NULL) {
					NodoAVL = Aux2->getAVL()->getRaiz();
					constructorAVL->MostrarActivosArbol(NodoAVL);
				}
				Aux2 = Aux2->Siguiente;
			} while (Aux2 != nullptr);
			Aux=Aux->Abajo;
		} while (Aux!= nullptr);
		
	}


}

void Matriz::BuscarArbol(string ID)
{
	
	Nodo* Aux = Cabecera;
	Nodo* Aux2;
	Nodo* AuxAbajo = Cabecera;
	NodoArbol* NodoAVL = nullptr;
	if (Aux->Siguiente->Abajo != nullptr) {
		Aux = Aux->Siguiente->Abajo;
		do {
			Aux2 = Aux;
			do {
				constructorAVL = Aux2->getAVL();
				if (constructorAVL != NULL) {
					NodoAVL = Aux2->getAVL()->getRaiz();
					constructorAVL->CambiarEstadoNodo(ID, NodoAVL);
					
				}
				Aux2 = Aux2->Siguiente;
			} while (Aux2 != nullptr);
			Aux = Aux->Abajo;
		} while (Aux != nullptr);

	}
}

string Matriz::BuscarEmpresaUsuario(Nodo* User)
{
	Nodo* Aux;
	do {
		Aux = User;
		User=User->Anterior;
	} while (User != nullptr);
	return Aux->Nombre;
}

string Matriz::BuscarDepartamentoUsuario(Nodo* user)
{
	Nodo* Aux;
	do {
		Aux = user;
		user = user->Arriba;
	} while (user != nullptr);
	return Aux->Nombre;
}
