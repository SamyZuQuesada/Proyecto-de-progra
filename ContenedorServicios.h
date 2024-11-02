#pragma once
#include "Librerias.h"
#include "Servicios.h"
#include "Citas"
#include "ContenedorCitas.h"
class ContenedorCitas;
class ContenedorServicios
{
private:
	vector<Servicios*> listaServicios;
	ContenedorCitas* contenedorCitas;
public:
	

	ContenedorServicios(ContenedorCitas* contenedorCitas)
	{
		this->contenedorCitas = contenedorCitas;
	}
	
	const vector<Servicios*>& getListaServicios() const
	{
		return listaServicios;
	}

	void setRegistrarServicio()
	{
		int codigoServicio = 0;
		string descripcion;
		float costoServicio = 0;
		bool disponibilidad = true;

		//llamar archivo txt.servicios para que antes de registrar un nuevo servicio carguen los datos del archivo ya anteriormente registrados y guardados
		recuperarArchivo();


		cout << "Ingrese el codigo del servicio: ";
		cin >> codigoServicio;

		if (codigoServicio < 0) //se valida que el codigo sea un numero positivo.
		{
			cout << "Codigo no valido, ingrese un numero positivo " << endl;
			return;
		}

		for (int i = 0; i < listaServicios.size(); i++) {
			if (listaServicios[i]->getCodigoServicio() == codigoServicio) { //se compara codigo, si este se repite imprimira que ya existe un servicio con este mismo codigo.
				cout << "Ya hay un servicio registrado con este codigo." << endl;
				return;
			}
		}
		cin.ignore();
		do
		{

			cout << "Ingrese la descripcion del servicio: ";
			getline(cin, descripcion);
			cout << "Ingrese el costo del servicio: ";
			cin >> costoServicio;


			cout << "Disponibilidad del servicio: 1= disponible, 0= no disponible): " << endl;
			cin >> disponibilidad;

			// Validaciones para verificar que no se ingresen campos vacios.
			if (codigoServicio <= 0 || descripcion.empty() || costoServicio <= 0)
			{
				cout << "No se permiten campos vacios o en negativo" << endl;
				return;
			}
		} while (codigoServicio <= 0 || descripcion.empty() || costoServicio <= 0);

		Servicios* newServicio = new Servicios(codigoServicio, descripcion, costoServicio, disponibilidad);
		listaServicios.push_back(newServicio); //se agrega el nuevo servicio al vector de servicios.

		cout << "Servicio registrado con exito" << endl;

		system("cls");

		cout << "............. Lista de servicios registrados................." << endl;

		for (int i = 0; i < listaServicios.size(); i++)
		{
			listaServicios[i]->getMostrarServicios();

		}
		cout << ".............................................................." << endl;

	}
	void getModificarServicio()
	{
		int codigoServicio;
		string Nuevadescripcion;
		float Nuevocosto;
		bool Nuevadisponibilidad;

		if (listaServicios.empty())
		{
			cout << "No hay servicios registrados" << endl;
			return;
		}

		cout << "Ingrese su numero de codigo" << endl;
		cin >> codigoServicio;
		cin.ignore();

		if (codigoServicio < 0) {
			cout << "Codigo no valido, ingrese un numero positivo." << endl;
			return;
		}
		else {
			for (int i = 0; i < listaServicios.size(); i++)
			{
				if (listaServicios[i]->getCodigoServicio() == codigoServicio)
				{ //se verifica si el codigo existe



					cin.ignore();
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


					if (codigoServicio < 0 || Nuevadescripcion.empty() || Nuevocosto < 0)
					{
						cout << "No se permiten campos vacios" << endl;
						return;
					}

					listaServicios[i]->setDescripcion(Nuevadescripcion);
					listaServicios[i]->setCostoServicio(Nuevocosto);
					listaServicios[i]->setDisponibilidad(Nuevadisponibilidad);
					cout << "Servicio modificado con exito" << endl;

					system("cls");

					cout << "............. Lista de servicios registrados................." << endl;
					for (int i = 0; i < listaServicios.size(); i++)
					{

						listaServicios[i]->getMostrarServicios();
					}
					cout << "............................................................" << endl;
					return;
				}
			}
			cout << "No existe un servicio registrado con ese codigo" << endl;


		}
	}
	void consultarServicios()
	{

		int serviciosTotal = 0;
		int disponibilidad = 0;

		cout << "................Lista de servicios registrados................ " << endl;
		if (listaServicios.empty())
		{
			cout << "No hay datos para mostrar..." << endl;
		}
		else
		{
			for (int i = 0; i < contenedorCitas->getListaCitas().size(); i++)
			{
				//llamara contenedor cita para mostrar las citas
				//incompleto contenedorCitas->getConsultarCitas();
				
				cout << "........................................................." << endl;

				if (listaServicios[i]->getDisponibilidad())
				{
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
	void guardarEnArchivo()
	{
		ofstream archivo("Servicios.txt"); //se prepara el archivo 
		if (archivo.is_open())
		{
			for (int i = 0; i < listaServicios.size(); i++)
			{
				//almacena la informacion
				cout << "........................................................" << endl;
				archivo << listaServicios[i]->getCodigoServicio()
					<< "-" << listaServicios[i]->getDescripcion()
					<< "-" << listaServicios[i]->getCostoServicio()
					<< "-" << listaServicios[i]->getDisponibilidad()
					<< endl;
				cout << "........................................................." << endl;

			}
			archivo.close(); //se cierra el archivo
			cout << "Datos guardados correctamente en el archivo Servicios.txt" << endl;
		}
		else
		{
			cout << "No se pudo abrir el archivo" << endl;
		}
	}

	void recuperarArchivo()
	{
		listaServicios.clear();
		ifstream archivo("Servicios.txt");
		if (archivo.is_open())
		{
			string linea;
			while (getline(archivo, linea))
			{
				stringstream ss(linea);
				string codigoServicio, descripcion, costoServicio, disponibilidad;

				getline(ss, codigoServicio, '-');
				int _codigoServicio = stoi(codigoServicio);

				getline(ss, descripcion, '-');

				getline(ss, costoServicio, '-');

				float _costoServicio = stof(costoServicio);

				getline(ss, disponibilidad, '-');

				bool _disponibilidad = (disponibilidad == "1");


				Servicios* nuevoServicio = new Servicios(_codigoServicio, descripcion, _costoServicio, _disponibilidad);
				listaServicios.push_back(nuevoServicio);
			}
			archivo.close();
			cout << "Datos recuperados correctamente" << endl;
		}
		else
		{
			cout << "No se pudo abrir el archivo" << endl;
		}
	}



	void getConsultarCitaEspecifica()
	{
		int codigoServicio;
		bool encontrado = false;

		cout << "Ingrese el codigo del servicio que desea consultar: ";
		cin >> codigoServicio;

		system("cls");

		cout << ".........Cita medica registrada con el numero de servicio " << codigoServicio << "........." << endl;

		for (int i = 0; i < listaServicios.size(); i++)
		{
			if (listaServicios[i]->getCodigoServicio() == codigoServicio)
			{
				cout << "Servicio encontrado!" << endl;
				listaServicios[i]->getMostrarServicios();
				encontrado = true;
				break;
			}
		}
		if (!encontrado)
		{
			cout << "No se encontro el servicio" << endl;
		}
		cout << "..............................................." << endl;

	}




	void menuServicios()
	{
		system("cls");
		int opcion;
		do {

			system("cls");
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
				setRegistrarServicio();
				system("pause");
				break;
			}
			case 2:
			{
				getModificarServicio();
				system("pause");
				break;
			}
			case 3:
			{
				consultarServicios();
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
				recuperarArchivo();
				system("pause");

				break;
			}
			case 6:
			{
				getConsultarCitaEspecifica();
				system("pause");
				break;
			}
			case 7:
			{
				cout << "Regresando al menu principal..." << endl;
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

		} while (opcion != 7);


	}


};
