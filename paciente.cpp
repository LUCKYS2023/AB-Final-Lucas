#include "Paciente.h"

Paciente::Paciente() : id(0), nombre(""), fechaIngreso(""), enfermedades("") {}

Paciente::Paciente(int id, std::string nombre, std::string fechaIngreso, std::string enfermedades)
    : id(id), nombre(nombre), fechaIngreso(fechaIngreso), enfermedades(enfermedades) {}

Paciente::~Paciente() {}

void Paciente::registrarPaciente() {
    std::cout << "Ingrese ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese Enfermedades (separadas por comas): ";
    std::getline(std::cin, enfermedades);
    std::cout << "Ingrese Fecha de Ingreso (DD-MM-YYYY): ";
    std::getline(std::cin, fechaIngreso);
}

void Paciente::mostrarPaciente() const {
    std::cout << "ID: " << id << "\nNombre: " << nombre
              << "\nEnfermedades: " << enfermedades
              << "\nFecha de ingreso: " << fechaIngreso << "\n";
}

void Paciente::modificarDatos(std::string nuevoNombre) {
    nombre = nuevoNombre;
}

void Paciente::agregarHistorial(std::string diagnostico) {
    historialClinico.push_back(diagnostico);
}

void Paciente::mostrarHistorial() const {
    std::cout << "Historial Clinico:\n";
    for (const auto& registro : historialClinico) {
        std::cout << "- " << registro << "\n";
    }
}

std::string Paciente::getFechaIngreso() const {
    return fechaIngreso;
}

std::string Paciente::getEnfermedades() const {
    return enfermedades;
}

int Paciente::getId() const {
    return id;
}

std::string Paciente::getNombre() const {
    return nombre;
}
