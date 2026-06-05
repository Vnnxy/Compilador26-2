#!/bin/bash

# Script para ejecutar pruebas unitarias del compilador
# Uso: ./run_tests.sh

COMPILER="../src/comp"
TEST_DIR="."
PASS_COUNT=0
FAIL_COUNT=0
ERROR_TESTS=""
SUCCESS_TESTS=""

# Colores para output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Verificar que el compilador existe
if [ ! -f "$COMPILER" ]; then
    echo -e "${RED}Error: Compilador no encontrado en $COMPILER${NC}"
    echo ""
    echo "Para compilar el compilador, ejecuta:"
    echo "  cd .."
    echo "  cd src"
    echo "  make clean && make"
    echo ""
    echo "Requisitos:"
    echo "  - Bison >= 3.2"
    echo "  - Flex"
    echo "  - g++ con soporte C++17"
    exit 1
fi

echo -e "${YELLOW}========================================${NC}"
echo -e "${YELLOW}  EJECUTANDO PRUEBAS DEL COMPILADOR${NC}"
echo -e "${YELLOW}========================================${NC}"
echo ""

# Arreglos para tests exitosos y con error esperado
VALID_TESTS=(
    "test_basic_variables.c"
    "test_functions.c"
    "test_mixed_types.c"
    "test_global_variables.c"
    "test_nested_calls.c"
    "test_multiple_locals.c"
    "test_no_params.c"
    "test_unused_return.c"
    "test_multiple_functions.c"
    "test_recursive.c"
    "test_complex_signatures.c"
)

ERROR_TESTS_EXPECTED=(
    "test_error_undeclared_var.c"
    "test_error_redeclaration.c"
    "test_error_undefined_func.c"
    "test_error_arg_count.c"
)

# Función para ejecutar un test válido
run_valid_test() {
    local test_file=$1
    echo -n "Testing $test_file ... "
    
    # Ejecutar el compilador y guardar resultado
    OUTPUT=$($COMPILER "$TEST_DIR/$test_file" 2>&1)
    EXIT_CODE=$?
    
    # Verificar que no hay errores semánticos
    if [[ $OUTPUT == *"error"* ]] || [[ $OUTPUT == *"Error"* ]]; then
        echo -e "${RED}FAIL${NC}"
        echo "  Salida: $OUTPUT" | head -n 3
        echo ""
        ((FAIL_COUNT++))
        return 1
    elif [ $EXIT_CODE -ne 0 ]; then
        echo -e "${RED}FAIL${NC}"
        echo "  Código de salida: $EXIT_CODE"
        echo ""
        ((FAIL_COUNT++))
        return 1
    else
        echo -e "${GREEN}PASS${NC}"
        ((PASS_COUNT++))
        return 0
    fi
}

# Función para ejecutar un test con error esperado
run_error_test() {
    local test_file=$1
    echo -n "Testing $test_file (error esperado) ... "
    
    # Ejecutar el compilador y guardar resultado
    OUTPUT=$($COMPILER "$TEST_DIR/$test_file" 2>&1)
    EXIT_CODE=$?
    
    # Verificar que hay errores semánticos
    if [[ $OUTPUT == *"error"* ]] || [[ $OUTPUT == *"Error"* ]]; then
        echo -e "${GREEN}PASS${NC} (error detectado correctamente)"
        ((PASS_COUNT++))
        return 0
    else
        echo -e "${RED}FAIL${NC} (no se detectó error)"
        echo ""
        ((FAIL_COUNT++))
        return 1
    fi
}

# Ejecutar tests válidos
echo -e "${YELLOW}Pruebas que deben ser válidas:${NC}"
for test in "${VALID_TESTS[@]}"; do
    if [ -f "$TEST_DIR/$test" ]; then
        run_valid_test "$test"
    fi
done

echo ""
echo -e "${YELLOW}Pruebas que deben generar errores:${NC}"
for test in "${ERROR_TESTS_EXPECTED[@]}"; do
    if [ -f "$TEST_DIR/$test" ]; then
        run_error_test "$test"
    fi
done

# Resumen final
echo ""
echo -e "${YELLOW}========================================${NC}"
echo -e "${YELLOW}  RESUMEN DE PRUEBAS${NC}"
echo -e "${YELLOW}========================================${NC}"
echo -e "Exitosas: ${GREEN}$PASS_COUNT${NC}"
echo -e "Fallidas:  ${RED}$FAIL_COUNT${NC}"
echo -e "Total:     $((PASS_COUNT + FAIL_COUNT))"
echo ""

if [ $FAIL_COUNT -eq 0 ]; then
    echo -e "${GREEN}✓ Todas las pruebas pasaron${NC}"
    exit 0
else
    echo -e "${RED}✗ Algunas pruebas fallaron${NC}"
    exit 1
fi
