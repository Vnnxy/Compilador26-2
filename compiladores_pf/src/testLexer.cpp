#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Scanner.hpp"
#include "Parser.hpp" // We still need this because it defines the token numbers!

using namespace std;

int main(const int argc, const char **argv)
{
    if (argc < 2) {
        cerr << "Error: No input file provided.\n";
        cerr << "Usage: ./test_lexer <filepath>\n";
        return EXIT_FAILURE;
    }

    ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open input file '" << argv[1] << "'\n";
        return EXIT_FAILURE;
    }

    // Instantiate the scanner
    C0::Scanner scanner(&inFile);

    // Dummy variables required by your yylex() signature
    C0::Parser::semantic_type lval;
    C0::Parser::location_type loc;

    cout << "--- STARTING LEXICAL ANALYSIS ---" << endl;
    cout << "TOKEN ID\tLEXEME" << endl;
    cout << "---------------------------------" << endl;

    int token_id;
    // scanner.yylex() returns 0 when it reaches the End of File (EOF)
    while ((token_id = scanner.yylex(&lval, &loc)) != 0) {
        // yytext() contains the actual string matched by the regex
        cout << token_id << "\t\t" << scanner.YYText() << endl;
    }

    cout << "---------------------------------" << endl;
    cout << "--- LEXICAL ANALYSIS COMPLETE ---" << endl;

    return EXIT_SUCCESS;
}