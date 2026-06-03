# Variables
CXX = g++
CXXFLAGS = -std=c++14 -Wall
BISON = bison
FLEX = flex

# The default target runs when you just type 'make'
all: test_lexer compiler

# 1. Rule to build the lexer testing tool
test_lexer: Parser.cpp lexer.cpp test_lexer.cpp
	$(CXX) $(CXXFLAGS) -o test_lexer testLexer.cpp lexer.cpp

# 2. Rule to build the main compiler
compiler: Parser.cpp lexer.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o compiler main.cpp Parser.cpp lexer.cpp

# 3. Rule to generate the C++ parser from Bison
Parser.cpp Parser.hpp: parser.yy
	$(BISON) -o Parser.cpp --defines=Parser.hpp parser.yy

# 4. Rule to generate the C++ scanner from Flex
# It depends on Parser.hpp to ensure Bison runs first!
lexer.cpp: lexer.ll Parser.hpp
	$(FLEX) -o lexer.cpp lexer.ll

# 5. Rule to clean up all generated files
clean:
	rm -f Parser.cpp Parser.hpp lexer.cpp compiler test_lexer location.hh position.hh