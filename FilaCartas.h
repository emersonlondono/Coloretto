#ifndef FILA_CARTAS_H
#define FILA_CARTAS_H

#include <vector>
#include "Carta.h"

class FilaCartas {
public:
    std::vector<Carta> fila;

    void agregarCarta(const Carta& carta);
    void mostrarFila() const;
    bool vacia() const;
    bool llena() const;
};

#endif // FILA_CARTAS_H
