#ifndef ABB_H
#define ABB_H

#include <iostream>

template <typename C, typename V>
class ABB;

template <typename C, typename V>
class NoABB {
private:
    C chave;
    V valor;
    NoABB *esq;
    NoABB *dir;
    friend class ABB<C, V>;

public:
    NoABB(C chave, V valor);
    ~NoABB() = default;
    C getChave() { return chave; }
    V &getValor() { return valor; }
};

template <typename C, typename V>
class ABB {
private:
    NoABB<C, V> *raiz;

    NoABB<C, V>* inserirNo(NoABB<C, V> *no, C chave, V valor);
    NoABB<C, V>* removerNo(NoABB<C, V>* no, C chave);
    void imprimirNo(NoABB<C, V> *no, int nivel, char lado);
    
public:
    ABB() {}
    ~ABB();

    // insere o par (chave, valor) na árvore
    void inserir(C chave, V valor);
    
    // retorna uma referência ao nó com a chave especificada
    NoABB<C, V>* buscar(C chave);

    // remove o nó com a chave especificada
    void remover(C chave);

    // imprime a árvore
    void imprimir();

    // retorna uma referência ao nó com a menor chave
    NoABB<C, V>* minimo();
    NoABB<C, V>* minimo(NoABB<C, V>* no);

    // retorna uma referência ao nó com a maior chave
    NoABB<C, V>* maximo();
    // retorna uma referência ao nó com a chave sucessora da chave especificada
    NoABB<C, V>* sucessor(C chave);
    // retorna uma referência ao nó com a chave antecessora da chave especificada
    NoABB<C, V>* antecessor(C chave);
    // retorna o número de nós da árvore
    int tamanho();
    // retorna true se a árvore estiver vazia
    bool vazia();
};

#endif