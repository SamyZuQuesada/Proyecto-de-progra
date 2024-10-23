#pragma once
#include "Librerias.h"
#include "Servicios.h"

class ContenedorServicios
{
private:
	vector<Servicios> listaServicios;

public:

	void setRegistrarNuevoServicio()
	{

	}



	void menuServicios()
	{
		system("cls");
		int opcion;

		cout << "......................Menu Servicios..............." << endl;
		cout << "1. Registrar nuevo servicio" << endl;
		cout << "2. Modificar un servicio" << endl;
		cout << "3. Consultar todos los servicios" << endl;
		cout << "4. Guardar contenedor en archivo" << endl;
		cout << "5. Recuperar datos del archivo" << endl;
		cout << "6. Consultar cita especifica" << endl;
		cout << "7. Regresar al menu principal" << endl;
		cout << "............................................." << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
		{
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
		} while (opcion != 7);


	}


};
