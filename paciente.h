#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>
#include <iostream>

class Paciente {
private:
    int id;
    std::string nombre;
    std::string fechaIngreso;
    std::string enfermedades;
    std::vector<std::string> historialClinico;

public:
    Paciente();
    Paciente(int id, std::string nombre, std::string fechaIngreso, std::string enfermedades);
    ~Paciente();

    void registrarPaciente();
    void mostrarPaciente() const;
    void modificarDatos(std::string nuevoNombre);
    void agregarHistorial(std::string diagnostico);
    void mostrarHistorial() const;
    std::string getFechaIngreso() const;
    std::string getEnfermedades() const;
    int getId() const;
    std::string getNombre() const;
};

#endif