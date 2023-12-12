#ifndef NO_SIMPLES_H
#define NO_SIMPLES_H

template <typename C, typename V>
class NoS {
private:
    C chave;
    V valor;
    NoS<C, V>* esq;
    NoS<C, V>* dir;

public:
    NoS(C chave, V valor) {
        this->chave = chave;
        this->valor = valor;
    }

    ~NoS() = default;
};

#endif