#ifndef ADT_H
#define ADT_H

#include "NoDuplo.hpp"
#include <iostream>

using namespace std;

template <typename C, typename V>
class ADT {
private:
    NoS<C, V>* raiz;
    int tamanho;

public:
    void imprimir() {
        cout << "funcionando!" << endl;
    }

};

#endif