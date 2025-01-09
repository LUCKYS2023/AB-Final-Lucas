#include "Reporte.h"
#include <iostream>
#include <iomanip>

void Reporte::listaPacAtend(const std::vector<Paciente>& pacientes, const std::string& fechaInicio, const std::string& fechaFin) {
    std::cout << "\n--- Pacientes atendidos entre " << fechaInicio << " y " << fechaFin << " ---\n";
    for (const auto& paciente : pacientes) {
        if (paciente.getFechaIng() >= fechaInicio && paciente.getFechaIng() <= fechaFin) {
            std::cout << "ID: " << paciente.getId()
                      << ", Nombre: " << paciente.getNombre()
                      << ", Fecha de Ingreso: " << paciente.getFechaIng() << "\n";
        }
    }
}

void Reporte::listaCitasPendPorMed(const std::vector<Cita>& citas, int idMedico) {
    std::cout << "\n--- Citas pendientes para el medico con ID " << idMedico << " ---\n";
    for (const auto& cita : citas) {
        if (cita.getIdMed() == idMedico) {
            std::cout << "Fecha: " << cita.getFecha()
                      << ", Hora: " << cita.getHora()
                      << ", Paciente ID: " << cita.getIdPac()
                      << ", Urgente: " << (cita.getEsUrge() ? "Si" : "No") << "\n";
        }
    }
}

void Reporte::pacConEnfeCroni(const std::vector<Paciente>& pacientes) {
    std::cout << "\n--- Pacientes con enfermedades cronicas ---\n";
    for (const auto& paciente : pacientes) {
        if (paciente.getEnfe().find("Cronica") != std::string::npos) {
            std::cout << "ID: " << paciente.getId()
                      << ", Nombre: " << paciente.getNombre()
                      << ", Enfermedades: " << paciente.getEnfe() << "\n";
        }
    }
}
