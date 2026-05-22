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

    gas_stations.push_back(make_pair(T, -1));

    int total_stops = 0;
    int total_distance = 0;
    for(int i = 0; i < gas_stations.size(); i++) {
        if( F >= T ) break;
        if( F >= gas_stations[i].first && F < gas_stations[i+1].first ) {
            F += gas_stations[i].second;
            total_stops++;
        }
        else continue;
    }

    cout << "La cantidad mínima de paradas en el viaje es: " << total_stops << "\n";

    return 0;
}
