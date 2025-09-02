#include <iostream>
#include <vector>
using namespace std;
#include "genoma.h"

void genoma::agregar_secuencias(secuencia s){
    this->secuencias.push_back(s);
}
vector<secuencia> genoma::get_secuencias(){
return this->secuencias;
} 
void genoma::set_secuencias(vector<secuencia> nuevas_secuencias){
    this->secuencias = nuevas_secuencias;
}