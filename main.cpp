#include "Juego.h"
#include <iostream>

int main() {
    int numJugadores;

    do {
        std::cout << "Ingrese el número de jugadores (3 a 5): ";
        std::cin >> numJugadores;

        if (numJugadores < 3 || numJugadores > 5) {
            std::cout << "Número de jugadores inválido. Debe ser entre 3 y 5." << std::endl;
        }
    } while (numJugadores < 3 || numJugadores > 5);

    Juego juego(numJugadores);
    juego.jugar();

    return 0;
}
