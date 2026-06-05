// Test 3: Mezcla de tipos y operaciones
// Prueba: Funciones con parámetros de diferentes tipos

int process(int a, float b, char c, int d)
{
    return a;
}

float calculate(float x, int y, char z)
{
    return x;
}

int main()
{
    int i;
    float f;
    char ch;

    i = process(100, 25.5, 'X', 200);
    f = calculate(1.5, 50, 'Y');

    return i;
}
