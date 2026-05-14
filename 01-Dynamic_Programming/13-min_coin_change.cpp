#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int MinCoinChange(vec& V, int n, int M) {
    mat dp(n+1, vec(M+1, -1));

    for(int j = 0; j <= M; j++) dp[0][j] = INT_MAX;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= M; j++)
            if( V[i-1] <= j )
                dp[i][j] = min( dp[i-1][j], 1 + dp[i][j-V[i-1]]) ;
            else
                dp[i][j] = dp[i-1][j];

    return dp[n][M];
}

int main() {
    vec V = {1,5,6,9};
    int M = 19;

    cout << "La cantidad mínima de monedas es: " << MinCoinChange(V, V.size(), M) << "\n";

    return 0;
}