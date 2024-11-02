#pragma once
#include "Librerias.h"

class Servicios
{
private:
	int codigoServicio;
	string descripcion;
	float costoServicio;
	bool disponibilidad;

public:
	Servicios(int _codigoServicio, string _descripcion, float _costoServicio, bool _disponibilidad)
	{
		this->codigoServicio = _codigoServicio;
		this->descripcion = _descripcion;
		this->costoServicio = _costoServicio;
		this->disponibilidad = _disponibilidad;
	}

	
	//metodos setter y getter

	void setCodigoServicio(int _codigoServicio)
	{
		this->codigoServicio = _codigoServicio;
	}
	int getCodigoServicio()const
	{
		return this->codigoServicio;
	}

	void setDescripcion(string _descripcion)
	{
		this->descripcion = _descripcion;
	}

	string getDescripcion()const
	{
		return this->descripcion;
	}

	void setCostoServicio(float _costoServicio)
	{
		this->costoServicio = _costoServicio;
	}
	float getCostoServicio()const
	{
		return this->costoServicio;
	}

	void setDisponibilidad(bool _disponibilidad)
	{
		this->disponibilidad = _disponibilidad;
	}

	bool getDisponibilidad()
	{
		return this->disponibilidad;
	}



	void getMostrarServicios()const
	{
		cout << "..................Datos del servicio.............................." << endl;
		cout << "Codigo: " << getCodigoServicio() << endl;
		cout << "Descripcion: " << getDescripcion() << endl;
		cout << "Costo: $" << getCostoServicio() << endl;
		cout << "Disponibilidad: " << (disponibilidad ? "Disponible" : "No disponible") << endl;
		cout << "................................................................." << endl;
	}
};
