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

// Datos predeterminados del programa
void inicializarDatos()
{
    // Pacientes predeterminados
    pacientes.push_back(Paciente(1, "Juan Domingo", "2024-11-01", "Hipertension"));
    pacientes.push_back(Paciente(2, "Maria Lainez", "2024-12-20", "Diabetes"));
    pacientes.push_back(Paciente(3, "Carlos Rando", "2025-01-15", "Asma"));
    pacientes.push_back(Paciente(4, "Lucas Germes", "2025-01-13", "Gripe A"));
    pacientes.push_back(Paciente(5, "Juan Pallares", "2025-01-15", "Varicela"));
    pacientes.push_back(Paciente(6, "Pilar Cutando", "2025-01-09", "Leucemia"));
    pacientes.push_back(Paciente(7, "Jose Maria Rodrigo", "2025-01-05", "Anginas"));
    pacientes.push_back(Paciente(8, "Victor Ruiz", "2025-01-19", "Ebola"));
    pacientes.push_back(Paciente(9, "Ismael Lopez", "2025-01-20", "Pancreatitis"));
    pacientes.push_back(Paciente(10, "Jorge Rodrigo", "2025-01-01", "Hepatitis C"));

    // Médicos predeterminados
    Medico medico1(1, "Dr. Ana Torres", "Cardiologia", true);
    medico1.agregarHor("Lunes 09:00-12:00");
    medico1.agregarHor("Miércoles 14:00-16:00");
    medicos.push_back(medico1);

    Medico medico2(2, "Dr. Luis De la Rosa", "Endocrinologia", true);
    medico2.agregarHor("Martes 10:00-13:00");
    medico2.agregarHor("Jueves 15:00-17:00");
    medicos.push_back(medico2);

    Medico medico3(3, "Dra. Paula Perez", "Fisioterapeuta", true);
    medico2.agregarHor("Mmiercoles 9:00-12:00");
    medico2.agregarHor("Viernes 14:00-17:00");
    medicos.push_back(medico3);

    Medico medico4(4, "Dr. Ernesto Velasco", "Podologia", true);
    medico2.agregarHor("Viernes 12:00-15:00");
    medico2.agregarHor("Domingo 17:00-21:00");
    medicos.push_back(medico4);

    Medico medico5(5, "Dr. Angel Saura", "Cirugia General", true);
    medico2.agregarHor("Viernes 12:00-15:00");
    medico2.agregarHor("Domingo 17:00-21:00");
    medicos.push_back(medico5);
}

// Menú de gestión de pacientes
void gestionPac()
{
    int opcion;
    do
    {
        std::cout << "\n--- Gestion de pacientes ---\n";
        std::cout << "1. Registrar paciente\n";
        std::cout << "2. Modificar datos personales\n";
        std::cout << "3. Buscar paciente\n";
        std::cout << "4. Mostrar pacientes\n";
        std::cout << "5. Regresar al menu principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1)
        {
            Paciente nuevoPac;
            nuevoPac.regisPac();
            pacientes.push_back(nuevoPac);
            std::cout << "Paciente registrado con exito.\n";
        }
        else if (opcion == 2)
        {
            int id;
            std::cout << "Ingrese ID del paciente a modificar: ";
            std::cin >> id;
            for (auto &paciente : pacientes)
            {
                if (paciente.getId() == id)
                {
                    std::string nuevoNombre;
                    std::cout << "Ingrese el nuevo nombre del paciente: ";
                    std::cin.ignore();
                    std::getline(std::cin, nuevoNombre);
                    paciente.modifiDato(nuevoNombre);
                    break;
                }
            }
        }
        else if (opcion == 3)
        {
            int id;
            std::cout << "Ingrese ID del paciente a buscar: ";
            std::cin >> id;
            for (const auto &paciente : pacientes)
            {
                if (paciente.getId() == id)
                {
                    paciente.mostrarPac();
                    break;
                }
            }
        }
        else if (opcion == 4)
        {
            for (const auto &paciente : pacientes)
            {
                paciente.mostrarPac();
            }
        }
    } while (opcion != 5);
}

