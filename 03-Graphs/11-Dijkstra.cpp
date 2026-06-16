#include "11-adj_list_weighted.hpp"

// This is the Min-Heap version of the algorithm
// It is preferred because it is a lot better than the base version.

void Dijkstra(Graph& g, Vertex* s) {
    vector<int> len(g.getN(), INT_MAX);
    len[s->getId()-1] = 0;

    auto f = [](pair<int, Vertex*> a, pair<int, Vertex*> b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, Vertex*>, vector<pair<int, Vertex*>>, decltype(f)> H(f);
    H.push(make_pair(0, s));

    while( !H.empty() ) {
        pair<int, Vertex*> v = H.top();
        H.pop();

        if( v.first <= len[v.second->getId()-1] ){
            for( pair<Vertex*,int> w: v.second->getEdges() ) {
                int new_len = len[v.second->getId()-1] + w.second;

                if( new_len < len[w.first->getId()-1] ) {
                    len[w.first->getId()-1] = new_len;
                    H.push(make_pair(new_len, w.first));
                }
            }
        }
    }

    cout << "List of distances:\n";
    for( Vertex* v: g.getVertices() ) {
        cout << "Hasta vértice " << v->getId() << ": " << len[v->getId()-1] << "\n";
    }
    cout << "\n";
}

int main() {
    Vertex v1(1, "0");
    Vertex v2(2, "1");
    Vertex v3(3, "2");
    Vertex v4(4, "3");
    Vertex v5(5, "4");

    v1.addEdge(&v2, 4); v1.addEdge(&v3, 8);
    v2.addEdge(&v1, 4); v2.addEdge(&v3, 3); v2.addEdge(&v5, 6);
    v3.addEdge(&v1, 8); v3.addEdge(&v2, 3); v3.addEdge(&v4, 2);
    v4.addEdge(&v3, 2); v4.addEdge(&v5, 10);
    v5.addEdge(&v2, 6); v5.addEdge(&v4, 10);

    Graph g;

    g.addVertex(&v1);
    g.addVertex(&v2);
    g.addVertex(&v3);
    g.addVertex(&v4);
    g.addVertex(&v5);

    g.showGraph();

    Dijkstra(g, &v1);

    return 0;
}
