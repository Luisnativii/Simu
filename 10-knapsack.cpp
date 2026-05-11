#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int Knapsack(vec& V, vec& W, int n, int C) {
    mat dp(n+1, vec(C+1, -1));

    for(int j = 0; j <= C; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= C; j++)
            if( W[i-1] <= j )
                dp[i][j] = max( dp[i-1][j], V[i-1] + dp[i-1][j-W[i-1]]) ;
            else
                dp[i][j] = dp[i-1][j];

    return dp[n][C];
}

int main() {
    vec V = {3,2,4,4};
    vec W = {4,3,2,3};
    int C = 6;

    cout << "El valor máximo es: " << Knapsack(V, W, V.size(), C) << "\n";

    return 0;
}