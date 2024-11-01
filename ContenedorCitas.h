#pragma once
#include "Librerias.h"
#include "Citas.h"
#include "Medicos.h"
#include "Pacientes.h"
#include "Servicios.h"
#include "ContenedorMedicos.h"
#include "ContenedorPacientes.h"
#include "ContenedorServicios.h"


class ContenedorCitas {
private:
    vector<Citas*> listaCitas;
    ContenedorMedicos* contenedorMedicos;
    ContenedorPacientes* contenedorPacientes;
    ContenedorServicios* contenedorServicios;
    int contadorConsecutivo = 1;

public:

    ContenedorCitas(ContenedorMedicos* contenedorMedicos, ContenedorPacientes* contenedorPacientes, ContenedorServicios* contenedorServicios)
    {
        this->contenedorMedicos = contenedorMedicos;
        this->contenedorPacientes = contenedorPacientes;
        this->contenedorServicios = contenedorServicios;
        //Se ha creado este constructor que recibe por parametro que es una instancia,
        // para poder accedecer y usar los atributos y metodos de las clases ContenedorMedicos, ContenedorPacientes y ContenedorServicios.

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

        cout << "Digite la cedula del paciente: " << endl;
        cin >> cedulaUsuario;

        if (!validarPaciente(cedulaUsuario))
        {
            int opcionPaciente;
            cout << "El paciente no se encuentra registrado en el sistema" << endl;
            cout << "Desea agregarlo al sistema ?" << endl;
            cout << "1- SI" << endl;
            cout << "0-NO" << endl;
            cin >> opcionPaciente;
            if (opcionPaciente == 1)
            {
                contenedorPacientes->setRegistrarPaciente();
                system("pause");
            }
            else if (opcionPaciente == 0)
            {
                cout << "Volviendo al menu..." << endl;
                return;
            }
            else
            {
                cout << "Opcion no valida" << endl;
                return;
            }

        }
        else
        {
            system("cls");
            cout << "El paciente ya se encuentra registrado en el sistema!!" << endl;
            contenedorPacientes->consultarPaciente();
        }

        cout << "Digite el codigo del servicio: " << endl;
        cin >> codigoServicio;

        if (!validarServicio(codigoServicio))
        {
            int opcionServicio;
            cout << "El servicio no se encuentra registrado en el sistema" << endl;
            cout << "Desea agregarlo al sistema ?" << endl;
            cout << "1- SI" << endl;
            cout << "0-NO" << endl;
            cin >> opcionServicio;
            if (opcionServicio == 1)
            {
                contenedorServicios->setRegistrarServicio();
                system("pause");
            }
            else if (opcionServicio == 0)
            {
                cout << "Volviendo al menu..." << endl;
                return;
            }
            else
            {
                cout << "Opcion no valida" << endl;
                return;
            }

        }
        else
        {
            system("cls");
            cout << "El servicio ya se encuentra registrado en el sistema!!" << endl;
            contenedorServicios->consultarServicios();

            cout << "...................................................................................." << endl;
            if (codigoServicio >= 0 && codigoServicio < contenedorServicios->getListaServicios().size() &&
                !contenedorServicios->getListaServicios()[codigoServicio]->getDisponibilidad())
            {
                int opcion;
                cout << "El servicio no esta disponible..." << endl;
                cout << "Desea intentar con otro servicio o cancelar..? (1-SI / 0-CANCELAR) " << endl;
                cin >> opcion;
                if (opcion == 1)
                {
                    while (true)
                    {
                        cout << "Digite el codigo del servicio: " << endl;
                        cin >> codigoServicio;
                        if (codigoServicio >= 0 && codigoServicio < contenedorServicios->getListaServicios().size() &&
                            contenedorServicios->getListaServicios()[codigoServicio]->getDisponibilidad())
                        {
                            cout << "El servicio esta disponible" << endl;
                            break;
                        }
                        else
                        {
                            cout << "El servicio no esta disponible, intente con otro servicio." << endl;
                            return;
                        }
                    }
                }
                else
                {
                    cout << "CANCELANDO EL AGENDAMIENTO..." << endl;
                    return;
                }
            }
            else
            {
                cout << "El servicio esta disponible" << endl;
            }
        }


        cout << "Digite el codigo del medico: " << endl;
        cin >> codigoMedico;
        if (!validarMedico(codigoMedico))
        {
            int opcionMedico;
            cout << "El medico no se encuentra registrado en el sistema" << endl;
            cout << "Desea agregarlo al sistema ?" << endl;
            cout << "1- SI" << endl;
            cout << "0-NO" << endl;
            cin >> opcionMedico;
            if (opcionMedico == 1)
            {
                contenedorMedicos->setRegistrarMedico();
                system("pause");
            }
            else if (opcionMedico == 0)
            {
                cout << "Volviendo al menu..." << endl;
                return;
            }
            else
            {
                cout << "Opcion no valida" << endl; 
                return;

            }
        }
        else
        {
            system("cls");
            cout << "El medico ya se encuentra registrado en el sistema!!" << endl;
            contenedorMedicos->consultarMedicos();
            

            if (codigoMedico >= 0 && codigoMedico < contenedorMedicos->getListaMedicos().size() &&
                !contenedorMedicos->getListaMedicos()[codigoMedico]->getDisponibilidad())
            {
                int opcion;
                cout << "El medico no esta disponible..." << endl;
                cout << "Desea intentar con otro medico o cancelar..?  (1-SI / 0-CANCELAR)" << endl;
                cin >> opcion;
                if (opcion == 1)
                {
                    while (true)
                    {
                        cout << "Digite el codigo del medico: " << endl;
                        cin >> codigoMedico;
                        if (codigoMedico >= 0 && codigoMedico < contenedorMedicos->getListaMedicos().size() &&
                            contenedorMedicos->getListaMedicos()[codigoMedico]->getDisponibilidad())
                        {
                            cout << "El medico esta disponible" << endl;
                            break;
                        }
                        else
                        {
                            cout << "El medico no esta disponible, intente con otro medico." << endl;
                            return;
                        }
                    }
                }
                else
                {
                    cout << "CANCELANDO EL AGENDAMIENTO.." << endl;
                    return;
                }
            }
            else
            {
                cout << "El medico esta disponible" << endl;
            }
        }

        system("cls");
        cout << "Digite el numero de cita: " << endl;
        cin >> numeroCita;
        for (int i = 0; i < listaCitas.size(); i++)
        {
            if (numeroCita == listaCitas[i]->getNumeroCita())
            {
                cout << "El numero de cita ya existe" << endl;
                citaExiste = true;
                system("pause");
                return;
            }
        }
        if (!citaExiste)
        {
            do
            {
                cin.ignore();

                cout << "Digite la fecha de la cita: " << endl;
                cin >> fecha;
                //getline(cin, fecha);

                cout << "El costo total de su cita es de: " << calcularCostoTotal(costoTotal) << endl;

                if (fecha.empty())
                {
                    cout << "No se permiten campos vacios, intentelo de nuevo" << endl;
                }


            } while (fecha.empty());

            Citas* newCita = new Citas(contadorConsecutivo++, cedulaUsuario, codigoMedico, fecha, codigoServicio, costoTotal);
            cout << "Cita agendada correctamente!!" << newCita->getFecha() << endl;
            listaCitas.push_back(newCita);

            cout << "Cita agendada correctamente!!" << endl;

            system("cls");

            //Mostrar datos de las citas agendadas
            cout << "...........LISTA DE CITAS............." << endl;
            for (int i = 0; i < listaCitas.size(); i++)
            {
                listaCitas[i]->getMostrarDatos();
            }
            cout << "......................................" << endl;
        }
    }


