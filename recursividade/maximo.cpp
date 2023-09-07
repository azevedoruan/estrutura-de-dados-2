#include <iostream>

using namespace std;

int maximo(int n, int v[]) {
    int x;
    if (n == 1)
        x = v[0];
    else {
        x = maximo (n-1, v); 
        if (x < v[n-1])
            x = v[n-1];
    }
    return x;
}

int main() {

    int vet[] = {2, 4, 3, 1, 10, 8};
    int result = maximo(6, vet);
    cout << "resultado: " << result << endl;

    return 0;
}