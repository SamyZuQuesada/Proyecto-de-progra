#include"Librerias.h"
#include"Persona.h"

class Pacientes : public Persona
{
private:
	string apellido;
	string fechaRegistro;

public:
	Pacientes(string _nombre, string _apellido, int _cedula, int _telefono, string _correo, string _fechaRegistro) : Persona(_nombre, _cedula, _telefono, _correo)
	{
		this->apellido = _apellido;
		this->fechaRegistro = _fechaRegistro;
	}

	void setApellido(string _apellido)
	{
		this->apellido = _apellido;
	}
	
	string getApellido() const
	{
		return this->apellido;
	}

	void setFechaRegistro(string _fechaRegistro)
	{
		this->fechaRegistro = _fechaRegistro;
	}
	string getFechaRegistro() const
	{
		return this->fechaRegistro;
	}


	void getMostrarDatos() const override
	{
		cout << "................Datos del paciente............" << endl;
		Persona::getMostrarDatos();
		cout << "Apellido: " << getApellido() << endl;
		cout << "Fecha de registro: " << getFechaRegistro() << endl;
		cout << "............................................." << endl;
	}

};