// Menú de gestión de médicos
void gestionMed()
{
    int opcion;
    do
    {
        std::cout << "\n--- Gestion de medicos ---\n";
        std::cout << "1. Registrar medico\n";
        std::cout << "2. Modificar especialidad\n";
        std::cout << "3. Cambiar disponibilidad\n";
        std::cout << "4. Mostrar medicos\n";
        std::cout << "5. Regresar al menu principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1)
        {
            Medico nuevoMedico;
            nuevoMedico.regisMed();
            medicos.push_back(nuevoMedico);
            std::cout << "Medico registrado con exito.\n";
        }
        else if (opcion == 2)
        {
            int id;
            std::cout << "Ingrese ID del medico a modificar: ";
            std::cin >> id;
            for (auto &medico : medicos)
            {
                if (medico.getId() == id)
                {
                    std::string nuevaEspecialidad;
                    std::cin.ignore();
                    std::cout << "Ingrese la nueva especialidad: ";
                    std::getline(std::cin, nuevaEspecialidad);
                    medico.modifiEspe(nuevaEspecialidad);
                    std::cout << "Especialidad modificada con exito.\n";
                    break;
                }
            }
        }
        else if (opcion == 3)
        {
            int id;
            std::cout << "Ingrese ID del medico: ";
            std::cin >> id;
            for (auto &medico : medicos)
            {
                if (medico.getId() == id)
                {
                    bool nuevaDisponibilidad;
                    std::cout << "¿Esta disponible? (1 para Si, 0 para No): ";
                    std::cin >> nuevaDisponibilidad;
                    medico.cambiarDispo(nuevaDisponibilidad);
                    std::cout << "Disponibilidad actualizada.\n";
                    break;
                }
            }
        }
        else if (opcion == 4)
        {
            for (const auto &medico : medicos)
            {
                medico.mostrarMed();
            }
        }
    } while (opcion != 5);
}

// Menú de gestión de citas
void gestionarCitas()
{
    int opcion;
    do
    {
        std::cout << "\n--- Gestion de citas ---\n";
        std::cout << "1. Registrar cita\n";
        std::cout << "2. Modificar cita\n";
        std::cout << "3. Mostrar citas\n";
        std::cout << "4. Regresar al menu principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1)
        {
            Cita nuevaCita;
            nuevaCita.asignarCita();
            citas.push_back(nuevaCita);
            std::cout << "Cita registrada con exito.\n";
        }
        else if (opcion == 2)
        {
            int id;
            std::cout << "Ingrese ID de la cita a modificar: ";
            std::cin >> id;
            for (auto &cita : citas)
            {
                if (cita.getId() == id)
                {
                    cita.modificarCita();
                    break;
                }
            }
        }
        else if (opcion == 3)
        {
            for (const auto &cita : citas)
            {
                cita.mostrarCita();
            }
        }
    } while (opcion != 4);
}

// Menú de reportes
void gestionarReportes()
{
    int opcion;
    do
    {
        std::cout << "\n--- Generacion de reportes ---\n";
        std::cout << "1. Listar pacientes atendidos en un rango de fechas\n";
        std::cout << "2. Listar citas pendientes por medico\n";
        std::cout << "3. Listar pacientes con enfermedades cronicas\n";
        std::cout << "4. Regresar al menu principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1)
        {
            std::string fechaInicio, fechaFin;
            std::cout << "Ingrese la fecha de inicio (DD-MM-YYYY): ";
            std::cin >> fechaInicio;
            std::cout << "Ingrese la fecha de fin (DD-MM-YYYY): ";
            std::cin >> fechaFin;
            Reporte::listaPacAtend(pacientes, fechaInicio, fechaFin);
        }
        else if (opcion == 2)
        {
            int idMedico;
            std::cout << "Ingrese ID del medico: ";
            std::cin >> idMedico;
            Reporte::listaCitasPendPorMed(citas, idMedico);
        }
        else if (opcion == 3)
        {
            Reporte::pacConEnfeCroni(pacientes);
        }
    } while (opcion != 4);
}

// Programa principal
int main()
{
    int opcion;
    do
    {
        std::cout << "\n=== Sistema de gestion hospitalaria ===\n";
        std::cout << "1. Gestion de pacientes\n";
        std::cout << "2. Gestion de medicos\n";
        std::cout << "3. Gestion de citas\n";
        std::cout << "4. Generacion de reportes\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            gestionPac();
            break;
        case 2:
            gestionMed();
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
            std::cout << "Opcion invalida. Intente nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}
