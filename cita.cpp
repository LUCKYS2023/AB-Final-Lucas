#include "Cita.h"
#include <iostream>

// Constructor por defecto
Cita::Cita() : idPaciente(0), idMedico(0), fecha(""), hora(""), esUrgente(false) {}

// Constructor parametrizado
Cita::Cita(int idPaciente, int idMedico, std::string fecha, std::string hora, bool esUrgente)
    : idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), hora(hora), esUrgente(esUrgente) {}

// Destructor
Cita::~Cita() {}

// Asignar una cita
void Cita::asignarCita(int idPaciente, int idMedico, std::string fecha, std::string hora, bool esUrgente) {
    this->idPaciente = idPaciente;
    this->idMedico = idMedico;
    this->fecha = fecha;
    this->hora = hora;
    this->esUrgente = esUrgente;
}

// Modificar una cita
void Cita::modificarCita(std::string nuevaFecha, std::string nuevaHora, bool nuevaUrgencia) {
    this->fecha = nuevaFecha;
    this->hora = nuevaHora;
    this->esUrgente = nuevaUrgencia;
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
    std::cout << "- Médico ID: " << idMedico << "\n";
    std::cout << "- Fecha: " << fecha << "\n";
    std::cout << "- Hora: " << hora << "\n";
    std::cout << "- Urgente: " << (esUrgente ? "Sí" : "No") << "\n";
}
