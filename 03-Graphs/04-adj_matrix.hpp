#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int num_vert;
    vector<vector<int>> A;

public:
    Graph(int n): num_vert(n) {
        A.resize(num_vert, vector<int>(num_vert,0));
    }

    int getNumVert() {
        return num_vert;
    }

    void addVertex(int i, int j) {
        A[i-1][j-1] = 1;
    }

    void showGraph() {
        for(int i = 0; i < num_vert; i++) {
            for(int j = 0; j < num_vert; j++)
                cout<< A[i][j] << " ";
            cout << "\n";
        }
        cout << "\n\n";
    }
};
