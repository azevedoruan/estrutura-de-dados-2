#ifndef NO_DUPLO_H
#define NO_DUPLO_H

#include "NoSimples.hpp"

template <typename C, typename V>
class NoD : public NoS<C, V> {
private:
    C chave2;
    NoS<C, V>* mei;

public:
    NoD(C chave, C chave2, V valor) : NoS<C, V>::NoS(chave, valor) {
        this->chave2 = chave2;
    }

    ~NoD() = default;
};

#endif