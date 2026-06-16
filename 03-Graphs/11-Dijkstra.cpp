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
        pair<int, Vertex*> p = H.top();
        H.pop();

        if( p.first <= len[p.second->getId()-1] ){
            for( pair<Vertex*,int> w: p.second->getEdges() ) {
                int new_len = len[p.second->getId()-1] + w.second;
                
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
    Vertex v1(1, "s");
    Vertex v2(2, "v");
    Vertex v3(3, "w");
    Vertex v4(4, "t");

    v1.addEdge(&v2, 1); v1.addEdge(&v3, 4);
    v2.addEdge(&v3, 2); v2.addEdge(&v4, 6);
    v3.addEdge(&v4, 3);

    Graph g;

    g.addVertex(&v1);
    g.addVertex(&v2);
    g.addVertex(&v3);
    g.addVertex(&v4);

    g.showGraph();

    Dijkstra(g, &v1);

    return 0;
}
