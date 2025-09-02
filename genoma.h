#ifndef GENOMA_H
#define GENOMA_H
#include <iostream>
#include <vector>
using namespace std;
#include "secuencia.h"
class genoma{
    private:
    
    vector<secuencia> secuencias;
    
    public:
    
    genoma get_genoma();
    
    int contar_bases();
    
    void listar_secuencia();
    
    void agregar_secuencias(secuencia s);

    void set_secuencias(vector<secuencia> nuevas_secuencias);

    secuencia buscar_secuencia(string nombre);

    vector<secuencia> get_secuencias();

};

#include "genoma.hxx"

#endif