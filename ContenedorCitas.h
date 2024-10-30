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

public:
    void setAgendarCita() {
        int numeroCita, cedulaUsuario, codigoMedico, codigoServicio;
        string fecha;
        float costoTotal;
        int contador = 1;

        // Verifica si la lista de citas está vacía
        if (listaCitas.empty())
        {
            cout << "Ingrese el codigo del medico: ";
            cin >> codigoMedico;

            // Si no hay médicos registrados, ofrece registrar o cancelar
            if (contenedorMedicos.getListaMedicos().empty()) {
                if (!manejarRegistroEntidad("medico")) return; // Si elige cancelar, sale del método
            }
            else {
                // Verifica si el código ingresado pertenece a un médico registrado
                if (!validarCodigoMedico(codigoMedico)) {
                    if (!manejarRegistroEntidad("medico")) return; // Si elige cancelar, sale del método
                }
            }

            // Solicita y valida el paciente
            cout << "Ingrese la cedula del paciente: ";
            cin >> cedulaUsuario;
            if (contenedorPacientes.getListaPacientes().empty()) {
                if (!manejarRegistroEntidad("paciente")) return; // Si elige cancelar, sale del método
            }
            else {
                if (!validarCedulaPaciente(cedulaUsuario)) {
                    if (!manejarRegistroEntidad("paciente")) return; // Si elige cancelar, sale del método
                }
            }
            // Continúa con la lógica para agendar la cita aquí...
        }
        else {
            // Lógica si la lista de citas no está vacía
        }
    }

    bool validarCodigoMedico(int codigoMedico) const
    {
        const auto& listaMedicos = contenedorMedicos.getListaMedicos();
        for (int i = 0; i < listaMedicos.size(); i++)
        {
            if (listaMedicos[i]->getCodigo() == codigoMedico)
            {
                return true;
            }
        }
        cout << "No se encontro ningun médico registrado con ese codigo." << endl;
        return false;
    }


    bool validarCedulaPaciente(int cedulaUsuario) const
    {
        const auto& listaPacientes = contenedorPacientes.getListaPacientes();
        for (int i = 0; i < listaPacientes.size(); i++)
        {
            if (listaPacientes[i]->getCedula() == cedulaUsuario)
            {
                return true;
            }
        }
        cout << "No se encontro ningun paciente registrado con esa cedula." << endl;
        return false;
    }

    // Función genérica para manejar el registro de entidades (médico o paciente)
    bool manejarRegistroEntidad(const string& entidad) {
        int opcion;
        do {
            cout << "1. Registrar un " << entidad << "\n2. Cancelar solicitud\nIngrese una opcion: ";
            cin >> opcion;
            if (opcion == 1) {
                if (entidad == "medico") contenedorMedicos.setRegistrarMedico();
                else if (entidad == "paciente") contenedorPacientes.setRegistrarPaciente();
                return true;
            }
            else if (opcion == 2) {
                cout << "Volviendo al menu..." << endl;
                return false;
            }
            else {
                cout << "Opcion no valida." << endl;
            }
        } while (opcion != 2);
        return false;
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
