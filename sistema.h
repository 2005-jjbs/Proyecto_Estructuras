#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <vector>
#include "genoma.h"
#include "secuencia.h"
using namespace std;

class sistema{
    private:
    
    genoma genomita;
    
    public:
    
    void cargar_archivo(string nombre_archivo);
    
    void listar_secuencias();

    void histograma(string nombre_secuencia);

    bool es_subsecuencia(vector<char> subsecuencia);

    void enmascarar(vector<char> subsecuencia);

    void guardar(string nombre_archivo);

};

#include "sistema.hxx"

#endif