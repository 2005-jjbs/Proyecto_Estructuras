#include <iostream>
#include <vector>
#include "sistema.h"
using namespace std;
void cargar_nombre_archivo(string filename){
    cout << "Cargando archivo: " << filename << endl;
    cout << "Exito"<<endl;
}

void listar_secuencias(){
    cout << "Exito"<<endl;
}

void histograma(){
    cout << "Exito"<<endl;
}

void es_subsecuencia(){
    cout << "Exito"<<endl;
}

void enmascarar(){
    cout << "Exito"<<endl;
}

void guardar(string filename){
    cout << "Exito"<<endl;
}

void codificar(string filename){
    cout << "Codificando archivo: " << filename << endl;
    cout << "Exito"<<endl;
}

void decodificar(string filename){
    cout << "Decodificando archivo: " << filename << endl;
    cout << "Exito"<<endl;
}

void ruta_mas_corta(vector<string> args){
    cout << "Exito"<<endl;
}

void base_remota(vector<string> args){
    cout << "Exito"<<endl;
}

void menu(){
    cout << "Comandos disponibles:\n";
    cout << "cargar \n";
    cout << "listar_secuencias \n";
    cout << "histograma\n";
    cout << "es_subsecuencia\n";
    cout << "enmascarar\n";
    cout << "guardar \n";
    cout << "codificar \n";
    cout << "decodificar\n";
    cout << "ruta_mas_corta\n";
    cout << "base_remota\n";
    cout << "salir\n";
    cout << "ayuda comando\n";
    
}




