

#pragma once
#include "Librerias.h"
#include "Servicios.h"
class ContenedorServicios
{
private:
	vector<Servicios*> listaServicios;

public:
	void setRegistrarServicio()
	{
		int codigo = 0;
		string descripcion;
		float costo = 0;
		bool disponibilidad = true;

		//llamar archivo txt.servicios para que antes de registrar un nuevo servicio carguen los datos del archivo ya anteriormente registrados y guardados
		recuperarArchivo();


		cout << "Ingrese el codigo del servicio: ";
		cin >> codigo;

		if (codigo < 0) //se valida que el codigo sea un numero positivo.
		{
			cout << "Codigo no valido, ingrese un numero positivo con un maximo de 4 digitos " << endl;
			return;
		}

		for (int i = 0; i < listaServicios.size(); i++) {
			if (listaServicios[i]->getCodigoServicio() == codigo) { //se compara codigo, si este se repite imprimira que ya existe un servicio con este mismo codigo.
				cout << "Ya hay un servicio registrado con este codigo." << endl;
				return;
			}
		}
		cin.ignore();
		cout << "Ingrese la descripcion del servicio: ";
		getline(cin, descripcion);
		cout << "Ingrese el costo del servicio: ";
		cin >> costo;


		// Validaciones para verificar que no se ingresen campos vacios.
		if (codigo <= 0 || descripcion.empty() || costo <= 0)
		{
			cout << "No se permiten campos vacios o en negativo" << endl;
			return;
		}

		Servicios* newServicio = new Servicios(codigo, descripcion, costo, disponibilidad);
		listaServicios.push_back(newServicio); //se agrega el nuevo servicio al vector de servicios.

		cout << "Servicio registrado con exito" << endl;

		for (int i = 0; i < listaServicios.size(); i++)
		{
			listaServicios[i]->getMostrarDatos();

		}

	}
	void getModificarServicio()
	{
		int codigo, cuenta = 0;
		string Nuevadescripcion;
		float Nuevocosto;
		bool Nuevadisponibilidad;

		cout << "Ingrese su numero de codigo" << endl;
		cin >> codigo;
		if (codigo <= 0) {
			cout << "Codigo no valido, ingrese un numero positivo." << endl;
			return;
		}
		for (int i = 0; i < listaServicios.size(); i++)
		{
			if (listaServicios[i]->getCodigoServicio() == codigo)
			{ //se verifica si el codigo existe



				cin.ignore();
				cout << "Ingrese la nueva descripcion del servicio: " << endl;
				getline(cin, Nuevadescripcion);

				cout << "Ingrese el nuevo costo del servicio: " << endl;
				cin >> Nuevocosto;

				cout << "Ingrese la nueva disponibilidad del servicio: 1= disponible, 0= no disponible): " << endl;
				cin >> Nuevadisponibilidad;
				if (Nuevadisponibilidad == 1) {
					cout << "Ahora el servicio esta disponible." << endl;
				}
				else {
					cout << "Ahora el servicio no esta disponible." << endl;
				}






				if (codigo <= 0 || Nuevadescripcion.empty() || Nuevocosto <= 0)
				{
					cout << "No se permiten campos vacios" << endl;
					return;
				}

				for (int i = 0; i < listaServicios.size(); i++) {
					if (listaServicios[i]->getCodigoServicio() == codigo) {
						listaServicios[i]->setDescripcion(Nuevadescripcion);
						listaServicios[i]->setCosto(Nuevocosto);
						listaServicios[i]->setDisponibilidad(Nuevadisponibilidad);
						cout << "Servicio modificado con exito" << endl;



					}
				}

				for (int i = 0; i < listaServicios.size(); i++)
				{
					listaServicios[i]->getMostrarDatos();

				}
				cuenta = 1;
			}
		}if (cuenta == 1) { cout << "se guardo correctamente el cambio de servicio" << endl; }
		else { cout << "el codigo no fue encontrado" << endl; }
	}
	void consultarServicios()
	{

		for (int i = 0; i < listaServicios.size(); i++)
		{
			cout << "----------------------------------" << endl;
			cout << "Servicio #" << i << ":" << endl;
			listaServicios[i]->getMostrarDatos();
			cout << ".                                 ." << endl;
		}
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
					<< "-" << listaServicios[i]->getCosto()
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
		else
		{
			cout << "No se pudo abrir el archivo" << endl;
		}
	}
	void getConsultarCitaEspecifica()
	{

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

