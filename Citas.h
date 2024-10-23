#pragma once
#include "Librerias.h"


class Citas
{
private:
	int numeroCita;
	int cedulaUsuario;
	int codigoMedico;
	string fecha;
	int codigoServicio;
	float costoTotal;

public:
	Citas(int _numeroCita, int _cedulaUsuario, int _codigoMedico, string _fecha, int _codigoServicio, float _costoTotal)
	{
		this->numeroCita = _numeroCita;
		this->cedulaUsuario = _cedulaUsuario;
		this->codigoMedico = _codigoMedico;
		this->fecha = _fecha;
		this->codigoServicio = _codigoServicio;
		this->costoTotal = _costoTotal;
	}

	// Getters y Setters
	void setNumeroCita(int _numeroCita)
	{
		this->numeroCita = _numeroCita;
	}
	int getNumeroCita()
	{
		return this->numeroCita;
	}

	void setCedulaUsuario(int _cedulaUsuario)
	{
		this->cedulaUsuario = _cedulaUsuario;
	}
	int getCedulaUsuario()
	{
		return this->cedulaUsuario;
	}

	void setCodigoMedico(int _codigoMedico)
	{
		this->codigoMedico = _codigoMedico;
	}
	int getCodigoMedico()
	{
		return this->codigoMedico;
	}

	void setFecha(string _fecha)
	{
		this->fecha = _fecha;
	}
	string getFecha()
	{
		return this->fecha;
	}

	void setCodigoServicio(int _codigoServicio)
	{
		this->codigoServicio = _codigoServicio;
	}
	int getCodigoServicio()
	{
		return this->codigoServicio;
	}

	void setCostoTotal(float _costoTotal)
	{
		this->costoTotal = _costoTotal;
	}
	float getCostoTotal()
	{
		return this->costoTotal;
	}

	void getMostrarDatos()
	{
		cout << "................Datos de la cita............" << endl;
		cout << "Numero de cita: " << getNumeroCita() << endl;
		cout << "Cedula del usuario: " << getCedulaUsuario() << endl;
		cout << "Codigo del medico: " << getCodigoMedico() << endl;
		cout << "Fecha: " << getFecha() << endl;
		cout << "Codigo del servicio: " << getCodigoServicio() << endl;
		cout << "................................................" << endl;

	}


	};