int main() {
    sistema s;
    string comando;
    string token;
    while(token!="salir"){
        cout<<"$";
        getline(cin, comando);
        
        // Separar la instrucción del parámetro de forma sencilla
        token = "";
        string parametro = "";
        
        // Buscar el primer espacio
        for(int i = 0; i < comando.length(); i++) {
            if(comando[i] == ' ') {
                token = comando.substr(0, i);  // Primera parte (instrucción)
                parametro = comando.substr(i + 1);  // Segunda parte (parámetro)
                break;
            }
        }
        
        if(token == "") {
            token = comando;
        }
    
    if(token == "cargar"){
        size_t punto = parametro.rfind('.');
        if (punto == string::npos) {
            cout << "Extension invalida. El archivo debe ser .fasta o .fa\n";
            continue;
        }
        string ext = parametro.substr(punto + 1); // lo que está después del punto
        if (ext != "fa" && ext != "fasta") {
            cout << "Extension invalida. El archivo debe ser .fasta o .fa\n";
            continue;
        }
        s.cargar_archivo(parametro);
    }
    else if(token == "listar_secuencias"){
        s.listar_secuencias();
    }
    else if(token == "histograma"){
        s.histograma(parametro);
    }
    else if(token == "es_subsecuencia"){
        vector<char> subsecuencia(parametro.begin(), parametro.end());
        s.es_subsecuencia(subsecuencia);
    }
    else if(token == "enmascarar"){
        vector<char> subsecuencia(parametro.begin(), parametro.end());
        s.enmascarar(subsecuencia);
    }
    else if(token == "guardar"){
        if(parametro.size() < 4 || parametro.substr(parametro.size() - 3) != ".fa") {
            cout << "Extension invalida. El archivo debe ser .fa\n";
            continue;
        }
        s.guardar(parametro);
    }
    else if(token == "codificar"){
        if (parametro.size() < 7 || parametro.substr(parametro.size() - 6) != ".fabin") {
            cout << "Extension invalida. El archivo debe tener extension .fabin\n";
            continue;
        }
        codificar(parametro);
    }
    else if(token == "decodificar"){
        if (parametro.size() < 7 || parametro.substr(parametro.size() - 6) != ".fabin") {
            cout << "Extension invalida. El archivo debe tener extension .fabin\n";
            continue;
        }
        decodificar(parametro);
    }
    
    else if(token == "ayuda"){
        if(parametro == "") {
            menu();
        }
        else if(parametro == "cargar"){
            
            cout<<"Este comando permite cargar en memoria los datos contenidos en el archivo\n";
            cout<<"Salida en pantalla del comando: \n";
            cout<<"(Archivo vacio)nombre_archivo no contiene secuencia\n";
            cout<<"(Archivo erroneo) nombre_archivo no se encuentra o no puede leerse\n";
            cout<<"(Una sola secuencia) 1 secuencia cargada correctamente desde nombre_archivo\n";
            cout<<"(Varias secuencias) n secuencias cargadas correctamente desde nombre_archivo\n";
            cout<<"Para usar el comando ingresar: \n";
            cout<<"cargar nombre_archivo\n";
            
        } 
        else if(parametro == "listar_secuencias"){
            cout<<"Este comando muestra las secuencias cargadas en memoria\n";
            cout<<"Salida en pantalla del comando: \n";
            cout<<"(no hay secuencias cargadas) No hay secuencias cargadas en memoria\n";
            cout<<"(resultado exitoso) Hay n secuencias cargadas en memoria:\n Secuencia descripcion_secuencia_1 contiene b bases. \n Secuencia descripcion_secuencia_2 contiene al menos b bases \n ... ";
            cout<<"Para usar el comando ingresar: \n";
            cout<<"listar_secuencias\n";
        }
        else if(parametro == "histograma"){
            cout<<"Este comando imprime el histograma de una secuencia en caso de que exista\n";
            cout<<"Salida en pantalla: \n";
            cout<<"(La secuencia no existe) Secuencia invalida\n";
            cout<<"(La secuencia existe) A: frecuencia_A \n C: frecuenci_C \n ... \n";
            cout<<"Para usar el comando ingresar: \n";
        }    
        else if(parametro == "es_subsecuencia"){
            cout<<"Este comando determina si la subsecuenia dada existe dentro de las secuencias cargadas en memoria\n";
            cout<<"Salida en pantalla del comando: \n";
            cout<<"(no hay secuencias cargadas) No hay secuencias cargadas en memoria\n";
            cout<<"(la subsecuencia no existe) La subsecuencia dada no existe dentro de las secuencias cargadas en memoria.\n";
            cout<<"Para usar el comando ingresar: \n";
            cout<<"es subsecuencia subsecuencia\n";
        }  
        else if(parametro == "enmascarar"){
            cout<<"Este comando enmascara una subsecuencia (secuencia corta de bases)\n";   
            cout<<"(no hay secuencias cargadas) No hay secuencias cargadas en memoria.\n";
            cout<<"(no se enmascararon subsecuencias) La subsecuencia dada no existe dentro de las secuencias cargadas en memoria, por tanto no se enmascara nada\n";
            cout<<"(varias subsecuencias esmascaradas) s subsecuencias han sido enmascaradas dentro de las secuencias cargadas en memoria.\n";
            cout<<"Para usar el comando ingresar: \n";
            cout<<"enmascarar subsecuencia\n";
        } 
        else if(parametro == "guardar"){
                cout<<"Este comando guarda en el archivo nombre_archivo\n";
                cout<<"Salida en pantalla del comando: \n";
                cout<<"(no hay secuencias guardadas) No hay secuencias cargadas en memoria \n";
                cout<<"(escritura exitosa) Las secuencias han sido cargadas en nombre_archivo\n";
                cout<<"(Problemas en archivo) Error guardando en nombre_archivo\n";
                cout<<"Para usar el comando ingresar: \n";
                cout<<"guardar nombre_archivo\n";
                
        }
        else if(parametro == "codificar"){
            cout<<"Este comando genera el archivo binario correspondiente, con el nombre nombre_archivo.fabin\n";
            cout<<"Salida en pantalla del comando: \n";
            cout<<"(no hay secuencias cargadas) No hay secuencias cargadas en memoria\n";
            cout<<"(mensaje de error) No se pueden guardar las secuencias cargadas en nombre_archivo.fabin.\n";
            cout<<"(codificacion exitosa) Secuencias codificadas y almacenadas en nombre_archivo.fabin.\n";
            cout<<"Para usar el comando ingresar: \n";
            cout<<"codificar nombre_archivo.fabin\n";
        }  
        else if(parametro == "decodificar"){
            cout<<"Este comando carga en memoria las secuencias contenidas en el archivo binario nombre_archivo.fabin\n";
            cout<<"Salida en pantalla del comando: \n";
            cout<<"(mensaje de error) No se pueden cargar las secuencias desde nombre_archivo.fabin .\n";
            cout<<"(decodificacion exitosa) Secuencias decodificadas desde nombre_archivo.fabin y cargadas en memoria.\n";
            cout<<"Para usar el comando ingresar: \n";
            cout<<"decodificar nombre_archivo.fabin\n";
        }   
        else if(parametro == "ruta_mas_corta"){
                cout<<"Este comando imprime en pantalla la secuencia de vertices (bases) del grafo que describen la ruta mas corta entre la base ubicada\nen la posicion [i, j] de la matriz de la secuencia descripcion_secuencia y la base ubicada en la posicion [x, y] de la misma matriz. Asi mismo debe imprimir el costo total de la ruta, teniendo en cuenta el peso que tiene cada conexion entre bases\n";
                cout<<"Salida en pantalla del comando: \n";
                cout<<"(La secuencia no existe)La secuencia descripcion_secuencia no existe\n";
                cout<<"(posicion de base origen invalida) La base en la posicion [i, j] no existe\n";
                cout<<"(posicion de base destino invalida) La base en la posicion [x,y] no existe\n";
                cout<<"(La secuencia existe) Para la secuencia descripcion_secuencia, la ruta mas corta entre la base N en [i, j] y la base M [x, y] es: ... \n el costo total de la ruta es: \n";
                cout<<"Para usar el comando ingresar: \n";
                cout<<"ruta_mas_corta descripcion_secuencia i j x y\n";
        }
        
        else if(parametro == "base_remota"){
            cout<<"Este comando busca la ubicación de la misma base (misma letra) más lejana dentro de la matriz\n";
            cout<<"Salida en pantalla del comando: \n";
            cout<<"(la secuencia no existe) La secuencia descripcion_secuencia no existe.\n";
            cout<<"(posición de base inválida) La base en la posición [i ,j ] no existe.\n";
            cout<<"(la base existe) Para la secuencia descripcion_secuencia , la base remota está ubicada en [a ,b ], y la ruta entre la base en [i ,j ] y la base remota en [a ,b ] es: .... El costo total de la ruta es: ...\n";
            cout<<"base remota descripcion secuencia i j\n";
        }
        else{
            cout<<"(comando desconocido) El comando " << parametro << " no es reconocido.\n";
        }
    }

    else if(token == "ruta_mas_corta"){
        
        vector<string> args;
        string temp = "";
        int count = 0;
        for (int i = 0; i < parametro.length(); ++i) {
            if (parametro[i] == ' ') {
            if (!temp.empty()) {
                args.push_back(temp);
                temp = "";
                count++;
            }
            } else {
            temp += parametro[i];
            }
        }
        if (!temp.empty()) {
            args.push_back(temp);
            count++;
        }

        // Verificar cantidad de argumentos
        if (args.size() != 5) {
            cout << "Error: Se requieren exactamente 5 argumentos para este comando.\n";
            continue;
        }
        ruta_mas_corta(args);
    }

    else if(token == "base_remota"){
                vector<string> args;
        string temp = "";
        int count = 0;
        for (int i = 0; i < parametro.length(); ++i) {
            if (parametro[i] == ' ') {
            if (!temp.empty()) {
                args.push_back(temp);
                temp = "";
                count++;
            }
            } else {
            temp += parametro[i];
            }
        }
        if (!temp.empty()) {
            args.push_back(temp);
            count++;
        }

        // Verificar cantidad de argumentos
        if (args.size() != 3) {
            cout << "Error: Se requieren exactamente 3 argumentos para este comando.\n";
            continue;
        }
        base_remota(args);
    }
    else if(token == "salir"){
        cout << "Saliendo del programa...\n";
        break;
    }
    else{
            cout<<"(comando desconocido) El comando " << token << " no es reconocido.\n";
            
        }
    }
}

