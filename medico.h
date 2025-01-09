#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>

class Medico {
private:
    int id;
    std::string nombre;
    std::string especialidad;
    bool disponible;
    std::vector<std::string> horarios;

public:
    Medico();
    Medico(int id, std::string nombre, std::string especialidad, bool disponible);
    ~Medico();

    void registrarMedico();
    void modificarEspecialidad(const std::string& nuevaEspecialidad);
    void cambiarDisponibilidad(bool nuevaDisponibilidad);
    void agregarHorario(const std::string& horario);
    void mostrarHorarios() const;

    int getId() const;
    std::string getNombre() const;
    std::string getEspecialidad() const;
    bool getDisponible() const;

    void mostrarMedico() const;
};

#endif
