// Test 6: Múltiples variables locales
// Prueba: Manejo de múltiples variables en diferentes ámbitos

int calculate(int a, int b, int c)
{
    int temp1;
    int temp2;
    int result;

    temp1 = a;
    temp2 = b;
    result = temp1;

    return result;
}

int main()
{
    int x;
    int y;
    int z;

    x = 10;
    y = 20;
    z = 30;

    return calculate(x, y, z);
}
