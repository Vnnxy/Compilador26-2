#ifndef TAC_HPP
#define TAC_HPP

#include <string>
#include <vector>

using namespace std;

extern vector<string> codigo;

string nuevaTemp();

string nuevaLabel();

void gen(string instr);

#endif