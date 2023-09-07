#include <iostream>

using namespace std;

template<typename T>
T sum(T a, T b) {
    return (T)a + b;
}

int main() {

    cout << "resultado de soma de inteiros: " << sum(10, 5) << endl;
    cout << "resultado de soma de flutuantes: " << sum(10.5, 5.34) << endl;

    return 0;
}