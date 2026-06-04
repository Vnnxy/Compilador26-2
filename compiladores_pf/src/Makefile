# ============================================================
# Compilador C_1
# ============================================================

CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -Iheaders

FLEX = flex++
BISON = bison

TARGET = comp

# ============================================================
# Fuentes propios
# ============================================================

SRCS = \
	main.cpp \
	TypeTab.cpp \
	SymTab.cpp \
	PilaTs.cpp \
	TAC.cpp

OBJS = \
	main.o \
	TypeTab.o \
	SymTab.o \
	PilaTs.o \
	TAC.o \
	Parser.o \
	Lexer.o

# ============================================================
# Regla principal
# ============================================================

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# ============================================================
# Bison
# ============================================================

Parser.cpp Parser.hpp: parser.yy
	$(BISON) -d -o Parser.cpp parser.yy

# ============================================================
# Flex
# ============================================================

Lexer.cpp: lexer.ll Parser.hpp
	$(FLEX) lexer.ll

# ============================================================
# Objetos
# ============================================================

main.o: main.cpp Parser.hpp headers/Lexer.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

TypeTab.o: TypeTab.cpp headers/TypeTab.hpp
	$(CXX) $(CXXFLAGS) -c TypeTab.cpp

SymTab.o: SymTab.cpp headers/SymTab.hpp
	$(CXX) $(CXXFLAGS) -c SymTab.cpp

PilaTs.o: PilaTs.cpp headers/PilaTs.hpp headers/SymTab.hpp
	$(CXX) $(CXXFLAGS) -c PilaTs.cpp

TAC.o: TAC.cpp headers/TAC.hpp
	$(CXX) $(CXXFLAGS) -c TAC.cpp

Parser.o: Parser.cpp
	$(CXX) $(CXXFLAGS) -c Parser.cpp

Lexer.o: Lexer.cpp headers/Lexer.hpp Parser.hpp
	$(CXX) $(CXXFLAGS) -c Lexer.cpp

# ============================================================
# Limpieza
# ============================================================

clean:
	rm -f \
	$(TARGET) \
	$(OBJS) \
	Parser.cpp \
	Parser.hpp \
	Lexer.cpp

.PHONY: all clean