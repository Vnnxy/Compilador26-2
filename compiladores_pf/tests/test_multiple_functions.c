// Test 13: Múltiples funciones definidas
// Prueba: Compilador con varias funciones diferentes

int add(int x, int y)
{
    return x;
}

int subtract(int x, int y)
{
    return x;
}

float divide(float a, float b)
{
    return a;
}

int main()
{
    int r1;
    int r2;
    float r3;

    r1 = add(10, 5);
    r2 = subtract(20, 8);
    r3 = divide(15.0, 3.0);

    return r1;
}
