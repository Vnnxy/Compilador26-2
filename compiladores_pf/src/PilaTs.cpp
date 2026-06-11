#include "headers/PilaTs.hpp"

/**
    Constructor
*/
PilaTs::PilaTs() {}

/**
    Destructor
*/
PilaTs::~PilaTs() {
    // Liberar memoria de todas las tablas restantes en la pila
    while (!pila.empty()) {
        delete pila.top();
        pila.pop();
    }
}

// Empuja una nueva tabla de símbolos al tope
void PilaTs::push(SymTab* ts) {
    pila.push(ts);
}

// Retira y retorna la tabla del tope
SymTab* PilaTs::pop() {
    if (pila.empty()) {
        cerr << "Error: intentando pop en pila vacía." << endl;
        return nullptr;
    }
    SymTab* ts = pila.top();
    pila.pop();
    return ts;
}

// Obtiene la tabla del tope (alcance actual)
SymTab* PilaTs::top() {
    if (pila.empty()) {
        cerr << "Error: intentando top en pila vacía." << endl;
        return nullptr;
    }
    return pila.top();
}

// Obtiene la tabla del fondo (alcance global)
// Nota: stack no tiene acceso directo al fondo, usamos una técnica auxiliar
SymTab* PilaTs::bottom() {
    if (pila.empty()) {
        cerr << "Error: intentando bottom en pila vacía." << endl;
        return nullptr;
    }
    // Copiar temporalmente todos los elementos para acceder al fondo
    stack<SymTab*> aux;
    while (pila.size() > 1) {
        aux.push(pila.top());
        pila.pop();
    }
    SymTab* fondo = pila.top();
    // Restaurar la pila
    while (!aux.empty()) {
        pila.push(aux.top());
        aux.pop();
    }
    return fondo;
}

// Regresa true si la pila está vacía.
bool PilaTs::empty() {
    return pila.empty();
}

// Regresa el tamaño del a pila.
int PilaTs::size() {
    return pila.size();
}

// Regresa true si el id existe en lso alcances actuales. (la utilizamos para ver si una variable ya fue declarada.)
bool PilaTs::lookup(string id){

    stack<SymTab*> aux = pila;

    while(!aux.empty()){

        SymTab* ts = aux.top();

        aux.pop();

        if(ts->existe(id)){

            return true;
        }
    }

    return false;
}

// Regresa el tipo de id dentro de la pila. Regresa -1 si no se encuentra.
int PilaTs::lookupType(string id){

    stack<SymTab*> aux = pila;

    while(!aux.empty()){

        SymTab* ts = aux.top();

        aux.pop();

        if(ts->existe(id)){

            return ts->getType(id);
        }
    }

    return -1;
}

// Regresa la categoría del id. regresa "" si no se encuentra.
string PilaTs::lookupCat(string id){

    stack<SymTab*> aux = pila;

    while(!aux.empty()){

        SymTab* ts = aux.top();

        aux.pop();

        if(ts->existe(id)){

            return ts->getCat(id);
        }
    }

    return "";
}

// Regresa la dirección que corresponde al id.
int PilaTs::lookupDir(string id){

    stack<SymTab*> aux = pila;

    while(!aux.empty()){

        SymTab* ts = aux.top();

        aux.pop();

        if(ts->existe(id)){

            return ts->getDir(id);
        }
    }

    return -1;
}

// Regresa el tipo de los parametros
vector<int> PilaTs::lookupParams(string id){

    stack<SymTab*> aux = pila;

    while(!aux.empty()){

        SymTab* ts = aux.top();

        aux.pop();

        if(ts->existe(id)){

            return ts->getParams(id);
        }
    }

    return vector<int>();
}

// Regresa el SymTab actuak en donde se encuentra el id.
SymTab* PilaTs::lookupScope(string id){

    stack<SymTab*> aux = pila;

    while(!aux.empty()){

        SymTab* ts = aux.top();

        aux.pop();

        if(ts->existe(id)){

            return ts;
        }
    }

    return nullptr;
}