    bool validarPaciente(int cedulaUsuario)
    {
        for (int i = 0; i < contenedorPacientes->getListaPacientes().size(); i++)
        {
            cout << "CEDULA: " << contenedorPacientes->getListaPacientes()[i]->getCedula() << endl;
            if (cedulaUsuario == contenedorPacientes->getListaPacientes()[i]->getCedula())
            {
                return true;
            }
        }
        return false;
    }

    bool validarMedico(int codigoMedico)
    {
        for (int i = 0; i < contenedorMedicos->getListaMedicos().size(); i++)
        {
            cout << "CODIGO: " << contenedorMedicos->getListaMedicos()[i]->getCodigo() << endl;
            if (codigoMedico == contenedorMedicos->getListaMedicos()[i]->getCodigo())

            {
                return true;
            }
        }
        return false;
    }

    bool validarServicio(int codigoServicio)
    {
        for (int i = 0; i < contenedorServicios->getListaServicios().size(); i++)
        {
            if (codigoServicio == contenedorServicios->getListaServicios()[i]->getCodigoServicio())
            {
                return true;
            }
        }
        return false;
    }

    float calcularCostoTotal(float costoTotal)
    {
        for (int i = 0; i < contenedorServicios->getListaServicios().size(); i++)
        {
            costoTotal += contenedorServicios->getListaServicios()[i]->getCostoServicio() + 0.02 + 0.10;
        }
        return costoTotal;
    }


