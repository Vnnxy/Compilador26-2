#include <cctype>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <sstream>

#include "Driver.hpp"
#include "FinalCode.h"

C0::Driver::~Driver() {
    delete (scanner);
    scanner = nullptr;
    delete (parser);
    parser = nullptr;
    delete table;
    table = nullptr;
}

void C0::Driver::parse(const string& filename) {
    this->filename = filename;
    std::ifstream in_file(filename);
    if (!in_file.good()) {
        exit(EXIT_FAILURE);
    }
    parse_helper(in_file);
    return;
}

void C0::Driver::parse_helper(std::istream &stream) {

    delete (scanner);
    try {
        scanner = new C0::Scanner(&stream);
    }    catch (std::bad_alloc &ba) {
        std::cerr << "Failed to allocate scanner: (" << ba.what() << "), exiting!!\n";
        exit(EXIT_FAILURE);
    }

    delete (parser);
    try {
        parser = new C0::Parser((*scanner) /* scanner */,
                (*this) /* driver */);
    }    catch (std::bad_alloc &ba) {
        std::cerr << "Failed to allocate parser: (" << ba.what() << "), exiting!!\n";
        exit(EXIT_FAILURE);
    }
    const int accept(0);
    if (parser->parse() != accept) {
        std::cerr << "Parse failed!!\n";
    }
    return;
}

void C0::Driver::init() {
    table = new Table();
    direcciones = 0;
    iStack = new PilaCount();
    wStack = new PilaCount();
    numIf = 0;
    numWhile = 0;
    numTemp = 0;
    numString = 0;
    int pos=  filename.find(".");
    output = filename.substr(0,pos-1)+".ens";
}

string C0::Driver::newLabel(int n) {
    stringstream l;
    l << "L" << n;
    return l.str();
}

string C0::Driver::newTemp() {
    stringstream l;
    l << "t" << numTemp;
    numTemp++;
    return l.str();
}

bool C0::Driver::isInSymbol(string id) {
    return table->isInSymbol(id);
}

void C0::Driver::addSymbol(string id) {
    table->addSymbol(id);
}

void C0::Driver::setDir(string id, int dir) {
    table->setDir(id, dir);
}

void C0::Driver::setType(string id, int type) {
    table->setType(id, type);
}

int C0::Driver::getType(string id) {
    return table->getType(id);
}

void C0::Driver::setVar(string id, string var) {
    table->setTypeVar(id, var);
}

string C0::Driver::getVar(string id) {
    return table->getTypeVar(id);
}

C0::Expresion C0::Driver::add(Expresion e1, Expresion e2) {
    Expresion e;
    if (e1.getType() == e2.getType()) {
        e = Expresion(newTemp(), e1.getType());
        addQuad(Quad("+", e1.getDir(), e2.getDir(), e.getDir()));
        return e;
    }
    return e;
}

C0::Expresion C0::Driver::sub(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("-", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::mul(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("*", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::div(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("/", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::number(string num) {
    Expresion e3(num, 0);
    return e3;
}

C0::Expresion C0::Driver::ident(string id) {
    int type = table->getType(id);
    Expresion e2(id, type);
    return e2;
}

C0::Expresion C0::Driver::_or(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("or", e1.getDir(), e2.getDir(), e2.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::_and(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("and", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::gt(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad(">", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::lt(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("<", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::equal(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("==", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::distinct(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("!=", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

void C0::Driver::asign(string id, Expresion e2) {
    C0::Expresion e3;
    int type = table->getType(id);
    //int dir = table->getDir(id);
    if (type == e2.getType()) {
        addQuad(Quad("=", e2.getDir(), "", id));

    }

}

void C0::Driver::addQuad(Quad q) {
    ci.push_back(q);
}

void C0::Driver::_if(Expresion e, int n) {
    stringstream l;
    l << "Le" << n;
    addQuad(Quad("ifFalse", e.getDir(), "", l.str()));
}

void C0::Driver::_while(Expresion e, int n) {
    stringstream l, l2;
    l << "FinWhile" << n;
    addQuad(Quad("ifFalse", e.getDir(), "", l.str()));

}

void C0::Driver::_goto(string label, int n) {
    stringstream l;
    l << label << n;
    addQuad(Quad("goto", "", "", l.str()));
}

void C0::Driver::_label(string label, int n) {
    stringstream l;
    l << label << n;
    addQuad(Quad("label", "", "", l.str()));
}

void C0::Driver::printCI() {
    cout << "Codigo intermedio " << ci.size() << endl;
    for (Quad q : ci) {
        if (q.getOp() == "=")
            cout << "\t\t" << q.getRes() << " " << q.getOp() << " " << q.getArg1() << endl;
        else if (q.getOp() == "label")
            cout << q.getRes() << ": " << endl;
        else if (q.getOp() == "ifFalse")
            cout << "\t\t" << q.getOp() << " " << q.getArg1() << " goto " << q.getRes() << endl;
        else if (q.getOp() == "goto")
            cout << "\t\t" << q.getOp() << " " << q.getRes() << endl;
        else if (q.getArg2() == "")
            cout << "\t\t" << q.getRes() << " = " << q.getOp() << " " << q.getArg1() << endl;
        else
            cout << "\t\t" << q.getRes() << " = " << q.getArg1() << " " << q.getOp() << " " << q.getArg2() << endl;
    }
}

void C0::Driver::printSymTab() {
    cout << "Tabla de símbolos" << endl;
    for (Symbol s : table->getSymTab()) {
        cout << s.getId() << "\t" << s.getDir() << "\t" << s.getType() << "\t" << s.getTypeVar() << endl;
    }
}

void C0::Driver::writew(Expresion e) {
    addQuad(Quad("printi", e.getDir(), "", ""));
}

void C0::Driver::writes(string s,int c) {
    stringstream ss;
    ss << c;
    addQuad(Quad("prints", ss.str(), "", ""));
    addString(s);
}

void C0::Driver::generateStrings() {
    for (unsigned int i = 0; i < strings.size(); i++) {
        addQuad(Quad("string",strings[i],"",""));
    }

}

void C0::Driver::addString(string s){
    strings.push_back(s);
}

void C0::Driver::translate() {
    FinalCode fc(output, ci);
    fc.translate();
}