#pragma once
#include "Librerias.h"
#include "Medicos.h"

class ContenedorMedicos
{
private:
	vector<Medicos*> listaMedicos; // se utiliza un vector de punteros a objeto de tipo medico

public:
	void setRegistrarMedico()
	{
		int codigo;
		string nombre, telefono, correo;
		bool disponibilidad;


		cout << "Ingrese el codigo del medico: ";
		cin >> codigo;

		if (codigo < 0 || codigo > 2222) //se valida que el codigo sea un numero positivo de hasta 4 digitos y no sea negativo
		{
			cout << "Codigo no valido, ingrese un numero positivo de hasta 4 digitos " << endl;
			return;
		}

		for (int i = 0; i < listaMedicos.size(); i++) {
			if (listaMedicos[i]->getCodigo() == codigo) { //se compara codigo, si este se repite imprimira que ya existe un medico con este mismo codigo 
				cout << "Ya hay un medico registrado con este codigo." << endl;
				return;
			}
		}

		cout << "Ingrese el nombre del medico: ";
		cin >> nombre;

		cout << "Ingrese el telefono del medico: ";
		cin >> telefono;

		cout << "Ingrese el correo del medico: ";
		cin >> correo;

		cout << "Ingrese la disponibilidad del medico (1 si esta disponible, 0 si no esta disponible): ";
		cin >> disponibilidad;
		if (disponibilidad == 1) {
			cout << "El medico esta disponible." << endl;
		}
		else {
			cout << "El medico no esta disponible." << endl;
		}

		// Validaciones para verificar que no se ingresen campos vacios
		if (nombre.empty() || telefono.empty() || correo.empty())
		{
			cout << "No se permiten campos vacios" << endl;
			return;
		}

		Medicos* newMedico = new Medicos(codigo, nombre, telefono, correo, disponibilidad);
		listaMedicos.push_back(newMedico); //se agrega el nuevo medico al vector de medicos

		cout << "Medico registrado con exito" << endl;

		for (int i = 0; i < listaMedicos.size(); i++)
		{
			listaMedicos[i]->getMostrarDatos();

		}

	}

	void getModificarMedico()
	{
		int codigo;
		string nuevoNombre;
		string nuevoTelefono;
		string nuevoCorreo;
		bool nuevaDisponibilidad;

		cout << "Ingrese su numero de codigo" << endl;
		cin >> codigo;
		if (codigo < 0 || codigo > 2222222222) {
			cout << "Codigo no valido, ingrese un numero positivo de hasta 10 digitos " << endl;
			return;
		}

		cout << "Ingrese el nuevo nombre del medico: " << endl;
		cin >> nuevoNombre;

		cout << "Ingrese el nuevo telefono del medico: " << endl;
		cin >> nuevoTelefono;

		cout << "Ingrese el nuevo correo del medico: " << endl;
		cin >> nuevoCorreo;

		cout << "Ingrese la nueva disponibilidad del medico (1 si esta disponible, 0 si no esta disponible): " << endl;
		cin >> nuevaDisponibilidad;
		if (nuevaDisponibilidad == 1) {
			cout << "El medico esta disponible." << endl;
		}
		else {
			cout << "El medico no esta disponible." << endl;
		}


		if (nuevoNombre.empty() || nuevoTelefono.empty() || nuevoCorreo.empty())
		{
			cout << "No se permiten campos vacios" << endl;
			return;
		}

		for (int i = 0; i < listaMedicos.size(); i++) {
			if (listaMedicos[i]->getCodigo() == codigo) {
				listaMedicos[i]->setNombre(nuevoNombre);
				listaMedicos[i]->setTelefono(nuevoTelefono);
				listaMedicos[i]->setCorreo(nuevoCorreo);
				listaMedicos[i]->setDisponibilidad(nuevaDisponibilidad);
				cout << "Medico modificado con exito" << endl;
				return;


			}
		}

		cout << "No se encontro el medico con el codigo ingresado" << endl;
	}

	void consultarMedicos()
	{
		int totalMedicos = listaMedicos.size();
		int disponibles = 0;

		cout << "Lista de medicos registrados: " << endl;
		cout << "..............................................." << endl;
		for (int i = 0; i < totalMedicos; i++)
		{
			listaMedicos[i]->getMostrarDatos();
			cout << "..............................................." << endl;

			if (listaMedicos[i]->getDisponibilidad())
			{
				disponibles++;
			}
		}
		cout << "..............................................." << endl;
		cout << "Total de medicos registrados: " << totalMedicos << endl;
		cout << "Medicos disponibles: " << disponibles << endl;
		cout << "Medicos no disponibles: " << totalMedicos - disponibles << endl;
	}

	void guardarEnArchivo()
	{
		ofstream archivo("Medicos.txt"); //se prepara el arcvhivo 
		if (archivo.is_open())
		{
			for (int i = 0; i < listaMedicos.size(); i++)
			{
				//almacena la informacion
				cout << "........................................................" << endl;
				archivo << listaMedicos[i]->getCodigo()
					<< "-" << listaMedicos[i]->getNombre()
					<< "-" << listaMedicos[i]->getTelefono()
					<< "-" << listaMedicos[i]->getCorreo()
					<< "-" << listaMedicos[i]->getDisponibilidad()
					<< endl;
				cout << "........................................................." << endl;

			}
			archivo.close(); //se cierra el archivo
			cout << "Datos guardados correctamente en el archivo Medicos.txt" << endl;
		}
		else
		{
			cout << "No se pudo abrir el archivo" << endl;
		}
	}

	void recuperarArchivo()
	{
		listaMedicos.clear();
		ifstream archivo("Medicos.txt");
		if (archivo.is_open())
		{
			string linea;
			while (getline(archivo, linea))
			{
				stringstream ss(linea);
				string codigo, nombre, telefono, correo, disponibilidad;

				getline(ss, codigo, '-');
				int _codigo = stoi(codigo);

				getline(ss, nombre, '-');

				getline(ss, telefono, '-');

				getline(ss, correo, '-');

				getline(ss, disponibilidad, '-');
				bool _disponibilidad = (disponibilidad == "1");


				Medicos* newMedico = new Medicos(_codigo, nombre, telefono, correo, _disponibilidad);
				listaMedicos.push_back(newMedico);
			}
			archivo.close();
			cout << "Datos recuperados correctamente" << endl;
		}
		else
		{
			cout << "No se pudo abrir el archivo" << endl;
		}
	}


	virtual void MenuMedicos()
	{
		int opcion;
		do
		{
			system("cls");

		cout << "......................Menu Medicos..............." << endl;
		cout << "1. Registrar nuevo medico" << endl;
		cout << "2. Modificar medicos" << endl;
		cout << "3. Consultar todos los datos" << endl;
		cout << "4. Guardar contenedor en archivo" << endl;
		cout << "5. Recuperar datos del archivo" << endl;
		cout << "6. Regresar al menu principal" << endl;
		cout << "............................................." << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
		{
			setRegistrarMedico();
			system("pause");
			break;
		}
		case 2:
		{
			getModificarMedico();
			system("pause");
			break;
		}
		case 3:
		{
			consultarMedicos();
			system("pause");
			break;
		}
		case 4:
		{
			guardarEnArchivo();
			system("pause");
			break;
		}
		case 5:
		{
			recuperarArchivo();
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Regresando al menu principal..." << endl;
			system("pause");
			break;
		}
		default:
		{
			cout << "Opcion no valida" << endl;
			break;
		}
		}

	} while (opcion != 6);
}

};
