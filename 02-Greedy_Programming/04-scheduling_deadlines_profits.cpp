#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,int>> jobs = { {2, 100}, {1, 19}, {2, 27}, {1, 25}, {3, 15} };

    sort(jobs.begin(), jobs.end(), 
        [](pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        }
    );

    auto max_deadline = max_element(jobs.begin(), jobs.end(), 
        [](pair<int,int> a, pair<int,int> b) {
            return a.first < b.first;
        }
    );

    vector<pair<int,int>> agenda((*max_deadline).first,{-1,-1});
    int total_profit = 0;

    for(pair<int,int> job: jobs) {
        int deadline = job.first;
        for(int i = deadline-1; i >= 0; i--) {
            if( agenda[i].first == -1 ) {
                agenda[i] = job;
                total_profit += job.second;
                break;
            }
        }
    }

    cout << "La ganancia máxima es: " << total_profit << "\n";
    cout << "La agenda es:\n";
    for(pair<int,int> job: agenda) {
        cout << job.first << " - " << job.second << "\n";
    }

    return 0;
}
