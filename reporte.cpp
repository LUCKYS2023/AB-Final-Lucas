#include "Reporte.h"
#include <iostream>
#include <iomanip>

// Listar pacientes atendidos en un rango de fechas
void Reporte::listarPacientesAtendidos(const std::vector<Paciente>& pacientes, const std::string& fechaInicio, const std::string& fechaFin) {
    std::cout << "\n--- Pacientes atendidos entre " << fechaInicio << " y " << fechaFin << " ---\n";
    for (const auto& paciente : pacientes) {
        if (paciente.getFechaIngreso() >= fechaInicio && paciente.getFechaIngreso() <= fechaFin) {
            std::cout << "ID: " << paciente.getId()
                << ", Nombre: " << paciente.getNombre()
                << ", Fecha de Ingreso: " << paciente.getFechaIngreso() << "\n";
        }
    }
}

// Listar citas pendientes por medico
void Reporte::listarCitasPendientesPorMedico(const std::vector<Cita>& citas, int idMedico) {
    std::cout << "\n--- Citas pendientes para el medico con ID " << idMedico << " ---\n";
    for (const auto& cita : citas) {
        if (cita.getIdMedico() == idMedico && cita.getFecha() >= "2024-10-23") {
            std::cout << "Fecha: " << cita.getFecha()
                << ", Hora: " << cita.getHora()
                << ", Paciente ID: " << cita.getIdPaciente()
                << ", Urgente: " << (cita.getEsUrgente() ? "Si" : "No") << "\n";
        }
    }
}

// Reportar pacientes con enfermedades cronicas
void Reporte::pacientesConEnfermedadesCronicas(const std::vector<Paciente>& pacientes) {
    std::cout << "\n--- Pacientes con Enfermedades Cronicas ---\n";
    for (const auto& paciente : pacientes) {
        if (paciente.getEnfermedades().find("Cronica") != std::string::npos) {
            std::cout << "ID: " << paciente.getId()
                << ", Nombre: " << paciente.getNombre()
                << ", Enfermedades: " << paciente.getEnfermedades() << "\n";
        }
    }
}
