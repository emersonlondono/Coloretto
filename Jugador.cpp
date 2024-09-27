#include "Jugador.h"
#include <algorithm>
#include <iostream>

Jugador::Jugador() : puntosEspeciales(0) {}

void Jugador::agregarCartas(const std::vector<Carta>& fila) {
    if (cartas.size() + fila.size() <= MAX_CARTAS) {
        for (auto& carta : fila) {
            if (carta.esEspecial) {
                puntosEspeciales += 2;
            } else {
                cartas.push_back(carta);
                if (std::find(colores.begin(), colores.end(), carta.color) == colores.end()) {
                    colores.push_back(carta.color);
                }
            }
        }
    } else {
        std::cout << "No puedes tener más de " << MAX_CARTAS << " cartas." << std::endl;
    }
}

void Jugador::mostrarCartas() {
    std::cout << "Cartas del jugador: ";
    for (const auto& carta : cartas) {
        std::cout << carta.color << " ";
    }
    std::cout << std::endl;
}

int Jugador::calcularPuntos() {
    std::vector<int> conteo_colores(colores.size(), 0);

    for (const auto& carta : cartas) {
        for (int i = 0; i < colores.size(); i++) {
            if (carta.color == colores[i]) {
                conteo_colores[i]++;
            }
        }
    }

    std::sort(conteo_colores.begin(), conteo_colores.end(), std::greater<int>());

    int puntos = puntosEspeciales;
    for (int i = 0; i < conteo_colores.size(); i++) {
        if (i < 3) {
            puntos += conteo_colores[i] * conteo_colores[i];
        } else {
            puntos -= conteo_colores[i] * conteo_colores[i];
        }
    }

    return puntos;
}
