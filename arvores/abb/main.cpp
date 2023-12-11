#include "abb.h"

void testeExercicio1Todos() {

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
    abb->remover(10);

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
}

void testeExercicio2A() {

    ABB<int, int>* abb = new ABB<int, int>();
    int v[] = {10, 4, 20, 6, 2, 3, 5, 7, 1, 8};
    int n = 10;

    cout << "vetor antes: ";
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << endl;
    abb->ordenar(v, n);
    cout << "vetor depois: ";
        for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << endl;
    delete abb;
}

int main() {

    //testeExercicio1Todos();
    testeExercicio2A();

    return 0;
}