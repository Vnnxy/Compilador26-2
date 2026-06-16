#include "headers/TypeTab.hpp"

// Constructor: pre-carga los tipos primitivos
TypeTab::TypeTab() {
    // Tipo 0: int (4 bytes)
    types[0] = Type("int", 4);

    // Tipo 1: float (4 bytes)
    types[1] = Type("float", 4);

    // Tipo 2: bool (1 byte)
    types[2] = Type("bool", 1);

    // Tipo 3: char (1 byte)
    types[3] = Type("char", 1);

    // El siguiente ID disponible es 4
    nextId = 4;
}

// Obtiene el ID de un tipo por nombre
int TypeTab::getId(string name) {
    for (auto& par : types) {
        if (par.second.name == name) {
            return par.first;
        }
    }

    return -1;
}

// ============================================================
// Agrega un tipo arreglo a la tabla de tipos
// ============================================================
int TypeTab::addArrayType(int numElems, int tipoBase) {

    int tam = numElems * getTam(tipoBase);

    types[nextId] = Type(
        "array",
        tam,
        numElems,
        tipoBase
    );

    nextId++;

    return nextId - 1;
}

// ============================================================
// Agrega un tipo struct a la tabla de tipos
// ============================================================
int TypeTab::addStructType(string name,
                           int tam,
                           SymTab* ts) {

    if(getId(name) != -1){

        return -1;
    }

    types[nextId] =
        Type(name,
             tam,
             ts);

    nextId++;

    return nextId - 1;
}

// Obtiene el tamaño de un tipo dado su ID
int TypeTab::getTam(int id) {

    if (types.find(id) != types.end()) {
        return types[id].tam;
    }

    cerr << "Error: tipo con ID "
         << id
         << " no encontrado en tabla de tipos."
         << endl;

    return 0;
}

// Obtiene el nombre de un tipo dado su ID
string TypeTab::getName(int id) {

    if (types.find(id) != types.end()) {
        return types[id].name;
    }

    return "desconocido";
}

// Obtiene el tipo base dado su id.
int TypeTab::getTipoBase(int id){

    return types[id].tipoBase;
}

// Obtiene la tabla de símbolos interna de un struct.
SymTab* TypeTab::getTS(int id){

    if(types.find(id) == types.end()){
        return nullptr;
    }

    return types[id].ts;
}

// Imprime la tabla de tipos
void TypeTab::print() {

    cout << "========== TABLA DE TIPOS ==========" << endl;

    cout << "ID\tNombre\t\tTam\tElems\tBase" << endl;

    cout << "----\t------\t\t---\t-----\t----" << endl;

    for (auto& par : types) {

        cout << par.first << "\t"
             << par.second.name << "\t\t"
             << par.second.tam << "\t"
             << par.second.numElems << "\t"
             << par.second.tipoBase << endl;
    }

    cout << "====================================" << endl;
}
