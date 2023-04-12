#pragma once

#include "conio.h"

#include <string>

class Palabra{
public:
    Palabra(const std::string &palabra);
    void imprimir() const;
    void set_cadena(const std::string &nuevaPalabra);
    bool marcar_letra(char letra);
    bool palabra_adivinada() const;
    bool seleccionar_categoria(const std::string &categoria);
    void descubrir();
    void ocultar();
    static std::string palabra_aleatoria(const std::string &nombreFichero);
private:
    std::string palabra, mascara;
};
