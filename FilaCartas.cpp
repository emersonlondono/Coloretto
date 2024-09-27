#include "FilaCartas.h"
#include <iostream>

void FilaCartas::agregarCarta(const Carta& carta) {
    fila.push_back(carta);
}

void FilaCartas::mostrarFila() const {
    for (const auto& carta : fila) {
        std::cout << carta.color << " ";
    }
    std::cout << std::endl;
}

bool FilaCartas::vacia() const {
    return fila.empty();
}

bool FilaCartas::llena() const {
    return fila.size() >= 3;
}

