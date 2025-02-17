#ifndef CITA_H
#define CITA_H

#include <string>
#include <vector>

class Cita {
private:
    int id;
    int idPaciente;
    int idMedico;
    std::string fecha;
    std::string hora;
    bool esUrgente;

public:
    Cita();
    Cita(int idPaciente, int idMedico, std::string fecha, std::string hora, bool esUrgente);
    ~Cita();

    void asignarCita();
    void modificarCita();
    void cancelarCita();
    int getId() const;

    int getIdPac() const;
    int getIdMed() const;
    std::string getFecha() const;
    std::string getHora() const;
    bool getEsUrge() const;

    void mostrarCita() const;

    // ✅ Agregar la declaración de cargarCitas()
    static void cargarCitas(std::vector<Cita>& citas);
};

#endif
