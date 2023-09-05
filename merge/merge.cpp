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

    delete[] e;
    delete[] d;
}