#include "Paciente.h"

Paciente::Paciente() : id(0), nombre(""), fechaIngreso(""), enfermedades("") {}

Paciente::Paciente(int id, std::string nombre, std::string fechaIngreso, std::string enfermedades)
    : id(id), nombre(nombre), fechaIngreso(fechaIngreso), enfermedades(enfermedades) {}

Paciente::~Paciente() {}

void Paciente::regisPac() {
    std::cout << "Ingrese ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese enfermedades (separadas por comas): ";
    std::getline(std::cin, enfermedades);
    std::cout << "Ingrese fecha de ingreso (DD-MM-YYYY): ";
    std::getline(std::cin, fechaIngreso);
}

void Paciente::mostrarPac() const {
    std::cout << "ID: " << id << "\nNombre: " << nombre
              << "\nEnfermedades: " << enfermedades
              << "\nFecha de ingreso: " << fechaIngreso << "\n";
}

void Paciente::modifiDato(const std::string nuevoNombre) {
    nombre = nuevoNombre;
}

void Paciente::agregarHist(std::string diagnostico) {
    historialClinico.push_back(diagnostico);
}

void Paciente::mostrarHist() const {
    std::cout << "Historial Clinico:\n";
    for (const auto& registro : historialClinico) {
        std::cout << "- " << registro << "\n";
    }
}

std::string Paciente::getFechaIng() const {
    return fechaIngreso;
}

std::string Paciente::getEnfe() const {
    return enfermedades;
}

int Paciente::getId() const {
    return id;
}

std::string Paciente::getNombre() const {
    return nombre;
}
