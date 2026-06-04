#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct Sym {

    int dir;

    int tipo;

    string cat;

    vector<int> params;

    Sym()
        : dir(0),
          tipo(-1),
          cat("") {}

    Sym(int dir,
        int tipo,
        string cat)
        : dir(dir),
          tipo(tipo),
          cat(cat) {}

    Sym(int dir,
        int tipo,
        string cat,
        vector<int> params)
        : dir(dir),
          tipo(tipo),
          cat(cat),
          params(params) {}
};

class SymTab {

private:

    map<string, Sym> syms;

public:

    SymTab();

    bool addSym(string id, 
                int dir, 
                int tipo, 
                string cat);

    bool addSym(string id,
                int dir,
                int tipo,
                string cat,
                vector<int> params);

    bool existe(string id);

    int getDir(string id);

    int getType(string id);

    string getCat(string id);

    vector<int> getArgs(string id);

    map<string, Sym> getSyms();

    vector<int> getParams(string id);

    void print();
};

#endif
