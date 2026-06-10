#include "headers/SymTab.hpp"
#include <algorithm>

SymTab::SymTab() {}

// ============================================================
// Agrega un símbolo a la tabla de símbolos
// ============================================================
bool SymTab::addSym(string id, int dir, int tipo, string cat) {

    if (existe(id)) {
        return false;
    }

    syms[id] = Sym(dir, tipo, cat);

    return true;
}

// ============================================================
// Versión para funciones
// ============================================================
bool SymTab::addSym(
    string id,
    int dir,
    int tipo,
    string cat,
    vector<int> params
) {

    if (existe(id)) {
        return false;
    }

    syms[id] = Sym(dir, tipo, cat, params);

    return true;
}

// ============================================================
// Verifica si existe un símbolo
// ============================================================
bool SymTab::existe(string id) {

    return syms.find(id) != syms.end();
}

// Obtiene la dirección de un símbolo
int SymTab::getDir(string id) {

    if (existe(id)) {
        return syms[id].dir;
    }

    cerr << "Error: símbolo '"
         << id
         << "' no encontrado."
         << endl;

    return -1;
}

// Obtiene el tipo de un símbolo
int SymTab::getType(string id) {

    if (existe(id)) {
        return syms[id].tipo;
    }

    cerr << "Error: símbolo '"
         << id
         << "' no encontrado."
         << endl;

    return -1;
}

// Obtiene la categoría de un símbolo
string SymTab::getCat(string id) {

    if (existe(id)) {
        return syms[id].cat;
    }

    return "";
}

// Retorna el mapa completo
map<string, Sym> SymTab::getSyms() {

    return syms;
}

// Imprime la tabla de símbolos
void SymTab::print() {

    cout << "========== TABLA DE SIMBOLOS ==========" << endl;

    cout << "Nombre\t\tDir\tTipo\tCat" << endl;

    cout << "------\t\t---\t----\t---" << endl;

    vector<pair<string, Sym>> entries(syms.begin(), syms.end());

    sort(entries.begin(), entries.end(),
        [](const pair<string,Sym>& a, const pair<string,Sym>& b){
            if(a.second.dir == -1) return false;
            if(b.second.dir == -1) return true;
            return a.second.dir < b.second.dir;
        });

    for (auto& par : entries) {

        cout << par.first << "\t\t"
             << par.second.dir << "\t"
             << par.second.tipo << "\t"
             << par.second.cat << endl;
    }

    cout << "========================================" << endl;
}

vector<int> SymTab::getParams(string id){

    if(existe(id)){

        return syms[id].params;
    }

    return {};
}
