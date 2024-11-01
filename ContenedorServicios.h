#pragma once
#include "Librerias.h"
#include "Servicios.h"
#include "Citas.h"

class ContenedorServicios {
private:
    vector<Servicios*> listaServicios;

public:

    const vector<Servicios*>& getListaServicios() const
    {
        return listaServicios;
    }

    void setRegistrarServicio() {
        int codigo = 0;
        string descripcion;
        float costo = 0;
        bool disponibilidad = true;
        recuperarArchivo();

        cout << "Ingrese el codigo del servicio: ";
        cin >> codigo;

        if (codigo < 0) {
            cout << "Codigo no valido, ingrese un numero positivo " << endl;
            return;
        }

        for (size_t i = 0; i < listaServicios.size(); i++) { // Cambiado a size_t
            if (listaServicios[i]->getCodigo() == codigo) {
                cout << "Ya hay un servicio registrado con este codigo." << endl;
                return;
            }
        }
        cin.ignore();
        do {
            cout << "Ingrese la descripcion del servicio: ";
            getline(cin, descripcion);
            cout << "Ingrese el costo del servicio: ";
            cin >> costo;

            cout << "Disponibilidad del servicio: 1= disponible, 0= no disponible): " << endl;
            cin >> disponibilidad;

            if (codigo <= 0 || descripcion.empty() || costo <= 0) {
                cout << "No se permiten campos vacios o en negativo" << endl;
                return;
            }
        } while (codigo <= 0 || descripcion.empty() || costo <= 0);

        Servicios* newServicio = new Servicios(codigo, descripcion, costo, disponibilidad);
        listaServicios.push_back(newServicio);

        cout << "Servicio registrado con exito" << endl;
        cout << "............. Lista de servicios registrados................." << endl;

        for (size_t i = 0; i < listaServicios.size(); i++) { // Cambiado a size_t
            listaServicios[i]->getMostrarServicios();
        }
        cout << ".............................................................." << endl;
    }

    void getModificarServicio() {
        int codigo;
        string Nuevadescripcion;
        float Nuevocosto;
        bool Nuevadisponibilidad;

        if (listaServicios.empty()) {
            cout << "No hay servicios registrados" << endl;
            return;
        }

        cout << "Ingrese su numero de codigo" << endl;
        cin >> codigo;
        cin.ignore();

        if (codigo < 0) {
            cout << "Codigo no valido, ingrese un numero positivo." << endl;
            return;
        }
        else {
            for (size_t i = 0; i < listaServicios.size(); i++) { // Cambiado a size_t
                if (listaServicios[i]->getCodigo() == codigo) {
                    cout << "Ingrese la nueva descripcion del servicio: " << endl;
                    getline(cin, Nuevadescripcion);

                    cout << "Ingrese el nuevo costo del servicio: " << endl;
                    cin >> Nuevocosto;

                    if (Nuevocosto < 0) {
                        cout << "Costo no valido, ingrese un numero positivo." << endl;
                        return;
                    }

                    cout << "Disponibilidad del nuevo servicio: 1= disponible, 0= no disponible): " << endl;
                    cin >> Nuevadisponibilidad;

                    if (codigo < 0 || Nuevadescripcion.empty() || Nuevocosto < 0) {
                        cout << "No se permiten campos vacios" << endl;
                        return;
                    }

                    listaServicios[i]->setDescripcion(Nuevadescripcion);
                    listaServicios[i]->setCosto(Nuevocosto);
                    listaServicios[i]->setDisponibilidad(Nuevadisponibilidad);
                    cout << "Servicio modificado con exito" << endl;

                    cout << "............. Lista de servicios registrados................." << endl;
                    for (size_t i = 0; i < listaServicios.size(); i++) { // Cambiado a size_t
                        listaServicios[i]->getMostrarServicios();
                    }
                    cout << "............................................................" << endl;
                    return;
                }
            }
            cout << "No existe un servicio registrado con ese codigo" << endl;
        }
    }

    void consultarServicios() {
        int disponibilidad = 0;

        cout << "................Lista de servicios registrados................ " << endl;
        if (listaServicios.empty()) {
            cout << "No hay datos para mostrar..." << endl;
        }
        else {
            for (size_t i = 0; i < listaServicios.size(); i++) { // Cambiado a size_t
                listaServicios[i]->getMostrarServicios();
                cout << "........................................................." << endl;

                if (listaServicios[i]->getDisponibilidad()) {
                    disponibilidad++;
                }
            }
        }
        cout << "..............................................." << endl;
        cout << "Total de servicios registrados: " << listaServicios.size() << endl;
        cout << "Servicios disponibles: " << disponibilidad << endl;
        cout << "Servicios no disponibles: " << listaServicios.size() - disponibilidad << endl;
        cout << "..............................................." << endl;
    }

    void guardarEnArchivo() {
        ofstream archivo("Servicios.txt");
        if (archivo.is_open()) {
            for (size_t i = 0; i < listaServicios.size(); i++) { // Cambiado a size_t
                archivo << listaServicios[i]->getCodigo()
                    << "-" << listaServicios[i]->getDescripcion()
                    << "-" << listaServicios[i]->getCosto()
                    << "-" << listaServicios[i]->getDisponibilidad()
                    << endl;
            }
            archivo.close();
            cout << "Datos guardados correctamente en el archivo Servicios.txt" << endl;
        }
        else {
            cout << "No se pudo abrir el archivo" << endl;
        }
    }

    void recuperarArchivo() {
        listaServicios.clear();
        ifstream archivo("Servicios.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                string codigo, descripcion, costo, disponibilidad;

                getline(ss, codigo, '-');
                int _codigo = stoi(codigo);

                getline(ss, descripcion, '-');

                getline(ss, costo, '-');
                float _costo = stof(costo);

                getline(ss, disponibilidad, '-');
                bool _disponibilidad = (disponibilidad == "1");

                Servicios* nuevoServicio = new Servicios(_codigo, descripcion, _costo, _disponibilidad);
                listaServicios.push_back(nuevoServicio);
            }
            archivo.close();
            cout << "Datos recuperados correctamente" << endl;
        }
        else {
            cout << "No se pudo abrir el archivo" << endl;
        }
    }

    void menuServicios() {
        int opcion;
        do {
            system("cls");
            cout << "......................Menu Servicios..............." << endl;
            cout << "1. Registrar nuevo servicio" << endl;
            cout << "2. Modificar un servicio" << endl;
            cout << "3. Consultar todos los servicios" << endl;
            cout << "4. Guardar contenedor en archivo" << endl;
            cout << "5. Recuperar datos del archivo" << endl;
            cout << "6. Regresar al menu principal" << endl;
            cout << "............................................." << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;
            switch (opcion) {
            case 1:
                setRegistrarServicio();
                system("pause");
                break;
            case 2:
                getModificarServicio();
                system("pause");
                break;
            case 3:
                consultarServicios();
                system("pause");
                break;
            case 4:
                guardarEnArchivo();
                system("pause");
                break;
            case 5:
                recuperarArchivo();
                system("pause");
                break;
            case 6:
                cout << "Regresando al menu principal..." << endl;
                system("pause");
                break;
            default:
                cout << "Opcion no valida" << endl;
                system("pause");
                break;
            }
        } while (opcion != 6);
    }
};
