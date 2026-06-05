# Test Index - Compilador C

Referencia rápida de todas las pruebas disponibles.

## Resumen por Categoría

### 1. Pruebas de Variables (test_*.c)

| Archivo | Descripción | Casos Cubiertos |
|---------|-------------|-----------------|
| `test_basic_variables.c` | Variables simples | int, float, char assignment |
| `test_global_variables.c` | Ámbito global | Global var access desde funciones |
| `test_multiple_locals.c` | Múltiples locales | Variable scoping |

### 2. Pruebas de Funciones

| Archivo | Descripción | Características |
|---------|-------------|-----------------|
| `test_functions.c` | Funciones básicas | Múltiples params, return |
| `test_mixed_types.c` | Tipos mixtos | int, float, char en params |
| `test_nested_calls.c` | Llamadas anidadas | func → func |
| `test_no_params.c` | Sin parámetros | Funciones simples |
| `test_unused_return.c` | Retorno no usado | Discard return value |
| `test_multiple_functions.c` | Múltiples funciones | 3+ funciones diferentes |
| `test_recursive.c` | Recursión | Función que se llama a sí misma |
| `test_complex_signatures.c` | Firmas complejas | Múltiples params de tipos variados |

### 3 Pruebas de Errores Semánticos

| Archivo | Error Esperado | Línea Problema |
|---------|----------------|----------------|
| `test_error_undeclared_var.c` | Variable no declarada | `x = y;` |
| `test_error_redeclaration.c` | Redeclaración | `int x; int x;` |
| `test_error_undefined_func.c` | Función no existe | `undefined_func(5)` |
| `test_error_arg_count.c` | Args inválidos | `func_two_args(5)` (falta 1) |

## Estadísticas

- **Total de pruebas**: 15
- **Pruebas válidas**: 11
- **Pruebas con error**: 4
- **Categorías cubiertas**: Variables, Funciones, Scoping, Tipos, Errores

## Cobertura de Features

| Feature | Test | Status |
|---------|------|--------|
| Variables int | test_basic_variables | ✓ |
| Variables float | test_basic_variables | ✓ |
| Variables char | test_basic_variables | ✓ |
| Funciones con params | test_functions | ✓ |
| Múltiples tipos de param | test_mixed_types | ✓ |
| Globales | test_global_variables | ✓ |
| Locales | test_multiple_locals | ✓ |
| Llamadas anidadas | test_nested_calls | ✓ |
| Sin parámetros | test_no_params | ✓ |
| Recursión | test_recursive | ✓ |
| Errores semánticos | test_error_* | ✓ |

## Ejecución Rápida

```bash
# Todas las pruebas
./run_tests.sh

# Una prueba específica
../src/comp test_basic_variables.c

# Ver solo errores
../src/comp test_error_undeclared_var.c
```
---

