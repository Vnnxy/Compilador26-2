// Test 5: Llamadas de funciones anidadas
// Prueba: Una función que llama a otra

int inner(int x)
{
    return x;
}

int outer(int a, int b)
{
    return inner(a);
}

int main()
{
    int result;
    result = outer(5, 10);
    return result;
}
