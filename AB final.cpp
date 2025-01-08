// AB final.cpp: define el punto de entrada de la aplicación.
//

#include <iostream>
#include <vector>
#include "AB final.h"
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include "Reporte.h"

// Listas globales para almacenar datos
std::vector<Paciente> pacientes;
std::vector<Medico> medicos;
std::vector<Cita> citas;

// Menú de gestión de pacientes
void gestionarPacientes() {
    int opcion;
    do {
        std::cout << "\n--- Gestión de Pacientes ---\n";
        std::cout << "1. Registrar paciente\n";
        std::cout << "2. Modificar datos personales\n";
        std::cout << "3. Buscar paciente\n";
        std::cout << "4. Mostrar pacientes\n";
        std::cout << "5. Regresar al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            Paciente nuevoPaciente;
            nuevoPaciente.registrarPaciente();
            pacientes.push_back(nuevoPaciente);
            std::cout << "Paciente registrado con éxito.\n";
        }
        else if (opcion == 2) {
            int id;
            std::cout << "Ingrese ID del paciente a modificar: ";
            std::cin >> id;
            for (auto& paciente : pacientes) {
                if (paciente.getId() == id) {
                    paciente.modificarDatos(0);
                    break;
                }
            }
        }
        else if (opcion == 3) {
            int id;
            std::cout << "Ingrese ID del paciente a buscar: ";
            std::cin >> id;
            for (const auto& paciente : pacientes) {
                if (paciente.getId() == id) {
                    paciente.mostrarPaciente();
                    break;
                }
            }
        }
        else if (opcion == 4) {
            for (const auto& paciente : pacientes) {
                paciente.mostrarPaciente();
            }
        }
    } while (opcion != 5);
}

// Menú de gestión de médicos
void gestionarMedicos() {
    int opcion;
    do {
        std::cout << "\n--- Gestión de Médicos ---\n";
        std::cout << "1. Registrar médico\n";
        std::cout << "2. Modificar especialidad\n";
        std::cout << "3. Cambiar disponibilidad\n";
        std::cout << "4. Mostrar médicos\n";
        std::cout << "5. Regresar al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            Medico nuevoMedico;
            nuevoMedico.registrarMedico();
            medicos.push_back(nuevoMedico);
            std::cout << "Médico registrado con éxito.\n";
        }
        else if (opcion == 2) {
            int id;
            std::cout << "Ingrese ID del médico a modificar: ";
            std::cin >> id;
            for (auto& medico : medicos) {
                if (medico.getId() == id) {
                    std::string nuevaEspecialidad;
                    std::cin.ignore();
                    std::cout << "Ingrese la nueva especialidad: ";
                    std::getline(std::cin, nuevaEspecialidad);
                    medico.modificarEspecialidad(nuevaEspecialidad);
                    std::cout << "Especialidad modificada con éxito.\n";
                    break;
                }
            }
        }
        else if (opcion == 3) {
            int id;
            std::cout << "Ingrese ID del médico: ";
            std::cin >> id;
            for (auto& medico : medicos) {
                if (medico.getId() == id) {
                    bool nuevaDisponibilidad;
                    std::cout << "¿Está disponible? (1 para Sí, 0 para No): ";
                    std::cin >> nuevaDisponibilidad;
                    medico.cambiarDisponibilidad(nuevaDisponibilidad);
                    std::cout << "Disponibilidad actualizada.\n";
                    break;
                }
            }
        }
        else if (opcion == 4) {
            for (const auto& medico : medicos) {
                medico.mostrarMedico();
            }
        }
    } while (opcion != 5);
}

// Menú de gestión de citas
void gestionarCitas() {
    int opcion;
    do {
        std::cout << "\n--- Gestión de Citas ---\n";
        std::cout << "1. Registrar cita\n";
        std::cout << "2. Modificar cita\n";
        std::cout << "3. Mostrar citas\n";
        std::cout << "4. Regresar al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            Cita nuevaCita;
            nuevaCita.asignarCita();
            citas.push_back(nuevaCita);
            std::cout << "Cita registrada con éxito.\n";
        }
        else if (opcion == 2) {
            int id;
            std::cout << "Ingrese ID de la cita a modificar: ";
            std::cin >> id;
            for (auto& cita : citas) {
                if (cita.getId() == id) {
                    cita.modificarCita();
                    break;
                }
            }
        }
        else if (opcion == 3) {
            for (const auto& cita : citas) {
                cita.mostrarCita();
            }
        }
    } while (opcion != 4);
}

// Menú de reportes
void gestionarReportes() {
    int opcion;
    do {
        std::cout << "\n--- Generación de Reportes ---\n";
        std::cout << "1. Listar pacientes atendidos en un rango de fechas\n";
        std::cout << "2. Listar citas pendientes por médico\n";
        std::cout << "3. Listar pacientes con enfermedades crónicas\n";
        std::cout << "4. Regresar al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::string fechaInicio, fechaFin;
            std::cout << "Ingrese la fecha de inicio (YYYY-MM-DD): ";
            std::cin >> fechaInicio;
            std::cout << "Ingrese la fecha de fin (YYYY-MM-DD): ";
            std::cin >> fechaFin;
            Reporte::listarPacientesAtendidos(pacientes, fechaInicio, fechaFin);
        }
        else if (opcion == 2) {
            int idMedico;
            std::cout << "Ingrese ID del médico: ";
            std::cin >> idMedico;
            Reporte::listarCitasPendientesPorMedico(citas, idMedico);
        }
        else if (opcion == 3) {
            Reporte::pacientesConEnfermedadesCronicas(pacientes);
        }
    } while (opcion != 4);
}

// Programa principal
int main() {
    int opcion;
    do {
        std::cout << "\n=== Sistema de Gestión Hospitalaria ===\n";
        std::cout << "1. Gestión de Pacientes\n";
        std::cout << "2. Gestión de Médicos\n";
        std::cout << "3. Gestión de Citas\n";
        std::cout << "4. Generación de Reportes\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            gestionarPacientes();
            break;
        case 2:
            gestionarMedicos();
            break;
        case 3:
            gestionarCitas();
            break;
        case 4:
            gestionarReportes();
            break;
        case 5:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}
