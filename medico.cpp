#include "Medico.h"
#include <iostream>

// Constructor por defecto
Medico::Medico() : id(0), nombre(""), especialidad(""), disponible(false) {}

// Constructor parametrizado
Medico::Medico(int id, std::string nombre, std::string especialidad, bool disponible)
    : id(id), nombre(nombre), especialidad(especialidad), disponible(disponible) {}

// Destructor
Medico::~Medico() {}

// Registrar un nuevo médico
void Medico::registrarMedico() {
    std::cout << "Ingrese ID del médico: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese nombre del médico: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese especialidad del médico: ";
    std::getline(std::cin, especialidad);
    std::cout << "¿Está disponible? (1 para Sí, 0 para No): ";
    std::cin >> disponible;
}

// Modificar la especialidad del médico
void Medico::modificarEspecialidad(std::string nuevaEspecialidad) {
    especialidad = nuevaEspecialidad;
}

// Cambiar la disponibilidad del médico
void Medico::cambiarDisponibilidad(bool nuevaDisponibilidad) {
    disponible = nuevaDisponibilidad;
}

// Agregar un horario disponible
void Medico::agregarHorario(std::string horario) {
    horarios.push_back(horario);
}

// Mostrar horarios disponibles
void Medico::mostrarHorarios() const {
    std::cout << "Horarios disponibles:\n";
    for (const auto& horario : horarios) {
        std::cout << "- " << horario << "\n";
    }
}

// Métodos de acceso
int Medico::getId() const {
    return id;
}

std::string Medico::getNombre() const {
    return nombre;
}

std::string Medico::getEspecialidad() const {
    return especialidad;
}

bool Medico::getDisponible() const {
    return disponible;
}

// Mostrar información del médico
void Medico::mostrarMedico() const {
    std::cout << "Médico:\n";
    std::cout << "- ID: " << id << "\n";
    std::cout << "- Nombre: " << nombre << "\n";
    std::cout << "- Especialidad: " << especialidad << "\n";
    std::cout << "- Disponible: " << (disponible ? "Sí" : "No") << "\n";
    mostrarHorarios();
}
