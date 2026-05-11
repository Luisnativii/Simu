#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int Knapsack_aux(vec& V, vec& W, int n, int C, mat& dp) {
    if( n == 0 || C == 0 ) return 0;
    if( dp[n][C] != -1 ) return dp[n][C];

    if( W[n-1] <= C )
        dp[n][C] = max ( Knapsack_aux(V, W, n-1, C, dp), V[n-1] + Knapsack_aux(V, W, n-1, C-W[n-1], dp) );
    else
        dp[n][C] = Knapsack_aux(V, W, n-1, C, dp);

    return dp[n][C];
}

int Knapsack(vec& V, vec& W, int n, int C) {
    mat dp(n+1, vec(C+1, -1));

    return Knapsack_aux(V, W, n, C, dp);
}

int main() {
    vec V = {3,2,4,4};
    vec W = {4,3,2,3};
    int C = 6;

    cout << "El valor máximo es: " << Knapsack(V, W, V.size(), C) << "\n";

    return 0;
}