# Test Suite - Guía de Uso

## Descripción General

La suite de pruebas consiste en **15 archivos de código fuente** (.c) que validan diferentes aspectos del compilador C:

### Características Probadas
- Variables y tipos de datos (int, float, char)
- Declaración y llamada de funciones
- Parámetros y valores de retorno
- Ámbito global y local
- Errores semánticos esperados
- Generación de código intermedio (TAC)

## Estructura de la Carpeta `/tests/`

```
tests/
├── run_tests.sh              # Script para ejecutar todas las pruebas
├── README.md                 # Documentación detallada
├── TEST_INDEX.md             # Índice y referencia rápida
├── USAGE.md                  # Este archivo
│
├── test_basic_variables.c    # Pruebas válidas
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
└── test_error_*.c            # Pruebas que esperan errores
    ├── test_error_undeclared_var.c
    ├── test_error_redeclaration.c
    ├── test_error_undefined_func.c
    └── test_error_arg_count.c
```

## Cómo Usar

### 1. Compilar el Compilador

Primero, se necesita compilar el compilador C mismo. Desde la raíz del proyecto:

```bash
cd src
make clean && make
```

**Requisitos:**
- **Bison**: versión 3.2 o superior
- **Flex**: versión reciente
- **C++ compiler**: g++ con soporte C++17

**Verificar versiones:**
```bash
bison --version
flex --version
g++ --version
```

### 2. Ejecutar la Suite Completa

```bash
cd tests
./run_tests.sh
```

**Salida esperada:**
```
========================================
  EJECUTANDO PRUEBAS DEL COMPILADOR
========================================

Pruebas que deben ser válidas:
Testing test_basic_variables.c ... PASS
Testing test_functions.c ... PASS
...

Pruebas que deben generar errores:
Testing test_error_undeclared_var.c (error esperado) ... PASS (error detectado correctamente)
...

========================================
  RESUMEN DE PRUEBAS
========================================
Exitosas: 15
Fallidas:  0
Total:     15

✓ Todas las pruebas pasaron
```

### 3. Ejecutar Pruebas Individuales

```bash
# Una prueba válida
../src/comp test_basic_variables.c

# Ejemplo de salida para test válido
# Analizando archivo: test_basic_variables.c
# -------------------------------------------
# 
# ===== CODIGO INTERMEDIO =====
# [instrucciones TAC aquí]
# 
# -------------------------------------------
# Compilación exitosa
```

```bash
# Una prueba con error esperado
../src/comp test_error_undeclared_var.c

# Ejemplo de salida para test con error
# Analizando archivo: test_error_undeclared_var.c
# -------------------------------------------
# Error semántico: variable 'y' no declarada en línea X
# Compilación fallida
```

### 4. Ver Detalles de una Prueba

```bash
# Ver el código del test
cat test_basic_variables.c

# Ver solo el TAC generado (sin ruido)
../src/comp test_basic_variables.c | grep -A 100 "CODIGO INTERMEDIO"
```

## Interpretación de Resultados

### Test Exitoso (Prueba Válida)

```
Testing test_basic_variables.c ... PASS
```
- El compilador procesó el código sin errores
- Se generó TAC válido
- No hay errores semánticos

### Test Exitoso (Error Esperado)

```
Testing test_error_undeclared_var.c (error esperado) ... PASS (error detectado correctamente)
```
- El compilador detectó correctamente el error semántico
- El error fue reportado apropiadamente

### Test Fallido (Prueba Válida)

```
Testing test_functions.c ... FAIL
  Error: ...
```
- El código debería compilarse pero no lo hizo
- Hay un problema en el compilador o en la prueba

### Test Fallido (Error Esperado)

```
Testing test_error_undeclared_var.c (error esperado) ... FAIL (no se detectó error)
```
- El compilador no detectó el error que debería detectar
- Problema en la detección de errores semánticos

<!-- ## Agregar Nuevas Pruebas

### Paso 1: Crear archivo de test
```bash
# Crear test que debe ser válido
cat > test_myfeature.c << 'EOF'
// Tu código aquí
int main() {
    return 0;
}
EOF
```

### Paso 2: Actualizar run_tests.sh
Agregar el nombre del archivo de test a uno de estos arreglos:

```bash
# Para tests que deben compilar sin errores
VALID_TESTS=(
    ...
    "test_myfeature.c"
)

# Para tests que deben generar errores
ERROR_TESTS_EXPECTED=(
    ...
    "test_error_myfeature.c"
)
```

### Paso 3: Ejecutar el test
```bash
./run_tests.sh
``` -->

<!-- ## Solución de Problemas

### El compilador no se compila
```
Error: %language 'C++' - invalid directive
```
**Solución:** Actualiza Bison a versión 3.2 o superior
```bash
# En macOS con Homebrew:
brew install bison
brew link bison --force

# Verificar:
bison --version
```

### El script run_tests.sh no tiene permisos
```
bash: ./run_tests.sh: Permission denied
```
**Solución:** Dar permisos de ejecución
```bash
chmod +x run_tests.sh
./run_tests.sh
```

### Tests pasan pero no generad TAC esperado
- Verificar que el código del test sea sintácticamente correcto
- Revisar la salida completa: `../src/comp test_xxx.c`
- Comparar con el archivo de prueba esperado -->

## Métricas de la Suite

| Métrica | Valor |
|---------|-------|
| Tests totales | 15 |
| Tests válidos | 11 |
| Tests con error | 4 |
| Líneas de código promedio por test | ~12 |
| Categorías de features | 5 |
| Tipos de datos probados | 3 (int, float, char) |

## Notas Importantes

1. **Los tests solo validan compilación**, no ejecución
2. **El TAC es código intermedio**, no código ejecutable
3. **Los errores esperados** son casos que debe detectar el compilador
4. **Las pruebas son independientes** - cada una se ejecuta sola

<!-- ## Casos de Uso

### Desarrollador: Verificar cambios
```bash
./run_tests.sh
```

### Depuración: Entender error específico
```bash
../src/comp test_error_undeclared_var.c
```

### QA: Test coverage report
```bash
./run_tests.sh 2>&1 | tee test_results.log
```

### CI/CD: Integración continua
```bash
#!/bin/bash
cd src && make clean && make || exit 1
cd ../tests && ./run_tests.sh || exit 1
``` -->

---
