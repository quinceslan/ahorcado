#include "Imagen.hpp"

#include <fstream>
#include <iostream>

Imagen::Imagen(): index(0){}

bool Imagen::cargar_fichero(const std::string &nombre){
    int cantidad, tamanio;
    std::ifstream fichero(nombre);
    if(!fichero.is_open()){
        lista.clear();
        lista.push_back("Error al abrir fichero");
        return false;
    }
    fichero>>cantidad>>tamanio;
    while(fichero.get()!= '\n');
    for(int i= 0; i< cantidad; ++i){
        std::string imagen;
        for(int j= 0; j< tamanio; ++j){
            std::string linea;
            std::getline(fichero, linea);
            imagen+= linea+ "\n";
        }
        lista.push_back(imagen);
    }
    if(fichero.fail()){
        lista.clear();
        lista.push_back("Error al leer fichero.");
        return false;
    }
    return true;
}

void Imagen::imprimir() const{
    std::cout<<lista[index];
}

void Imagen::siguiente(){
    if(index< int(lista.size()- 1)){
        index+= 1;
    }
}

void Imagen::anterior(){
    if(index> 0){
        index-= 1;
    }
}

void Imagen::al_principio(){
    index= 0;
}
