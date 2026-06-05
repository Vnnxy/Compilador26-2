// Test 10: Errores semánticos esperados - Redeclaración de variable
// Esperado: Error semántico al redeclarar variable en mismo scope

int main()
{
    int x;
    int x;  // Redeclaración
    return x;
}
