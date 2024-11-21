#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>

class Paciente {
private:
    int id;
    std::string nombre;
    std::string fechaIngreso;
    std::vector<std::string> historialClinico;

public:
    Paciente(); // Constructor por defecto
    Paciente(int id, std::string nombre, std::string fechaIngreso); // Constructor parametrizado
    ~Paciente(); // Destructor

    void registrarPaciente();
    void modificarDatos(std::string nuevoNombre);
    void agregarHistorial(std::string diagnostico);
    void mostrarHistorial();
    int getId() const;
    std::string getNombre() const;
};

#endif
