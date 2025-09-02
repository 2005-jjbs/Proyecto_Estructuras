#ifndef SECUENCIA_H
#define SECUENCIA_H
#include <iostream>
#include <vector>
using namespace std;

class secuencia{
    private:
    
    string nombre;
    
    vector<char> descripcion;
    
    public:
    
    secuencia();
    
    vector<char> get_descripcion();

    string get_nombre();

    void set_nombre(string n);

    void set_descripcion(string n);

    void set_descripcion(vector<char> n);

};

#include "secuencia.hxx"

#endif