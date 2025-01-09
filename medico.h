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

    void regisMed();
    void modifiEspe(const std::string& nuevaEspecialidad);
    void cambiarDispo(bool nuevaDisponibilidad);
    void agregarHor(const std::string& horario);
    void mostrarHor() const;

    int getId() const;
    std::string getNombre() const;
    std::string getEspe() const;
    bool getDispo() const;

    void mostrarMed() const;
};

#endif
