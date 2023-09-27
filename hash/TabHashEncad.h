#include <iostream>
#include <utility>

class TabHashEncadeamento {
public:
    TabHashEncadeamento(int tamanho);
    ~TabHashEncadeamento();
    void inserir(int chave, int valor);
    void remover(int chave);
    std::pair<int, int>& buscar(int chave);
    void imprimir();
    std::pair<int, int> invalido;

private:
    int m; // tamanho da tabela
    int n; // numero de pares chave-valor inseridos

    std::vector<std::pair<int, int>> *tabela;
    int hash(int chave);
};
