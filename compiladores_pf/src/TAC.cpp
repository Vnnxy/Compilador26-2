#include "headers/TAC.hpp"

vector<string> codigo;

static int tempCount = 0;
static int labelCount = 0;

string nuevaTemp(){

    return "t" + to_string(tempCount++);
}

string nuevaLabel(){

    return "L" + to_string(labelCount++);
}

void gen(string instr){

    codigo.push_back(instr);
}