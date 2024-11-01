#pragma once
#include "Librerias.h"
#include "Persona.h"

class Pacientes : public Persona
{
private:
    string apellido;
    string fechaRegistro;

public:
    Pacientes(int _cedula, string _nombre, int _telefono, string _correo, string _apellido, string _fechaRegistro) : Persona(_cedula, _nombre, _telefono, _correo)
    {
        this->apellido = _apellido;
        this->fechaRegistro = _fechaRegistro;
    }

    // Métodos setter y getter
    void setApellido(const string& _apellido)
    {
        this->apellido = _apellido;
    }

    const string& getApellido() const
    {
        return this->apellido;
    }

    void setFechaRegistro(const string& _fechaRegistro)
    {
        this->fechaRegistro = _fechaRegistro;
    }

    const string& getFechaRegistro() const
    {
        return this->fechaRegistro;
    }

    // Método que muestra datos del paciente utilizando polimorfismo
    void getMostrarDatos() const override
    {
        cout << "................Datos del paciente............" << endl;
        Persona::getMostrarDatos();
        cout << "Apellido: " << getApellido() << endl;
        cout << "Fecha de registro en formato: DD/MM/AAAA: " << getFechaRegistro() << endl;
        cout << "..............................................." << endl;
    }
};
