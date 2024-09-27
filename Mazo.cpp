#include "Mazo.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

Mazo::Mazo() {
    std::vector<std::string> colores = {"Rojo", "Azul", "Verde", "Amarillo", "Naranja", "Morado", "Rosa"};
    for (std::string color : colores) {
        for (int i = 0; i < 7; i++) {
            cartas.push_back(Carta(color));
        }
    }
    for (int i = 0; i < 3; i++) {
        cartas.push_back(Carta("+2 puntos", true));
    }

    barajar();
}

void Mazo::barajar() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::random_shuffle(cartas.begin(), cartas.end());
}

Carta Mazo::sacarCarta() {
    if (!vacio()) {
        Carta carta = cartas.back();
        cartas.pop_back();
        return carta;
    }
    throw std::runtime_error("El mazo está vacío");
}

bool Mazo::vacio() {
    return cartas.empty();
}

int Mazo::cartasRestantes() const {
    return cartas.size();
}

