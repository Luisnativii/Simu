#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int MWIS_aux(vec& W, int n, vec& A) {
    if( n == 0 ) return 0;
    if( n == 1 ) return W[0];
    if( A[n] != -1) return A[n];

    A[n] = max( MWIS_aux(W, n-1, A), W[n-1] + MWIS_aux(W, n-2, A) );

    return A[n];
}

int MWIS(vec& W, int n) {
    vec A(n+1, -1);

    return MWIS_aux(W, n, A);
}

int main() {
    vec W = {3,2,1,6,4,5};

    cout << "El Wmax es: " << MWIS(W, 6) << "\n";

    return 0;
}