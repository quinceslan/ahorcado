#pragma once

#include "Imagen.hpp"
#include "Palabra.hpp"
#include "Teclado.hpp"

#include <string>
#include <vector>

class App{
public:
    App();
    bool run();
private:
    Imagen imagen;
    Palabra palabra;
    Teclado teclado;
    
    void imprimir() const;

    std::string seleccionar_categoria() const;
    const std::string &seleccionar_lista(const std::vector<std::string> &lista) const;
};