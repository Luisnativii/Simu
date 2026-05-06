#include <bits/stdc++.h>
using namespace std;
/*
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

        cout << M << " " << C << "\n";
        for(int k: K) cout << k << " ";
        cout << "\n";
        for(int i = 0; i < C; i++)
            for(int j = 0; j < p[i].size(); j++)
                cout << p[i][j] << " ";
        cout << "\n";
    }

    return 0;
}