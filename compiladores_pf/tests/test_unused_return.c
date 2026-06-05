// Test 8: Función void-like (retorna algo pero no se usa)
// Prueba: Funciones que retornan valores pero se usan en contextos diferentes

int helper()
{
    return 0;
}

int main()
{
    int x;
    int y;

    x = helper();
    helper();
    y = 15;

    return y;
}
