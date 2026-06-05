# Resumen - Suite de Tests Creada

## Archivos Creados

Se ha creado una suite completa de **15 pruebas unitarias** en la carpeta `/tests/`:

### Scripts Ejecutables
- **`run_tests.sh`** - Ejecuta automáticamente toda la suite
- **`list_tests.sh`** - Lista todos los tests disponibles con descripción

### Pruebas Unitarias (15 archivos .c)

#### ✓ Pruebas Válidas (11 tests)
```
test_basic_variables.c        - Variables simples (int, float, char)
test_functions.c              - Funciones con parámetros
test_mixed_types.c            - Parámetros de tipos variados
test_global_variables.c       - Variables de ámbito global
test_nested_calls.c           - Funciones que llaman funciones
test_multiple_locals.c        - Múltiples variables locales
test_no_params.c              - Funciones sin parámetros
test_unused_return.c          - Retorno de funciones no usado
test_multiple_functions.c     - Varias funciones
test_recursive.c              - Función recursiva
test_complex_signatures.c     - Firmas complejas con múltiples tipos
```

#### ✗ Pruebas con Errores (4 tests)
```
test_error_undeclared_var.c   - Variable no declarada
test_error_redeclaration.c    - Variable redeclarada
test_error_undefined_func.c   - Función no declarada
test_error_arg_count.c        - Número incorrecto de argumentos
```

### Documentación

1. **README.md** - Documentación completa de la suite
   - Descripción de cada test
   - Cómo ejecutarlos
   - Interpretación de resultados

2. **TEST_INDEX.md** - Referencia rápida
   - Tabla de tests por categoría
   - Cobertura de features
   - Estadísticas

3. **USAGE.md** - Guía de uso detallada
   - Requisitos de compilación
   - Paso a paso para usar la suite
   - Solución de problemas
   - Cómo agregar nuevos tests

4. **SUITE_SUMMARY.md** - Este archivo

## Cobertura

La suite cubre:

| Aspecto | Cobertura |
|---------|-----------|
| Tipos de datos | int, float, char |
| Declaración de variables | Global, local |
| Funciones | Con/sin parámetros, recursivas |
| Parámetros | Simples, múltiples, tipos variados |
| Retornos | Diferentes tipos, ignorados |
| Errores semánticos | 4 tipos diferentes |
| Scoping | Global y local |
| Control de flujo | Labels en atributos (infraestructura) |

## Estadísticas

```
Total de pruebas:        15
Pruebas válidas:         11
Pruebas con error:       4
Líneas de código aprox:  180
Archivos creados:        7 (scripts + docs)
```

## Uso Rápido

### Ver lista de tests
```bash
cd tests
./list_tests.sh
```

### Ejecutar toda la suite (cuando el compilador esté disponible)
```bash
cd tests
./run_tests.sh
```

### Ejecutar un test individual
```bash
cd tests
../src/comp test_basic_variables.c
```

## ✨ Características

- Tests independientes (cada uno se ejecuta aislado)
- Documentación completa (3 archivos .md)
- Scripts de automatización
- Fácil de extender (agregar nuevas pruebas)
- Tests de error (valida detección de errores)
- Colores en output (PASS/FAIL claramente identificados)
- Cobertura de features principales

## Estructura Creada

```
compiladores_pf/
└── tests/
    ├── run_tests.sh              ← Ejecutador principal
    ├── list_tests.sh             ← Visor de tests
    ├── README.md                 ← Documentación
    ├── TEST_INDEX.md             ← Índice rápido
    ├── USAGE.md                  ← Guía de uso
    ├── SUITE_SUMMARY.md          ← Este archivo
    │
    ├── test_basic_variables.c
    ├── test_functions.c
    ├── test_mixed_types.c
    ├── test_global_variables.c
    ├── test_nested_calls.c
    ├── test_multiple_locals.c
    ├── test_no_params.c
    ├── test_unused_return.c
    ├── test_multiple_functions.c
    ├── test_recursive.c
    ├── test_complex_signatures.c
    │
    ├── test_error_undeclared_var.c
    ├── test_error_redeclaration.c
    ├── test_error_undefined_func.c
    └── test_error_arg_count.c
```

## Requisitos

Para ejecutar la suite necesitas:

1. **Compilar el compilador primero**:
   ```bash
   cd src
   make clean && make
   ```

2. **Requisitos de compilación**:
   - Bison >= 3.2
   - Flex
   - g++ con C++17

## Notas

- Los tests validan **compilación**, no ejecución
- El TAC generado es **código intermedio**, no ejecutable
- Cada test es **independiente** de los otros
- Los tests se pueden ejecutar en **cualquier orden**

---
