#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__ 1

#include <string>
#include <cstddef>
#include <istream>
#include <vector>
using namespace std;

#include "Scanner.hpp"
#include "parser.tab.hh"
#include "Table.h"
#include "Expresion.h"
#include "Quad.h"
#include "PilaCount.h"

namespace C0{
class Driver{
public:
   Driver() = default;
   virtual ~Driver();   
   void parse( const string& filename );
   string file;
   bool trace_parsing;

   void init();
   bool isInSymbol(string id);
   void addSymbol(string id);
   void setDir(string id, int dir);
   int getDir(string id);
   void setType(string id, int type);
   int getType(string id);
   void setVar(string id, string var);
   string getVar(string id);
   Expresion add(Expresion e1, Expresion e2);
   Expresion sub(Expresion e1, Expresion e2);
   Expresion mul(Expresion e1, Expresion e2);
   Expresion div(Expresion e1, Expresion e2);
   Expresion number(string num);
   Expresion ident(string id);
   Expresion _or(Expresion e1, Expresion e2);
   Expresion _and(Expresion e1, Expresion e2);
   Expresion gt(Expresion e1, Expresion e2);
   Expresion lt(Expresion e1, Expresion e2);
   Expresion equal(Expresion e1, Expresion e2);
   Expresion distinct(Expresion e1, Expresion e2);
   void asign(string id, Expresion e2);   
   void addQuad(Quad q);   
   void _if(Expresion e, int n);   
   void _while(Expresion e, int n);   
   void _goto(string label, int n);
   void _label(string label, int n);
   string newLabel(int n);
   string newTemp();
   void printCI();
   void printSymTab();
   void writew(Expresion e);
   void writes(string s, int c);
   void generateStrings();
   void translate();
   void addString(string s);

   
private:
   C0::Table *table = nullptr;   
   void parse_helper( std::istream &stream );
   C0::Parser  *parser  = nullptr;
   C0::Scanner *scanner = nullptr;
   string output;
   string filename;
public:
   PilaCount *iStack;   
   PilaCount *wStack;   
   int numTemp; 
   int numIf;
   int numString;
   int numWhile;
   int numWhile2 = 0;
   int direcciones = 0;
   vector<Quad> ci;
   int current_type;
   vector<string> strings;
   
   
};
}

#endif /* END __MCDRIVER_HPP__ */