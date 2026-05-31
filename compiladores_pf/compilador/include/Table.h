#ifndef TABLA_H
#define TABLA_H
#include <vector>
using namespace std;
#include "Symbol.h"
#include "Type.h"

namespace C0
{
    class Table
    {
    private:
        vector<C0::Symbol> symTab;
        vector<C0::Type> typeTab;

    public:
        Table();
        ~Table();
        void addSymbol(string id);
        void addType(string name);
        bool isInSymbol(string id);
        void setDir(string id, int dir);
        void setType(string id, int type);
        void setTypeVar(string id, string type);
        void setArgs(string id, vector<int> args);

        int getDir(string id);
        int getType(string id);
        string getTypeVar(string id);
        vector<int> getArgs(string id);
        vector<C0::Symbol> getSymTab();
    };
}
#endif
