#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int LCS(int n1, int n2, string S1, string S2) {
    mat dp(n1+1, vec(n2+1, -1));

    for(int j = 0; j <= n2; j++) dp[0][j] = 0;
    for(int i = 0; i <= n1; i++) dp[i][0] = 0;

    for(int i = 1; i <= n1; i++)
        for(int j = 1; j <= n2; j++)
            if( S1[i-1] == S2[j-1] )
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

    return dp[n1][n2];
}

int main() {
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";

    cout << "La longitud de la LCS es: " << LCS(S1.size(), S2.size(), S1, S2) << "\n";

    return 0;
}