# Repositorio Base del Proyecto Compilador

Proyecto de compilador frontend en C++ usando Flex y Bison. Compilador para un subconjunto de lenguaje C con análisis léxico, sintáctico, semántico y generación de código de tres direcciones (TAC).

## Características
- Análisis léxico (Flex)
- Análisis sintáctico (Bison)
- Análisis semántico
- Tablas de tipos
- Tablas de símbolos
- Generación de código de tres direcciones (TAC)
- Declaraciones y llamadas a funciones
- Soporte de arreglos y structs
- Detección de errores semánticos

## Construcción

```bash
make
```

## Ejecución

### Compilación del compilador
```bash
make
```
Esto generará el ejecutable `comp` en la carpeta `/src/`.

### Ejecución del compilador
```bash
./src/comp <archivo_fuente.c>
```

**Ejemplo:**
```bash
./src/comp src/prueba
```

### Flujo de ejecución
Al ejecutar el compilador, se mostrará:
1. Confirmación del archivo siendo analizado
2. Resultados del análisis léxico, sintáctico y semántico
3. **Código intermedio (TAC)** generado
4. Mensaje de éxito o errores semánticos encontrados

### Archivo de prueba
Existe un archivo de ejemplo `src/prueba` que contiene código válido del compilador:
```c
int f(int a, float b, int c, char d)
{
    return a;
}

int main()
{
    int x;
    x = f(10, 20.5, 3, 'z');
    return x;
}
```

Para ejecutar con este archivo:
```bash
./src/comp src/prueba
```

### Requisitos
- Compilador C++ con soporte C++11 o superior
- Flex (generador de analizadores léxicos)
- Bison (generador de analizadores sintácticos)
- Make

## Estructura del Proyecto

### `/compilador/` - Versión Anterior del Compilador
Contiene una implementación anterior del compilador con su propia estructura:
- **include/** - Headers de la versión anterior (Driver.hpp, Expresion.h, Quad.h, Symbol.h, Table.h, Type.h, etc.)
- **src/** - Código fuente de la versión anterior con implementación usando clases como Driver, Expresion, FinalCode, Quad, Stack, Symbol, Table, Type
- Nota: Esta carpeta se mantiene como histórico de desarrollo

### `/docs/` - Documentación
- **specification.md** - Especificación del lenguaje y características soportadas por el compilador

### `/include/` - Headers Compartidos
- **symbol_table.hpp** - Definiciones de tabla de símbolos

### `/src/` - Código Fuente Principal

#### Archivos de Configuración de Herramientas
- **lexer.ll** - Definición de reglas léxicas (Flex). Especifica tokens, patrones de identificadores, números, caracteres, comentarios
- **parser.yy** - Definición de reglas sintácticas (Bison). Define la gramática del lenguaje, reglas de producción y acciones semánticas

#### Archivos de Implementación
- **main.cpp** - Punto de entrada del compilador. Lee archivo fuente, instancia lexer y parser, y controla el flujo de compilación
- **SymTab.cpp** - Implementación de tabla de símbolos para gestionar variables, funciones y sus propiedades
- **TAC.cpp** - Generación de código de tres direcciones. Crea instrucciones intermedias durante el análisis
- **TypeTab.cpp** - Tabla de tipos para gestionar y validar tipos de datos
- **PilaTs.cpp** - Pila de tablas de símbolos para manejo de ámbitos (scopes)

#### Subdirectorio `/src/headers/` - Headers de Implementación Actual
- **Lexer.hpp** - Clase lexer que hereda de yyFlexLexer. Interfaz principal para análisis léxico
- **Parser.hpp** - Clase parser generada por Bison. Realiza análisis sintáctico y semántico
- **Attributes.hpp** - Estructuras de atributos semánticos (tipo, dirección, labels, etc.) para los nodos del árbol sintáctico
- **SymTab.hpp** - Definición de estructura Sym y tabla de símbolos con información de variables/funciones
- **TAC.hpp** - Interfaz para generación de código intermedio (temporales, labels, instrucciones)
- **TypeTab.hpp** - Tabla de tipos con información de tipos base y derivados
- **PilaTs.hpp** - Pila de contextos de tablas de símbolos para manejo de scope
- **ErrorSem.hpp** - Manejo de errores semánticos durante análisis
- **FlexLexer.h** - Header base de Flex (biblioteca estándar)

#### Otros Archivos
- **prueba** - Archivo de prueba del compilador
- **Makefile** - Configuración de construcción del proyecto

### Makefile Principal
Ubicado en la raíz del proyecto, configura la construcción de toda la solución

### Flujo de Compilación
1. **Análisis Léxico (Lexer)**: Lee el archivo fuente y genera tokens usando reglas en lexer.ll
2. **Análisis Sintáctico (Parser)**: Valida la estructura gramatical usando reglas en parser.yy
3. **Análisis Semántico**: Durante el parsing, valida tipos, símbolos y genera errores semánticos
4. **Generación de TAC**: Produce código intermedio de tres direcciones
5. **Salida**: Genera código intermedio listo para posterior compilación
