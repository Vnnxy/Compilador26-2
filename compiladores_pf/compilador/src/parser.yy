%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {C0}
%define parser_class_name {Parser}

%code requires{
    #include "Expresion.h"
   namespace C0 {
      class Driver;
      class Scanner;      
   }
   

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif
}

%parse-param { Scanner  &scanner  }
%parse-param { Driver  &driver  }

%code{
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "Driver.hpp"

#undef yylex
#define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token <std::string>    ID
%token <std::string>    NUMERO
%token <std::string>    STRING
%token                  IF ELSE WHILE PUTS PUTW BREAK
%token                  INT VOID
%token                  LKEY RKEY PYC 

%left                   ASIG /*=*/
%left                   OR /*||*/
%left                   AND /*&&*/
%left                   EQUAL DISTINCT /*== !=*/
%left                   LT GT /* < >*/
%left                   MAS MENOS /* + -*/
%left                   MUL DIV /* * / */
%nonassoc               LPAR RPAR /* ( ) */
%left                   ELSE

%type <Expresion> expresion condicion
%type<int> type

%locations
%start program

%%
program : {
        driver.init();
    }
    declaraciones 
    {
        driver.printSymTab();
    }
    funcion    
    | 
    funcion    
    ;

declaraciones
    : 
    declaraciones declaracion
    | declaracion
    ;

declaracion       
    : type
    {
        driver.current_type=$1;
    }
    ID PYC {
        if(driver.isInSymbol($3)){
            std::cout<<"Error variable ya declarada"<<std::endl;
        }else{
            driver.addSymbol($3);
            driver.direcciones+=4;
            driver.setDir($3, driver.direcciones);
            driver.setType($3, driver.current_type);
            driver.setVar($3,"var");
        }
    }   
    ;

type: INT {
        $$=0;
    }
    ;

funcion
    : VOID ID LPAR RPAR LKEY bloqueSentencias RKEY
    {          
        driver.printCI();
        driver.generateStrings();
        driver.translate();    
    }
    ;

bloqueSentencias
    : sentencias
    | %empty
    ;

sentencias
    :  sentencias sentencia     
    | 
    sentencia
    ;

expresion
    : expresion MAS expresion {$$=driver.add($1, $3);}
    | expresion MENOS expresion{$$=driver.sub($1, $3);}
    | expresion MUL expresion{$$=driver.mul($1, $3);}
    | expresion DIV expresion{$$=driver.div($1, $3);}
    | LPAR expresion RPAR{ $$=$2;}
    | NUMERO{$$=driver.number($1);}
    | ID{$$=driver.ident($1);}
    ;

condicion
    : condicion OR condicion{$$=driver._or($1, $3);}
    | condicion AND condicion{$$=driver._and($1, $3);}
    | expresion EQUAL expresion{$$=driver.equal($1, $3);}
    | expresion DISTINCT expresion{$$=driver.distinct($1, $3);}
    | expresion GT expresion{$$=driver.gt($1, $3);}
    | expresion LT expresion{$$=driver.lt($1, $3);}
    | LPAR condicion RPAR{$$=$2;}
    ;

sentIf
    : IF LPAR
    {
        driver.numIf++;
        driver.iStack->push(driver.numIf);
    }
     condicion
     {
         driver._if($4, driver.iStack->top());
         
     }
    RPAR LKEY bloqueSentencias RKEY
    {
        driver._goto("Lei",driver.iStack->top());
        driver._label("Le", driver.iStack->top());
    }
    sentElse 
    {
        driver._label("Lei", driver.iStack->top());
        driver.iStack->pop();
    }
    ;

sentElse
    : ELSE LKEY bloqueSentencias RKEY 
    | %empty
    ;

sentWhile
    : WHILE LPAR
    {
        driver.numWhile++;
        driver.wStack->push(driver.numWhile);
        driver._label("InicioWhile", driver.wStack->top());

    }
     condicion
     {
        driver._while($4, driver.wStack->top());
     }
    RPAR LKEY
    {
        driver.numWhile2++;
    }
    bloqueSentencias 
     {
        driver.numWhile2--;
     }
     RKEY
     {
        driver._goto("InicioWhile", driver.wStack->top());
        driver._label("FinWhile", driver.wStack->top());
        driver.wStack->pop();
     }
    ;

sentAsig
    : ID 
    {
        if(!driver.isInSymbol($1)){
            std::cout<<"Error la varaible no fue declarada es:"<<$1<<endl;
        }
    }
      ASIG expresion PYC
    {
        driver.asign($1, $4);
    }

    ;

sentPutw
    : PUTW LPAR expresion
    {
        driver.writew($3);
    }
     RPAR PYC
    ;

sentPuts
    : PUTS LPAR STRING
    {
        driver.writes($3, driver.numString);
        driver.numString++;
    }
     RPAR PYC
    ;

sentBreak
    : BREAK
    {
        if(driver.numWhile2 <=0)              
            cout<<"Error no se puede poner un break sin while"<<endl;
    }
    PYC
    ;

sentencia
    : sentIf
    | sentWhile
    | sentAsig
    | sentPutw
    | sentPuts
    | sentBreak
    ;
%%

void C0::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l << endl;
}