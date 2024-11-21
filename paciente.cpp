#include "Paciente.h"
#include <iostream>

Paciente::Paciente() : id(0), nombre(""), fechaIngreso("") {}
Paciente::Paciente(int id, std::string nombre, std::string fechaIngreso) 
    : id(id), nombre(nombre), fechaIngreso(fechaIngreso) {}
Paciente::~Paciente() {}

void Paciente::registrarPaciente() {
    std::cout << "Ingrese ID del paciente: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese nombre del paciente: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese fecha de ingreso: ";
    std::getline(std::cin, fechaIngreso);
}

void Paciente::modificarDatos(std::string nuevoNombre) {
    nombre = nuevoNombre;
}

void Paciente::agregarHistorial(std::string diagnostico) {
    historialClinico.push_back(diagnostico);
}

void Paciente::mostrarHistorial() {
    std::cout << "Historial Clínico de " << nombre << ":\n";
    for (const auto& registro : historialClinico) {
        std::cout << "- " << registro << "\n";
    }
}

int Paciente::getId() const {
    return id;
}

std::string Paciente::getNombre() const {
    return nombre;
}

