#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int Rod_Cutting(vec& P, int n) {
    vec R(n+1, -1);
    R[0] = 0;

    for(int i = 1; i <= n; i++){
        int q = INT_MIN;
        for(int j = 1; j <= i; j++)
            q = max(q, P[j-1] + R[i-j]);
        R[i] = q;
    }

    return R[n];
}

int main() {
    vec P = {1,5,8,9,10,17,17,20,24,30};
    
    int rod = 4;
    cout << "La ganancia máxima es: " << Rod_Cutting(P, rod) << "\n";

    rod = 7;
    cout << "La ganancia máxima es: " << Rod_Cutting(P, rod) << "\n";

    return 0;
}