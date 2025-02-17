// AB final.cpp: define el punto de entrada de la aplicacion.

#include <iostream>
#include <vector>
#include <fstream> // Para manejo de archivos
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include "Reporte.h"
#include <sstream>

// Listas globales para almacenar datos
std::vector<Paciente> pacientes;
std::vector<Medico> medicos;
std::vector<Cita> citas;

// Funciones para guardar y cargar datos en archivos
void guardarPacientes();
void cargarPacientes();
void guardarMedicos();
void cargarMedicos();
void guardarCitas();
void cargarCitas();

// Inicializacion de datos (carga desde archivos o datos por defecto)
void inicializarDatos() {
    cargarPacientes();
    cargarMedicos();
    cargarCitas();

    if (pacientes.empty()) { // Si no hay datos, añadir datos predeterminados
        pacientes.push_back(Paciente(1, "Juan Domingo", "2024-11-01", "Hipertension"));
        pacientes.push_back(Paciente(2, "Maria Lainez", "2024-12-20", "Diabetes"));
    }

    if (medicos.empty()) {
        Medico medico1(1, "Dr. Ana Torres", "Cardiologia", true);
        medico1.agregarHor("Lunes 09:00-12:00");
        medicos.push_back(medico1);
    }
}

// Menu de gestion de pacientes
void gestionPac() {
    int opcion;
    do {
        std::cout << "\n--- Gestion de Pacientes ---\n";
        std::cout << "1. Registrar paciente\n";
        std::cout << "2. Modificar datos personales\n";
        std::cout << "3. Buscar paciente\n";
        std::cout << "4. Mostrar pacientes\n";
        std::cout << "5. Regresar al menu principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            Paciente nuevoPac;
            nuevoPac.regisPac();
            pacientes.push_back(nuevoPac);
            guardarPacientes();
        }
        else if (opcion == 2) {
            int id;
            std::cout << "Ingrese ID del paciente a modificar: ";
            std::cin >> id;
            for (auto& paciente : pacientes) {
                if (paciente.getId() == id) {
                    std::string nuevoNombre;
                    std::cout << "Ingrese el nuevo nombre del paciente: ";
                    std::cin.ignore();
                    std::getline(std::cin, nuevoNombre);
                    paciente.modifiDato(nuevoNombre);
                    guardarPacientes();
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
                    paciente.mostrarPac();
                    break;
                }
            }
        }
        else if (opcion == 4) {
            for (const auto& paciente : pacientes) {
                paciente.mostrarPac();
            }
        }
    } while (opcion != 5);
}

// Funciones para guardar y cargar pacientes
void cargarPacientes() {
    std::ifstream archivo("pacientes.txt");
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de pacientes.\n";
        return;
    }

    pacientes.clear();
    std::string linea;

    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;  // Evitar procesar líneas vacías

        std::stringstream ss(linea);  // Usamos stringstream para dividir los datos
        int id;
        std::string nombre, fecha, enfermedades;

        ss >> id;
        ss.ignore(); // Ignorar la coma
        std::getline(ss, nombre, ',');
        std::getline(ss, fecha, ',');
        std::getline(ss, enfermedades, ',');

        if (!nombre.empty() && !fecha.empty()) {
            pacientes.push_back(Paciente(id, nombre, fecha, enfermedades));
        }
    }

    archivo.close();
}

void guardarPacientes() {
    std::ofstream archivo("pacientes.txt", std::ios::trunc);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo de pacientes.\n";
        return;
    }

    for (const auto& paciente : pacientes) {
        if (!paciente.getNombre().empty()) {
            archivo << paciente.getId() << ','
                << paciente.getNombre() << ','
                << paciente.getFechaIng() << ','
                << paciente.getEnfe() << '\n';
        }
    }

    archivo.close();
}


// Funciones para guardar y cargar medicos
void guardarMedicos() {
    std::ofstream archivo("medicos.txt");
    for (const auto& medico : medicos) {
        archivo << medico.getId() << "," << medico.getNombre() << ","
            << medico.getEspe() << "," << medico.getDispo() << "\n";
    }
    archivo.close();
}

void cargarMedicos() {
    std::ifstream archivo("medicos.txt");
    if (!archivo) return;

    int id;
    std::string nombre, especialidad;
    bool disponible;
    while (archivo >> id) {
        std::getline(archivo, nombre, ',');
        std::getline(archivo, especialidad, ',');
        archivo >> disponible;
        medicos.push_back(Medico(id, nombre, especialidad, disponible));
    }
    archivo.close();
}

// Funciones para guardar y cargar citas
void guardarCitas() {
    std::ofstream archivo("citas.txt");
    for (const auto& cita : citas) {
        archivo << cita.getIdPac() << "," << cita.getIdMed() << ","
            << cita.getFecha() << "," << cita.getHora() << ","
            << cita.getEsUrge() << "\n";
    }
    archivo.close();
}

void cargarCitas() {
    std::ifstream archivo("citas.txt");
    if (!archivo) return;

    int idPaciente, idMedico;
    std::string fecha, hora;
    bool esUrgente;
    while (archivo >> idPaciente) {
        archivo >> idMedico;
        std::getline(archivo, fecha, ',');
        std::getline(archivo, hora, ',');
        archivo >> esUrgente;
        citas.push_back(Cita(idPaciente, idMedico, fecha, hora, esUrgente));
    }
    archivo.close();
}

// Programa principal
int main() {
    inicializarDatos();
    int opcion;
    do {
        std::cout << "\n=== Sistema de Gestion Hospitalaria ===\n";
        std::cout << "1. Gestion de Pacientes\n";
        std::cout << "2. Gestion de Medicos\n";
        std::cout << "3. Gestion de Citas\n";
        std::cout << "4. Salir y Guardar\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            gestionPac();
            break;
        case 2:
            // Aqui iria gestionMed();
            break;
        case 3:
            // Aqui iria gestionarCitas();
            break;
        case 4:
            std::cout << "Guardando datos y saliendo...\n";
            guardarPacientes();
            guardarMedicos();
            guardarCitas();
            break;
        default:
            std::cout << "Opcion invalida. Intente nuevamente.\n";
        }
    } while (opcion != 4);

    return 0;
}
