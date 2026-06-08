%{
    #include <cstdlib>
    #include <cstring>

    #include "Parser.hpp"
    #include "headers/Lexer.hpp"

    #define YY_DECL int C1::Lexer::lex(C1::Parser::semantic_type *yylval)
%}

%option c++
%option noyywrap
%option outfile="Lexer.cpp"
%option yyclass="Lexer"

%x COMMENT

DIG         [0-9]
LETTER      [a-zA-Z_]

ID          {LETTER}({LETTER}|{DIG})*

NUM         {DIG}+
FLOATNUM    {DIG}+"."{DIG}+

CHARCONST   \'([^\\\n]|(\\.))\'

WSPC        [ \t\r]+

%%

"int"          { return Parser::token::INT; }
"float"        { return Parser::token::FLOAT; }
"bool"         { return Parser::token::BOOL; }
"char"         { return Parser::token::CHAR; }

"struct"       { return Parser::token::STRUCT; }
"def"          { return( Parser::token::DEF );    }

"if"           { return Parser::token::IF; }
"else"         { return Parser::token::ELSE; }

"while"        { return Parser::token::WHILE; }
"for"          { return Parser::token::FOR; }

"break"        { return Parser::token::BREAK; }
"return"       { return Parser::token::RETURN; }

"true"         { return Parser::token::TRUE; }
"false"        { return Parser::token::FALSE; }

"=="           { return Parser::token::EQ; }
"!="           { return Parser::token::NEQ; }

"<="           { return Parser::token::LE; }
">="           { return Parser::token::GE; }

"<"            { return Parser::token::LT; }
">"            { return Parser::token::GT; }

"&&"           { return Parser::token::AND; }
"||"           { return Parser::token::OR; }

"!"            { return Parser::token::NOT; }

"+"            { return Parser::token::PLUS; }
"-"            { return Parser::token::MINUS; }

"*"            { return Parser::token::MULT; }
"/"            { return Parser::token::DIV; }
"%"            { return Parser::token::MOD; }


"="            { return Parser::token::ASSIGN; }

";"            { return Parser::token::SEMICOLON; }
","            { return Parser::token::COMMA; }

"."            { return Parser::token::DOT; }

"["            { return Parser::token::LBRACKET; }
"]"            { return Parser::token::RBRACKET; }

"{"            { return Parser::token::LBRACE; }
"}"            { return Parser::token::RBRACE; }

"("            { return Parser::token::LPAREN; }
")"            { return Parser::token::RPAREN; }

{FLOATNUM}     {
                    yylval->emplace<float>(
                        atof(yytext)
                    );
                    return Parser::token::FLOAT_LITERAL;
                }

{NUM}          {
                    yylval->emplace<int>(
                        atoi(yytext)
                    );
                    return Parser::token::NUM;
                }

{CHARCONST}    {
                    yylval->emplace<char>(
                        yytext[1]
                    );
                    return Parser::token::CHAR_LITERAL;
                }

{ID}           {
                    yylval->emplace<char*>(
                        strdup(yytext)
                    );
                    return Parser::token::ID;
                }

{WSPC}         { /* Ignorar espacios */ }

"\n"           { yylineno++; }

"//"[^\n]*        { }

"/*"              { BEGIN(COMMENT); }

<COMMENT>"*/"     { BEGIN(INITIAL); }

<COMMENT>\n       { line++; }

<COMMENT>[^*\n]+  { }

<COMMENT>"*"      { }

<<EOF>>        { yyterminate(); }

.              {
                    std::cerr
                        << "Error léxico: carácter inesperado '"
                        << yytext
                        << "' en línea "
                        << line
                        << std::endl;
               }

%%
