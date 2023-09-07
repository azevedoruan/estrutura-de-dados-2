#include <iostream>

template<typename T>
void troca(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 1;
    int b = 2;
    std::cout << "a: " << a << " b: " << b << std::endl;
    troca(a,b);
    std::cout << "a: " << a << " b: " << b << std::endl;

    float c = 1.5;
    float d = 2.5;
    std::cout << "c: " << c << " d: " << d << std::endl;
    troca(c,d);
    std::cout << "c: " << c << " d: " << d << std::endl;

    return 0;
}
