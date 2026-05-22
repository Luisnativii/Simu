#include <bits/stdc++.h>
using namespace std;

int main() {
    int k = 3;
    vector<int> queries = { 1, 2, 3, 2, 4, 1, 5, 2, 1, 2, 3, 4 };

    vector<int> cache;

    int cont = 0;
    for(int q = 0; q < k; q++) {
        cont++;
        cache.push_back(queries[q]);
    }
    for(int q = k; q < queries.size(); q++) {
        if( find(cache.begin(), cache.end(), queries[q]) != cache.end() ) continue;
        else {
            cont++;
            vector<int> positions;
            for(int c: cache) {
                int max_pos = -1;
                for(int i = q+1; i < queries.size(); i++) {
                    if( queries[i] == c ) max_pos = i;
                }
                positions.push_back(max_pos);
            }
            int pos = -1;
            int max = INT_MIN;
            for(int i = 0; i < positions.size(); i++) {
                if( positions[i] > max ) pos = i;
            }
            if( pos == -1 ) pos = 0;
            cache[pos] = queries[q];
        }
    }

    cout << "La cantidad mínima de page faults es (contando desde que la caché estaba vacía): " << cont << "\n";

    return 0;
}