    void disponibilidadServicio(int codigoServicio)
    {
        bool encontrado = false;

        for (int i = 0; i < contenedorServicios->getListaServicios().size(); i++)
        {
            if (contenedorServicios->getListaServicios()[i]->getCodigoServicio() == codigoServicio)
            {
                encontrado = true;
                if (contenedorServicios->getListaServicios()[i]->getDisponibilidad())
                {
                    cout << "El servicio con el codigo: " << codigoServicio << " esta disponible" << endl;
                }
                else
                {
                    cout << "El servicio con el codigo: " << codigoServicio << " no esta disponible" << endl;
                }
                break;
            }
        }
        if (!encontrado)
        {
            cout << "No se ha encontrado un servicio con ese codigo" << endl;
        }
    }

    void getModificarCitas()
    {
        int numeroCita;
        string nuevaFecha;
        bool buscar = false;

        if (listaCitas.empty())
        {
            cout << "No hay citas registradas" << endl;
            return;
        }

        cout << "Ingrese el numero de cita" << endl;
        cin >> numeroCita;
        cin.ignore();

        for (int i = 0; i < listaCitas.size(); i++)
        {
            if (listaCitas[i]->getNumeroCita() == numeroCita)
            {
                buscar = true;

                cout << "Ingrese la nueva fecha de la cita: " << endl;
                getline(cin, nuevaFecha);

                if (nuevaFecha.empty())
                {
                    cout << "No se permiten campos vacios" << endl;
                    return;
                }

                listaCitas[i]->setFecha(nuevaFecha);
                cout << "Fecha modificada correctamente!!" << endl;
                break;
            }
        }
        if (!buscar)
        {
            cout << "No se ha encontrado una cita con ese numero.." << endl;

        }
        else
        {
            system("cls");

            cout << ".........LISTA DE CITAS.........." << endl;
            for (int i = 0; i < listaCitas.size(); i++)
            {
                listaCitas[i]->getMostrarDatos();
            }
            cout << "................................." << endl;
        }
    }

