#pragma once
#include "Librerias.h"
#include "Medicos.h"

class ContenedorMedicos
{
private:
	vector<Medicos*> listaMedicos; // se utiliza un vector de punteros a objeto de tipo medico

public:

	/vector<Medicos&> getVectorMedicos()
	{
		return listaMedicos;
	}*/
	void setRegistrarMedico()
	{
		int codigo, cedula;
		string nombre, telefono, correo;
		bool disponibilidad;

		cout << "Ingrese la cedula del medico: ";
		cin >> cedula;

		if (cedula < 0 || cedula > 2222222222)
		{
			cout << "Cedula no valida, ingrese un numero positivo de hasta 10 digitos " << endl;
			return;
		}
			for (int i = 0; i < listaMedicos.size(); i++) {
				if (listaMedicos[i]->getCedula() == cedula) { //se compara codigo, si este se repite imprimira que ya existe un medico con este mismo codigo 
					cout << "Ya hay un medico registrado con esta cedula." << endl;
					return;
				}
			}
		

		    cout << "Ingrese el codigo del medico: " << endl;
			cin >> codigo;

			if (codigo < 0 || codigo > 2222)
			{
				cout << "codigo no valido, ingrese un numero positivo de hasta 4 digitos " << endl;
				return;
			}

			cin.ignore();
			do
			{

				cout << "Ingrese el nombre del medico: ";
				getline(cin, nombre);

				cout << "Ingrese el telefono del medico: ";
				getline(cin, telefono);

				cout << "Ingrese el correo del medico: ";
				getline(cin, correo);

				cout << "Ingrese la disponibilidad del medico (1 si esta disponible, 0 si no esta disponible): ";
				cin >> disponibilidad;


				// Validaciones para verificar que no se ingresen campos vacios

				if (nombre.empty() || telefono.empty() || correo.empty())
				{
					cout << "No se permiten campos vacios, intentelo de nuevo" << endl;
				}
			} while (nombre.empty() || telefono.empty() || correo.empty());// se hace uso de metodo do-while para que se soliciten los datos al usuario hasta llene todos los campos

			Medicos* newMedico = new Medicos(cedula, nombre, telefono, correo, codigo, disponibilidad);
			listaMedicos.push_back(newMedico); //se agrega el nuevo medico al vector de medicos

			cout << "Medico registrado con exito" << endl;

			//Se muestra la lista de medicos registrados
			cout << "............. Lista de medicos registrados................." << endl;
			for (int i = 0; i < listaMedicos.size(); i++)
			{

				listaMedicos[i]->getMostrarDatos();
			}

		cout << "............................................................" << endl;
	}

	void getModificarMedico()
	{
		int cedula;
		string nuevoNombre;
		string nuevoTelefono;
		string nuevoCorreo;
		bool nuevaDisponibilidad;


		if (listaMedicos.empty())
		{
			cout << "No hay medicos registrados" << endl;
			return;
		}

		cout << "Ingrese su numero de cedula" << endl;
		cin >> cedula;
		cin.ignore();

		if (cedula < 0 || cedula > 2222222222) {
			cout << "Cedula no valida, ingrese un numero positivo de hasta 10 digitos " << endl;
			return;
		}

		for (int i = 0; i < listaMedicos.size(); i++)
		{
			if (listaMedicos[i]->getCedula() == cedula) // se verifica que la cedula ingresada por el usuario coincida con la cedula del medico ya existente
			{

				cout << "Ingrese el nuevo nombre del medico: " << endl;
				getline(cin, nuevoNombre);

				cout << "Ingrese el nuevo telefono del medico: " << endl;
				getline(cin, nuevoTelefono);

				cout << "Ingrese el nuevo correo del medico: " << endl;
				getline(cin, nuevoCorreo);

				cout << "Ingrese la nueva disponibilidad del medico (1 si esta disponible, 0 si no esta disponible): " << endl;
				cin >> nuevaDisponibilidad;
				cin.ignore();

				// Validaciones para verificar que no se ingresen campos vacios
				if (nuevoNombre.empty() || nuevoTelefono.empty() || nuevoCorreo.empty())
				{
					cout << "No se permiten campos vacios" << endl;
					return;
				}

				listaMedicos[i]->setNombre(nuevoNombre);
				listaMedicos[i]->setTelefono(nuevoTelefono);
				listaMedicos[i]->setCorreo(nuevoCorreo);
				listaMedicos[i]->setDisponibilidad(nuevaDisponibilidad);
				cout << "Medico modificado con exito" << endl;
			}

			cout << "............. Lista de medicos registrados................." << endl;
			for (int i = 0; i < listaMedicos.size(); i++)
			{

				listaMedicos[i]->getMostrarDatos();
			}
			cout << "............................................................" << endl;

			cout << "No existe un medico con esa cedula" << endl;
		}
	}

	void consultarMedicos()
	{
		int disponibilidad = 0;

		cout << "................Lista de medicos registrados................ " << endl;
		if (listaMedicos.empty())
		{
			cout << "No hay datos para mostrar..." << endl;
		}
		else
		{
			for (int i = 0; i < listaMedicos.size(); i++)
			{
				listaMedicos[i]->getMostrarDatos();
				cout << "........................................................." << endl;

				if (listaMedicos[i]->getDisponibilidad())
				{
					disponibilidad++;
				}
			}
		}
		cout << "..............................................." << endl;
		cout << "Total de medicos registrados: " << listaMedicos.size() << endl;
		cout << "Medicos disponibles: " << disponibilidad << endl;
		cout << "Medicos no disponibles: " << listaMedicos.size() - disponibilidad << endl;
		cout << "..............................................." << endl;
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
				archivo << listaMedicos[i]->getCedula()
					<< "-" << listaMedicos[i]->getNombre()
					<< "-" << listaMedicos[i]->getTelefono()
					<< "-" << listaMedicos[i]->getCorreo()
					<< "-" << listaMedicos[i]->getCodigo()
					<< "-" << (listaMedicos[i]->getDisponibilidad() ? "1" : "0") 
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
				string cedula, nombre, telefono, correo, codigo, disponibilidad;


				getline(ss, cedula, '-');
				int _cedula = stoi(cedula);

				getline(ss, nombre, '-');

				getline(ss, telefono, '-');

				getline(ss, correo, '-');

				getline(ss, codigo, '-');
				int _codigo = stoi(codigo);

				getline(ss, disponibilidad, '-');
				bool _disponibilidad = (disponibilidad == "1");


				Medicos* newMedico = new Medicos(_cedula, nombre, telefono, correo,_codigo, _disponibilidad);
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


	 void MenuMedicos()
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
			recuperarArchivo();
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
