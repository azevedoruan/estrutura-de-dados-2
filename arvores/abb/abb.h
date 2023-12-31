#ifndef ABB_H
#define ABB_H

#include <iostream>
#include <queue>

using namespace std;

template <typename C, typename V>
class ABB;

template <typename C, typename V>
class NoABB {
private:
    C chave;
    V valor;
    int profundidade;
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
    int getProfundidade() { return profundidade; }
    void setProfundidade(int profundidade) { this->profundidade = profundidade; }
};

template <typename C, typename V>
class ABB {
private:
    NoABB<C, V> *raiz;
    int tamanho;
    int h;
    int ci;

    NoABB<C, V>* inserirNo(NoABB<C, V> *no, C chave, V valor, int nivel) {
        if(no == nullptr) {
            tamanho++;
            if (tamanho > 1)
                ci++;
            if (nivel > h)
                h = nivel;
            return new NoABB(chave, valor);
        }
        if(chave == no->chave)
            no->valor = valor;
        else if(chave < no->chave)
            no->esq = inserirNo(no->esq, chave, valor, nivel + 1);
        else
            no->dir = inserirNo(no->dir, chave, valor, nivel + 1);
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
            tamanho--;
            if (tamanho > 1)
                ci--;
        } 
        return no;
    }

    NoABB<C, V>* buscarNoMenor(NoABB<C, V>* no) {
        if (no == nullptr)
            return nullptr;
        if (no->esq == nullptr)
            return no;
        else
            return buscarNoMenor(no->esq);
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
            cout << "(" << lado << ") " << no->chave << " prof " << no->getProfundidade() << endl;
        }
        
        imprimirNo(no->esq, nivel + 1, 'e');
        imprimirNo(no->dir, nivel + 1, 'd');
    }

    int contadorNo(NoABB<C, V>* no) {
        if (no == nullptr)
            return 0;
        else
            return contadorNo(no->esq) + contadorNo(no->dir) + 1;
    }

    int alturaNo(NoABB<C, V>* no) {
        if (no == nullptr)
            return 0;
        
        int hEsq = alturaNo(no->esq);
        int hDir = alturaNo(no->dir);

        if (hEsq >= hDir)
            return hEsq + 1;
        else
            return hDir + 1;
    }

    void calcularProfundidadeNo(NoABB<C, V>* no, int profundidade) {
        if (no == nullptr)
            return;
        no->setProfundidade(profundidade);
        calcularProfundidadeNo(no->dir, profundidade + 1);
        calcularProfundidadeNo(no->esq, profundidade + 1);
    }

    int comprimentoInternoNo(NoABB<C, V>* no) {
        if (no == nullptr)
            return 0;
        return comprimentoInternoNo(no->esq) + comprimentoInternoNo(no->dir) + 1;
    }
    
    void destruirNo(NoABB<C, V>* no) {
        if (no == nullptr) {
            return;
        } else {
            destruirNo(no->esq);
            destruirNo(no->dir);
            delete no;            
        }
    }

public:
    ABB() {
        raiz = nullptr;
        tamanho = 0;
        h = 0;
        ci = 0;
    }
    ~ABB() {
        destruirNo(raiz);
    }

    // insere o par (chave, valor) na árvore
    void inserir(C chave, V valor) {
        raiz = inserirNo(raiz, chave, valor, 0);
    }

    void inserirIterativo(C chave, V valor) {
        if (raiz == nullptr) {
            raiz = new NoABB(chave, valor);
            return;
        }

        NoABB<C, V>* noCorrente = raiz;
        bool inserido = false;

        while (inserido == false) {
            if (noCorrente->getChave() == chave) {
                noCorrente->valor = valor;
                inserido = true;
            } else if (chave < noCorrente->getChave()) {
                if (noCorrente->esq == nullptr) {
                    noCorrente->esq = new NoABB(chave, valor);
                    inserido = true;
                } else {
                    noCorrente = noCorrente->esq;
                }
            } else if (chave > noCorrente->getChave()) {
                if (noCorrente->dir == nullptr) {
                    noCorrente->dir = new NoABB(chave, valor);
                    inserido = true;
                } else {
                    noCorrente = noCorrente->dir;
                }
            }
        }       
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

    NoABB<C, V>* buscarIterativo(C chave) {
        queue<NoABB<C, V>*> queueNoABB;
        queueNoABB.push(raiz);

        while (!queueNoABB.empty()) {
            if (queueNoABB.front()->getChave() == chave) {
                return queueNoABB.front();
            }
            else {
                if (queueNoABB.front()->esq != nullptr)
                    queueNoABB.push(queueNoABB.front()->esq);
                if (queueNoABB.front()->dir != nullptr)
                    queueNoABB.push(queueNoABB.front()->dir);
                queueNoABB.pop();
            }
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
    int getTamanho() {
        //exercicio 1.c
        //Escreva uma função recursiva ABB_Tamanho que devolva o número de nós de uma árvore binária.
        return contadorNo(raiz);
    }

    int tamanhoAnsioso() {
        return this->tamanho;
    }

    // retorna true se a árvore estiver vazia
    bool vazia();

    // retorna o número de níveis de uma árvore
    int altura() {
        //exercico 1.d
        //Escreva uma função recursiva ABB_Altura que calcule a altura de uma árvore binária. Sua implementação
        //deve ser preguiçosa (lazy), ou seja, não é necessário calcular as profundidades antes
        return alturaNo(raiz) - 1;
    }

    int alturaAnsiosa() {
        return h;
    }

    void calcularProfundidades() {
        //exercicio 1.e
        //Acrescente um campo profundidade a estrutura ABB para armazenar a profundidade do nó. Escreva uma
        //função ABB_CalcularProfundidades que atribua as profundidades de todos os nós.
        calcularProfundidadeNo(raiz, 0);
    }

    int comprimentoInterno() {
        //exercicio 1.f
        //O comprimento interno de uma árvore binária é a soma das profundidades dos seus nós, ou seja, a soma de
        //todos os caminhos que levam da raíz até um nó. Escreva um método ABB_ComprimentoInterno que retorne
        //o comprimento interno de uma árvore binária.
        return comprimentoInternoNo(raiz) - 1;
    }

    int comprimentoInternoAnsioso() {
        return ci;
    }

    void ordenar(int* v, int n) {
        for (int i = 0; i < n; i++) {
            inserir(v[i], 0);
        }

        NoABB<C, V>* aux = nullptr;
        for (int i = 0; i < n; i++) {
            aux = buscarNoMenor(raiz);
            v[i] = aux->chave;
            remover(aux->chave);
        }
    }
};

#endif