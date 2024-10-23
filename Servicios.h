#pragma once
#include "Librerias.h"

class Servicios
{
private:
	int codigo;
	string descripcion;
	float costo;
	string disponibilidad;

public:
	Servicios(int _codigo, string _descripcion, float _costo, string _disponibilidad)
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
	int getCodigo()
	{
		return this->codigo;
	}

	
	void setDescripcion(string _descripcion)
	{
		this->descripcion = _descripcion;
	}

	string getDescripcion()
	{
		return this->descripcion;
	}

	void setCosto(float _costo)
	{
		this->costo = _costo;
	}
	float getCosto()
	{
		return this->costo;
	}

	void setDisponibilidad(string _disponibilidad)
	{
		this->disponibilidad = _disponibilidad;
	}

	string getDisponibilidad()
	{
		return this->disponibilidad;
	}
};