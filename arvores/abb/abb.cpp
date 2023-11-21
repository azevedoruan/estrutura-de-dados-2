#include "abb.h"

template<typename C, typename V>
NoABB<C,V>::NoABB(C chave, V valor) {
    this->chave = chave;
    this->valor = valor;
    this->dir = nullptr;
    this->esq = nullptr;
}

template<typename C, typename V>
void ABB<C, V>::inserir(C chave, V valor) {
    this->raiz = this->inserirNo(this->raiz, chave, valor);
}

template<typename C, typename V>
NoABB<C, V>* ABB<C, V>::buscar(C chave) {
    auto p = this->raiz;
    while(p != nullptr){
        if(chave == p->chave){
            return p;
        }
        if(chave < p->chave)
            p = p->esq;
        else
            p = p->dir;
    }
    return nullptr;
}

template<typename C, typename V>
void ABB<C, V>::remover(C chave) {
    this->raiz = this->removerNo(this->raiz, chave);
}

template<typename C, typename V>
NoABB<C, V>* ABB<C, V>::minimo(NoABB<C, V>* no) {
    if(no == nullptr)
        return nullptr;

    auto p = no;
    while(p->esq != nullptr)
        p = p->esq;

    return p;
}

template<typename C, typename V>
NoABB<C, V>* ABB<C, V>::inserirNo(NoABB<C, V>* no, C chave, V valor) {
    if(no == nullptr)
        return new NoABB(chave, valor);
    if(chave == no->chave)
        no->valor = valor;
    else if(chave < no->chave)
        no->esq = inserirNo(no->esq, chave, valor);
    else
        no->dir = inserirNo(no->dir, chave, valor);
    return no;
}

template<typename C, typename V>
NoABB<C, V>* ABB<C, V>::removerNo(NoABB<C, V>* no, C chave) {
    if(no == nullptr){
        return nullptr;
    }

    if(chave < no->chave)
        no->esq = removerNo(no->esq, chave);
    else if(chave > no->chave)
        no->dir = removerNo(no->dir, chave);
    else {
        //caso 1: o elemento a ser removido é folha
        if(no->esq == nullptr && no->dir == nullptr){
            delete no;
            return nullptr;
        }
        //caso 2: o elemento a ser removido tem 1 filho
        //2a: tá faltando o filho esquerdo. 
        if(no->esq == nullptr){
            auto aux = no->dir;
            delete no;
            return aux;
        }
        //2b: tá faltando o filho direito.
        if(no->dir == nullptr){
            auto aux = no->esq;
            delete no;
            return aux;
        }
        //caso 3: o nó a ser removido tem 2 filhos!
        //encontrar o sucessor
        auto suc = minimo(no->dir);
        no->chave = suc->chave;
        no->valor = suc->valor;
        no->dir = removerNo(no->dir, suc->chave);
    } 
    return no;
}