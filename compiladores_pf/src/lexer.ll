%option noyywrap c++

%{
    #include "parser.tab.hh"

    using namespace yy;
%}

DIGITO [0-9]+

%%

[ \t\r]+      ;

\n            return parser::make_ENDL();

"+"           return parser::make_PLUS();
"*"           return parser::make_MULT();

"("           return parser::make_LPAREN();
")"           return parser::make_RPAREN();

{DIGITO} {
    return parser::make_NUMERO(std::stoi(yytext));
}

. {
    throw std::runtime_error("Caracter invalido");
}

%%
