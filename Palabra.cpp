#include "Palabra.hpp"

#include <cassert>
#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>
#include <cstdlib>

Palabra::Palabra(const std::string &palabra){
    set_cadena(palabra);
    srand(time(nullptr));
}

void Palabra::imprimir() const{
    //std::cout<<"  =>  ";
	std::cout<<' ';
    for(unsigned i= 0; i< mascara.size(); ++i){
        std::cout<<(i? " ": "");
        std::cout<<mascara[i];
    }
    std::cout<<'\n';
}

void Palabra::set_cadena(const std::string &nuevaPalabra){
    assert(nuevaPalabra.size()> 3);
    palabra.clear();
    mascara.clear();
    for(char letra: nuevaPalabra){
        palabra.push_back(toupper(letra));
    }
    ocultar();
}

bool Palabra::marcar_letra(char letra){
    letra= toupper(letra);
    bool encontrado= false;
    for(unsigned i= 0; i< palabra.size(); ++i){
        if(mascara[i]== letra){
            return true;
        }
        if(palabra[i]== letra){
            mascara[i]= letra;
            encontrado= true;
        }
    }
    return encontrado;
}

bool Palabra::palabra_adivinada() const{
    return palabra== mascara;
}

bool Palabra::seleccionar_categoria(const std::string &categoria){
    typedef std::pair<std::string, std::string> Par;
    std::ifstream fichero("data/categorias.txt");
    if(!fichero.is_open()){
        return false;
    }
    Par par;
    while(fichero>>par.first>>par.second){
        if(par.first== categoria){
            set_cadena(palabra_aleatoria(par.second));
            return true;
        }
    }
    std::cout<<"No se encuentra categoria '"<<categoria<<"'."<<std::endl;
    return false;
}

void Palabra::descubrir(){
    mascara= palabra;
}

void Palabra::ocultar(){
    mascara.resize(palabra.size(), '-');
}

std::string Palabra::palabra_aleatoria(const std::string &nombreFichero){
    std::ifstream fichero("data/"+ nombreFichero);
    if(!fichero.is_open()){
        std::cerr<<"No se puede abrir '"<<nombreFichero<<"' para lectura."<<std::endl;
        return "nopalabra";
    }
    std::vector<std::string> lista;
    std::string palabra;
    while(fichero>>palabra){
        lista.push_back(palabra);
    }
    if(lista.empty()){
        return "nopalabra";
    }
    return lista[rand()% lista.size()];
}
