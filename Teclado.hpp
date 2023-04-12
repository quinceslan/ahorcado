#pragma once

#include <vector>
#include <string>

class Teclado{
public:
    Teclado();
    char leer();
    void reiniciar();
    void imprimir() const;
private:
    std::vector<std::string>    teclado;

    bool marcar_teclado(char entrada);
};
