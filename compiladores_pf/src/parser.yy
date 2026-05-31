%skeleton "lalr1.cc"
%require "3.0"

%defines
%define api.namespace {yy}
//%define api.parser.class.name {parser}
%define api.value.type variant
%define api.token.constructor

%code requires{
    #include <string>
}

%code{
    #include <iostream>
    #include <stdexcept>

    using namespace std;
    //extern int yylex(yy::parser::semantic_type * yylval);
    #define YY_DECL yy::parser::symbol_type yylex();
    YY_DECL
}

%token <int> NUMERO

%right PLUS "+"
%right MUL "*"
%nonassoc LPAR RPAR
%token ENDL

%type <int> L E T F

%%

L : 
    E ENDL
    {
        cout<<"Resultado es " << $1 <<endl;
    }
;

E:  
    E PLUS T{
        $$ = $1 + $3;
    }
    |
    T {
        $$= $1;
    }
;

T:  
    T MUL T{
        $$ = $1 * $3;
    }
    |
    F {
        $$= $1;
    }
;

F: 
    LPAR E RPAR{
        $$ =$2;
    }
    |
    NUMERO{
        $$ = $1;
    }
%%

void yy::parser::error(const string& msg){
    cerr<<"Error sintactico: "<< msg <<endl;
}

int main(){
    yy::parser parser;
    return parser.parse();
}
