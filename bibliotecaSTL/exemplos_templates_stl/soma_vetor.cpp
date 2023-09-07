#include <iostream>
template <typename T>
T soma_array(T* arr, size_t n) {
    T sum = 0;
    for (size_t i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {3.14, 2.71, 1.618};
    
    int sum_int = soma_array<int>(intArray, 5);
    //A chamada abaixo também funciona, o compilador determina
    //o parametro do template automaticamente
    //int sum_int = soma_array(intArray, 5);
    
    double sum_double = soma_array<double>(doubleArray, 3);
    //A chamada abaixo também funciona, o compilador determina
    //o parametro do template automaticamente
    //double sum_double = soma_array(doubleArray, 3);

    std::cout << "Soma de intArray: " << sum_int << std::endl;
    std::cout << "Soma de doubleArray: " << sum_double << std::endl;

    return 0;
}
