#pragma once
#include "Librerias.h"
#include "Persona.h"
#include "Pacientes.h"


class ContenedorPacientes
{
private:
	vector<Pacientes*> listaPacientes;


public:

	void setRegistrarPaciente()
	{
		int cedula;
		string nombre, telefono, correo, apellido, fechaRegistro;


		cout << "Ingrese la cedula del paciente: ";
		cin >> cedula;


		if (cedula < 0 || cedula > 9999999999)
		{
			cout << "Cedula no valida, ingrese un numero positivo de hasta 10 digitos " << endl;
			return;
		}

		for (int i = 0; i < listaPacientes.size(); i++) {
			if (listaPacientes[i]->getCedula() == cedula) { //se compara codigo, si este se repite imprimira que ya existe un paciente con este mismo codigo 
				cout << "Ya hay un paciente registrado con esta cedula." << endl;
				return;
			}
		}

		cin.ignore();

		cout << "Ingrese el nombre del paciente: ";
		getline(cin, nombre);

		cout << "Ingrese el apellido del paciente: ";
		getline(cin, apellido);

		cout << "Ingrese el telefono del paciente: ";
		getline(cin, telefono);

		cout << "Ingrese el correo del paciente: ";
		getline(cin, correo);

		cout << "Ingrese la fecha de registro del paciente: ";
		getline(cin, fechaRegistro);

		if (nombre.empty() || apellido.empty() || telefono.empty() || correo.empty() || fechaRegistro.empty())
		{
			cout << "No se permiten campos vacios" << endl;
			return;
		}


		Pacientes* newPaciente = new Pacientes(nombre, telefono, correo, apellido, cedula, fechaRegistro);
		listaPacientes.push_back(newPaciente);

		cout << "Paciente registrado con exito!!" << endl;

		for (int i = 0; i < listaPacientes.size(); i++)
		{
			listaPacientes[i]->getMostrarDatos();
		}

	}

	void setModificarPacientes()
	{
		int cedula;
		bool buscar = false;
		string nombre, telefono, correo, apellido, fechaRegistro;

		if (listaPacientes.empty())
		{
			cout << "No hay datos que mostrar... Agrega un paciente para actualizar.. " << endl;
		}

		else
		{

			cout << "Ingrese el num° de cedula del paciente: ";
			cin >> cedula;

			for (int i = 0; i < listaPacientes.size(); i++) {
				if (listaPacientes[i]->getCedula() == cedula)
				{
					buscar = true;

					cin.ignore();

					cout << "Ingrese el nombre del paciente: ";
					getline(cin, nombre);

					cout << "Ingrese el apellido del paciente: ";
					getline(cin, apellido);

					cout << "Ingrese el telefono del paciente: ";
					getline(cin, telefono);

					cout << "Ingrese el correo del paciente: ";
					getline(cin, correo);

					cout << "Ingrese la fecha de registro del paciente: ";
					getline(cin, fechaRegistro);


					if (nombre.empty() || apellido.empty() || telefono.empty() || correo.empty() || fechaRegistro.empty())
					{
						cout << "No se permiten campos vacios" << endl;
						return;
					}

					// Actualizar los datos del paciente encontrado
					listaPacientes[i]->setNombre(nombre);
					listaPacientes[i]->setApellido(apellido);
					listaPacientes[i]->setTelefono(telefono);
					listaPacientes[i]->setCorreo(correo);
					listaPacientes[i]->setFechaRegistro(fechaRegistro);

					cout << "Paciente modificado con éxito!" << endl;
					listaPacientes[i]->getMostrarDatos();

				}
			}
			if (!buscar)
			{
				cout << "No se ha registrado un paciente con ese numero de cedula..." << endl;

			}
		}
	}


	void setMostrarListaPacientes()
	{

		if (listaPacientes.empty())
		{
			cout << "No hay datos que mostrar..." << endl;
			return;
		}

		else
		{
			cout << ".............. Lista de Pacientes .............." << endl;
			for (int i = 0; i < listaPacientes.size(); i++) {
				listaPacientes[i]->getMostrarDatos();
				cout << "................................................" << endl;
			}
		}
	}

	void guardarArchivo(const string& nombreArchivo) const
	{
		ofstream archivo(nombreArchivo);
		if (archivo.is_open())
		{
			for (int i = 0; i < listaPacientes.size(); i++)
			{
				archivo << listaPacientes[i]->getCedula() << "," <<
					listaPacientes[i]->getNombre() << "," <<
					listaPacientes[i]->getApellido() << "," <<
					listaPacientes[i]->getTelefono() << "," <<
					listaPacientes[i]->getCorreo() << "," <<
					listaPacientes[i]->getFechaRegistro() << "," << endl;
				cout << "...................................................." << endl;
			}
			archivo.close();
			cout << "Paciente fue guardado correctamente....";
		}
		else
		{
			cout << "Error al abrir el archivo para guardar los datos." << endl;
		}
	}

	void cargarArchivos(const string& nombreArchivo)
	{
		listaPacientes.clear();
		ifstream archivo(nombreArchivo);

		if (!archivo.is_open())
		{
			cout << "Error al abrir el archivo." << endl;
			return;
		}

		string linea;
		while (getline(archivo, linea))
		{
			stringstream ss(linea);
			string cedula, nombre, apellido, telefono, correo, fechaRegistro;

			getline(ss, cedula, '-');
			int _cedula = stoi(cedula);

			getline(ss, nombre, '-');

			getline(ss, apellido, '-');

			getline(ss, telefono, '-');

			getline(ss, correo, '-');

			getline(ss, fechaRegistro, '-');

			Pacientes* paciente = new Pacientes(nombre, telefono, correo, apellido, _cedula, fechaRegistro);
			listaPacientes.push_back(paciente);
		}
		archivo.close();
		cout << "Datos cargados correctamente..." << endl;
	}

	void menuPacientes()
	{

		int opcion;
		string nombreArchivo = "pacientes.txt";

		do {
			system("cls");
			cout << "......................Menu Pacientes..............." << endl;
			cout << "1. Registrar nuevo paciente" << endl;
			cout << "2. Modificar paciente" << endl;
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
				setRegistrarPaciente();
				system("pause");
				break;
			}
			case 2:
			{
				setModificarPacientes();
				system("pause");
				break;
			}
			case 3:
			{
				setMostrarListaPacientes();
				system("pause");
				break;
			}
			case 4:
			{
				guardarArchivo(nombreArchivo);
				system("pause");
				break;
			}
			case 5:
			{
				cargarArchivos(nombreArchivo);
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
				cout << "Opcion no valida." << endl;
				system("pause");
				break;
			}
			}
		} while (opcion != 6);
	}
};
