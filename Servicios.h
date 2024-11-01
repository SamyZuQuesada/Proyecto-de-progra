#pragma once
#include "Librerias.h"

class Servicios
{
private:
	int codigo;
	string descripcion;
	float costo;
	bool disponibilidad;

public:
	Servicios(int _codigo, string _descripcion, float _costo, bool _disponibilidad)
	{
		this->codigo = _codigo;
		this->descripcion = _descripcion;
		this->costo = _costo;
		this->disponibilidad = _disponibilidad;
	}

	
	//metodos setter y getter

	void setCodigo(int _codigo)
	{
		this->codigo = _codigo;
	}
	int getCodigo()const
	{
		return this->codigo;
	}

	int getCodigoServicio() const {
		return this->codigo;
	}

	void setDescripcion(string _descripcion)
	{
		this->descripcion = _descripcion;
	}

	string getDescripcion()const
	{
		return this->descripcion;
	}

	void setCosto(float _costo)
	{
		this->costo = _costo;
	}
	float getCosto()const
	{
		return this->costo;
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
		cout << "Codigo: " << getCodigo() << endl;
		cout << "Descripcion: " << getDescripcion() << endl;
		cout << "Costo: $" << getCosto() << endl;
		cout << "Disponibilidad: " << (disponibilidad ? "Disponible" : "No disponible") << endl;
		cout << "................................................................." << endl;
	}
};
