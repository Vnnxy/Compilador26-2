#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include <string>
#include <vector>

using namespace std;

// ============================================================
// Atributos semánticos generales
// ============================================================

struct Attr {

    // Tipo del atributo
    int tipo;

    // Tipo base (arrays)
    int base;

    // Dirección / temporal
    string dir;

    // Tamaño
    int tam;

    // Labels para control de flujo
    string trueLabel;

    string falseLabel;

    string nextLabel;

    // Lista de tipos (args/params)
    vector<int> lista;

    // Temporales de argumentos
    vector<string> listaDir;

    vector<string> code;

    Attr()
        : tipo(-1),
          base(-1),
          dir(""),
          tam(0),
          trueLabel(""),
          falseLabel(""),
          nextLabel("") {}
};

#endif