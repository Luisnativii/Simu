#include <bits/stdc++.h>
using namespace std;

#define mat(name, type, f, c, init) vector<vector<type>> name(f, vector<type>(c,init))

typedef vector<int> vec;

typedef struct{
    int R;
    string LCS;
} Answer;

Answer LCS(int n1, int n2, string S1, string S2) {
    mat(dp, int, n1+1, n2+1, -1);
    mat(rec, string, n1+1, n2+1, "");

    for(int j = 0; j <= n2; j++) {
        dp[0][j] = 0;
        rec[0][j] = "";
    }
    for(int i = 0; i <= n1; i++) {
        dp[i][0] = 0;
        rec[i][0] = "";
    }

    for(int i = 1; i <= n1; i++)
        for(int j = 1; j <= n2; j++)
            if( S1[i-1] == S2[j-1] ) {
                dp[i][j] = 1 + dp[i-1][j-1];
                rec[i][j] = rec[i-1][j-1]+S1[i-1];
            }
            else
                if(dp[i][j-1] > dp[i-1][j]) {
                    dp[i][j] = dp[i][j-1];
                    rec[i][j] = rec[i][j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                    rec[i][j] = rec[i-1][j];
                }
    
    Answer res;
    res.R = dp[n1][n2];
    res.LCS = rec[n1][n2]; 

    return res;
}

int main() {
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";

    Answer result = LCS(S1.size(), S2.size(), S1, S2);

    cout << "La longitud de la LCS es: " << result.R << "\n";
    cout << "La LCS es: " << result.LCS << "\n";

    return 0;
}