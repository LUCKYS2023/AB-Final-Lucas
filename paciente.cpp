#include "Paciente.h"
#include <iostream>

class Paciente {
private:
    int id;
    std::string nombre;
    std::string enfermedades; 
    std::string fechaIngreso;

public:
    Paciente() : id(0), nombre(""), enfermedades(""), fechaIngreso("") {} // Constructor por defecto

    int getId() const { return id; }
    void mostrarPaciente() const {
        std::cout << "ID: " << id << "\nNombre: " << nombre
            << "\nEnfermedades: " << enfermedades
            << "\nFecha de ingreso: " << fechaIngreso << "\n";
    }

    void registrarPaciente() {
        std::cout << "Ingrese ID: ";
        std::cin >> id;
        std::cin.ignore(); // Limpiar el buffer
        std::cout << "Ingrese Nombre: ";
        std::getline(std::cin, nombre);
        std::cout << "Ingrese Enfermedades (separadas por comas): ";
        std::getline(std::cin, enfermedades);
        std::cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD): ";
        std::getline(std::cin, fechaIngreso);
    }


    void modificarDatos() {
        std::cout << "Modificando datos del paciente ID: " << id << "\n";
        std::cout << "Nombre actual: " << nombre << "\nIngrese nuevo nombre: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);
        std::cout << "Enfermedades actuales: " << enfermedades << "\nIngrese nuevas enfermedades: ";
        std::getline(std::cin, enfermedades);
        std::cout << "Fecha de ingreso actual: " << fechaIngreso << "\nIngrese nueva fecha de ingreso: ";
        std::getline(std::cin, fechaIngreso);
    }
    
    void mostrarPaciente() {
        std::cout << "ID: " << id << "\nNombre: " << nombre;
        std::cout << "\nEnfermedades: " << enfermedades;
        std::cout << "\nFecha de ingreso: " << fechaIngreso << "\n";
    }
};

