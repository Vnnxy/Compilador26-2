// Scanner.hpp
#pragma once

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "Parser.hpp"   // Bison's generated header (renamed above)

namespace C0 {

class Scanner : public yyFlexLexer {
public:
    Scanner(std::istream* in = nullptr) : yyFlexLexer(in) {}

    int yylex(C0::Parser::semantic_type* lval,
              C0::Parser::location_type* loc);

private:
    C0::Parser::semantic_type* yylval = nullptr;
};

} // namespace C0