// PEREIRA, Silvio Lago. Estruturas de Dados em C
// exercicio 6.9 - Crie uma função recursiva para calcular a soma dos n primeiros itens armazenados num vetor de números inteiros v.

#include <iostream>

using namespace std;

int somaVet(int *v, int n) {
    if (n <= 0)
        return 0;
    return somaVet(v, n-1) + v[n-1];
}

int main() {

    int vet[] = {2, 4, 3, 1, 10, 8};
    float result = somaVet(vet, 5);
    cout << "resultado: " << result << endl;

    return 0;
}