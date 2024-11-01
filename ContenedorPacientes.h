#pragma once
#include "Librerias.h"
#include "Persona.h"
#include "Pacientes.h"


class ContenedorPacientes
{
private:
	vector<Pacientes*> listaPacientes;


public:

	//Esto devuelve la referencia de Pacientes* que es un vector de punteros
	const vector<Pacientes*>& getListaPacientes() const
	{
		return listaPacientes;
	}


	void setRegistrarPaciente()
	{
		int cedula, telefono;
		string nombre, correo, apellido, fechaRegistro;


		cout << "Ingrese la cedula del paciente: ";
		cin >> cedula;


		if (cedula < 0 || cedula > 2222222222)
		{
			cout << "Cedula no valida, ingrese un numero positivo de hasta 10 digitos " << endl;
			return;
		}
		for (int i = 0; i < listaPacientes.size(); i++)
		{
			if (listaPacientes[i]->getCedula() == cedula)
			{ //se compara codigo, si este se repite imprimira que ya existe un paciente con la misma identificacion 
				cout << "Ya hay un paciente registrado con esta cedula." << endl;
				return;
			}
		}
		cin.ignore();
		do {

			cout << "Ingrese el nombre del paciente: ";
			getline(cin, nombre);

			cout << "Ingrese el apellido del paciente: ";
			getline(cin, apellido);

			cout << "Ingrese el telefono del paciente: ";
			cin >> telefono;

			cin.ignore();

			cout << "Ingrese el correo del paciente: ";
			getline(cin, correo);

			cout << "Ingrese la fecha de registro del paciente: ";
			getline(cin, fechaRegistro);

			if ((cedula <= 0) || nombre.empty() || apellido.empty() || (telefono <= 0) || correo.empty() || fechaRegistro.empty())
			{
				cout << "No se permiten campos vacios" << endl;
				return;
			}
		} while ((cedula <= 0) || nombre.empty() || apellido.empty() || (telefono <= 0) || correo.empty() || fechaRegistro.empty());


		Pacientes* newPaciente = new Pacientes(cedula, nombre, telefono, correo, apellido, fechaRegistro);
		listaPacientes.push_back(newPaciente);

		cout << "Paciente registrado con exito!!" << endl;

		cout << "............. Lista de pacientes registrados................." << endl;
		for (int i = 0; i < listaPacientes.size(); i++)
		{
			listaPacientes[i]->getMostrarDatos();
		}
		cout << "............................................................" << endl;
	}

	void setModificarPacientes()
	{
		int cedula, telefono;
		string nombre, correo, apellido, fechaRegistro;
		bool verificar = false;

		if (listaPacientes.empty())
		{
			cout << "No hay datos que mostrar... Agrega un paciente para actualizar." << endl;
			return;
		}

		cout << "Ingrese su número de cédula: ";
		cin >> cedula;
		cin.ignore();

		if (cedula < 0 || cedula > 2222222222)
		{
			cout << "Cédula no válida, ingrese un número positivo de hasta 10 dígitos." << endl;
			return;
		}

		for (int i = 0; i < listaPacientes.size(); i++)
		{
			// Verificar si la cédula ingresada coincide con un paciente existente
			if (listaPacientes[i]->getCedula() == cedula)
			{
				verificar = true;

				cout << "Ingrese el nombre del paciente: ";
				getline(cin, nombre);

				cout << "Ingrese el apellido del paciente: ";
				getline(cin, apellido);

				cout << "Ingrese el teléfono del paciente: ";
				cin >> telefono;
				cin.ignore();

				cout << "Ingrese el correo del paciente: ";
				getline(cin, correo);

				cout << "Ingrese la fecha de registro del paciente: ";
				getline(cin, fechaRegistro);

				// Validar que no haya campos vacíos ni valores inválidos
				if (nombre.empty() || apellido.empty() || telefono <= 0 || correo.empty() || fechaRegistro.empty())
				{
					cout << "No se permiten campos vacíos o valores inválidos." << endl;
					return;
				}

				// Actualizar los datos del paciente encontrado
				listaPacientes[i]->setNombre(nombre);
				listaPacientes[i]->setApellido(apellido);
				listaPacientes[i]->setTelefono(telefono);
				listaPacientes[i]->setCorreo(correo);
				listaPacientes[i]->setFechaRegistro(fechaRegistro);

				cout << "¡Paciente modificado con éxito!" << endl;

				cout << "............. Lista de pacientes registrados................." << endl;
				for (int j = 0; j < listaPacientes.size(); j++)
				{
					listaPacientes[j]->getMostrarDatos();
				}
				cout << "............................................................" << endl;
				return;
			}
		}

		if (!verificar)
		{
			cout << "No existe un paciente registrado con esa cédula." << endl;
		}
	}

