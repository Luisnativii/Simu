#include <bits/stdc++.h>
using namespace std;

/*
    Para compilar y ejecutar:
        g++ -o run 19-UVA11450-Wedding_Shopping.cpp
        cat 19-input.txt | ./run
*/
int main() {
    int N;
    cin >> N;
    for(int tc = 1; tc <= N; tc++) {
        int M,C;
        cin >> M >> C;
        vector<int> K;
        vector<vector<int>> p;
        for(int i = 1; i <= C; i++) {
            int K_i;
            cin >> K_i;
            vector<int> p_ik;
            for(int k = 1; k <= K_i; k++) {
                int temp;
                cin >> temp;
                p_ik.push_back(temp);
            }
            K.push_back(K_i);
            p.push_back(p_ik);
        }

        /*
        cout << M << " " << C << "\n";
        for(int k: K) cout << k << " ";
        cout << "\n";
        for(int i = 0; i < C; i++)
            for(int j = 0; j < p[i].size(); j++)
                cout << p[i][j] << " ";
        cout << "\n";
        */

        vector<vector<int>> dp(C+1, vector<int>(M+1,-2));
        for(int i = 0; i <= C; i++) dp[i][0] = -1;
        for(int j = 0; j <= M; j++) dp[0][j] = 0;

        for(int i = 1; i <= C; i++)
            for(int j = 1; j <= M; j++) {
                dp[i][j] = -1;
                for(int k = 0; k < K[i-1]; k++)
                    if( p[i-1][k] <= j && dp[i - 1][j - p[i-1][k]] != -1 )
                        dp[i][j] = max( dp[i][j] , p[i-1][k] + dp[i - 1][j - p[i-1][k]] );
            }
        
        if( dp[C][M] == -1 )
            cout << "no solution\n";
        else
            cout << dp[C][M] << "\n";
    }

    return 0;
}