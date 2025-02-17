#include "Reporte.h"
#include <iostream>

// ✅ Implementación correcta de listaCitasPendPorMed()
void Reporte::listaCitasPendPorMed(const std::vector<Cita>& citas, int idMedico) {
    std::cout << "\n--- Citas pendientes para el médico con ID " << idMedico << " ---\n";
    for (const auto& cita : citas) {
        if (cita.getIdMed() == idMedico) {  // 💡 Asegúrate de que getIdMed() está bien definido en Cita
            std::cout << "Fecha: " << cita.getFecha()
                << ", Hora: " << cita.getHora()
                << ", Paciente ID: " << cita.getIdPac()
                << ", Urgente: " << (cita.getEsUrge() ? "Sí" : "No") << "\n";
        }
    }
}

// ✅ Implementación correcta de listaPacAtend()
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

// ✅ Implementación correcta de pacConEnfeCroni()
void Reporte::pacConEnfeCroni(const std::vector<Paciente>& pacientes) {
    std::cout << "\n--- Pacientes con enfermedades crónicas ---\n";
    for (const auto& paciente : pacientes) {
        if (paciente.getEnfe().find("Crónica") != std::string::npos) {  // Asegúrate de que "Crónica" es el término correcto
            std::cout << "ID: " << paciente.getId()
                << ", Nombre: " << paciente.getNombre()
                << ", Enfermedades: " << paciente.getEnfe() << "\n";
        }
    }
}
