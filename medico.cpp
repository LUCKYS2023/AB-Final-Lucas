#include "Medico.h"
#include <iostream>

Medico::Medico() : id(0), nombre(""), especialidad(""), disponible(false) {}

Medico::Medico(int id, std::string nombre, std::string especialidad, bool disponible)
    : id(id), nombre(nombre), especialidad(especialidad), disponible(disponible) {}

Medico::~Medico() {}

void Medico::regisMed() {
    std::cout << "Ingrese ID del medico: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese nombre del medico: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese especialidad del medico: ";
    std::getline(std::cin, especialidad);
    std::cout << "¿Esta disponible? (1 para Si, 0 para No): ";
    std::cin >> disponible;
}

void Medico::modifiEspe(const std::string& nuevaEspecialidad) {
    especialidad = nuevaEspecialidad;
}

void Medico::cambiarDispo(bool nuevaDisponibilidad) {
    disponible = nuevaDisponibilidad;
}

void Medico::agregarHor(const std::string& horario) {
    horarios.push_back(horario);
}

void Medico::mostrarHor() const {
    std::cout << "Horarios disponibles:\n";
    for (const auto& horario : horarios) {
        std::cout << "- " << horario << "\n";
    }
}

int Medico::getId() const {
    return id;
}

std::string Medico::getNombre() const {
    return nombre;
}

std::string Medico::getEspe() const {
    return especialidad;
}

bool Medico::getDispo() const {
    return disponible;
}

void Medico::mostrarMed() const {
    std::cout << "Medico:\n";
    std::cout << "- ID: " << id << "\n";
    std::cout << "- Nombre: " << nombre << "\n";
    std::cout << "- Especialidad: " << especialidad << "\n";
    std::cout << "- Disponible: " << (disponible ? "Si" : "No") << "\n";
    mostrarHor();
}
