#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,int>> jobs = { {86, 78}, {25, 26}, {88, 54}, {16, 45}, {24, 76} };

    sort(jobs.begin(), jobs.end(), 
        [](pair<int,int> a, pair<int,int> b) {
            return a.first < b.first;
        }
    );

    cout << "La agenda es:\n";
    for(pair<int,int> p: jobs) {
        cout << p.first << " - " << p.second << "\n";
    }

    return 0;
}
