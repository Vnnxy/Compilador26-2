#ifndef TYPETAB_HPP
#define TYPETAB_HPP

#include <string>
#include <map>
#include <iostream>

#include "SymTab.hpp"

using namespace std;

struct Type {

    string name;

    int tam;

    int numElems;

    int tipoBase;

    SymTab* ts;

    Type()
        : name(""),
          tam(0),
          numElems(-1),
          tipoBase(-1),
          ts(nullptr) {}

    Type(string name,
         int tam)
        : name(name),
          tam(tam),
          numElems(-1),
          tipoBase(-1),
          ts(nullptr) {}

    Type(string name,
         int tam,
         int numElems,
         int tipoBase)
        : name(name),
          tam(tam),
          numElems(numElems),
          tipoBase(tipoBase),
          ts(nullptr) {}

    Type(string name,
         int tam,
         SymTab* ts)
        : name(name),
          tam(tam),
          numElems(-1),
          tipoBase(-1),
          ts(ts) {}
};

class TypeTab {

private:

    map<int, Type> types;

    int nextId;

public:

    TypeTab();

    int getId(string name);

    int addArrayType(int numElems,
                     int tipoBase);

    int addStructType(string name,
                      int tam,
                      SymTab* ts);

    int getTam(int id);

    string getName(int id);

    int getTipoBase(int id);

    SymTab* getTS(int id);

    void print();
};

#endif
