#include <iostream>
using namespace std;

int fibonacci_posposicion(int pos) {
    if( pos == 0 ) return 0;
    if( pos == 1 ) return 1;
    return fibonacci_posposicion(pos - 1) + fibonacci_posposicion(pos - 2);
}

/*************************************/

int fibonacci_aux(int pos, int a, int b) {
    if( pos == 0 ) return b;
    return fibonacci_aux(pos-1, b, a+b);
}

 int fibonacci_cola(int pos) {
    if( pos == 0 ) return 0;
    if( pos == 1 ) return 1;
    return fibonacci_aux(pos-2, 1, 1);
}

/*************************************/

int factorial_posposicion(int n) {
    if( n == 0 || n == 1 ) return 1;
    return n * factorial_posposicion(n-1);
}

/*************************************/

int factorial_aux(int n, int f) {
    if( n == 1) return f;
    return factorial_aux(n-1, f*n);
}

int factorial_cola(int n) {
    if( n == 0 || n == 1 ) return 1;
    return factorial_aux(n-1, n);
}

/*************************************/
/*************************************/
int main() {
    for(int i = 0; i <= 10; i++)
        cout << factorial_cola(i) << "\n";

    return 0;
}