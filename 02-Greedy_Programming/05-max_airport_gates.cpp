#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<float,float>> flights = { {9, 9.1}, {9.4, 12}, {9.5, 11.2}, {11, 11.3}, {15, 19}, {18, 20} };
    vector<pair<float,char>> times;

    for(pair<float,float> flight: flights) {
        times.push_back(make_pair(flight.first,'A'));
        times.push_back(make_pair(flight.second,'D'));
    }

    sort(times.begin(), times.end(), 
        [](pair<float,char> a, pair<float,char> b) {
            return a.first < b.first;
        }
    );

    int cont = 0;
    int max_cont = 0;
    for(pair<float,char> t: times) {
        if( t.second == 'A' ) cont++;
        else cont--;
        max_cont = max( max_cont, cont );
    }

    cout << "La cantidad mínima de gates necesaria es: " << max_cont << "\n";

    return 0;
}
