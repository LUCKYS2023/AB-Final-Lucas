#include "Cita.h"
#include <iostream>

void Cita::cargarCitas(std::vector<Cita>& citas) {
    citas.push_back(Cita(1, 1, "2024-12-01", "10:00", false));
    citas.push_back(Cita(2, 3, "2024-12-02", "14:00", true));
    citas.push_back(Cita(3, 5, "2024-12-03", "09:30", false));
    citas.push_back(Cita(4, 2, "2024-12-04", "12:00", true));
    citas.push_back(Cita(5, 4, "2024-12-05", "16:45", false));
}

Cita::Cita() : id(0), idPaciente(0), idMedico(0), fecha(""), hora(""), esUrgente(false) {}

Cita::Cita(int idPaciente, int idMedico, std::string fecha, std::string hora, bool esUrgente)
    : id(0), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), hora(hora), esUrgente(esUrgente) {
}

Cita::~Cita() {}

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

void Cita::cancelarCita() {
    idPaciente = 0;
    idMedico = 0;
    fecha = "";
    hora = "";
    esUrgente = false;
}

int Cita::getIdPac() const {
    return idPaciente;
}

int Cita::getIdMed() const {
    return idMedico;
}

std::string Cita::getFecha() const {
    return fecha;
}

std::string Cita::getHora() const {
    return hora;
}

bool Cita::getEsUrge() const {
    return esUrgente;
}

void Cita::mostrarCita() const {
    std::cout << "Cita:\n";
    std::cout << "- ID: " << id << "\n";
    std::cout << "- Paciente ID: " << idPaciente << "\n";
    std::cout << "- Medico ID: " << idMedico << "\n";
    std::cout << "- Fecha: " << fecha << "\n";
    std::cout << "- Hora: " << hora << "\n";
    std::cout << "- Urgente: " << (esUrgente ? "Si" : "No") << "\n";
}
