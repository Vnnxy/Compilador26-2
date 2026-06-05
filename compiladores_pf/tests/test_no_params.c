// Test 7: Función sin parámetros
// Prueba: Definición y llamada de función sin argumentos

int get_constant()
{
    return 42;
}

char get_char()
{
    return 'Q';
}

int main()
{
    int value;
    char letter;

    value = get_constant();
    letter = get_char();

    return value;
}
