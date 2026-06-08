%language "C++"

%require "3.2"

%defines "headers/Parser.hpp"
%output "Parser.cpp"

// ============================================================
// CONFIGURACIÓN DEL PARSER
// ============================================================

%define api.parser.class {Parser}
%define api.namespace {C1}

%define api.value.type variant

%parse-param {Lexer* lexer}

// ============================================================
// INCLUDES NECESARIOS
// ============================================================

%code requires {

    #include <string>
    #include <vector>
    #include <stack>
    #include <algorithm>

    #include "Attributes.hpp"
    #include "TypeTab.hpp"
    #include "SymTab.hpp"
    #include "PilaTs.hpp"

    namespace C1 {
        class Lexer;
    }
}

// ============================================================
// CÓDIGO C++ AUXILIAR
// ============================================================

%code {

    #include <iostream>

    #include "headers/Lexer.hpp"

    #include "headers/TAC.hpp"

    #include "headers/ErrorSem.hpp"

    #include <stack>

    using namespace std;

    #define yylex lexer->lex

    // ========================================================
    // ESTRUCTURAS GLOBALES
    // ========================================================

    TypeTab tablaTipos;

    PilaTs pilaTs;

    stack<int> pilaDir;

    int dir = 0;

    int currentType = -1;

    vector<int> listaParams;

    int tipoReturn = -1;

    bool funcionValida = true;

    stack<string> pilaBreak;

    // ========================================================
    // FUNCIONES AUXILIARES DE TIPOS
    // ========================================================

    bool esNumerico(int tipo){

        return tipo == tablaTipos.getId("int") ||
            tipo == tablaTipos.getId("float");
    }

    bool esBooleano(int tipo){

        return tipo == tablaTipos.getId("bool");
    }

    bool tiposCompatibles(int t1, int t2){

        if(t1 == t2)
            return true;

        // int -> float permitido
        if(t1 == tablaTipos.getId("float") &&
            t2 == tablaTipos.getId("int"))
            return true;

        return false;
    }

    int tipoDominante(int t1, int t2){

        if(t1 == tablaTipos.getId("float") ||
            t2 == tablaTipos.getId("float"))
                return tablaTipos.getId("float");

        return tablaTipos.getId("int");
    }

}

// ============================================================
// TOKENS CON ATRIBUTOS
// ============================================================

%token <int> NUM
%token <float> FLOAT_LITERAL
%token <char> CHAR_LITERAL
%token <char*> ID

// ============================================================
// PALABRAS RESERVADAS
// ============================================================

%token INT
%token FLOAT
%token BOOL
%token CHAR

%token STRUCT
%token DEF

%token IF
%token ELSE

%token WHILE
%token FOR

%token BREAK
%token RETURN

%token TRUE
%token FALSE

// ============================================================
// OPERADORES
// ============================================================

%token PLUS
%token MINUS

%token MULT
%token DIV
%token MOD

%token ASSIGN

%token EQ
%token NEQ

%token LT
%token GT
%token LE
%token GE

%token AND
%token OR
%token NOT

// ============================================================
// SÍMBOLOS
// ============================================================

%token SEMICOLON
%token COMMA

%token DOT

%token LBRACKET
%token RBRACKET

%token LBRACE
%token RBRACE

%token LPAREN
%token RPAREN

%token REGISTER

// ============================================================
// PRECEDENCIA
// ============================================================

%right ASSIGN

%left OR
%left AND

%left EQ NEQ

%left LT GT LE GE

%left PLUS MINUS

%left MULT DIV

%right NOT

%left DOT
%left LBRACKET

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

// ============================================================
// TIPOS DE NO TERMINALES
// ============================================================

%type <Attr> P
%type <Attr> D
%type <Attr> STRUCT_VARS

%type <Attr> T
%type <Attr> B
%type <Attr> A

%type <Attr> L
%type <Attr> F

%type <Attr> LVALUE
%type <Attr> S
%type <Attr> BREAK_MARK
%type <Attr> STMT

%type <Attr> E

%type <Attr> FUNC
%type <Attr> BLOQUE
%type <Attr> RETURN_STMT
%type <Attr> ARGS

// ============================================================
// SÍMBOLO INICIAL
// ============================================================

%start P

%%

// ============================================================
// PROGRAMA
// ============================================================

