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
	const void getmostrarServicios() const
	{
		cout << "codigo: " << this->codigo << endl;
		cout << "descripcion: " << this->descripcion << endl;
		cout << "costo: " << this->costo << endl;
		cout << "disponibilidad: " << (disponibilidad ? "Activo" : "Inactivo") << endl;
		cout << "------------------------------------------" << endl;
		
	}

	void setCodigo(int _codigo)
	{
		this->codigo = _codigo;
	}
	const int getCodigo() const
	{
		return this->codigo;
	}


	void setDescripcion(string _descripcion)
	{
		this->descripcion = _descripcion;
	}

	const string getDescripcion() const
	{
		return this->descripcion;
	}

	void setCosto(float _costo)
	{
		this->costo = _costo;
	}
	const float getCosto() const
	{
		return this->costo;
	}

	void setDisponibilidad(bool _disponibilidad)
	{
		this->disponibilidad = _disponibilidad;
	}

	const bool getDisponibilidad() const
	{
		return this->disponibilidad;
	}
};
