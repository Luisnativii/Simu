#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int LCS_aux(int n1, int n2, string S1, string S2, mat& dp) {
    if( n1 == 0 || n2 == 0 ) return 0;
    if( dp[n1][n2] != -1 ) return dp[n1][n2];

    if( S1[n1-1] == S2[n2-1] )
        dp[n1][n2] = 1 + LCS_aux(n1-1, n2-1, S1, S2, dp);
    else
        dp[n1][n2] = max(LCS_aux(n1, n2-1, S1, S2, dp), LCS_aux(n1-1, n2, S1, S2, dp));

    return dp[n1][n2];
}

int LCS(int n1, int n2, string S1, string S2) {
    mat dp(n1+1, vec(n2+1, -1));

    return LCS_aux(n1, n2, S1, S2, dp);
}

int main() {
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";

    cout << "La longitud de la LCS es: " << LCS(S1.size(), S2.size(), S1, S2) << "\n";

    return 0;
}