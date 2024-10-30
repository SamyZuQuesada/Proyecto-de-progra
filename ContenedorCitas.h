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
    ContenedorMedicos contenedorMedicos;
    ContenedorPacientes contenedorPacientes;
    ContenedorServicios contenedorServicios;

public:

    const vector<Citas*>& getListaCitas() const
    {
        return listaCitas;
    }

    void setAgendarCita() {
        int numeroCita, cedulaUsuario, codigoMedico, codigoServicio;
        string fecha;
        float costoTotal;
        int contador = 1;

        if (listaCitas.empty()) { //si la lista esta vacía solicita los datos
            cout << "Ingrese el codigo del medico: "; cin >> codigoMedico;

            if (contenedorMedicos.getListaMedicos().empty()) {

                int opcion = 0;
                cout << "No hay ningun medico registrado." << endl;
                do {//si no hay ningun médico registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                    system("pause");
                    system("cls");
                    cout << "1. Registrar un medico" << endl;
                    cout << "2. Cancelar solicitud" << endl;
                    cout << "Ingrese una opcion:"; cin >> opcion;

                    switch (opcion) {
                    case 1:
                    {
                        contenedorMedicos.setRegistrarMedico(); //Aqui no es necesario darle a citas acceso a los getters que usa el setRegistraMedicos del contenedor de médicos, ya que con que el método tenga acceso es suficiente
                        break;
                    }
                    case 2:
                        cout << "Volviendo al menu..." << endl;
                        system("pause");
                        system("cls");
                        return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                    default:
                        break;
                    }
                } while (opcion != 2);
            }//si el contenedor de medicos no estuviese vacio hace lo sgte
            else {
                for (int i = 0; i < contenedorMedicos.getListaMedicos().size(); i++) {

                    Medicos* medicos = contenedorMedicos.getListaMedicos()[i]; //con esto accedemos a un medico por iteración 

                    if (medicos->getCodigo() == codigoMedico) { //si el codigo ya registrado se parece al codigo medco ya ingresado hace los siguiente...
                        //comprobar disponibilidad
                        medicos->getDisponibilidad();
                        if (!medicos->getDisponibilidad()) {
                            cout << "Disponibilidad: " << (disponibilidad ? "Disponible" : "No disponible") << endl;
                        }
                        break;
                    }
                    else {
                        int opcion = 0;
                        cout << "No hay ningun medico registrado con ese codigo." << endl;
                        do {//si no hay ningun médico registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                            system("pause");
                            system("cls");
                            cout << "1. Registrar un medico" << endl;
                            cout << "2. Cancelar solicitud" << endl;
                            cout << "Ingrese una opcion:"; cin >> opcion;

                            switch (opcion) {
                            case 1:
                            {
                                contenedorMedicos.setRegistrarMedico(); //Aqui no es necesario darle a citas acceso a los getters que usa el setRegistraMedicos del contenedor de médicos, ya que con que el método tenga acceso es suficiente
                                break;
                            }
                            case 2:
                                cout << "Volviendo al menu..." << endl;
                                system("pause");
                                system("cls");
                                return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                            default:
                                break;
                            }
                        } while (opcion != 2);
                    }
                }
            }
            //ahora solicita los datos del paciente

            cout << "Ingrese el codigo del medico: "; cin >> cedulaUsuario;

            if (contenedorPacientes.getListaPacientes().empty()) {

                int opcion = 0;
                cout << "No hay ningun paciente registrado." << endl;
                do {//si no hay ningun paciente registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                    system("pause");
                    system("cls");
                    cout << "1. Registrar un paciente" << endl;
                    cout << "2. Cancelar solicitud" << endl;
                    cout << "Ingrese una opcion:"; cin >> opcion;

                    switch (opcion) {
                    case 1:
                    {
                        contenedorPacientes.setRegistrarPaciente();
                        break;
                    }
                    case 2:
                        cout << "Volviendo al menu..." << endl;
                        system("pause");
                        system("cls");
                        return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                    default:
                        break;
                    }
                } while (opcion != 2);
            }//si el contenedor de pacientes no estuviese vacio hace lo sgte
            else {
                for (int i = 0; i < contenedorPacientes.getListaPacientes().size(); i++) {

                    Pacientes* pacientes = contenedorPacientes.getListaPacientes()[i]; //con esto accedemos a un paciente por iteración 

                    if (pacientes->getCedula() == cedulaUsuario) { //si la cedula ya registrada se parece la cedula del paciente ya ingresado hace los siguiente...
                        break;
                    }
                    else {
                        int opcion = 0;
                        cout << "No hay ningun paciente registrado con esa cedula." << endl;
                        do {//si no hay ningun médico registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                            system("pause");
                            system("cls");
                            cout << "1. Registrar a un paciente" << endl;
                            cout << "2. Cancelar solicitud" << endl;
                            cout << "Ingrese una opcion:"; cin >> opcion;

                            switch (opcion) {
                            case 1:
                            {
                                contenedorPacientes.setRegistrarPaciente();
                                break;
                            }
                            case 2:
                                cout << "Volviendo al menu..." << endl;
                                system("pause");
                                system("cls");
                                return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                            default:
                                break;
                            }
                        } while (opcion != 2);
                    }
                }
            }
            //Ahora solicita los servicios

            cout << "Ingrese el codigo del servicio: "; cin >> codigoServicio;

            if (contenedorServicios.getListaServicios().empty()) {

                int opcion = 0;
                cout << "No hay ningun servicio registrado." << endl;
                do {//si no hay ningun servicio registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                    system("pause");
                    system("cls");
                    cout << "1. Registrar un servicio" << endl;
                    cout << "2. Cancelar solicitud" << endl;
                    cout << "Ingrese una opcion:"; cin >> opcion;

                    switch (opcion) {
                    case 1:
                    {
                        contenedorServicios.setRegistrarServicio(); //Llama a la funcion set del contenedor de servicios
                        break;
                    }
                    case 2:
                        cout << "Volviendo al menu..." << endl;
                        system("pause");
                        system("cls");
                        return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                    default:
                        break;
                    }
                } while (opcion != 2);
            }//si el contenedor de servicios no estuviese vacio hace lo sgte
            else {
                for (int i = 0; i < contenedorServicios.getListaServicios().size(); i++) {

                    Servicios* servicios = contenedorServicios.getListaServicios()[i]; //con esto accedemos a un servicio por iteración 

                    if (servicios->getCodigo() == codigoServicio) { //si el codigo del servicio que ya esta registrado se parece al codigo ya ingresado hace los siguiente...
                        break;
                    }
                    else {
                        int opcion = 0;
                        cout << "No hay ningun servicio registrado con esa codigo." << endl;
                        do {//si no hay ningun servicio registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                            system("pause");
                            system("cls");
                            cout << "1. Registrar a un paciente" << endl;
                            cout << "2. Cancelar solicitud" << endl;
                            cout << "Ingrese una opcion:"; cin >> opcion;

                            switch (opcion) {
                            case 1:
                            {
                                contenedorServicios.setRegistrarServicio();
                                break;
                            }
                            case 2:
                                cout << "Volviendo al menu..." << endl;
                                system("pause");
                                system("cls");
                                return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                            default:
                                break;
                            }
                        } while (opcion != 2);
                    }
                }
                //habiendo cumplido con los requisitos para agendar, se le solicitan los datos
                cin.ignore();
                cout << "Ingrese la fecha: "; getline(cin, fecha);//falta por completar eso y el requisito 5.1.3
            }
        }//caso contrario, el vecotr de citas no esta vacio...
        //tiene que recorrer citas, para ver si el paciente se encuentra en el sistema, en caso de estarlo se le solicitará la fecha de la cita, si ya hay una cita para esa fecha de esa misma persona, no se le permite agendar otra, peri se le permite si es en un dia distinto
        else {
            cout << "Ingrese la cedula del paciente: "; cin >> cedulaUsuario;

            for (int i = 0; i < this->getListaCitas().size(); i++) {

                Citas* citas = listaCitas[i];//con esto accede al puntero citas en cada iteracion

                if (citas->getCedulaUsuario() == cedulaUsuario) { //se usa el -> en lugar de . porque se trata con punteros y no con instancias de objetos
                    //se verifica si  el paciente se encuentra registrado
                    cin.ignore();
                    cout << "Ingrese una fecha para agendar una cita: "; getline(cin, fecha);

                    if (citas->getFecha() == fecha) {
                        cout << "No se permite que el paciente agende otra cita para el mismo dia." << endl;
                        system("pause");
                        system("cls");
                        return;
                    }
                    else { //si la fehca no es la misma, entonces solicita los otros datos de la cita
                        //aqui es distinto que cuando el vector estaba vacio
                        cout << "Ingrese el codigo de un medico: "; cin >> codigoMedico;

                        for (int i = 0; i < contenedorMedicos.getListaMedicos().size(); i++) {

                            Medicos* medicos = contenedorMedicos.getListaMedicos()[i]; //con esto accedemos a un medico por iteración 

                            if (medicos->getCodigo() == codigoMedico) { //si el codigo ya registrado se parece al codigo medco ya ingresado hace los siguiente...
                                break;
                            }
                            else {
                                int opcion = 0;
                                cout << "No hay ningun medico registrado con ese codigo." << endl;
                                do {//si no hay ningun médico registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                                    system("pause");
                                    system("cls");
                                    cout << "1. Registrar un medico" << endl;
                                    cout << "2. Cancelar solicitud" << endl;
                                    cout << "Ingrese una opcion:"; cin >> opcion;

                                    switch (opcion) {
                                    case 1:
                                    {
                                        contenedorMedicos.setRegistrarMedico(); //Aqui no es necesario darle a citas acceso a los getters que usa el setRegistraMedicos del contenedor de médicos, ya que con que el método tenga acceso es suficiente
                                        break;
                                    }
                                    case 2:
                                        cout << "Volviendo al menu..." << endl;
                                        system("pause");
                                        system("cls");
                                        return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                                    default:
                                        break;
                                    }
                                } while (opcion != 2);

                                }
                            }

                        //ahora solicta servicio
                        cout << "Ingrese el codigo de un servicio: "; cin >> codigoServicio;

                        for (int i = 0; i < contenedorServicios.getListaServicios().size(); i++) {

                            Servicios* servicios = contenedorServicios.getListaServicios()[i]; //con esto accedemos a un servicio por iteración 

                            if (servicios->getCodigo() == codigoServicio) { //si el codigo del servicio que ya esta registrado se parece al codigo ya ingresado hace los siguiente...
                                break;
                            }
                            else {
                                int opcion = 0;
                                cout << "No hay ningun servicio registrado con esa codigo." << endl;
                                do {//si no hay ningun servicio registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                                    system("pause");
                                    system("cls");
                                    cout << "1. Registrar a un paciente" << endl;
                                    cout << "2. Cancelar solicitud" << endl;
                                    cout << "Ingrese una opcion:"; cin >> opcion;

                                    switch (opcion) {
                                    case 1:
                                    {
                                        contenedorServicios.setRegistrarServicio();
                                        break;
                                    }
                                    case 2:
                                        cout << "Volviendo al menu..." << endl;
                                        system("pause");
                                        system("cls");
                                        return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                                    default:
                                        break;
                                    }
                                } while (opcion != 2);
                            }
                        }
                        //tengo que solicitar los otros datos aun de la cita
                    }//else del caso en caso de la fecha no sea la misma
                }
                else {
                    //en caso de que el paciente no se encuentra registrado
                    int opcion = 0;
                    cout << "No hay ningun paciente registrado con esa cedula." << endl;
                    do {//si no hay ningun médico registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                        system("pause");
                        system("cls");
                        cout << "1. Registrar a un paciente" << endl;
                        cout << "2. Cancelar solicitud" << endl;
                        cout << "Ingrese una opcion:"; cin >> opcion;

                        switch (opcion) {
                        case 1:
                        {
                            contenedorPacientes.setRegistrarPaciente();
                            break;
                        }
                        case 2:
                            cout << "Volviendo al menu..." << endl;
                            system("pause");
                            system("cls");
                            return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                        default:
                            break;
                        }
                    } while (opcion != 2);

                    //ahora solicita medico otra vez
                    cout << "Ingrese el codigo de un medico: "; cin >> codigoMedico;

                    for (int i = 0; i < contenedorMedicos.getListaMedicos().size(); i++) {

                        Medicos* medicos = contenedorMedicos.getListaMedicos()[i]; //con esto accedemos a un medico por iteración 

                        if (medicos->getCodigo() == codigoMedico) { //si el codigo ya registrado se parece al codigo medco ya ingresado hace los siguiente...
                            break;
                        }
                        else {
                            int opcion = 0;
                            cout << "No hay ningun medico registrado con ese codigo." << endl;
                            do {//si no hay ningun médico registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                                system("pause");
                                system("cls");
                                cout << "1. Registrar un medico" << endl;
                                cout << "2. Cancelar solicitud" << endl;
                                cout << "Ingrese una opcion:"; cin >> opcion;

                                switch (opcion) {
                                case 1:
                                {
                                    contenedorMedicos.setRegistrarMedico(); //Aqui no es necesario darle a citas acceso a los getters que usa el setRegistraMedicos del contenedor de médicos, ya que con que el método tenga acceso es suficiente
                                    break;
                                }
                                case 2:
                                    cout << "Volviendo al menu..." << endl;
                                    system("pause");
                                    system("cls");
                                    return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                                default:
                                    break;
                                }
                            } while (opcion != 2);

                        }
                    }
                    //ahora solicita servicio otra vez
                    cout << "Ingrese el codigo de un servicio: "; cin >> codigoServicio;

                    for (int i = 0; i < contenedorServicios.getListaServicios().size(); i++) {

                        Servicios* servicios = contenedorServicios.getListaServicios()[i]; //con esto accedemos a un servicio por iteración 

                        if (servicios->getCodigo() == codigoServicio) { //si el codigo del servicio que ya esta registrado se parece al codigo ya ingresado hace los siguiente...
                            break;
                        }
                        else {
                            int opcion = 0;
                            cout << "No hay ningun servicio registrado con esa codigo." << endl;
                            do {//si no hay ningun servicio registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
                                system("pause");
                                system("cls");
                                cout << "1. Registrar a un paciente" << endl;
                                cout << "2. Cancelar solicitud" << endl;
                                cout << "Ingrese una opcion:"; cin >> opcion;

                                switch (opcion) {
                                case 1:
                                {
                                    contenedorServicios.setRegistrarServicio();
                                    break;
                                }
                                case 2:
                                    cout << "Volviendo al menu..." << endl;
                                    system("pause");
                                    system("cls");
                                    return; //cuando se seleccione este caso, el return garantiza que salga completamente del método 
                                default:
                                    break;
                                }
                            } while (opcion != 2);
                        }
                    }
                    //falta solicitar los otros datos de la cita

                }
            }
        }
    }


    void menuCitas() {
        int opcion;
        do {
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

            switch (opcion) {
            case 1:
                setAgendarCita();
                system("pause"); 
                break;
            case 2:
                // getModificar();
                break;
            case 3:
                // getConsultar();
                break;
            case 4:
                // guardarEnArchivo();
                break;
            case 5:
                // recuperarDeArchivo();
                break;
            case 6:
                cout << "Regresando al menu principal." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
            system("pause");
        } while (opcion != 6);
    }
};
