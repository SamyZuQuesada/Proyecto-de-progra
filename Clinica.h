#pragma once
#include "Librerias.h"
#include "ContenedorCitas.h"
#include "ContenedorMedicos.h"
#include "ContenedorPacientes.h"
#include "ContenedorServicios.h"

class Clinica
{
private:
    string nombreClinica;
    string direccionClinica;
    string especialidades;
    string correoClinica;
    string telefonoClinica;

public:
    Clinica()
    {
        this->nombreClinica = "Clinica San Quantum Code";
        this->direccionClinica = "Nicoya, Guanacaste";
        this->especialidades = "Medicina General, Odontologia, Nutricion, Pediatria, Psicologia";
        this->correoClinica = "santaquantumcode@hotmail.com";
        this->telefonoClinica = "2685-5314"; // Cambio para corregir truncamiento
    }

    void menuClinica()
    {
        int opcionClinica;
        bool salir = false;
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
            cout << "================== LISSY NOGUERA MEDINA ========================" << endl;
            cout << "================================================================" << endl;

            cout << "Presione enter para poner continuar..." << endl;
            cin.get();
            system("cls");

            cout << "----------------------------------------------------------------" << endl;
            cout << "------------------------BIENVENID@S-----------------------------" << endl;
            cout << "------------------CLINICA SAN QUANTUM CODE----------------------" << endl;
            cout << "-----------------------MENU PRINCIPAL---------------------------" << endl;
            cout << "----------------------------------------------------------------" << endl;
            cout << "1-Gestion de servicios: " << endl;
            cout << "2-Gestion de medicos: " << endl;
            cout << "3-Gestion de pacientes: " << endl;
            cout << "4-Gestion de citas: " << endl;
            cout << "5-Salir" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Ingrese su opcion: ";
            cin >> opcionClinica;

            switch (opcionClinica)
            {
            case 1:
                contenedorServicios.menuServicios();
                system("pause");
                break;

            case 2:
                contenedorMedicos.menuMedicos();
                system("pause");
                break;

            case 3:
                contenedorPacientes.menuPacientes();
                system("pause");
                break;

            case 4:
                // contenedorCitas.MenuCitas();
                system("pause");
                break;

            case 5:
            {
                int opcionSalir;
                cout << "..........................................." << endl;
                cout << "Desea salir de nuestro menu?" << endl;
                cout << "1-SI" << endl;
                cout << "0-NO" << endl;
                cout << "..........................................." << endl;
                cin >> opcionSalir;

                if (opcionSalir == 1)
                {
                    salir = true;
                    cout << "¡Gracias por usar nuestra clinica!" << endl;
                    cout << "Estamos ubicados en: Nicoya, Guanacaste " << endl;
                    cout << "Nuestro correo es: sanquantumcode@hotmail.com" << endl;
                    cout << "Recordar que brindamos nuestros servicios de: Medicina General, Odontologia, Nutricion, Pediatria, Psicologia" << endl;
                    cout << "Nuestro numero telefonico es: 2685-5314" << endl;
                    cout << "¡Clinica San Quantum Code le agradace por confiar en nosotros! " << endl;
                    cout << "!LO ESPERAMOS PRONTO!" << endl;
                    system("pause");
                }
                else if (opcionSalir == 0)
                {
                    cout << "¡GRACIAS POR CONTINUAR EN NUESTRO MENU!" << endl;
                    system("pause");
                }
                else
                {
                    cout << "¡Opcion no valida!" << endl;
                    system("pause");
                }
                break;
            }

            default:
                cout << "--¡OPCION INCORRECTA!--" << endl;
                cout << "VUELVA A INTENTAR CON OTRA OPCION..." << endl;
                break;
            }

        } while (!salir);
    }
};
