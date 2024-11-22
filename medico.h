#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>

class Medico {
private:
    int id;
    std::string nombre;
    std::string fechaIngreso;
    std::vector<std::string> historialClinico;

public:
    Medico(); // Constructor por defecto
    Medico(int id, std::string nombre);
    Medico(int id, std::string nombre, std::string fechaIngreso); // Constructor parametrizado
    ~Medico(); // Destructor

    void registrarMedico();
    void modificarDatos(std::string nuevoNombre);
    int getId() const;
    std::string getNombre() const;
};

#endif
