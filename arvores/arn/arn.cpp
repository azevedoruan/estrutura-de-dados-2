#include "arn.h"

template <typename tC, typename tV>
bool inline ARN<tC, tV>::ehVermelho(NoARN<tC, tV>* no) {
    if (no == nullptr)
       return false;
    
    return no->cor == ARN<tC, tV>::Cor::VERMELHO ? true : false;
}

template <typename tC, typename tV>
void ARN<tC, tV>::inserir(tC chave, tV valor) {
    ARN<tC, tV>::inserirNo(raiz, chave, valor);
}

template <typename tC, typename tV>
NoARN<tC, tV>* ARN<tC, tV>::inserirNo(NoARN<tC, tV>* no, tC chave, tV valor) {
    if (no == nullptr)
        return new NoARN<tC, tV>(chave, valor);

    if (chave < no->getChave())
        no->esq = inserirNo(no->esq, chave, valor);
    else if (chave > no->getChave())
        no->dir = inserirNo(no->dir, chave, valor);
    else
        no->valor = valor;

    if (ehVermelho(no->dir) && !ehVermelho(no->esq))
        rotEsq(no);
    
    if (ehVermelho(no->esq) && ehVermelho(no->esq->esq))
        rotDir(no);

    if (ehVermelho(no->esq) && ehVermelho(no->dir))
        invCor(no);
}