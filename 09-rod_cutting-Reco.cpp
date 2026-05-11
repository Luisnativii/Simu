#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

typedef struct{
    int R;
    string pieces;
} Answer;

Answer Rod_Cutting(vec& P, int n) {
    vec R(n+1, -1);
    string S[n+1];
    R[0] = 0;
    S[0] = "";

    for(int i = 1; i <= n; i++){
        int q = INT_MIN;
        string ss = "";
        for(int j = 1; j <= i; j++)
            if( P[j-1] + R[i-j] > q ) {
                q = P[j-1] + R[i-j];
                
                ss = to_string(j) + "-" + to_string(i-j);
            }
        R[i] = q;
        S[i] = ss;
    }

    Answer A;
    A.R = R[n];
    A.pieces = S[n];
    return A;
}

int main() {
    vec P = {1,5,8,9,10,17,17,20,24,30};

    int rod = 4;
    Answer result = Rod_Cutting(P, rod);
    cout << "La ganancia máxima es: " << result.R << "\n";
    cout << "Generado por piezas de longitud: " << result.pieces << "\n";

    rod = 7;
    result = Rod_Cutting(P, rod);
    cout << "La ganancia máxima es: " << result.R << "\n";
    cout << "Generado por piezas de longitud: " << result.pieces << "\n";

    return 0;
}