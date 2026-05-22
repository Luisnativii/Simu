#include <bits/stdc++.h>
using namespace std;

int main() {
    int T = 100;
    int F = 10;
    vector<pair<int,int>> gas_stations = { {10, 60}, {20, 30}, {30, 30}, {60, 40} };

    sort(gas_stations.begin(), gas_stations.end(), 
        [](pair<int,int> a, pair<int,int> b) {
            return a.first < b.first;
        }
    );

    int total_stops = 0;
    int stop = 0;
    while ( F < T &&  ) {

    }

    return 0;
}
