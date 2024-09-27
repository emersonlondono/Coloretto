#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
public:
    std::string color;
    bool esEspecial;
    bool esComodin;

    Carta(std::string c, bool especial = false, bool comodin = false);
};

#endif // CARTA_H
