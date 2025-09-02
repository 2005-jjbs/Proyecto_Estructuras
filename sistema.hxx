#include <iostream>
#include <vector>
#include <fstream>
#include "sistema.h"
#include "secuencia.h"

void sistema::cargar_archivo(string nombre_archivo) {
    ifstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        string linea;
        string nombre;
        vector<char> descripcion;
        while (getline(archivo, linea)) {
            if (linea[0] == '>') {
                if (!descripcion.empty() && !nombre.empty()) {
                    secuencia s;
                    s.set_nombre(nombre);
                    s.set_descripcion(descripcion);
                    this->genomita.agregar_secuencias(s);
                }
                nombre = linea.substr(1);
                descripcion.clear();
            } else {
                for (char c : linea) {
                    descripcion.push_back(c);
                }
                descripcion.push_back('\n'); // Conserva el salto de línea original
            }
        }
        if (!descripcion.empty() && !nombre.empty()) {
            secuencia s;
            s.set_nombre(nombre);
            s.set_descripcion(descripcion);
            this->genomita.agregar_secuencias(s);
        }
        archivo.close();
        cout << "Se cargo correctamente el archivo" << endl;
    } else {
        cout << "Error: No se pudo abrir el archivo " << nombre_archivo << endl;
    }
}

bool sistema::es_subsecuencia(vector<char> subsecuencia){
    vector<secuencia> secuencias = this->genomita.get_secuencias();
    int contador = 0;
    vector<secuencia>::iterator it1;
    vector<char>::iterator it2;
    vector<char>::iterator it3;
    vector<char>::iterator sub;
    if(secuencias.empty()){
        cout << "No hay secuencias cargadas en el genoma." << endl;
        return true;    
    }
    for (it1 = secuencias.begin(); it1 != secuencias.end(); it1++){
        vector<char> ar = it1->get_descripcion();
        for (it2 = ar.begin(); it2 != ar.end(); it2++){
            if(*it2==subsecuencia.front()){
                 it3=it2;
                 bool c=true;
                for(sub=subsecuencia.begin(); sub !=subsecuencia.end(); sub++){
                    if(it3 >= ar.end()){
                    c = false;
                    break;
                    }
                  if(*it3 != *sub){
                    c = false;
                    break;
                    }
                    it3++;   
                }
                if(c)
                    contador++;
            }
        }
    }
    if(contador > 0){
        cout << "La subsecuencia fue encontrada " << contador << " veces en el genoma." << endl;
        return true;
    }
    else{
        cout << "La subsecuencia no fue encontrada en el genoma." << endl;
        return false;
    }
      
}

//funcion listar secuencias
void sistema::listar_secuencias(){
    vector<secuencia> secuencias = this->genomita.get_secuencias();
    if(secuencias.empty()){
        cout << "No hay secuencias cargadas en el genoma." << endl;
        return;    
    }

    int cantidad = secuencias.size();
    cout << "Hay" << cantidad << "secuencias cargadas en memoria" << endl;
    for (int i = 0; i < cantidad; i++){
       string nombre = secuencias[i].get_nombre();
       vector<char> descripcion = secuencias[i].get_descripcion();
       int bases = 0;
       bool incompleta = false;
       for (int j = 0; j < descripcion.size(); j++){
           if(descripcion[j] == '-' || descripcion[j] == 'R' || descripcion[j] == 'Y' || descripcion[j] == 'K' || descripcion[j] == 'M' || descripcion[j] == 'S' || descripcion[j] == 'W' || descripcion[j] == 'B' || descripcion[j] == 'D' || descripcion[j] == 'H' || descripcion[j] == 'V' || descripcion[j] == 'N'){
               incompleta = true;
           }else{
            bases++;
           }
       }
       cout << "Secuencia: " << nombre << endl;
       for (int j = 0; j < descripcion.size(); j++){
            cout << descripcion[j];
        }
       if (incompleta){
        cout << endl <<"contiene al menos " << bases << " bases" << endl;
       }else{
        cout << endl <<"contiene " << bases << " bases" << endl;
       }

    }
}

