#ifndef REPORTE_H
#define REPORTE_H

#include <string>
#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class Reporte {
public:
    // Métodos para generar reportes
    static void listarPacientesAtendidos(const std::vector<Paciente>& pacientes, const std::string& fechaInicio, const std::string& fechaFin);
    static void listarCitasPendientesPorMedico(const std::vector<Cita>& citas, int idMedico);
    static void pacientesConEnfermedadesCronicas(const std::vector<Paciente>& pacientes);
};

#endif
