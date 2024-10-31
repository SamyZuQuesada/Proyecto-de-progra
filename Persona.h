#pragma once
#include "Librerias.h"

class Persona
{
protected:
	int cedula;
	string nombre;
	int telefono;
	string correo;
	
	
public:
	Persona(int _cedula, string _nombre, int _telefono, string _correo)
	{
		this->cedula = _cedula;
		this->nombre = _nombre;
		this->telefono = _telefono;
		this->correo = _correo;
	
	}


	//metodos setter y getter
	
	void setCedula(int _cedula)
	{
		this->cedula = _cedula;
	}
	
	int getCedula() const
	{
		return this->cedula;
	}
	
	void setNombre(string _nombre)
	{
		this->nombre = _nombre;
	}

	string getNombre() const
	{
		return this->nombre;
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
		cout << "Cedula: " << getCedula() << endl;
		cout << "Nombre: " << getNombre() << endl;
		cout << "Telefono: " << getTelefono() << endl;
		cout << "Correo: " << getCorreo() << endl;
		
    }
};

