// PEREIRA, Silvio Lago. Estruturas de Dados em C
// exercicio 6.1 - 	Crie uma função recursiva para calcular x^n, sendo x != 0 um número real e n um número natural.

#include <iostream>

using namespace std;

float pow(float x, int n) {
    if (n == 0)
        return 1;
    if (x == 0)
        return 0;
    return (float)(pow(x, n-1) * x);
}

int main() {

    float result = pow(2.5, 2);
    cout << "resultado: " << result << endl;

    return 0;
}