#include "Cita.h"
#include <iostream>

// Constructor por defecto
Cita::Cita() : id(0), idPaciente(0), idMedico(0), fecha(""), hora(""), esUrgente(false) {}

// Constructor parametrizado
Cita::Cita(int idPaciente, int idMedico, std::string fecha, std::string hora, bool esUrgente)
    : idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), hora(hora), esUrgente(esUrgente) {}

// Destructor
Cita::~Cita() {}

// Asignar una cita
void Cita::asignarCita() {
    std::cout << "Ingrese ID de la cita: ";
    std::cin >> id;
    std::cout << "Ingrese ID del paciente: ";
    std::cin >> idPaciente;
    std::cout << "Ingrese ID del medico: ";
    std::cin >> idMedico;
    std::cin.ignore();
    std::cout << "Ingrese la fecha (DD-MM-YYYY): ";
    std::getline(std::cin, fecha);
    std::cout << "Ingrese la hora (HH:MM): ";
    std::getline(std::cin, hora);
    std::cout << "¿Es urgente? (1: Si, 0: No): ";
    std::cin >> esUrgente;
}

// Modificar una cita
void Cita::modificarCita() {
    std::cin.ignore();
    std::cout << "Ingrese nueva fecha (DD-MM-YYYY): ";
    std::getline(std::cin, fecha);
    std::cout << "Ingrese nueva hora (HH:MM): ";
    std::getline(std::cin, hora);
    std::cout << "¿Es urgente? (1: Si, 0: No): ";
    std::cin >> esUrgente;
}

int Cita::getId() const {
    return id;
}

// Cancelar una cita
void Cita::cancelarCita() {
    this->idPaciente = 0;
    this->idMedico = 0;
    this->fecha = "";
    this->hora = "";
    this->esUrgente = false;
}

// Métodos de acceso
int Cita::getIdPaciente() const {
    return idPaciente;
}

int Cita::getIdMedico() const {
    return idMedico;
}

std::string Cita::getFecha() const {
    return fecha;
}

std::string Cita::getHora() const {
    return hora;
}

bool Cita::getEsUrgente() const {
    return esUrgente;
}

// Mostrar información de la cita
void Cita::mostrarCita() const {
    std::cout << "Cita:\n";
    std::cout << "- Paciente ID: " << idPaciente << "\n";
    std::cout << "- Medico ID: " << idMedico << "\n";
    std::cout << "- Fecha: " << fecha << "\n";
    std::cout << "- Hora: " << hora << "\n";
    std::cout << "- Urgente: " << (esUrgente ? "Si" : "No") << "\n";
}
