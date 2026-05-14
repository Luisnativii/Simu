#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<ll> memo(64+1,-1);

ll factorial_memo(int n) {
    if( memo[n] != -1 ) return memo[n];
    memo[n] = n * factorial_memo(n-1);
    return memo[n];
}

int main() {
    int n = 0;

    memo[0] = 1;
    memo[1] = 1;

    cout << "¿De qué numero quieres el factorial?(-1 para salir)\n";
    cin >> n;
    while(n != -1) {
        auto start = chrono::high_resolution_clock::now();
        cout << "El factorial de " << n << " es: " << factorial_memo(n) << "\n";
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> tiempo = end - start;
        cout << "Duración del proceso: " << tiempo.count() << "s\n\n";

        cout << "¿De qué numero quieres el factorial?(-1 para salir)\n";
        cin >> n;
    }

    cout << "Bye!\n";

    return 0;
}