#include "headers/TAC.hpp"

// el codigo tac
vector<string> codigo;

// Contadores para los scopes y labels.
static int tempCount = 0;
static int labelCount = 0;

// Crea una nueva variable temporal
string nuevaTemp(){

    return "t" + to_string(tempCount++);
}
//Crea un nuevo label.
string nuevaLabel(){

    return "L" + to_string(labelCount++);
}
// Agrega la instruccion a codigo.
void gen(string instr){

    codigo.push_back(instr);
}