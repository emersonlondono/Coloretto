#include "Juego.h"
#include <iostream>
#include <stdexcept>

Juego::Juego(int numJugadores) : maxFilas(numJugadores), ronda(0) {
    for (int i = 0; i < numJugadores; i++) {
        jugadores.push_back(Jugador());
    }
    filas.resize(maxFilas);
}

void Juego::jugar() {
    bool juegoActivo = true;

    while (juegoActivo) {
        std::cout << "---- Ronda " << ronda + 1 << " ----" << std::endl;

        juegoActivo = false;
        for (const auto& jugador : jugadores) {
            if (jugador.cartas.size() < Jugador::MAX_CARTAS && !mazo.vacio()) {
                juegoActivo = true;
                break;
            }
        }

        if (!juegoActivo) break;

        for (int turno = 0; turno < jugadores.size(); ++turno) {
            std::cout << "Turno del jugador " << turno + 1 << std::endl;
            std::cout << "Cartas restantes en el mazo: " << mazo.cartasRestantes() << std::endl;

            std::cout << "Opciones:\n1. Agregar carta a una fila\n2. Tomar una fila" << std::endl;
            int opcion;
            std::cin >> opcion;

            if (opcion == 1) {
                try {
                    Carta nuevaCarta = mazo.sacarCarta();
                    std::cout << "Carta obtenida: " << nuevaCarta.color << std::endl;

                    bool todasLlenas = true;
                    for (const auto& fila : filas) {
                        if (!fila.llena()) {
                            todasLlenas = false;
                            break;
                        }
                    }

                    if (todasLlenas) {
                        std::cout << "Todas las filas están llenas. Debes tomar una fila." << std::endl;
                        mostrarFilas();
                        std::cout << "Elija la fila que desea tomar (1 a " << maxFilas << "): ";
                        int filaElegida;
                        std::cin >> filaElegida;

                        if (filaElegida >= 1 && filaElegida <= maxFilas && !filas[filaElegida - 1].vacia()) {
                            jugadores[turno].agregarCartas(filas[filaElegida - 1].fila);
                            filas[filaElegida - 1].fila.clear();
                        } else {
                            std::cout << "Fila vacía o elección inválida. Intente de nuevo." << std::endl;
                            --turno;
                        }
                    } else {
                        bool filaValida = false;
                        while (!filaValida) {
                            mostrarFilas();
                            std::cout << "Elija la fila a la que desea agregar la carta (1 a " << maxFilas << "): ";
                            int filaElegida;
                            std::cin >> filaElegida;

                            if (filaElegida >= 1 && filaElegida <= maxFilas) {
                                if (!filas[filaElegida - 1].llena()) {
                                    filas[filaElegida - 1].agregarCarta(nuevaCarta);
                                    filaValida = true;
                                } else {
                                    std::cout << "Fila llena. Elija otra fila." << std::endl;
                                }
                            } else {
                                std::cout << "Elección inválida. Intente de nuevo." << std::endl;
                            }
                        }
                    }
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                    break;
                }
            } else if (opcion == 2) {
                mostrarFilas();
                std::cout << "Elija la fila que desea tomar (1 a " << maxFilas << "): ";
                int filaElegida;
                std::cin >> filaElegida;

                if (filaElegida >= 1 && filaElegida <= maxFilas && !filas[filaElegida - 1].vacia()) {
                    jugadores[turno].agregarCartas(filas[filaElegida - 1].fila);
                    filas[filaElegida - 1].fila.clear();
                } else {
                    std::cout << "Fila vacía o elección inválida. Intente de nuevo." << std::endl;
                    --turno;
                }
            }

            jugadores[turno].mostrarCartas();
        }

        ronda++;
    }

    std::cout << "\n¡El juego ha terminado! Puntajes finales:" << std::endl;
    int mayorPuntaje = -1;
    int jugadorGanador = -1;
    for (int i = 0; i < jugadores.size(); i++) {
        int puntos = jugadores[i].calcularPuntos();
        std::cout << "Jugador " << i + 1 << ": " << puntos << " puntos" << std::endl;
        if (puntos > mayorPuntaje) {
            mayorPuntaje = puntos;
            jugadorGanador = i + 1;
        }
    }
    std::cout << "¡El ganador es el Jugador " << jugadorGanador << " con " << mayorPuntaje << " puntos!" << std::endl;
}

void Juego::mostrarFilas() {
    for (int i = 0; i < maxFilas; i++) {
        std::cout << "Fila " << i + 1 << ": ";
        filas[i].mostrarFila();
    }
}

