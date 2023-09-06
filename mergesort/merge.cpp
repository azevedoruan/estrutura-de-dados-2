#include <iostream>

void merge(int *v, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int *e = new int[n1];
    int *d = new int[n2];

    for (int i = 0; i < n1; i++) {
        e[i] = v[p+i];
    }

    for (int i = 0; i < n2; i++) {
        d[i] = v[(q+1)+i];
    }

    int k = p;
    int i = 0;
    int j = 0;

    while((i < n1) && (j < n2)) {

        if (e[i] <= d[j]) {
            v[k] = e[i];
            i++;
        }
        else {
            v[k] = d[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        v[k] = e[i];
        i++;
        k++;
    }

    while(j < n2) {
        v[k] = d[j];
        j++;
        k++;
    }

    delete[] e;
    delete[] d;
}

int main() {

    int v[] = {3, 5, 6, 0, 4, 7};
    merge(v, 0, 2, 5);
    
    for(int i = 0; i < 6; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}