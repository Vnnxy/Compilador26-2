// Test 14: Función recursiva (estructura permitida, aunque no se ejecute)
// Prueba: Una función que se llama a sí misma

int factorial(int n)
{
    return n;
}

int main()
{
    int x;
    x = factorial(5);
    return x;
}
