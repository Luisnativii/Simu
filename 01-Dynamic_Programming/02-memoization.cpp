#include <bits/stdc++.h>
using namespace std;

long fibonacci(int pos) {
    if( pos == 0 ) return 0;
    if( pos == 1 ) return 1;
    return fibonacci(pos - 1) + fibonacci(pos - 2);
}

/*************************************/

long fibonacci_memo_aux(int pos, vector<long>& memo) {
    if( memo[pos] != -1 ) return memo[pos];
    memo[pos] = fibonacci_memo_aux(pos-1, memo) + fibonacci_memo_aux(pos-2, memo);
    return memo[pos];
}

long fibonacci_memo(int pos) {
    if( pos == 0 ) return 0;
    if( pos == 1 ) return 1;

    vector<long> memo(pos+1,-1);
    memo[0] = 0;
    memo[1] = 1;

    return fibonacci_memo_aux(pos, memo);
}

/*************************************/
int main(int argc, char* argv[]) {
    int pos = atoi(argv[1]);
    int mode = atoi(argv[2]);

    auto start = chrono::high_resolution_clock::now();
    if( mode == 0)
        cout << "La posición " << pos << " es: " << fibonacci(pos) << "\n";
    else
        cout << "La posición " << pos << " es: " << fibonacci_memo(pos) << "\n";
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> tiempo = end - start;
    cout << "Duración del proceso: " << tiempo.count() << "s\n";

    return 0;
}