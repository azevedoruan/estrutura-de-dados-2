#include "abb.h"

int main() {

    ABB<int, int> abb;

    abb.inserirIterativo(10, 0);
    abb.inserirIterativo(4, 0);
    abb.inserirIterativo(20, -2);
    abb.inserirIterativo(6, 0);
    abb.inserirIterativo(2, 0);
    abb.inserirIterativo(3, 56);
    abb.inserirIterativo(5, 0);
    abb.inserirIterativo(7, 0);
    abb.inserirIterativo(1, 0);
    abb.inserirIterativo(8, 0);
    abb.calcularProfundidades();

    abb.imprimir();
    cout << "tamanho: " << abb.getTamanho() << endl;
    cout << "tamanho ansioso: " << abb.tamanhoAnsioso() << endl;
    cout << "altura (lazy): " << abb.altura() << endl;
    cout << "altura (eager): " << abb.alturaAnsiosa() << endl;
    cout << "comprimento interno: " << abb.comprimentoInterno() << endl;
    cout << "comprimento interno ansioso: " << abb.comprimentoInternoAnsioso() << endl;
    cout << "busca interativa: " << abb.buscarIterativo(3)->getValor() << endl;

    return 0;
}