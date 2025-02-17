#ifndef REPORTE_H
#define REPORTE_H

#include <string>
#include <vector>
#include "Paciente.h"
#include "Cita.h"

class Reporte {
public:
    static void listaPacAtend(const std::vector<Paciente>& pacientes, const std::string& fechaInicio, const std::string& fechaFin);
    static void listaCitasPendPorMed(const std::vector<Cita>& citas, int idMedico);  // 💡 Asegúrate de que esta línea existe
    static void pacConEnfeCroni(const std::vector<Paciente>& pacientes);
};

#endif