P :

    {
        dir = 0;

        pilaTs.push(new SymTab());
    }

    D

    {
        cout << endl;

        tablaTipos.print();

        cout << endl;

        cout << "TABLA GLOBAL" << endl;

        pilaTs.top()->print();
    }

;

// ============================================================
// DECLARACIONES
// ============================================================

STRUCT_VARS :
    ID
    {
        if (currentType != -1) {
            pilaTs.top()->addSym($1, dir, currentType, "var");
            dir += tablaTipos.getTam(currentType);
        }
        free($1);
    }
    | STRUCT_VARS COMMA ID
    {
        if (currentType != -1) {
            pilaTs.top()->addSym($3, dir, currentType, "var");
            dir += tablaTipos.getTam(currentType);
        }
        free($3);
    }
    | 
    {
        $$ = Attr();
    }
;

D :

    FUNC D

    |

    T L SEMICOLON D

    |

    STRUCT ID
    {
        pilaTs.push(new SymTab());

        pilaDir.push(dir);

        dir = 0;
    }

    LBRACE D RBRACE
    {
        // Mid-rule action — runs BEFORE L
        SymTab* ts = pilaTs.pop();
        int tamStruct = dir;
        dir = pilaDir.top();
        pilaDir.pop();

        string nombreStruct = $2;

        if(tablaTipos.getId(nombreStruct) != -1){
            cerr << "Struct redeclarado: " << nombreStruct << endl;
            currentType = -1;
        }
        else{
            int tipoStruct = tablaTipos.addStructType(
                nombreStruct,
                tamStruct,
                ts
            );
            currentType = tipoStruct; 
        }
    }

    STRUCT_VARS  SEMICOLON D

    {
        if($2) free($2);
    }


    |

    /* epsilon */
    {
        $$ = Attr();
    }

;

// ============================================================
// FUNCIONES
// ============================================================

FUNC :

    DEF T ID

    {
        string id = $3;

        if(pilaTs.bottom()->existe(id)){

            cerr << "Función redeclarada: "
                 << id
                 << endl;
        }
        else{

            // Nuevo scope para función
            pilaTs.push(new SymTab());

            // Guardar dir actual
            pilaDir.push(dir);

            // Reiniciar offset local
            dir = 0;

            // Guardar tipo retorno
            tipoReturn = $2.tipo;
        }
    }

    LPAREN F RPAREN

    BLOQUE

    {
        string id = $3;

        for(string instr : $8.code){
            codigo.push_back(instr);
        }

        SymTab* tsFunc = pilaTs.top();

        cout << "\nTABLA FUNCION " << id << endl;
        tsFunc->print();

        pilaTs.pop();

        dir = pilaDir.top();
        pilaDir.pop();

        pilaTs.bottom()->addSym(
            id,
            -1,
            $2.tipo,
            "func",
            listaParams
        );

        listaParams.clear();

        free($3);
    }
;

// ============================================================
// TIPOS
// ============================================================

T :

    B 

    {
        currentType = $1.tipo;
    }

    A

    {
        $$.tipo = $3.tipo;
        currentType = $$.tipo;
    }

    |

    REGISTER LBRACE

    {
        pilaTs.push(new SymTab());

        pilaDir.push(dir);

        dir = 0;
    }

    D RBRACE

    {
        SymTab* tsStruct =
            pilaTs.pop();

        int tamStruct = dir;

        dir = pilaDir.top();

        pilaDir.pop();

        string nombreStruct =
            "struct_" +
            to_string(tablaTipos.getTam(0))
            + "_"
            + to_string(rand());

        int tipoStruct =
            tablaTipos.addStructType(
                nombreStruct,
                tamStruct,
                tsStruct
            );

        $$.tipo = tipoStruct;

        currentType = tipoStruct;
    }

;

// ============================================================
// TIPOS BÁSICOS
// ============================================================

B :

    INT
    {
        $$.tipo = tablaTipos.getId("int");
    }

    |

    FLOAT
    {
        $$.tipo = tablaTipos.getId("float");
    }

    |

    BOOL
    {
        $$.tipo = tablaTipos.getId("bool");
    }

    |

    CHAR
    {
        $$.tipo = tablaTipos.getId("char");
    }

;

// ============================================================
// ARRAYS
// ============================================================

A :

    LBRACKET NUM RBRACKET A

    {
        if($2 <= 0){

            cerr << "Error: tamaño inválido de arreglo"
                 << endl;
            errorSem=true;
        }

        $$.tipo =
            tablaTipos.addArrayType($2,
                                    $4.tipo);
    }

    |

    /* epsilon */
    {
        $$.tipo = currentType;
    }

