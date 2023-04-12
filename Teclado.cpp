#include "Teclado.hpp"
#include "conio.h"

#include <iostream>
#include <cctype>

Teclado::Teclado(){
    reiniciar();
}

char Teclado::leer(){
    char entrada= getch();
    if(!isalnum(entrada)){
        return '\0';
    }
    entrada= toupper(entrada);
    if(isalpha(entrada)){
        if(!marcar_teclado(entrada)){
            entrada= '\0';
        }
    }
    return entrada;
}

void Teclado::reiniciar(){
    teclado.clear();
    teclado.push_back(" 1234567890");
    teclado.push_back(" QWERTYUIOP");
    teclado.push_back(" ASDFGHJKL");
    teclado.push_back(" ZXCVBNM");
}

void Teclado::imprimir() const{
    int i= 0;
    for(const std::string &linea: teclado){
        for(int j= 0; j< i; ++j){
            std::cout<<' ';
        }
        for(char letra: linea){
            std::cout<<" "<<letra;
        }
        std::cout<<'\n';
        ++i;
    }
}

bool Teclado::marcar_teclado(char entrada){
    for(std::string &linea: teclado){
        for(char &letra: linea){
            if(letra== entrada){
                letra= ' ';
                return true;
            }
        }
    }
    return false;
}
