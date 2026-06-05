// Test 9: Errores semánticos esperados - Variables no declaradas
// Esperado: Error semántico al usar variable no declarada

int main()
{
    int x;
    // y no está declarada
    x = y;
    return x;
}
