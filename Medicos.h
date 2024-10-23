#pragma once
#include "Librerias.h"
#include "Persona.h"

class Medicos : public Persona
{
private:
	int codigo;
	string disponibilidad;

public:
	Medicos(int _codigo, string _nombre, string _telefono, string _correo, string _disponibilidad) : Persona(_nombre, _correo, _telefono )
	{
		this->codigo = _codigo;
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
	
	void setDisponibilidad(string _disponibilidad)
	{
		this->disponibilidad = _disponibilidad;
	}
	
	string getDisponibilidad()
	{
		return this->disponibilidad;
	}

	//Metodo que muestra datos del medico utilizando polimosrfismo
	void getMostrarDatos() override
	{
		cout << "................Datos del medico............" << endl;
		Persona::getMostrarDatos();
		cout << "Codigo: " << getCodigo() << endl;
		cout << "Disponibilidad: " << getDisponibilidad() << endl;
		cout << "............................................." << endl;
	}
};
