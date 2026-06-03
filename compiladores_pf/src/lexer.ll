%{
#include <string>
#include <iostream>
using namespace std;
#include "Scanner.hpp"
#undef  YY_DECL
#define YY_DECL int C0::Scanner::yylex( \
    C0::Parser::semantic_type* const lval, \
    C0::Parser::location_type* loc )     

using token = C0::Parser::token;
#define YY_NO_UNISTD_H
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

%option debug
%option nodefault
%option yyclass="C0::Scanner"
%option noyywrap
%option c++

/* Patrones auxiliares (Comments here are fine unindented because we are before the first %%) */
DIG      [0-9]
LETRA    [a-zA-Z_]
NUM      {DIG}+
DECIMAL  {DIG}+"."{DIG}+
ID       {LETRA}({LETRA}|{DIG})*
CHAR   \'([^\'\\]|\\.)\'
STRING   \"([\x20-\x21\x23-\xFE])*\"

%%

    /* Codigo ejecutado al inicio de cada llamada a yylex (INDENTED!) */
    yylval = lval;

    /* Comentarios (Must be indented!) */
"//"[^\n]* { /* comentario de linea, ignorar */ }
"/*"([^*]|\*+[^*/])*\*+"/"          { /* comentario de bloque, ignorar */ }

    /* Palabras reservadas */
"def"       { return( token::DEF );    }
"struct"    { return( token::STRUCT ); }
"int"       { return( token::INT );    }
"float"     { return( token::FLOAT );  }
"char"      { return( token::CHAR );   }
"bool"      { return( token::BOOL );   }
"void"      { return( token::VOID );   }
"if"        { return( token::IF );     }
"else"      { return( token::ELSE );   }
"while"     { return( token::WHILE );  }
"for"       { return( token::FOR );    }
"break"     { return( token::BREAK );  }
"return"    { return( token::RETURN ); }
"true"      { return( token::TRUE );   }
"false"     { return( token::FALSE );  }

    /* Literales */
{DECIMAL}   {
                yylval->build< std::string >( yytext );
                return( token::DECIMAL );
            }

{NUM}       {
                yylval->build< std::string >( yytext );
                return( token::NUM );
            }

{CHAR}     {
                yylval->build< std::string >( yytext );
                return( token::CHARI );
            }

{STRING}    {
                yylval->build< std::string >( yytext );
                return( token::STRING );
            }

    /* Identificadores (despues de palabras reservadas) */
{ID}        {
                yylval->build< std::string >( yytext );
                return( token::ID );
            }

    /* Delimitadores */
"("         { return( token::LPAR );    }
")"         { return( token::RPAR );    }
"["         { return( token::LBRAC );   }
"]"         { return( token::RBRAC );   }
"{"         { return( token::LKEY );    }
"}"         { return( token::RKEY );    }
";"         { return( token::PYC );     }
","         { return( token::COMMA );   }
"."         { return( token::DOT );     }

    /* Operadores aritmeticos */
"+"         { return( token::MAS );     }
"-"         { return( token::MENOS );   }
"*"         { return( token::MUL );     }
"/"         { return( token::DIV );     }
"%"         { return( token::MOD );     }

    /* Operadores relacionales
       Los de dos caracteres DEBEN ir antes que los de uno */
"=="        { return( token::EQUAL );    }
"!="        { return( token::DISTINCT ); }
">="        { return( token::GTE );      }
"<="        { return( token::LTE );      }
">"         { return( token::GT );       }
"<"         { return( token::LT );       }

    /* Operadores logicos */
"&&"        { return( token::AND ); }
"||"        { return( token::OR );  }

    /* Asignacion */
"="         { return( token::ASIG ); }

    /* Espacios en blanco y saltos de linea */
\n          { loc->lines(); }
[ \t\r]     { /* ignorar */ }

    /* Error lexico */
.           {
                cerr << "ERROR LEXICO: caracter inesperado '"
                     << yytext << "' en linea "
                     << loc->begin.line << endl;
            }

%%