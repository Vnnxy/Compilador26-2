# Test Suite - Compilador C

Suite de pruebas unitarias para el compilador de lenguaje C.

## Descripción

Estos tests validan que el compilador correctamente:
- Analiza código léxico y sintácticamente correcto
- Detecta y reporta errores semánticos
- Genera código de tres direcciones (TAC)
- Maneja diferentes tipos de datos
- Procesa funciones con múltiples parámetros
- Gestiona ámbitos (scopes) correctamente

## Estructura de Tests

### Pruebas Válidas (sin errores esperados)

1. **test_basic_variables.c**
   - Variables simples e inicializaciones
   - Tipos: int, float, char

2. **test_functions.c**
   - Definición y llamada de funciones
   - Funciones con múltiples parámetros
   - Retorno de valores

3. **test_mixed_types.c**
   - Funciones con parámetros de tipos variados
   - Mezcla de int, float, char

4. **test_global_variables.c**
   - Variables globales
   - Acceso a globales desde funciones

5. **test_nested_calls.c**
   - Funciones que llaman otras funciones
   - Paso de valores entre funciones

6. **test_multiple_locals.c**
   - Múltiples variables locales
   - Gestión de ámbito local

7. **test_no_params.c**
   - Funciones sin parámetros
   - Retorno desde funciones simples

8. **test_unused_return.c**
   - Llamadas a funciones cuyo valor no se usa
   - Evaluación de expresiones

9. **test_multiple_functions.c**
   - Compilador con varias funciones
   - Diferentes tipos de retorno

10. **test_recursive.c**
    - Función recursiva (estructura, no ejecución)
    - Llamada a misma función

11. **test_complex_signatures.c**
    - Funciones con múltiples parámetros complejos
    - Retornos de diferentes tipos

### Pruebas de Errores Semánticos

Estas pruebas esperan que el compilador reporte errores:

1. **test_error_undeclared_var.c**
   - Uso de variable no declarada
   - Error esperado: Variable no existe

2. **test_error_redeclaration.c**
   - Redeclaración de variable en mismo scope
   - Error esperado: Variable ya declarada

3. **test_error_undefined_func.c**
   - Llamada a función no declarada
   - Error esperado: Función no existe

4. **test_error_arg_count.c**
   - Número incorrecto de argumentos
   - Error esperado: Argumento count mismatch

## Ejecución de Tests

### Opción 1: Script automatizado
```bash
chmod +x run_tests.sh
./run_tests.sh
```

### Opción 2: Ejecución manual de un test
```bash
../src/comp test_basic_variables.c
```

### Opción 3: Ejecutar todos los tests
```bash
for test in test_*.c; do
  echo "=== Testing $test ==="
  ../src/comp "$test"
done
```

## Interpretación de Resultados

### Prueba Válida
```
Analizando archivo: ...
CODIGO INTERMEDIO
[instrucciones TAC]
Compilación exitosa
```

### Prueba con Error
```
Error semántico en línea X: [mensaje de error]
Compilación fallida
```

## Agregar Nuevas Pruebas

Para agregar una nueva prueba:

1. Crea un archivo `test_mytest.c` en esta carpeta
2. Agrega el nombre del archivo a:
   - `VALID_TESTS` si debe compilar sin errores
   - `ERROR_TESTS_EXPECTED` si debe generar error
3. Ejecuta `./run_tests.sh`

## Notas

- El compilador se construye desde la raíz con `make`
- El ejecutable debe estar en `../src/comp`
- Los tests no validan la ejecución del código, solo la compilación
- El TAC (código intermedio) generado se muestra en stdout
