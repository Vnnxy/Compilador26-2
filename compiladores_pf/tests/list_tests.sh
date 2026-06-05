#!/bin/bash

# Lista rápida de todos los tests disponibles con descripción

echo "=========================================="
echo "  TEST SUITE - Lista Completa"
echo "=========================================="
echo ""

echo "TESTS VÁLIDOS (Deben compilar sin errores):"
echo ""
ls -1 test_[!e]*.c | nl | while read num file; do
    description=$(head -3 "$file" | grep "// " | head -1 | sed 's|// ||')
    printf "  %2d. %-35s: %s\n" "$num" "$file" "$description"
done

echo ""
echo "TESTS CON ERRORES ESPERADOS (Deben reportar error):"
echo ""
ls -1 test_error*.c | nl | while read num file; do
    description=$(head -3 "$file" | grep "// " | head -1 | sed 's|// ||')
    printf "  %2d. %-35s: %s\n" "$num" "$file" "$description"
done

echo ""
echo "=========================================="
echo "  ESTADÍSTICAS"
echo "=========================================="
valid_count=$(ls -1 test_[!e]*.c 2>/dev/null | wc -l)
error_count=$(ls -1 test_error*.c 2>/dev/null | wc -l)
total=$((valid_count + error_count))

printf "  Tests válidos:         %2d\n" "$valid_count"
printf "  Tests con error:       %2d\n" "$error_count"
printf "  Total:                 %2d\n" "$total"
echo ""

echo "=========================================="
echo "  CÓMO EJECUTAR"
echo "=========================================="
echo "  Suite completa:  ./run_tests.sh"
echo "  Un test:         ../src/comp test_xxx.c"
echo "  Documentación:   cat README.md"
echo ""
