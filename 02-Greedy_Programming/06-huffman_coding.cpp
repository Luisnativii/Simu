#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> files = { 22, 77, 35, 57, 28, 76, 29 };

    int total_cost = 0;
    while(files.size() > 1) {
        sort(files.begin(), files.end());
        int first = files[0];
        files.pop_front();
        int second = files[0];
        files.pop_front();
        total_cost += first + second;
        files.push_back(first + second);
    }

    cout << "El costo mínimo para fusionar los archivos es: " << total_cost << "\n";

    return 0;
}
