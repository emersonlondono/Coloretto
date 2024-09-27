#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Mazo.h"
#include "Jugador.h"
#include "FilaCartas.h"

class Juego {
public:
    Mazo mazo;
    std::vector<Jugador> jugadores;
    std::vector<FilaCartas> filas;
    int maxFilas;
    int ronda;

    Juego(int numJugadores);
    void jugar();
    void mostrarFilas();
};

#endif // JUEGO_H
