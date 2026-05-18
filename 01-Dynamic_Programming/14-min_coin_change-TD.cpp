#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int MinCoinChange_aux(vec& V, int n, int M, mat& dp) {
    if( n == 0 ) return INT_MAX;
    if( M == 0 ) return 0;
    if( dp[n][M] != -1) return dp[n][M];

    if( V[n-1] <= M )
        dp[n][M] = min( MinCoinChange_aux(V, n-1, M, dp), 1 + MinCoinChange_aux(V, n, M-V[n-1], dp) );
    else
        dp[n][M] = MinCoinChange_aux(V, n-1, M, dp);

    return dp[n][M];
}

int MinCoinChange(vec& V, int n, int M) {
    mat dp(n+1, vec(M+1, -1));

    return MinCoinChange_aux(V, n, M, dp);
}

int main() {
    vec V = {1,5,6,9};
    int M = 19;

    cout << "La cantidad mínima de monedas es: " << MinCoinChange(V, V.size(), M) << "\n";

    return 0;
}