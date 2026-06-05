// Test 4: Variables globales
// Prueba: Declaración de variables en ámbito global

int global_x;
float global_y;
char global_c;

int function_using_globals()
{
    return global_x;
}

int main()
{
    global_x = 99;
    global_y = 12.5;
    global_c = 'Z';

    return function_using_globals();
}
