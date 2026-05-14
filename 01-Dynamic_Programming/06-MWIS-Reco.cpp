#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

vec MWIS(vec& W, int n) {
    vec A(n+1, -1);
    A[0] = 0;
    A[1] = W[0];

    for(int i = 2; i <= n; i++)
        A[i] = max(A[i-1], W[i-1] + A[i-2]);

    return A;
}

int main() {
    vec W = {3,2,1,6,4,5};

    vec memo = MWIS(W, 6);
    cout << "El Wmax es: " << memo[6] << "\n";

    vec S;
    int i = 6;
    while( i >= 2 ) {
        if(memo[i-1] >= W[i-1]+memo[i-2])
            i--;
        else {
            S.push_back(i);
            i -= 2;
        }
    }

    if( i == 1 )
        S.push_back(1);

    //reverse(S.begin(), S.end());
    cout << "[ ";
    for(int i: S)
        cout << i << " ";
    cout << "]\n";

    return 0;
}