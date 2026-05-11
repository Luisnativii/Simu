#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int Rod_Cutting_aux(vec& P, int n, vec& R) {
    if( n == 0 ) return 0;
    if( R[n] != -1 ) return R[n];

    int q = INT_MIN;
    for(int j = 1; j <= n; j++)
        q = max(q, P[j-1] + Rod_Cutting_aux(P, n-j, R));
    R[n] = q;

    return R[n];
}

int Rod_Cutting(vec& P, int n) {
    vec R(n+1, -1);

    return Rod_Cutting_aux(P, n, R);
}

int main() {
    vec P = {1,5,8,9,10,17,17,20,24,30};
    
    int rod = 4;
    cout << "La ganancia máxima es: " << Rod_Cutting(P, rod) << "\n";

    rod = 7;
    cout << "La ganancia máxima es: " << Rod_Cutting(P, rod) << "\n";

    return 0;
}