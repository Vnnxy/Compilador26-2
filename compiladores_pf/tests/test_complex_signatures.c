// Test 15: Mezcla de tipos en parámetros y retornos
// Prueba: Funciones complejas con varios tipos

char process_data(int count, float value, char mode)
{
    return mode;
}

int analyze(char input, int threshold)
{
    return threshold;
}

float compute(float x, int y, int z, char op)
{
    return x;
}

int main()
{
    int counter;
    float data;
    char status;

    counter = 0;
    data = 0.0;
    status = 'X';

    status = process_data(100, 99.9, 'A');
    counter = analyze('B', 50);
    data = compute(42.5, 10, 20, 'C');

    return counter;
}
