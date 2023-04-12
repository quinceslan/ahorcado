#include "App.hpp"
#include "conio.h"

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <fstream>
#include <vector>

const std::string FICHEROIMAGEN= "data/imagen.txt";
const std::string FICHEROCATEGORIAS= "data/categorias.txt";

App::App(): palabra("holamundo"){
    if(!imagen.cargar_fichero(FICHEROIMAGEN)){
        std::cerr<<"Error al cargar fichero '"<<FICHEROIMAGEN<<"' para lectura."<<std::endl;
        exit(EXIT_FAILURE);
    }
}

bool App::run(){
    std::string categoria= seleccionar_categoria();
    palabra.seleccionar_categoria(categoria);
    imagen.al_principio();
    bool gano= true;
    int contador= 0;
    while(true){
        clrscr();
        imprimir();
        char entrada= teclado.leer();
        if(isalpha(entrada)){
            if(!palabra.marcar_letra(entrada)){
                ++contador;
                imagen.siguiente();
            }
            if(palabra.palabra_adivinada()){
                break;
            }
            if(contador>= 7){
                gano= false;
                break;
            }
        }
    }
    clrscr();
    teclado.reiniciar();
    imprimir();
    return gano;
}

void App::imprimir() const{
    imagen.imprimir();
    std::cout<<'\n';
    std::cout<<"|-----------------------|\n";
    palabra.imprimir();
    std::cout<<"|-----------------------|\n";
    teclado.imprimir();
    std::cout<<"|-----------------------|\n";
}

const std::string &App::seleccionar_lista(const std::vector<std::string> &lista) const{
    unsigned opcion= 0;
    while(true){
        clrscr();
        std::cout<<"\nEscoja una categoria:\n";
        for(unsigned i= 0; i< lista.size(); ++i){
            std::cout<<(i== opcion?" => ": "    ");
            std::cout<<lista[i]<<'\n';
        }
        char entrada= getch();
        entrada= toupper(entrada);
        if(entrada== 'S' && opcion< lista.size()- 1){
            opcion+= 1;
        }
        else if(entrada== 'W' && opcion> 0){
            opcion-= 1;
        }
        else if(entrada == '\n' || entrada== '\r'){
            break;
        }
    }
    return lista[opcion];
}

std::string App::seleccionar_categoria() const{
    std::vector<std::string> lista;
    std::ifstream fichero(FICHEROCATEGORIAS);
    if(!fichero.is_open()){
        std::cerr<<"Error al abrir '"<<FICHEROCATEGORIAS<<"' para lectura."<<std::endl;
        exit(EXIT_FAILURE);
    }
    std::string categoria;
    while(fichero>>categoria){
        while(fichero.get()!= '\n');
        lista.push_back(categoria);
    }
    if(lista.empty()){
        std::cerr<<"No hay categorias para listar, saliendo app..."<<std::endl;
        exit(EXIT_FAILURE);
    }
    return seleccionar_lista(lista);
}