;

// ============================================================
// LISTA DE VARIABLES
// ============================================================

L :

    L COMMA ID

    {
        string id = $3;

        if(!pilaTs.lookup(id)){

            pilaTs.top()->addSym(id,
                                 dir,
                                 currentType,
                                 "var");

            dir += tablaTipos.getTam(currentType);
        }
        else{

            cerr << "Variable redeclarada: "
                 << id
                 << endl;
            errorSem = true;
        }

        free($3);
    }

    |

    ID A

    {
        string id = $1;

        if(!pilaTs.lookup(id)){

            pilaTs.top()->addSym(
                id,
                dir,
                $2.tipo,
                "var"
            );

            dir += tablaTipos.getTam($2.tipo);
        }
        else{

            cerr << "Variable redeclarada: "
                 << id
                 << endl;

            errorSem = true;
        }

        free($1);
    }

;

// ============================================================
// PARÁMETROS
// ============================================================

F : F COMMA T ID
    {
        pilaTs.top()->addSym($4, dir, $3.tipo, "param");
        dir += tablaTipos.getTam($3.tipo);
        listaParams.push_back($3.tipo);
        free($4);
    }
  | T ID
    {
        pilaTs.top()->addSym($2, dir, $1.tipo, "param");
        dir += tablaTipos.getTam($1.tipo);
        listaParams.push_back($1.tipo);
        free($2);
    }
  | /* epsilon */ { $$ = Attr(); }
;

// ============================================================
// BLOQUES
// ============================================================

BLOQUE :

    LBRACE S RBRACE
    {
        $$ = $2;
    }

;

LVALUE :

   ID
    {
        string id = $1;
        
        if (!pilaTs.lookup(id)) {
            cerr << "Variable no declarada: " << id << endl;
            errorSem = true;
            $$.tipo = tablaTipos.getId("int");
            $$.dir  = id;
        } else {
            $$.tipo = pilaTs.lookupType(id);
            $$.dir  = id;          // use name as address in TAC
        }
        $$.code = {};
        
        free($1);
    }

    | LVALUE LBRACKET E RBRACKET
{
    int baseType = tablaTipos.getTipoBase($1.tipo);
    if (baseType == -1) {
        cerr << "Subíndice sobre tipo no arreglo" << endl;
        errorSem = true;
        $$.tipo = tablaTipos.getId("int");
        $$.dir  = $1.dir;
        $$.ldir = $1.dir;
    } else {
        if (!esNumerico($3.tipo)) {
            cerr << "Índice de arreglo no entero" << endl;
        }

        int tamBase = tablaTipos.getTam(baseType);

        string tOffset = nuevaTemp();
        string tVal    = nuevaTemp();

        $$.code = $1.code;
        $$.code.insert($$.code.end(), $3.code.begin(), $3.code.end());

        $$.code.push_back(
            tOffset + " = " + $3.dir + " * " + to_string(tamBase)
        );

        // ldir = addressable form (for assignment target)
        $$.ldir = $1.dir + "[" + tOffset + "]";

        // dir = loaded value (for rvalue use AND as base for further indexing)
        $$.code.push_back(tVal + " = " + $$.ldir);
        $$.dir  = tVal;
        $$.tipo = baseType;
    }
}
    | LVALUE DOT ID
    {
        string campo = $3;
        SymTab* tsStruct = tablaTipos.getTS($1.tipo);

        if (tsStruct == nullptr) {
            cerr << "Acceso con '.' sobre tipo no struct" << endl;
            $$.tipo = tablaTipos.getId("int");
            $$.dir  = $1.dir;
            $$.ldir = $1.dir;
        } else if (!tsStruct->existe(campo)) {
            cerr << "Campo inexistente: " << campo << endl;
            $$.tipo = tablaTipos.getId("int");
            $$.dir  = $1.dir;
            $$.ldir = $1.dir;
        } else {
            $$.tipo = tsStruct->getType(campo);
            $$.code = $1.code;

            // ldir = the addressable form (used when this is an assignment target)
            $$.ldir = $1.dir + "." + campo;

            // dir = a temp holding the loaded value (used when this is an rvalue)
            $$.dir = $$.ldir;
        }

        free($3);
    }
;

