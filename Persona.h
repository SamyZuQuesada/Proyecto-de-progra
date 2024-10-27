
#pragma once
#include "Librerias.h"

class Persona
{
protected:

	string nombre;
	int cedula;
	int telefono;
	string correo;

public:
	Persona(string _nombre, int _cedula, int _telefono, string _correo)
	{
		this->nombre = _nombre;
		this->cedula = _cedula;
		this->telefono = _telefono;
		this->correo = _correo;
	}

	//metodos setter y getter

	void setNombre(string _nombre)
	{
		this->nombre = _nombre;
	}

	string getNombre() const
	{
		return this->nombre;
	}

	void setCedula(int _cedula)
	{
		this->cedula = _cedula;
	}

	int getCedula() const
	{
		return this->cedula;
	}

	void setTelefono(int _telefono)
	{
		this->telefono = _telefono;
	}
	int getTelefono() const
	{
		return this->telefono;
	}
	void setCorreo(string _correo)
	{
		this->correo = _correo;
	}
	string getCorreo() const
	{
		return this->correo;
	}

	virtual void getMostrarDatos() const
	{
		cout << "Nombre: " << this->nombre << endl;
		cout << "Cedula: " << this->cedula << endl;
		cout << "Telefono: " << this->telefono << endl;
		cout << "Correo: " << this->correo << endl;
	}
};
