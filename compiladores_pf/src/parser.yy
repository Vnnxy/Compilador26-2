    %skeleton "lalr1.cc"
    %require "3.0"

    %defines
    %define api.namespace {C0}
    %define api.parser.class {Parser}
    %define api.value.type variant
    %locations           

    %code requires {
        #include <string>

        namespace C0 {
            class Scanner; // <-- ADD THIS: Forward declaration for Parser.hpp
        }
    }

    %code {
        #include <iostream>
        #include "Scanner.hpp"
        using namespace std;

        static int yylex(C0::Parser::semantic_type* lval,
                     C0::Parser::location_type* loc,
                     C0::Scanner& scanner) {
        return scanner.yylex(lval, loc);
    }
    }
    %param { C0::Scanner& scanner }  

    /* ── Keywords ── */
    %token DEF STRUCT VOID
    %token INT FLOAT CHAR BOOL
    %token IF ELSE WHILE FOR BREAK RETURN
    %token TRUE FALSE

    /* ── Value-carrying tokens ── */
    %token <std::string> ID
    %token <std::string> NUM
    %token <std::string> DECIMAL
    %token <std::string> CHARI
    %token <std::string> STRING

    /* ── Punctuation & operators ── */
    %token LPAR RPAR LBRAC RBRAC LKEY RKEY PYC COMMA DOT
    %token MAS MENOS MUL DIV MOD
    %token EQUAL DISTINCT GTE LTE GT LT
    %token AND OR ASIG
    %%

    input: %empty ;

    %%

    void C0::Parser::error(const location_type& loc, const std::string& msg) {
        std::cerr << "Error sintactico: " << msg << " en " << loc << std::endl;
    }