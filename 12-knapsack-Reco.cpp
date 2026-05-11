#include <bits/stdc++.h>
using namespace std;

#define mat(name, type, f, c, init) vector<vector<type>> name(f, vector<type>(c,init))

typedef vector<int> vec;

typedef struct{
    int V;
    string objects;
} Answer;

Answer Knapsack(vec& V, vec& W, int n, int C) {
    mat(dp, int, n+1, C+1, -1);
    mat(rec, string, n+1, C+1, "");

    for(int j = 0; j <= C; j++){
        dp[0][j] = 0;
        rec[0][j] = "";
    }
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
        rec[i][0] = "";
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= C; j++)
            if( W[i-1] <= j )
                if( V[i-1] + dp[i-1][j-W[i-1]] > dp[i-1][j] ){
                    dp[i][j] = V[i-1] + dp[i-1][j-W[i-1]];
                    rec[i][j] = to_string(i) + ", " + rec[i-1][j-W[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                    rec[i][j] = rec[i-1][j];
                }
            else {
                dp[i][j] = dp[i-1][j];
                rec[i][j] = rec[i-1][j];
            }

    Answer res;
    res.V = dp[n][C];
    res.objects = rec[n][C];

    return res;
}

int main() {
    vec V = {3,2,4,4};
    vec W = {4,3,2,3};
    int C = 6;

    Answer result = Knapsack(V, W, V.size(), C);

    cout << "El valor máximo es: " << result.V << "\n";
    cout << "Se utilizan los objetos: " << result.objects << "\n";

    return 0;
}