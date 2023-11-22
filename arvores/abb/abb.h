#ifndef ABB_H
#define ABB_H

#include <iostream>

using namespace std;

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
    NoABB(C chave, V valor) {
        this->chave = chave;
        this->valor = valor;
        this->dir = nullptr;
        this->esq = nullptr;
    }

    ~NoABB() = default;
    C getChave() { return chave; }
    V &getValor() { return valor; }
};

template <typename C, typename V>
class ABB {
private:
    NoABB<C, V> *raiz;

    NoABB<C, V>* inserirNo(NoABB<C, V> *no, C chave, V valor) {
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

    NoABB<C, V>* removerNo(NoABB<C, V>* no, C chave) {
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

    void imprimirNo(NoABB<C, V> *no, int nivel, char lado) {
        int nivelAux = nivel;
        if (no == nullptr) {
            return;
        }
        else {
            while (nivelAux > 0) {
                cout << "       ";
                nivelAux--;
            }
            cout << "(" << lado << ") " << no->chave << endl;
        }
        
        imprimirNo(no->esq, nivel + 1, 'e');
        imprimirNo(no->dir, nivel + 1, 'd');
    }
    
public:
    ABB() { raiz = nullptr; }
    ~ABB() = default;

    // insere o par (chave, valor) na árvore
    void inserir(C chave, V valor) {
        raiz = inserirNo(raiz, chave, valor);
    }
    
    // retorna uma referência ao nó com a chave especificada
    NoABB<C, V>* buscar(C chave) {
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

    // remove o nó com a chave especificada
    void remover(C chave) {
        raiz = removerNo(raiz, chave);
    }

    // imprime a árvore
    void imprimir() {
        imprimirNo(raiz, 0, 'r');
    }

    // retorna uma referência ao nó com a menor chave
    NoABB<C, V>* minimo();
    NoABB<C, V>* minimo(NoABB<C, V>* no) {
        if(no == nullptr)
            return nullptr;

        auto p = no;
        while(p->esq != nullptr)
            p = p->esq;

        return p;
    }

    // retorna uma referência ao nó com a maior chave
    NoABB<C, V>* maximo();
    // retorna uma referência ao nó com a chave sucessora da chave especificada
    NoABB<C, V>* sucessor(C chave);
    // retorna uma referência ao nó com a chave antecessora da chave especificada
    NoABB<C, V>* antecessor(C chave);

    // retorna o número de nós da árvore
    int tamanho() {
        //TODO exercicio 1.c
        //Escreva uma função recursiva ABB_Tamanho que devolva o número de nós de uma árvore binária.
        
    }

    // retorna true se a árvore estiver vazia
    bool vazia();

    // retorna o número de níveis de uma árvore
    int altura() {
        //TODO exercico 1.d
        //Escreva uma função recursiva ABB_Altura que calcule a altura de uma árvore binária. Sua implementação
        //deve ser preguiçosa (lazy), ou seja, não é necessário calcular as profundidades antes
    }

    int calcularProfundidades(NoABB<C, V>* no) {
        //TODO exercicio 1.e
        //Acrescente um campo profundidade a estrutura ABB para armazenar a profundidade do nó. Escreva uma
        //função ABB_CalcularProfundidades que atribua as profundidades de todos os nós.
    }

    int comprimentoInterno() {
        //TODO exercicio 1.f
        //O comprimento interno de uma árvore binária é a soma das profundidades dos seus nós, ou seja, a soma de
        //todos os caminhos que levam da raíz até um nó. Escreva um método ABB_ComprimentoInterno que retorne
        //o comprimento interno de uma árvore binária.
    }
};

#endif