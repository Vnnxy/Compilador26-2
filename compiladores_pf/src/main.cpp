#include <iostream>
#include <fstream>
#include <cstdlib>

#include "headers/Lexer.hpp"
#include "headers/Parser.hpp"
#include "headers/TAC.hpp"
#include "headers/ErrorSem.hpp"

// Bandera para errores semánticos
bool errorSem = false;
// Bandera para errores léxicos
bool errorLexico = false;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cerr
            << "Uso: ./comp <archivo_fuente>"
            << std::endl;

        return EXIT_FAILURE;
    }

    std::ifstream in(argv[1]);

    if (!in.is_open()) {

        std::cerr
            << "Error: no se pudo abrir el archivo '"
            << argv[1]
            << "'"
            << std::endl;

        return EXIT_FAILURE;
    }

    C1::Lexer lexer(&in);

    C1::Parser parser(&lexer);

    std::cout
        << "Analizando archivo: "
        << argv[1]
        << std::endl;

    std::cout
        << "-------------------------------------------"
        << std::endl;

    int result = parser.parse();

    extern vector<string> codigo;

    in.close();

    std::cout << std::endl;

    // ========================================================
    // Guardar código intermedio en archivo
    // ========================================================

    std::string nombreSalida =
        std::string(argv[1]) + ".tac";

    std::ofstream out(nombreSalida);

    if(!out.is_open()){

        std::cerr
            << "No se pudo crear el archivo de salida: "
            << nombreSalida
            << std::endl;
    }
    else{

        for(const std::string& instr : codigo){

            out
                << instr
                << std::endl;
        }

        out.close();

        std::cout
            << "Codigo intermedio guardado en: "
            << nombreSalida
            << std::endl;
}

    std::cout << std::endl;

    std::cout
        << "-------------------------------------------"
        << std::endl;

    // Status final. 
    if (result == 0 && !errorSem && !errorLexico) {

        std::cout
            << "Analisis completado exitosamente."
            << std::endl;

    } else {

        std::cout
            << "El analisis termino con errores."
            << std::endl;
    }

    return result;
}