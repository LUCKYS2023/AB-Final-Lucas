#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>

class Medico {
private:
    int id;                        // ID único del médico
    std::string nombre;            // Nombre del médico
    std::string especialidad;      // Especialidad médica
    bool disponible;               // Indica si está disponible para nuevas citas
    std::vector<std::string> horarios; // Lista de horarios disponibles

public:
    // Constructores y destructor
    Medico();
    Medico(int id, std::string nombre, std::string especialidad, bool disponible);
    ~Medico();

    // Métodos para gestionar la información del médico
    void registrarMedico();
    void modificarEspecialidad(std::string nuevaEspecialidad);
    void cambiarDisponibilidad(bool nuevaDisponibilidad);
    void agregarHorario(std::string horario);
    void mostrarHorarios() const;

    // Métodos de acceso
    int getId() const;
    std::string getNombre() const;
    std::string getEspecialidad() const;
    bool getDisponible() const;

    // Mostrar información del médico
    void mostrarMedico() const;
};

#endif