//Funcion enmascarar
void sistema::enmascarar(vector<char> subsecuencia){
    vector<secuencia> secuencias = this->genomita.get_secuencias();
    if(secuencias.empty()){
        cout << "No hay secuencias cargadas en el genoma." << endl;
        return;    
    }
    bool encontrado = false;
    for (int i = 0; i < secuencias.size(); i++){
        vector<char> descripcion = secuencias[i].get_descripcion();
        bool modificado = false;
        for (int j = 0; j <= descripcion.size() - subsecuencia.size(); j++){
            bool c = true;
            for (int k = 0; k < subsecuencia.size(); k++){
                if (descripcion[j + k] != subsecuencia[k]){
                    c = false;
                    break;
                }
            }
            if (c){
                for (int k = 0; k < subsecuencia.size(); k++){
                    descripcion[j + k] = 'X';
                }
                modificado = true;
                encontrado = true;
            }
        }
        if (modificado == true){
            secuencias[i].set_descripcion(descripcion);
        }
    }
    this->genomita.set_secuencias(secuencias);
    if (encontrado){
        cout << "Subsecuencia enmascarada exitosamente en las secuencias cargadas." << endl;
    } else {
        cout << "La subsecuencia no fue encontrada en las secuencias cargadas." << endl;
    }
            
}

void sistema::histograma(string nombre_secuencia){
    vector<secuencia> secuencias = this->genomita.get_secuencias();
    vector<secuencia>::iterator it;
    bool encontrado = false;
    int a = 0, c = 0, g = 0, t = 0, u = 0, r = 0, y = 0, k = 0, m = 0, s = 0, w = 0, b = 0, d = 0, h = 0, v = 0, n = 0, sep = 0;
    for(it = secuencias.begin(); it != secuencias.end(); it++){
        if(it->get_nombre() == nombre_secuencia){
            encontrado = true;
            vector<char> descripcion = it->get_descripcion();
            vector<char>::iterator it_desc;
            for ( it_desc = descripcion.begin(); it_desc != descripcion.end(); it_desc++){
                switch (*it_desc){
                    case 'A': a++; break;
                    case 'C': c++; break;
                    case 'G': g++; break;
                    case 'T': t++; break;
                    case 'U': u++; break;
                    case 'R': r++; break;
                    case 'Y': y++; break;
                    case 'K': k++; break;
                    case 'M': m++; break;
                    case 'S': s++; break;
                    case 'W': w++; break;
                    case 'B': b++; break;
                    case 'D': d++; break;
                    case 'H': h++; break;
                    case 'V': v++; break;
                    case 'N': n++; break;
                    case '-': sep++; break;

                }
        }
    }

}

    if(!encontrado){
        cout << "La secuencia " << nombre_secuencia << " no fue encontrada." << endl;
        return;
    }
    cout <<"Histograma de la secuencia " << nombre_secuencia << ":" << endl;
    cout << "A: " << a << endl;
    cout << "C: " << c << endl;
    cout << "G: " << g << endl;
    cout << "T: " << t << endl;
    cout << "U: " << u << endl;
    cout << "R: " << r << endl;
    cout << "Y: " << y << endl;
    cout << "K: " << k << endl;
    cout << "M: " << m << endl;
    cout << "S: " << s << endl;
    cout << "W: " << w << endl;
    cout << "B: " << b << endl;
    cout << "D: " << d << endl;
    cout << "H: " << h << endl;
    cout << "V: " << v << endl;
    cout << "N: " << n << endl;
    cout << "-: " << sep << endl;
    return;

}


//Implementacion funcion que guarda en archivo

void sistema::guardar(string nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        vector<secuencia> secuencias = this->genomita.get_secuencias();
        if (secuencias.empty()) {
            cout << "No hay secuencias para guardar." << endl;
            return;
        }
        for (vector<secuencia>::iterator it = secuencias.begin(); it != secuencias.end(); it++) {
            archivo << ">" << it->get_nombre() << endl;
            vector<char> desc = it->get_descripcion();
            for (char c : desc) {
                archivo << c;
            }
        }
        archivo.close();
        cout << "Secuencias guardadas en " << nombre_archivo << endl;
    } else {
        cout << "Error: No se pudo guardar el archivo " << nombre_archivo << endl;
    }
}
