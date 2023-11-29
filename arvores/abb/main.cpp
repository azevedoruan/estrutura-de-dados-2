#include "abb.h"

int main() {

    ABB<int, int> abb;

    abb.inserir(10, 0);
    abb.inserir(4, 0);
    abb.inserir(20, 0);
    abb.inserir(6, 0);
    abb.inserir(2, 0);
    abb.inserir(3, 0);
    abb.inserir(5, 0);
    abb.inserir(7, 0);
    abb.inserir(1, 0);
    abb.calcularProfundidades();

    abb.imprimir();
    cout << "tamanho: " << abb.tamanho() << endl;
    cout << "altura (lazy): " << abb.altura() << endl;

    return 0;
}