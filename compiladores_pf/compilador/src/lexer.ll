%{
#include <string>
#include <iostream>
using namespace std;


#include "Scanner.hpp"
#undef  YY_DECL
#define YY_DECL int C0::Scanner::yylex( C0::Parser::semantic_type * const lval, C0::Parser::location_type *location )

using token = C0::Parser::token;


#define YY_NO_UNISTD_H
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option debug
%option nodefault
%option yyclass="C0::Scanner"
%option noyywrap
%option c++

cadena \"([\x20-\x21\x23-\xFE])*\"

%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}

[0-9]+       {
               yylval->build< std::string >( yytext );
               return( token::NUMERO );
            }

"if"       {
               return( token::IF );
            }            


"else"       {
               return( token::ELSE );
            }            


"while"       {
               return( token::WHILE );
            }            


"putw"       {
               return( token::PUTW );
            }            

"puts"       {
               return( token::PUTS );
            } 

"int"       {
               return( token::INT );
            }    

"void"       {
               return( token::VOID );
            }    
        

"break"       {
               return( token::BREAK );
            }                       

[a-zA-Z][a-zA-Z0-9_]*   {
               yylval->build< std::string >( yytext );
               return( token::ID );
            }

{cadena}    {
               yylval->build< std::string >( yytext );
               return( token::STRING );
            }
"("       {
               return( token::LPAR );
            }

")"       {
               return( token::RPAR );
            }

"{"       {
               return( token::LKEY );
            }            

"}"       {
               return( token::RKEY );
            }  

";"       {
               return( token::PYC );
            }            


"+"       {
               return( token::MAS );
            }
"-"       {
               return( token::MENOS );
            }
"*"       {
               return( token::MUL );
            }
"/"       {
               return( token::DIV );
            }    
">"       {
               return( token::GT );
            }
"<"       {
               return( token::LT );
            }
"="       {
               return( token::ASIG );
            }
"=="       {
               return( token::EQUAL );
            }
"!="       {
               return( token::DISTINCT );
            }
"||"       {
               return( token::OR );
            }                   

"&&"        {
               return( token::AND );
            }            


\n          {
               /** Update line number **/
               loc->lines();               
            }

[ \t\r]     {}

.           {
               cout<<"ERROR LÉXICO: "<<yytext << endl;
            }
%%