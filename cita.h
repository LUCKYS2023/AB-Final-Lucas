#ifndef CITA_H
#define CITA_H

#include <string>

class Cita {
private:
    int idPaciente;            // ID del paciente asignado a la cita
    int idMedico;              // ID del médico asignado a la cita
    std::string fecha;         // Fecha de la cita (formato YYYY-MM-DD)
    std::string hora;          // Hora de la cita (formato HH:MM)
    bool esUrgente;            // Indica si la cita es urgente

public:
    // Constructores y destructor
    Cita();
    Cita(int idPaciente, int idMedico, std::string fecha, std::string hora, bool esUrgente);
    ~Cita();

    // Métodos para asignar y modificar citas
    void asignarCita(int idPaciente, int idMedico, std::string fecha, std::string hora, bool esUrgente);
    void modificarCita(std::string nuevaFecha, std::string nuevaHora, bool nuevaUrgencia);
    void cancelarCita();

    // Métodos de acceso
    int getIdPaciente() const;
    int getIdMedico() const;
    std::string getFecha() const;
    std::string getHora() const;
    bool getEsUrgente() const;

    // Métodos para mostrar información
    void mostrarCita() const;
};

#endif
