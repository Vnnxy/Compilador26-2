// Test 12: Errores semánticos esperados - Número incorrecto de argumentos
// Esperado: Error semántico si los argumentos no coinciden

int func_two_args(int a, int b)
{
    return a;
}

int main()
{
    int x;
    x = func_two_args(5);  // Falta un argumento
    return x;
}
