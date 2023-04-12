#pragma once

#include "conio.h"

#include <string>
#include <vector>

class Imagen{
public:
    Imagen();
    bool cargar_fichero(const std::string &nombre);
    void imprimir() const;
    void siguiente();
    void anterior();
    void al_principio();
private:
    std::vector<std::string> lista;
    int index;
};