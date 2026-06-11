#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include <string>
#include <vector>

using namespace std;

// ============================================================
// Atributos semánticos generales
// Cada símbolo no-terminal en el parser tiene un Attr asociado
// que acumula información semántica durante el análisis.
// ============================================================

struct Attr {

    // Tipo del atributo (int,float,etc)
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
    // Utilizado para atributos, x.n
    string ldir;

    // Lista de tipos (args/params)
    vector<int> lista;

    // Temporales de argumentos
    vector<string> listaDir;

    // TAC
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