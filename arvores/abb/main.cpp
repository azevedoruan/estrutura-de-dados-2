#include "abb.h"

int main() {

    ABB<int, int>* abb = new ABB<int, int>();

    abb->inserirIterativo(10, 0);
    abb->inserirIterativo(4, 0);
    abb->inserirIterativo(20, -2);
    abb->inserirIterativo(6, 0);
    abb->inserirIterativo(2, 0);
    abb->inserirIterativo(3, 56);
    abb->inserirIterativo(5, 0);
    abb->inserirIterativo(7, 0);
    abb->inserirIterativo(1, 0);
    abb->inserirIterativo(8, 0);
    abb->calcularProfundidades();

    abb->imprimir();
    cout << "tamanho: " << abb->getTamanho() << endl;
    cout << "altura: " << abb->altura() << endl;
    cout << "comprimento interno: " << abb->comprimentoInterno() << endl;
    cout << "tamanho (eager): " << abb->tamanhoAnsioso() << endl;
    cout << "altura (eager): " << abb->alturaAnsiosa() << endl;
    cout << "comprimento interno (eager): " << abb->comprimentoInternoAnsioso() << endl;
    cout << "busca iterativa: " << abb->buscarIterativo(3)->getValor() << endl;
    delete abb;
    cout << "destruir arvore" << endl;

    return 0;
}