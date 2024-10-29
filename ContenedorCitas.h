#pragma once
#include "Librerias.h" //las clases necesarias para que esto funcione se encuentran dentro de librerias

class ContenedorCitas {
private:
	vector<Citas*> listaCitas;

	 vector<Medicos*>& listaMedicos; //referencia constante al vector de medicos
	 ContenedorMedicos* contenedorMedicos; //pareciera que esto se puede declarar bajo la etiqueta public:

	 vector<Servicios*>& listaServicios; //referencia constante al vector de servicios
	 ContenedorServicios* contenedorServicos;

	 vector<Pacientes*>& listaPacientes; //referencia constante al vector de pacientes
	 ContenedorPacientes* contenedorPacientes;
	
public:

	void setAgendarCita() {											
															
		int numeroCita;
		int cedulaUsuario; //cedulaUsuario se refiere al paciente
		int codigoMedico;
		string fecha;
		int codigoServicio;
		float costoTotal;

		//recuperarArchivo(); //esto hay que arreglarlo

		
		if (listaCitas.empty()) {   //si lista citas esta vacio, entonces solicita los datos del medico
			cout << "Ingrese el codigo del medico: "; cin >> codigoMedico;
			//si el vector listaCitas no está vacío, se salta todo este bloque de código hasta la línea 55
			for (int i = 0; i < listaMedicos.size(); i++) {
				if (listaMedicos.empty()) {
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
							contenedorMedicos->setRegistrarMedico(); //Aqui no es necesario darle a citas acceso a los getters que usa el setRegistraMedicos del contenedor de médicos, ya que con que el método tenga acceso es suficiente
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
					break;
				}//caso contrario, listaMedicos no está vacío, se inicia la validación para ver si el código del médico ingresado se encuentra registrado.
				else {
					if (listaMedicos[i]->getCodigo() == codigoMedico) {  //si se encuentra el medico, se salta todo el bloque 60-83
						break; //esto es para que siga con la solicitud, solo se interrumpe la solicitud cuando no cumple con los requisitos (solo los medicos, pacientes y servicios registrados pueden agendar citas).
					}//deberia de informar que sí se encontró al médico?
					else {
						int opcion = 0;
						cout << "No se encontro ningun medico registrado con ese codigo." << endl;
						do {
							system("pause");
							system("cls");
							cout << "1. Registrar un medico" << endl;
							cout << "2. Cancelar solicitud" << endl;
							cout << "Ingrese una opcion:"; cin >> opcion;

							switch (opcion) {
							case 1:
							{
								contenedorMedicos->setRegistrarMedico(); 
								break;
							}
							case 2:
								cout << "Volviendo al menu..." << endl;
								system("pause");
								system("cls");   
								return;
							default:
								break;
							}
						} while (opcion != 2);
						break;
						}
					//continua con la solicitud
					break;
					}
					break; //break del for de listaMedicos
				}

			//continua la solicitud pero ahora con paciente

			cout << "Ingrese la cedula del paciente: "; cin >> cedulaUsuario;
			
			for (int i = 0; i < listaPacientes.size(); i++) {
				if (listaPacientes.empty()) {
					int opcion = 0;
					cout << "No hay ningun paciente registrado." << endl;
					do {//si no hay ningun paciente registrado se da a elegir al usuario entre cancelar la solicitud, o registrar el médico
						system("pause");
						system("cls");
						cout << "1. Registrar un medico" << endl;
						cout << "2. Cancelar solicitud" << endl;
						cout << "Ingrese una opcion:"; cin >> opcion;

						switch (opcion) {
						case 1:
						{
							contenedorPacientes->setRegistrarPaciente(); //Aqui no es necesario darle a citas acceso a los getters que usa el setRegistraMedicos del contenedor de médicos, ya que con que el método tenga acceso es suficiente
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
					break;
				}//caso contrario, listaMedicos no está vacío, se inicia la validación para ver si el código del médico ingresado se encuentra registrado.
				else {
					if (listaMedicos[i]->getCodigo() == codigoMedico) {  //si se encuentra el medico, se salta todo el bloque 60-83
						break; //esto es para que siga con la solicitud, solo se interrumpe la solicitud cuando no cumple con los requisitos (solo los medicos, pacientes y servicios registrados pueden agendar citas).
					}//deberia de informar que sí se encontró al médico?
					else {
						int opcion = 0;
						cout << "No se encontro ningun medico registrado con ese codigo." << endl;
						do {
							system("pause");
							system("cls");
							cout << "1. Registrar un medico" << endl;
							cout << "2. Cancelar solicitud" << endl;
							cout << "Ingrese una opcion:"; cin >> opcion;

							switch (opcion) {
							case 1:
							{
								contenedorMedicos->setRegistrarMedico();
								break;
							}
							case 2:
								cout << "Volviendo al menu..." << endl;
								system("pause");
								system("cls");
								return;
							default:
								break;
							}
						} while (opcion != 2);
						break;
					}
					//continua con la solicitud
					break;
				}
				break; //break del for de listaMedicos
			}
		}
		else {
			//en caso de que la lista de citas no este vacia se hace esto....
		}

		}//llave del metodo
