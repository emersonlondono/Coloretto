#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include <string>
#include "Carta.h"

class Jugador {
public:
    std::vector<Carta> cartas;
    std::vector<std::string> colores;
    int puntosEspeciales;
    static const int MAX_CARTAS = 12;

    Jugador();
    void agregarCartas(const std::vector<Carta>& fila);
    void mostrarCartas();
    int calcularPuntos();
};

#endif // JUGADOR_H