// ============================================================
// SENTENCIAS
// ============================================================

S:
    STMT S

    {
        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $2.code.begin(),
            $2.code.end()
        );
    }

    |

    /* epsilon */
    {
        $$ = Attr();
    }
;

// ============================================================
// AUXILIAR PARA MANEJAR PILABREAK
// ============================================================

BREAK_MARK :
{
    $$ = Attr();

    $$.dir = nuevaLabel();

    pilaBreak.push($$.dir);
}
;

STMT :

    LVALUE ASSIGN E SEMICOLON
    {
        if (!tiposCompatibles($1.tipo, $3.tipo)) {
            cerr << "Tipos incompatibles en asignación" << endl;
            errorSem = true;
        }

        $$.code = $1.code;

        if (!$1.ldir.empty() && !$$.code.empty()) {
        $$.code.pop_back();
    }
        $$.code.insert($$.code.end(), $3.code.begin(), $3.code.end());

        string dest = $1.ldir.empty() ? $1.dir : $1.ldir;
        $$.code.push_back(dest + " = " + $3.dir);
        
    }
    
    |

    IF LPAREN E RPAREN STMT
    %prec LOWER_THAN_ELSE

    {
        if(!esBooleano($3.tipo)){

            cerr 
                << "Condición no booleana en if"
                << endl;
        }

        string Lfin = nuevaLabel();

        $$.code = $3.code;

        $$.code.push_back(
            "ifFalse "
            + $3.dir
            + " goto "
            + Lfin
        );

        $$.code.insert(
            $$.code.end(),
            $5.code.begin(),
            $5.code.end()
        );

        $$.code.push_back(
            Lfin + ":"
        );
    }

    |

    IF LPAREN E RPAREN STMT
    ELSE STMT

    {
        if(!esBooleano($3.tipo)){

            cerr 
                << "Condición no booleana en if"
                << endl;
        }

        string Lelse = nuevaLabel();
        string Lfin  = nuevaLabel();

        $$.code = $3.code;

        $$.code.push_back(
            "ifFalse "
            + $3.dir
            + " goto "
            + Lelse
        );

        $$.code.insert(
            $$.code.end(),
            $5.code.begin(),
            $5.code.end()
        );

        $$.code.push_back(
            "goto " + Lfin
        );

        $$.code.push_back(
            Lelse + ":"
        );

        $$.code.insert(
            $$.code.end(),
            $7.code.begin(),
            $7.code.end()
        );

        $$.code.push_back(
            Lfin + ":"
        );
    }

    |

    WHILE LPAREN E RPAREN BREAK_MARK STMT

    {
        if(!esBooleano($3.tipo)){

            cerr << "Condición no booleana en while"
                 << endl;
        }

        string Linicio = nuevaLabel();
        string Lfin    = $5.dir;

        $$.code.push_back(
            Linicio + ":"
        );

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        $$.code.push_back(
            "ifFalse "
            + $3.dir
            + " goto "
            + Lfin
        );

        $$.code.insert(
            $$.code.end(),
            $6.code.begin(),
            $6.code.end()
        );

        $$.code.push_back(
            "goto " + Linicio
        );

        $$.code.push_back(
            Lfin + ":"
        );

        pilaBreak.pop();
    }

    |

    FOR LPAREN
    ID ASSIGN E SEMICOLON
    E SEMICOLON
    ID ASSIGN E
    RPAREN
    BREAK_MARK
    STMT

    {
        string Linicio = nuevaLabel();
        string Lfin    = $13.dir;

        // Inicialización

        $$.code = $5.code;

        $$.code.push_back(
            string($3)
            + " = "
            + $5.dir
        );

        // Inicio del ciclo

        $$.code.push_back(
            Linicio + ":"
        );

        // Condición

        $$.code.insert(
            $$.code.end(),
            $7.code.begin(),
            $7.code.end()
        );

        $$.code.push_back(
            "ifFalse "
            + $7.dir
            + " goto "
            + Lfin
        );

        // Cuerpo

        $$.code.insert(
            $$.code.end(),
            $14.code.begin(),
            $14.code.end()
        );

        // Incremento

        $$.code.insert(
            $$.code.end(),
            $11.code.begin(),
            $11.code.end()
        );

        $$.code.push_back(
            string($9)
            + " = "
            + $11.dir
        );

        // Regreso

        $$.code.push_back(
            "goto " + Linicio
        );

        $$.code.push_back(
            Lfin + ":"
        );

        free($3);
        free($9);
        pilaBreak.pop();
    }

    |

    BREAK SEMICOLON
    {
        $$ = Attr();

        if(pilaBreak.empty()){

            cerr
                << "break fuera de ciclo"
                << endl;

            errorSem = true;
        }
        else{

            $$.code.push_back(
                "goto " +
                pilaBreak.top()
            );
        }
    }

    |

    RETURN_STMT

    {
        $$ = $1;
    }

    |

    BLOQUE

    |

    T L SEMICOLON

    {
        $$ = Attr();
    }

