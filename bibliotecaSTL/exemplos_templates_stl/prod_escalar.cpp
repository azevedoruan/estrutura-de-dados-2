#include <iostream>

template <typename T>
T prod_escalar(T* arr1, T* arr2, size_t n) {
    T soma = 0;
    for (size_t i = 0; i < n; ++i) {
        soma += arr1[i] * arr2[i];
    }
    return soma;
}

int main() {
    int intArray1[] = {1, 2, 3, 4, 5};
    int intArray2[] = {1, 2, 3, 4, 5};
    double doubleArray1[] = {3.14, 2.71, 1.618};
    double doubleArray2[] = {3.14, 2.71, 1.618};

    int prod_int = prod_escalar<int>(intArray1, intArray2, 5);

    double prod_double = prod_escalar<double>(doubleArray1, doubleArray2, 3);

    std::cout << "Produto escalar de intArray1 e intArray2: " << prod_int << std::endl;
    std::cout << "Produto escalar de doubleArray1 e doubleArray2: " << prod_double << std::endl;

    return 0;
}
