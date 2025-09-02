#include <iostream>
#include <vector>
#include <fstream>
#include "secuencia.h"
using namespace std;

void secuencia::set_nombre(string n){
    this->nombre = n;
}

void secuencia::set_descripcion(string n){
    this->descripcion.clear();
    for(char c:n){
        this->descripcion.push_back(c);
    }
}

void secuencia::set_descripcion(vector<char> n){
    this->descripcion=n;
}

vector<char> secuencia::get_descripcion(){
    return this->descripcion;
}

secuencia::secuencia(){
    this->nombre="";
    this->descripcion={};
}

string secuencia::get_nombre() {
    return nombre; 
}