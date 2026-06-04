#include "headers/PilaTs.hpp"

PilaTs::PilaTs() {}

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

bool PilaTs::empty() {
    return pila.empty();
}

int PilaTs::size() {
    return pila.size();
}

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
