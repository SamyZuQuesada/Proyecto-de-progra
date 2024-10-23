#pragma once
#include "Librerias.h"
#include "Medicos.h"

class ContenedorMedicos 
{
private:
	vector<Medicos*> listaMedicos;

public:
	void setRegistrarMedico()
	{
		int codigo;
		string nombre, telefono, correo, disponibilidad;


		cout << "Ingrese el codigo del medico: ";
		cin >> codigo;

		if (codigo < 0 || codigo > 9999)
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

		cout << "Ingrese la disponibilidad del medico: ";
		cin >> disponibilidad;

		if (nombre.empty() || telefono.empty() || correo.empty() || disponibilidad.empty())
		{
			cout << "No se permiten campos vacios" << endl;
			return;
		}

		Medicos* newMedico = new Medicos(codigo, nombre, telefono, correo, disponibilidad);
		listaMedicos.push_back(newMedico);



		cout << "Medico registrado con exito" << endl;

		for (int i = 0; i < listaMedicos.size(); i++) 
		{
			listaMedicos[i]->getMostrarDatos();

		}

	}
















	virtual void MenuMedicos()
	{
		system("cls");
		int opcion;

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