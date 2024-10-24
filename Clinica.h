#pragma once
#include"Librerias.h"
#include"ContenedorCitas.h"
#include"ContenedorMedicos.h"
#include"ContenedorPacientes.h"
#include"ContenedorServicios.h"

class Clinica
{

private:

	string nombreClinia;
	string direccionClinica;
	string especialidades;
	string correoClinica;
	string telefonoClinica;

public:
	Clinica()
	{
		this->nombreClinia = "Clinica San Quantum Code";
		this->direccionClinica = "Nicoya, Guanacaste";
		this->especialidades = "Medicina General, Odontologia, Nutricion, Pediadria, Psicologia";
		this->correoClinica = "santaquantumcode@hotmail.com";
		this->telefonoClinica = 2685-5314;
	}

	void menuClinica()
	{

		int opcionClinica;
		ContenedorServicios contenedorServicios;
		ContenedorMedicos contenedorMedicos;
		ContenedorPacientes contenedorPacientes;
		ContenedorCitas contenedorCitas;

		do
		{
			cout << "================================================================" << endl;
			cout << "=====================  PROGRAMADORES  ==========================" << endl;
			cout << "================================================================" << endl;
			cout << "================== CAMILA MORA CASTILLO ========================" << endl;
			cout << "================== DANIEL ELIZONDO GUTIERREZ ===================" << endl;
			cout << "================= SAMIRA ZUNIGA QUESADA ========================" << endl;
			cout << "================== NAEL BARRANTES DIAZ =========================" << endl;
			cout << "================== LIZZY NOGUERA MEDINA ========================" << endl;
			cout << "================================================================" << endl;

			// Pausar para que el usuario presione Enter
			cout << "Presione enter para poner continuar..." << endl;
			cin.get(); // Espera que el usuario presione Enter
			system("cls");
			


			system("cls");
			cout << "================================================================" << endl;
			cout << "=================BIENVENIDOS/BIENVENIDAS========================" << endl;
			cout << "=================CLINICA SAN QUANTUM CODE=======================" << endl;
			cout << "======================MENU PRINCIPAL============================" << endl;
			cout << "================================================================" << endl;
			cout << "1-Gestion de servicios: " << endl;
			cout << "2-Gestion de medicos: " << endl;
			cout << "3-Gestion de pacientes: " << endl;
			cout << "4-Gestion de citas: " << endl;
			cout << "5-Salir" << endl;
			cout << "================================================================" << endl;
			cout << "Ingrese su opcion: ";
			cin >> opcionClinica;

			switch (opcionClinica)
			{

			case 1:
			{
				contenedorServicios.menuServicios();
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
				system("pause");
				break;
			}

			case 5:
			{
				bool salir = false;
				int opcion;
				while (!salir)
				{
					cout << "Desea salir de nuestro menu?" << endl;
					cout << "1-SI" << endl;
					cout << "0-NO" << endl;
					cin >> opcion;

					switch (opcion)
					{
					case 1:
					{
						salir = true;
						cout << "¡Gracias por usar nuestra clinica!" << endl;
						cout << "Estamos ubicados en: Nicoya, Guanacaste " << endl;
						cout << "Nuestro correo es: sanaquantumcode@hotmail.com" << endl;
						cout << "Recordar que brindamos nuestros servicios de: Medicina General, Odontologia, Nutricion, Pediadria, Psicologia" << endl;
						cout << "Nuestro numero telefonico es: 2685-5314" << endl;
						cout << "¡Clinica San Quantum Code le agradace por confiar en nosotros! " << endl;
						cout << "!LO ESPERAMOS PRONTO!" << endl;
						system("pause");
						break;
					}
					case 0:
					{
						salir = false;
						cout << "¡GRACIAS POR CONTINUAR EN NUESTRO MENU!" << endl;
						system("pause");
						break;
					}
					default:
					{
						cout << "OPCION INVALIDA" << endl;
						system("pause");
						break;
					}
					}
				}
			}
			default:
			{
				cout << "==¡OPCION INCORRECTA!==" << endl;
				cout << "VUELVA A INTENTAR CON OTRA OPCION..." << endl;
				break;
			}

			}

		} while (opcionClinica != 5);


	}
};
