#pragma once
#include "Librerias.h"
#include "Citas.h"
#include "Medicos.h"
#include "Pacientes.h"
#include "Servicios.h"
#include "ContenedorMedicos.h"
#include "ContenedorPacientes.h"
#include "ContenedorServicios.h"
#include <fstream>
#include <sstream>
#include <limits>

class ContenedorCitas {
private:
    vector<Citas*> listaCitas;
    ContenedorMedicos* contenedorMedicos;
    ContenedorPacientes* contenedorPacientes;
    ContenedorServicios* contenedorServicios;
    int contadorConsecutivo = 1;

public:

    ContenedorCitas() = default;

    ContenedorCitas(ContenedorMedicos* contenedorMedicos, ContenedorPacientes* contenedorPacientes, ContenedorServicios* contenedorServicios)
    {
        this->contenedorMedicos = contenedorMedicos;
        this->contenedorPacientes = contenedorPacientes;
        this->contenedorServicios = contenedorServicios;
    }

    // Destructor para liberar memoria
    ~ContenedorCitas()
    {
        for (auto cita : listaCitas)
        {
            delete cita;
        }
    }

    const vector<Citas*>& getListaCitas() const
    {
        return listaCitas;
    }

    void setAgendarCita()
    {
        int numeroCita, cedulaUsuario, codigoMedico, codigoServicio;
        string fecha;
        float costoTotal = 0;
        bool citaExiste = false;

        cout << "Digite la cedula del paciente: ";
        cin >> cedulaUsuario;

        if (!validarPaciente(cedulaUsuario))
        {
            int opcionPaciente;
            cout << "El paciente no se encuentra registrado en el sistema\nDesea agregarlo al sistema?\n1- SI\n0- NO\n";
            cin >> opcionPaciente;
            if (opcionPaciente == 1)
            {
                contenedorPacientes->setRegistrarPaciente();
                system("pause");
            }
            else if (opcionPaciente == 0)
            {
                cout << "Volviendo al menu...\n";
                return;
            }
            else
            {
                cout << "Opcion no valida\n";
            }
        }
        else
        {
            cout << "El paciente ya se encuentra registrado en el sistema!\n";
            contenedorPacientes->consultarPaciente();
        }

        cout << "Digite el codigo del servicio: ";
        cin >> codigoServicio;

        if (!validarServicio(codigoServicio))
        {
            int opcionServicio;
            cout << "El servicio no se encuentra registrado en el sistema\nDesea agregarlo al sistema?\n1- SI\n0- NO\n";
            cin >> opcionServicio;
            if (opcionServicio == 1)
            {
                contenedorServicios->setRegistrarServicio();
                system("pause");
            }
            else if (opcionServicio == 0)
            {
                cout << "Volviendo al menu...\n";
                return;
            }
            else
            {
                cout << "Opcion no valida\n";
            }
        }
        else
        {
            cout << "El servicio ya se encuentra registrado en el sistema!\n";
            contenedorServicios->consultarServicios();
        }

        cout << "Digite el codigo del medico: ";
        cin >> codigoMedico;
        if (!validarMedico(codigoMedico))
        {
            int opcionMedico;
            cout << "El medico no se encuentra registrado en el sistema\nDesea agregarlo al sistema?\n1- SI\n0- NO\n";
            cin >> opcionMedico;
            if (opcionMedico == 1)
            {
                contenedorMedicos->setRegistrarMedico();
                system("pause");
            }
            else if (opcionMedico == 0)
            {
                cout << "Volviendo al menu...\n";
                return;
            }
            else
            {
                cout << "Opcion no valida\n";
            }
        }
        else
        {
            cout << "El medico ya se encuentra registrado en el sistema!\n";
            contenedorMedicos->consultarMedicos();
        }

        cout << "Digite el numero de cita: ";
        cin >> numeroCita;
        for (size_t i = 0; i < listaCitas.size(); i++)
        {
            if (numeroCita == listaCitas[i]->getNumeroCita())
            {
                cout << "El numero de cita ya existe\n";
                citaExiste = true;
                system("pause");
                return;
            }
        }
        if (!citaExiste)
        {
            do
            {
                cout << "Digite la fecha de la cita: ";
                cin.ignore();
                getline(cin, fecha);

                if (fecha.empty())
                {
                    cout << "No se permiten campos vacios, intentelo de nuevo\n";
                }
            } while (fecha.empty());

            Citas* newCita = new Citas(contadorConsecutivo++, cedulaUsuario, codigoMedico, fecha, codigoServicio, costoTotal);
            listaCitas.push_back(newCita);
            cout << "Cita registrada con exito!\n";
        }
    }

    bool validarPaciente(int cedulaUsuario)
    {
        for (size_t i = 0; i < contenedorPacientes->getListaPacientes().size(); i++)
        {
            if (cedulaUsuario == contenedorPacientes->getListaPacientes()[i]->getCedula())
            {
                return true;
            }
        }
        return false;
    }

    bool validarMedico(int codigoMedico)
    {
        for (size_t i = 0; i < contenedorMedicos->getListaMedicos().size(); i++)
        {
            if (codigoMedico == contenedorMedicos->getListaMedicos()[i]->getCodigo())
            {
                return true;
            }
        }
        return false;
    }