	void consultarPaciente()
	{

		if (listaPacientes.empty())
		{
			cout << "No hay datos para mostrar..." << endl;
			return;
		}

		int opcion;
		cout << "..........Digite una opcion.........." << endl;
		cout << "1. Para ver todos los pacientes " << endl;
		cout << "2. Para buscar pacientes por fecha de registro" << endl;
		cout << "Digite una opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
		{
			cout << ".............. Lista de Pacientes .............." << endl;
			for (int i = 0; i < listaPacientes.size(); i++) 
			{
				listaPacientes[i]->getMostrarDatos();
			}//fin del for
			cout << "................................................" << endl;
			//fin del else
			cout << "Total de pacientes registrados: " << listaPacientes.size() << endl;
			break;
		}
		case 2:
		{
			string fechaBusqueda;
			bool encontrado = false; 
			int contador = 0; 

			cout << "Ingrese la fecha de registro que desea buscar (Formato: DD/MM/AAAA): ";
			getline(cin, fechaBusqueda);

			cout << "............. Pacientes registrados el " << fechaBusqueda << " ................." << endl;

			for (int i = 0; i < listaPacientes.size(); i++)
			{
				if (listaPacientes[i]->getFechaRegistro() == fechaBusqueda)
				{
					listaPacientes[i]->getMostrarDatos();  // Mostrar los datos del paciente
					encontrado = true; 
					contador++; 
				}
			}

			if (!encontrado)
			{
				cout << "No se encontraron pacientes registrados en esa fecha..." << endl;
			}
			else
			{
				cout << "Los pacientes registrados el dia " << fechaBusqueda << ": " << contador << endl;
			}

			cout << "............................................................" << endl;
			break;
		}
		default:
		{
			cout << "Opcion no valida, intentelo de nuevo..." << endl;
			break;
			}
		}
	}

	void guardarArchivo()
	{
		ofstream archivo("pacientes.txt");
		if (archivo.is_open())
		{
			for (int i = 0; i < listaPacientes.size(); i++)
			{
				archivo << listaPacientes[i]->getCedula()
					<< "-" << listaPacientes[i]->getNombre()
					<< "-" << listaPacientes[i]->getApellido()
					<< "-" << listaPacientes[i]->getTelefono()
					<< "-" << listaPacientes[i]->getCorreo()
					<< "-" << listaPacientes[i]->getFechaRegistro()
					<< endl;
			}
			archivo.close();
			cout << "Paciente fue guardado correctamente....";
		}
		else
		{
			cout << "Error al abrir el archivo." << endl;
		}
	}

	void recuperarArchivos()
	{
		listaPacientes.clear();
		ifstream archivo("pacientes.txt");

		if (archivo.is_open())
		{

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
				int _telefono = stoi(telefono);

				getline(ss, correo, '-');

				getline(ss, fechaRegistro, '-');

				Pacientes* paciente = new Pacientes(_cedula, nombre, _telefono, correo, apellido, fechaRegistro);
				listaPacientes.push_back(paciente);
			}
			archivo.close();
			cout << "Datos cargados correctamente..." << endl;
		}
		else
		{
			cout << "Error al abrir el archivo." << endl;
		}
	}

	void menuPacientes()
	{

		int opcion;

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
				recuperarArchivos();
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
				consultarPaciente();
				system("pause");
				break;
			}
			case 4:
			{
				guardarArchivo();
				system("pause");
				break;
			}
			case 5:
			{
				recuperarArchivos();
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
