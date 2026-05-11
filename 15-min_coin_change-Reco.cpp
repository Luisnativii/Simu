#include <bits/stdc++.h>
using namespace std;

#define mat(name, type, f, c, init) vector<vector<type>> name(f, vector<type>(c,init))

typedef vector<int> vec;

typedef struct{
    int R;
    string coins;
} Answer;

Answer MinCoinChange(vec& V, int n, int M) {
    mat(dp, int, n+1, M+1, -1);
    mat(rec, string, n+1, M+1, "");

    for(int j = 0; j <= M; j++) {
        dp[0][j] = INT_MAX;
        rec[0][j] = "";
    }
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
        rec[i][0] = "";
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= M; j++)
            if( V[i-1] <= j )
                if( 1 + dp[i][j-V[i-1]] < dp[i-1][j] ) {
                    dp[i][j] = 1 + dp[i][j-V[i-1]];
                    rec[i][j] = to_string(V[i-1]) + ", " + rec[i][j-V[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                    rec[i][j] = rec[i-1][j];
                }
            else{
                dp[i][j] = dp[i-1][j];
                rec[i][j] = rec[i-1][j];
            }
    
    Answer res;
    res.R = dp[n][M];
    res.coins = rec[n][M] ;

    return res;
}

int main() {
    vec V = {1,5,6,9};
    int M = 19;

    Answer result = MinCoinChange(V, V.size(), M);

    cout << "La cantidad mínima de monedas es: " << result.R << "\n";
    cout << "La combinación de monedas es: " << result.coins << "\n";

    return 0;
}