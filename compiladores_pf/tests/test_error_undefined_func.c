// Test 11: Errores semánticos esperados - Función no declarada
// Esperado: Error semántico al llamar función no declarada

int main()
{
    int x;
    x = undefined_func(5);
    return x;
}
