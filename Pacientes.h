#pragma once
#include "Librerias.h"
#include "Persona.h"

class Pacientes : public Persona
{
private:
	int cedula;
	string apellido;
	string fechaRegistro;

public:
	Pacientes(string _nombre, string _telefono, string _correo, string _apellido, int _cedula, string _fechaRegistro) : Persona(_nombre, _correo, _telefono)
	{
		this->cedula = _cedula;
		this->apellido = _apellido;
		this->fechaRegistro = _fechaRegistro;
	}

	//metodos setter y getter

	void setCedula(const int _cedula)
	{
		this->cedula = _cedula;
	}

	const int getCedula() const
	{
		return this->cedula;
	}

	void setApellido(const string _apellido)
	{
		this->apellido = _apellido;
	}
	const string getApellido() const
	{
		return this->apellido;
	}

	void setFechaRegistro(const string _fechaRegistro)
	{
		this->fechaRegistro = _fechaRegistro;
	}
	const string getFechaRegistro() const
	{
		return this->fechaRegistro;
	}

	//Metodo que muestra datos del paciente utilizando polimosrfismo
	void getMostrarDatos() const override
	{
		cout << "................Datos del paciente............" << endl;
		Persona::getMostrarDatos();
		cout << "Apellido: " << getApellido() << endl;
		cout << "Cedula: " << getCedula() << endl;
		cout << "Fecha de registro: " << getFechaRegistro() << endl;
		cout << "..............................................." << endl;
	}
	
	};
