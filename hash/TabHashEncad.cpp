#include "TabHashEncad.h"
#include <iostream>

TabHashEncadeamento::TabHashEncadeamento(int tamanho)
{
    this->n = 0;
    this->m = tamanho;
    this->tabela = new std::vector<std::pair<int, int>>[m];
    this->invalido = std::make_pair(-1, -1);
}

TabHashEncadeamento::~TabHashEncadeamento()
{
    delete[] this->tabela;
}

int TabHashEncadeamento::hash(int chave)
{
    return chave % this->m;
}

void TabHashEncadeamento::inserir(int chave, int valor)
{
    auto &elemento = buscar(chave);
    if (elemento != this->invalido)
    {
        elemento.second = valor;
        return;
    }
    int hash = hash(cahve);

    this->tabela[h].push_back(std::make_pair(chave, valor));
}

std::pair<int, int>& TabHashEncadeamento::buscar(int chave)
{
    int h = hash(chave);
    for (auto& elemento : this->tabela[h]) {
        if (elemento.first == chave) {
            return elemento;
        }
    }

    return this->invalido;
}