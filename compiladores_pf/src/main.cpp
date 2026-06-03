#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Scanner.hpp"
#include "Parser.hpp"

using namespace std;

int main(const int argc, const char **argv)
{
    if (argc < 2) {
        std::cerr << "Error: No input file provided.\n";
        std::cerr << "Usage: ./compiler <filepath>\n";
        return EXIT_FAILURE;
    }

    // Open the file provided in the terminal
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file '" << argv[1] << "'\n";
        return EXIT_FAILURE;
    }

    C0::Scanner scanner(&inFile);
    C0::Parser parser(scanner);
    
    int result = parser.parse();
    return (result == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}