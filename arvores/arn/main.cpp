#include <iostream>
#include "arn.h"

using namespace std;

int main(int argc, char* argv[]) {

    NoARN<int, int>* no = new NoARN<int, int>(10, -56);
    ARN<int, int> arn;

    cout << "chave do no: " << no->getChave() << "\n" << "valor do no: " << no->getValor() << endl;
    cout << "no e vermelho? " << arn.ehVermelho(no) << endl;


    return 0;
}