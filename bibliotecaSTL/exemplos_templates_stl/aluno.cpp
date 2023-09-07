#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Aluno {
public:
    Aluno(string nome, int idade) : nome(nome), ra(idade) {}
    //sobrecarga do operador ==
    bool operator==(const Aluno& outro) {
        return this->ra == outro.ra;
    }
    //sobrecarga do operador <
    bool operator<(const Aluno& outro) {
        return this->ra < outro.ra;
    }
    void imprimir(){
        cout << "Nome: " << nome << ", RA: " << ra << endl;
    }

private:
    string nome;
    int ra;
};

void comparar_alunos () {
    Aluno a1("João", 2013952);
    Aluno a2("Maria", 1992365);
    Aluno a3("João", 2013952);

    if(a1 == a2){
        cout << "a1 e a2 são iguais" << endl;
    } else {
        cout << "a1 e a2 são diferentes" << endl; //imprime
    }

    if(a1 == a3){
        cout << "a1 e a3 são iguais" << endl; //imprime
    } else {
        cout << "a1 e a3 são diferentes" << endl;
    }
}

void teste_busca(){
    vector<Aluno> alunos;
    alunos.push_back(Aluno("João" , 2032548));
    alunos.push_back(Aluno("Maria" , 2038894));
    alunos.push_back(Aluno("Pedro" , 1922659));
    alunos.push_back(Aluno("João" , 1900136));
    alunos.push_back(Aluno("José" , 1898856));
    alunos.push_back(Aluno("Amanda" , 2199432));
    alunos.push_back(Aluno("Vanessa", 1788965));

    //find (busca sequencial) é uma função da biblioteca algorithm, necessita
    //que o operador == esteja sobrecarregado

    auto aluno = find(alunos.begin(), alunos.end(), Aluno("Vanessa", 1788965));
    if(aluno != alunos.end()){
        aluno->imprimir();
    } else {
        cout << "Aluno não encontrado" << endl;
    }
}

void teste_ordenacao(){
    vector<Aluno> alunos;

    alunos.push_back(Aluno("João"   , 2032548));
    alunos.push_back(Aluno("Maria"  , 2038894));
    alunos.push_back(Aluno("Pedro"  , 1922659));
    alunos.push_back(Aluno("João"   , 1900136));
    alunos.push_back(Aluno("José"   , 1898856));
    alunos.push_back(Aluno("Amanda" , 2199432));
    alunos.push_back(Aluno("Vanessa", 1788965));
    //sort é uma função da biblioteca algorithm, necessita
    //que o operador < esteja sobrecarregado
    sort(alunos.begin(), alunos.end());

    for(auto aluno : alunos){
        aluno.imprimir();
    }
}

int main(){
    //teste_busca();
    teste_ordenacao();
    return 0;
}
