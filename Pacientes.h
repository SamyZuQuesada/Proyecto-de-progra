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

	void setCedula(int _cedula)
	{
		this->cedula = _cedula;
	}
	int getCedula()
	{
		return this->cedula;
	}

	void setApellido(string _apellido)
	{
		this->apellido = _apellido;
	}
	string getApellido()
	{
		return this->apellido;
	}

	void setFechaRegistro(string _fechaRegistro)
	{
		this->fechaRegistro = _fechaRegistro;
	}
	string getFechaRegistro()
	{
		return this->fechaRegistro;
	}

	//Metodo que muestra datos del paciente utilizando polimosrfismo
	void getMostrarDatos() override
	{
		cout << "................Datos del paciente............" << endl;
		Persona::getMostrarDatos();
		cout << "Apellido: " << getApellido() << endl;
		cout << "Cedula: " << getCedula() << endl;
		cout << "..............................................." << endl;
	}
	
	};