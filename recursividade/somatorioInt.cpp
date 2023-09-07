// PEREIRA, Silvio Lago. Estruturas de Dados em C
// exercicio 6.1 - Crie uma função recursiva para calcular a soma 1 + 2 + 3 + ... + n, sendo n um número natural.

#include <iostream>

using namespace std;

float somatorioInt(int n) {
    if (n == 1)
        return 1;
    return somatorioInt(n-1) + n;
}

int main() {

    float result = somatorioInt(10);
    cout << "resultado: " << result << endl;

    return 0;
}