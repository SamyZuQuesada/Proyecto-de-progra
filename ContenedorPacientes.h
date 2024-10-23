#pragma once
#include "Librerias.h"
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

			cout << "Ingrese el nombre del paciente: ";
			cin >> nombre;

			cout << "Ingrese el apellido del paciente: ";
			cin >> apellido;

			cout << "Ingrese el telefono del paciente: ";
			cin >> telefono;

			cout << "Ingrese el correo del paciente: ";
			cin >> correo;

			cout << "Ingrese la fecha de registro del paciente: ";
			cin >> fechaRegistro;

			if (nombre.empty() || apellido.empty() || telefono.empty() || correo.empty() || fechaRegistro.empty())
			{
				cout << "No se permiten campos vacios" << endl;
				return;
			}
			

			Pacientes* newPaciente = new Pacientes(nombre, telefono, correo, apellido,cedula, fechaRegistro);
			listaPacientes.push_back(newPaciente);

            cout << "Paciente registrado con exito" << endl;

			for (int i = 0; i < listaPacientes.size(); i++)
			{
				listaPacientes[i]->getMostrarDatos();

		    }
	}

	void menuPacientes()
	{
		system("cls");
		int opcion;

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
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		default:
		{
			cout << "Opcion no valida" << endl;
			break;
		}
		} while (opcion != 6);
	
	
	}
};