    bool validarServicio(int codigoServicio)
    {
        for (size_t i = 0; i < contenedorServicios->getListaServicios().size(); i++)
        {
            if (codigoServicio == contenedorServicios->getListaServicios()[i]->getCodigoServicio())
            {
                return true;
            }
        }
        return false;
    }

    void getModificarCitas()
    {
        int numeroCita;
        string nuevaFecha;
        bool buscar = false;

        if (listaCitas.empty())
        {
            cout << "No hay citas registradas\n";
            return;
        }

        cout << "Ingrese el numero de cita: ";
        cin >> numeroCita;
        cin.ignore();

        for (size_t i = 0; i < listaCitas.size(); i++)
        {
            if (listaCitas[i]->getNumeroCita() == numeroCita)
            {
                buscar = true;
                cout << "Ingrese la nueva fecha de la cita: ";
                getline(cin, nuevaFecha);

                if (nuevaFecha.empty())
                {
                    cout << "No se permiten campos vacios\n";
                    return;
                }

                listaCitas[i]->setFecha(nuevaFecha);
                cout << "Fecha modificada correctamente!\n";
                break;
            }
        }

        if (!buscar)
        {
            cout << "No existe una cita con ese numero..\n";
        }
    }

    void getConsultarCitas()
    {
        int opcion;
        bool buscar = false;

        cout << "....CONSULTAR CITAS....\n";
        cout << "1. Consultar todas las citas\n";
        cout << "2. Consultar una cita en especifico\n";
        cin >> opcion;

        if (opcion == 1)
        {
            for (size_t i = 0; i < listaCitas.size(); i++)
            {
                listaCitas[i]->getMostrarDatos();
            }
        }
        else if (opcion == 2)
        {
            int numeroCita;
            cout << "Ingrese el numero de cita: ";
            cin >> numeroCita;

            for (size_t i = 0; i < listaCitas.size(); i++)
            {
                if (listaCitas[i]->getNumeroCita() == numeroCita)
                {
                    buscar = true;
                    listaCitas[i]->getMostrarDatos();
                }
            }

            if (!buscar)
            {
                cout << "No se ha encontrado una cita con ese numero..\n";
            }
        }
        else
        {
            cout << "Opcion no valida\n";
        }
    }

    void guardarEnArchivo()
    {
        ofstream archivo("Citas.txt");
        if (archivo.is_open())
        {
            for (size_t i = 0; i < listaCitas.size(); i++)
            {
                archivo << listaCitas[i]->getNumeroCita() << "-"
                    << listaCitas[i]->getCedulaUsuario() << "-"
                    << listaCitas[i]->getCodigoMedico() << "-"
                    << listaCitas[i]->getFecha() << "-"
                    << listaCitas[i]->getCodigoServicio() << "-"
                    << listaCitas[i]->getCostoTotal() << endl;
            }
            archivo.close();
            cout << "Datos guardados correctamente en el archivo Citas.txt\n";
        }
        else
        {
            cout << "No se pudo abrir el archivo\n";
        }
    }

    void recuperarArchivos()
    {
        listaCitas.clear();
        ifstream archivo("Citas.txt");
        int ultimoConsecutivo = 0;

        if (archivo.is_open())
        {
            string linea;
            while (getline(archivo, linea))
            {
                stringstream ss(linea);

                int _numeroCita, _cedulaUsuario, _codigoMedico, _codigoServicio;
                string fecha;
                float _costoTotal;

                ss >> _numeroCita;
                ss.ignore();
                ss >> _cedulaUsuario;
                ss.ignore();
                ss >> _codigoMedico;
                ss.ignore();
                getline(ss, fecha, '-');
                ss >> _codigoServicio;
                ss.ignore();
                ss >> _costoTotal;

                ultimoConsecutivo = max(ultimoConsecutivo, _numeroCita);
                listaCitas.push_back(new Citas(_numeroCita, _cedulaUsuario, _codigoMedico, fecha, _codigoServicio, _costoTotal));
            }
            contadorConsecutivo = ultimoConsecutivo + 1;
            archivo.close();
            cout << "Datos recuperados correctamente\n";
        }
        else
        {
            cout << "No se pudo abrir el archivo\n";
        }
    }

    void menuCitas()
    {
        int opcion;
        do
        {
            cout << "......................Menu Citas...............\n";
            cout << "1. Agendar nueva cita\n";
            cout << "2. Modificar una cita\n";
            cout << "3. Consultar todas las citas\n";
            cout << "4. Guardar contenedor en archivo\n";
            cout << "5. Recuperar datos del archivo\n";
            cout << "6. Regresar al menu principal\n";
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                setAgendarCita();
                break;
            case 2:
                getModificarCitas();
                break;
            case 3:
                getConsultarCitas();
                break;
            case 4:
                guardarEnArchivo();
                break;
            case 5:
                recuperarArchivos();
                break;
            case 6:
                cout << "Regresando al menu principal.\n";
                break;
            default:
                cout << "Opcion no valida\n";
                break;
            }
            system("pause");
        } while (opcion != 6);
    }
};