;


// ============================================================
// RETURN
// ============================================================

RETURN_STMT :

    RETURN E SEMICOLON

    {
        if(!tiposCompatibles(tipoReturn,
                            $2.tipo)){
            cerr 
                << "Tipo de retorno incorrecto"
                << endl;
            errorSem = true;
        }
        $$.tipo = $2.tipo;
        $$.dir = $2.dir;
        $$.code = $2.code;

        $$.code.push_back(
            "return "
            + $2.dir
        );
    }

;

// ============================================================
// EXPRESIONES
// ============================================================

E :

    E PLUS E

    {
        if(!esNumerico($1.tipo) ||
        !esNumerico($3.tipo)){
            cerr << "Error: suma inválida"
            << endl;
            errorSem=true;
    }
    else{
        $$.tipo =
            tipoDominante($1.tipo,
                           $3.tipo);
        }

        string izq = $1.dir;
        string der = $3.dir;

        int tipoFloat =
            tablaTipos.getId("float");

        int tipoInt =
            tablaTipos.getId("int");

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        if($1.tipo == tipoInt &&
            $3.tipo == tipoFloat){

            string tcast = nuevaTemp();

            $$.code.push_back(
                tcast +
                " = (float) " +
                $1.dir
            );

            izq = tcast;
        }  

        if($1.tipo == tipoFloat &&
            $3.tipo == tipoInt){

            string tcast = nuevaTemp();

            $$.code.push_back(
                tcast +
                " = (float) " +
                $3.dir
            );

            der = tcast;
        } 

        string t = nuevaTemp();

        $$.code.push_back(
            t + " = " +
            izq + " + " +
            der
        );

        $$.dir = t;
    }

    | 
    
    E MINUS E
    
    {
        if(!esNumerico($1.tipo) ||
           !esNumerico($3.tipo)){
            cerr << "Error: resta inválida"
            << endl;
            errorSem=true;
        }
        else{
            $$.tipo =
                tipoDominante($1.tipo,
                               $3.tipo);
        }

        string izq = $1.dir;
        string der = $3.dir;

        int tipoFloat =
            tablaTipos.getId("float");

        int tipoInt =
            tablaTipos.getId("int");

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        if($1.tipo == tipoInt &&
            $3.tipo == tipoFloat){

            string tcast = nuevaTemp();

            $$.code.push_back(
                tcast +
                " = (float) " +
                $1.dir
            );

            izq = tcast;
        }  

        if($1.tipo == tipoFloat &&
            $3.tipo == tipoInt){

            string tcast = nuevaTemp();

            $$.code.push_back(
                tcast +
                " = (float) " +
                $3.dir
            );

            der = tcast;
        } 

        string t = nuevaTemp();

        $$.code.push_back(
            t + " = " +
            izq + " - " +
            der
        );

        $$.dir = t;
    }   

    | 
    
    E MULT E

    {
        if(!esNumerico($1.tipo) ||
           !esNumerico($3.tipo)){
            cerr << "Error: multiplicación inválida"
                 << endl;
            errorSem=true;
        }
        else{
            $$.tipo =
                tipoDominante($1.tipo,
                               $3.tipo);
        }

        string izq = $1.dir;
        string der = $3.dir;

        int tipoFloat =
            tablaTipos.getId("float");

        int tipoInt =
            tablaTipos.getId("int");

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        if($1.tipo == tipoInt &&
            $3.tipo == tipoFloat){

            string tcast = nuevaTemp();

            $$.code.push_back(
                tcast +
                " = (float) " +
                $1.dir
            );

            izq = tcast;
        }  

        if($1.tipo == tipoFloat &&
            $3.tipo == tipoInt){

            string tcast = nuevaTemp();

            $$.code.push_back(
                tcast +
                " = (float) " +
                $3.dir
            );

            der = tcast;
        } 

        string t = nuevaTemp();

        $$.code.push_back(
            t + " = " +
            izq + " * " +
            der
        );

        $$.dir = t;
    }

    | 
    
    E DIV E

    {
        if(!esNumerico($1.tipo) ||
           !esNumerico($3.tipo)){
            cerr << "Error: división inválida"
                 << endl;
            errorSem=true;
        }
        else{
            $$.tipo =
                tipoDominante($1.tipo,
                               $3.tipo);
        }

        string izq = $1.dir;
        string der = $3.dir;

        int tipoFloat =
            tablaTipos.getId("float");

        int tipoInt =
            tablaTipos.getId("int");

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        if($1.tipo == tipoInt &&
            $3.tipo == tipoFloat){

            string tcast = nuevaTemp();

            $$.code.push_back(
                tcast +
                " = (float) " +
                $1.dir
            );

            izq = tcast;
        }  

        if($1.tipo == tipoFloat &&
            $3.tipo == tipoInt){

            string tcast = nuevaTemp();

            $$.code.push_back(
                tcast +
                " = (float) " +
                $3.dir
            );

            der = tcast;
        } 

        string t = nuevaTemp();

        $$.code.push_back(
            t + " = " +
            izq + " / " +
            der
        );

        $$.dir = t;
    }

    | 
    
    E LT E

    {
        if(!esNumerico($1.tipo) ||
           !esNumerico($3.tipo)){
            cerr << "Comparación inválida"
                 << endl;
            errorSem=true;
        }
        $$.tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        $$.code.push_back(
            t + " = " +
            $1.dir + " < " +
            $3.dir
        );

        $$.dir = t;
    }

    |

    E LE E

    {
        if(!esNumerico($1.tipo) ||
           !esNumerico($3.tipo)){
            cerr << "Comparación inválida"
                 << endl;
            errorSem=true;
        }
        $$.tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        $$.code.push_back(
            t + " = " +
            $1.dir + " <= " +
            $3.dir
        );

        $$.dir = t;
    }

    | 
    
    E GT E

    {
        if(!esNumerico($1.tipo) ||
           !esNumerico($3.tipo)){
            cerr << "Comparación inválida"
                 << endl;
            errorSem=true;
        }
        $$.tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        $$.code.push_back(
            t + " = " +
            $1.dir + " > " +
            $3.dir
        );

        $$.dir = t;
    }

    | 
    
    E GE E

    {
        if(!esNumerico($1.tipo) ||
           !esNumerico($3.tipo)){
            cerr << "Comparación inválida"
                 << endl;
            errorSem=true;
        }
        $$.tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        $$.code.push_back(
            t + " = " +
            $1.dir + " >= " +
            $3.dir
        );

        $$.dir = t;
    }

    | 
    
    E EQ E

    {
        if(!tiposCompatibles($1.tipo,
                             $3.tipo) &&
           !tiposCompatibles($3.tipo,
                             $1.tipo)){
            cerr << "Comparación inválida"
                 << endl;
            errorSem=true;
        }
        $$.tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        $$.code.push_back(
            t + " = " +
            $1.dir + " == " +
            $3.dir
        );

        $$.dir = t;
    }

    | 
    
    E NEQ E

    {
        if(!tiposCompatibles($1.tipo,
                             $3.tipo) &&
           !tiposCompatibles($3.tipo,
                             $1.tipo)){

            cerr << "Comparación inválida"
                 << endl;
            errorSem=true;
        }
        $$.tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        $$.code.push_back(
            t + " = " +
            $1.dir + " != " +
            $3.dir
        );

        $$.dir = t;
    }

    | 
    
    E AND E

    {
        if(!esBooleano($1.tipo) ||
           !esBooleano($3.tipo)){
            cerr << "AND requiere booleanos"
                 << endl;
        }
        $$.tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        $$.code.push_back(
            t + " = " +
            $1.dir + " && " +
            $3.dir
        );

        $$.dir = t;
    }

    | 
    
    E OR E

    {
        if(!esBooleano($1.tipo) ||
           !esBooleano($3.tipo)){
            cerr << "OR requiere booleanos"
                 << endl;
        }
        $$.tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );

        $$.code.push_back(
            t + " = " +
            $1.dir + " || " +
            $3.dir
        );

        $$.dir = t;
    }

    | 
    
    NOT E

    {
        if(!esBooleano($2.tipo)){
            cerr << "NOT requiere booleano"
                 << endl;
        }
        $$.tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        $$.code = $2.code;

        $$.code.push_back(
            t + " = !" +
            $2.dir
        );

        $$.dir = t;
    }

    |

    LPAREN E RPAREN

    {
        $$.code = $2.code;
        $$.tipo = $2.tipo;
        $$.dir = $2.dir;
    }

    |

    NUM

    {
        $$.tipo =
            tablaTipos.getId("int");

        $$.dir =
            to_string($1);
    }

    |

    FLOAT_LITERAL

    {
        $$.tipo =
            tablaTipos.getId("float");
        
        $$.dir =
            to_string($1);
    }

    |

    CHAR_LITERAL

    {
        $$.tipo =
            tablaTipos.getId("char");
        $$.dir = string("'") + $1 + "'";
    }

    |

    TRUE

    {
        $$.tipo =
            tablaTipos.getId("bool");
        $$.dir = "true";
    }

    |

    FALSE

    {
        $$.tipo =
            tablaTipos.getId("bool");
        $$.dir = "false";
    }

    | LVALUE
    {
        $$.tipo = $1.tipo;
        $$.code = $1.code;
        $$.ldir = $1.ldir;
        $$.dir  = $1.dir;

    }

    |

    ID LPAREN ARGS RPAREN

    {
        string id = $1;

        // ====================================================
        // Verificar existencia
        // ====================================================

        if(!pilaTs.bottom()->existe(id)){

            cerr
                << "Funcion no declarada: "
                << id
                << endl;

            $$.tipo =
                tablaTipos.getId("int");
        }

        else{

            // ====================================================
            // Verificar categoría
            // ====================================================

            if(pilaTs.bottom()->getCat(id) != "func"){

                cerr
                    << id
                    << " no es una funcion"
                    << endl;
            }

            // ====================================================
            // Obtener parámetros esperados
            // ====================================================

            vector<int> esperados =
                pilaTs.bottom()->getParams(id);

            // ====================================================
            // Verificar cantidad de argumentos
            // ====================================================

            if(esperados.size() != $3.lista.size()){

                cerr
                    << "Cantidad incorrecta de argumentos en llamada a "
                    << id
                    << endl;
                errorSem = true;
            }

            // ====================================================
            // Verificar tipos de argumentos
            // ====================================================

            else{

                for(size_t i = 0;
                    i < esperados.size();
                    i++){

                    if(!tiposCompatibles(
                            esperados[i],
                            $3.lista[i])){

                        cerr
                            << "Tipo incompatible en argumento "
                            << i + 1
                            << " de llamada a "
                            << id
                            << endl;
                    }
                }
            }

            // ====================================================
            // Generar PARAMS TAC
            // ====================================================

            $$.code = $3.code;
            for(string d : $3.listaDir){

                $$.code.push_back(
                    "param " + d
                );

            }

            // ====================================================
            // Generar CALL TAC
            // ====================================================

            string t = nuevaTemp();

            $$.code.push_back(
                t
                + " = call "
                + id
                + ", "
                + to_string($3.listaDir.size())
            );


            // ====================================================
            // Resultado
            // ====================================================

            $$.dir = t;

            $$.tipo =
                pilaTs.bottom()->getType(id);
        }

        free($1);
    }

;

// ============================================================
// ARGUMENTOS
// ============================================================

ARGS :

    E

    {
        $$.code = $1.code;
        $$.lista.push_back($1.tipo);

        $$.listaDir.push_back($1.dir);
    }

    |

    E COMMA ARGS

    {
        $$.code = $1.code;

        $$.code.insert(
            $$.code.end(),
            $3.code.begin(),
            $3.code.end()
        );
        $$.lista.push_back($1.tipo);

        $$.listaDir.push_back($1.dir);

        for(int t : $3.lista){
            $$.lista.push_back(t);
        }

        for(string d : $3.listaDir){
            $$.listaDir.push_back(d);
        }
    }

    |

    /* epsilon */
    {
        $$ = Attr();
    }
;

%%

// ============================================================
// MANEJO DE ERRORES
// ============================================================

void C1::Parser::error(const std::string& msg){
    cerr << "Error sintáctico: "
         << msg
         << " cerca de token: '"
         << lexer->YYText()  // shows the actual token text
         << "' en línea "
         << lexer->lineno()  // shows line number
         << endl;
}
