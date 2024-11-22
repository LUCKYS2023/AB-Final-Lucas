#include "Medico.h"
#include <iostream>

Medico::Medico() : id(0), nombre(""), fechaIngreso("") {}
Medico::Medico(int id, std::string nombre) 
    : id(id), nombre(nombre), fechaIngreso(fechaIngreso) {}
Medico::~Medico() {}

void Medico::registrarMedico() {
    std::cout << "Ingrese ID del medico: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese nombre del medico: ";
    std::getline(std::cin, nombre);
}

void Medico::modificarDatos(std::string nuevoNombre) {
    nombre = nuevoNombre;
}


int Medico::getId() const {
    return id;
}

std::string Medico::getNombre() const {
    return nombre;
}

