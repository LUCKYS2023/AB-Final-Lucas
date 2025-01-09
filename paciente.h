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

    void regisPac();
    void mostrarPac() const;
    void modifiDato(std::string nuevoNombre);
    void agregarHist(std::string diagnostico);
    void mostrarHist() const;
    std::string getFechaIng() const;
    std::string getEnfe() const;
    int getId() const;
    std::string getNombre() const;
};

#endif