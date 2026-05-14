#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int MWIS(vec& W, int n) {
    vec A(n+1, -1);
    A[0] = 0;
    A[1] = W[0];

    for(int i = 2; i <= n; i++)
        A[i] = max(A[i-1], W[i-1] + A[i-2]);

    return A[n];
}

int main() {
    vec W = {3,2,1,6,4,5};

    cout << "El Wmax es: " << MWIS(W, 6) << "\n";

    return 0;
}