    void getConsultarCitas()
    {
        int opcion;
        bool buscar = false;

        cout << ".........CONSULTAR CITAS.........." << endl;
        cout << "1. Consultar todas las citas: " << endl;
        cout << "2. Consultar una cita en especifico: " << endl;
		cout << "..................................." << endl;
        cin >> opcion;

        if (opcion == 1)
        {
            system("cls");
     
            cout << ".........LISTA DE CITAS.........." << endl;
            if (listaCitas.empty())
            {
                cout << "La lista de citas esta vacia" << endl;
            }

            for (int i = 0; i < listaCitas.size(); i++)
            {
                listaCitas[i]->getMostrarDatos();
            }
            cout << "................................." << endl;
        }
        else if (opcion == 2)
        {
            int numeroCita;

            cout << "Ingrese el numero de cita: " << endl;
            cin >> numeroCita;

            for (int i = 0; i < listaCitas.size(); i++)
            {
                if (listaCitas[i]->getNumeroCita() == numeroCita)
                {
                    buscar = true;
                    listaCitas[i]->getMostrarDatos();
                }
            }

            if (!buscar)
            {
                cout << "No se ha encontrado una cita con ese numero.." << endl;
				return;
            }
        }
        else
        {
            cout << "Opcion no valida" << endl;
			return;
        }
    }

    void guardarEnArchivo()
    {
        ofstream archivo("Citas.txt");
        if (archivo.is_open())
        {
            for (int i = 0; i < listaCitas.size(); i++)
            {
                archivo << listaCitas[i]->getNumeroCita()
                    << "-" << listaCitas[i]->getCedulaUsuario()
                    << "-" << listaCitas[i]->getCodigoMedico()
                    << "-" << listaCitas[i]->getFecha()
                    << "-" << listaCitas[i]->getCodigoServicio()
                    << "-" << listaCitas[i]->getCostoTotal()
                    << endl;
            }
            archivo.close();
            cout << "Datos guardados correctamente en el archivo Citas.txt" << endl;
        }
        else
        {
            cout << "No se pudo abrir el archivo" << endl;
        }
    }

    void recuperarArchivos()
    {
        listaCitas.clear();
        ifstream archivo("Citas.txt");
        if (archivo.is_open())
        {
            string linea;
            int ultimoConsecutivo = 0;
            while (getline(archivo, linea))
            {
                stringstream ss(linea);

                string numeroCita, cedulaUsuario, codigoMedico, fecha, codigoServicio, costoTotal, consecutivo;

                getline(ss, numeroCita, '-');
                int _numeroCita = stoi(numeroCita);

                getline(ss, cedulaUsuario, '-');
                int _cedulaUsuario = stoi(cedulaUsuario);

                getline(ss, codigoMedico, '-');
                int _codigoMedico = stoi(codigoMedico);

                getline(ss, fecha, '-');

                getline(ss, codigoServicio, '-');
                int _codigoServicio = stoi(codigoServicio);

                getline(ss, costoTotal, '-');
                float _costoTotal = stof(costoTotal);

                getline(ss, consecutivo, '-');
                int _consecutivo = stoi(consecutivo);

                if (contadorConsecutivo > ultimoConsecutivo)
                    ultimoConsecutivo = contadorConsecutivo;


                Citas* newCita = new Citas(_numeroCita, _cedulaUsuario, _codigoMedico, fecha, _codigoServicio, _costoTotal);
                listaCitas.push_back(newCita);

            }
            archivo.close();
            cout << "Datos recuperados correctamente" << endl;

            contadorConsecutivo = ultimoConsecutivo + 1;
        }
        else
        {
            cout << "No se pudo abrir el archivo" << endl;
            return;
        }
    }

    void menuCitas()
    {
        int opcion;
        do
        {
            system("cls");
            cout << "......................Menu Citas..............." << endl;
            cout << "1. Agendar nueva cita" << endl;
            cout << "2. Modificar una cita" << endl;
            cout << "3. Consultar todas las citas" << endl;
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
                setAgendarCita();
                system("pause");
                break;
            }
            case 2:
            {
                getModificarCitas();
                system("pause");
                break;
            }
            case 3:
            {
                getConsultarCitas();
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
                recuperarArchivos();
                system("pause");
                break;
            }
            case 6:
            {
                cout << "Regresando al menu principal." << endl;
                system("pause");
                break;
            }
            default:
            {
                cout << "Opcion no valida" << endl;
                system("pause");
                break;
            }

            }
        } while (opcion != 6);
    }
};
