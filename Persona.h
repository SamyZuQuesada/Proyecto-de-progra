
#pragma once
#include "Librerias.h"

class Persona
{
protected:

	string nombre;
	string telefono;
	string correo;

public:
	Persona(string _nombre, string _telefono, string _correo)
	{
		this->nombre = _nombre;
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

	void setTelefono(string _telefono)
	{
		this->telefono = _telefono;
	}
	string getTelefono() const
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
		cout << "Telefono: " << this->telefono << endl;
		cout << "Correo: " << this->correo << endl;
	}
};
