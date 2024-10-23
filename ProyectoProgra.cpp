#include "Librerias.h"
#include "ContenedorServicios.h"
#include "ContenedorMedicos.h"
#include "ContenedorPacientes.h"
#include "ContenedorCitas.h"
#include <vector>

int main()
{
	ContenedorServicios contenedorServicios;
	ContenedorMedicos contenedorMedicos;
	ContenedorPacientes contenedorPacientes;
	ContenedorCitas contenedorCitas;

	int opcion;
	

	do
	{
		system("cls");
		cout << "....................Menu Principal...................." << endl;
		cout << "1. Gestion de Servicios" << endl;
		cout << "2. Gestion de Medicos" << endl;
		cout << "3. Gestion de Pacientes" << endl;
		cout << "4. Agendar cita medica" << endl;
		cout << "5. Salir de sistema" << endl;
		cout << "........................................................." << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1: 
		{
            
			system("pause");
			break;
		}

		case 2:
		{
			contenedorMedicos.MenuMedicos();
			system("pause");
			break;
		}

		case 3:
		{
			contenedorPacientes.menuPacientes();
			system("pause");
			break;
		}

		case 4:
		{
			//citas
			system("pause");
			break;
		}

		case 5:
		{
			cout << "Saliendo del sistema..." << endl;
			system("pause");
			break;
		}
		default:
		{
			cout << "Opcion invalida. Intente nuevamente." << endl;
			system("pause");
			break;
		}
		
		}
	} while (opcion != 5);

}