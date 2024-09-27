#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include "Carta.h"

class Mazo {
public:
    std::vector<Carta> cartas;

    Mazo();
    void barajar();
    Carta sacarCarta();
    bool vacio();
    int cartasRestantes() const;
};

#endif // MAZO_H
