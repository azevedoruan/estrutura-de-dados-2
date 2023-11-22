#include "abb.h"

int main() {

    ABB<int, int> abb;

    abb.inserir(10, 0);
    abb.inserir(4, 0);
    abb.inserir(20, 0);
    abb.inserir(6, 0);
    abb.inserir(2, 0);
    abb.inserir(3, 0);

    abb.imprimir();

    return 0;
}