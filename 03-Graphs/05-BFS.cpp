#include "03-adj_list.hpp"

void BFS(Graph& g, Vertex* s) {
    vector<bool> explored(g.getN(), false);
    explored[s->getId()-1] = true;
    queue<Vertex*> Q;

    Q.push(s);
    while( !Q.empty() ) {
        Vertex* v = Q.front();
        Q.pop();
        for(Vertex* w: v->getEdges()) {
            if( !explored[w->getId()-1] ) {
                explored[w->getId()-1] = true;
                Q.push(w);
            }
        }
    }

    cout << "List of reachable vertices:\n";
    for( Vertex* v: g.getVertices() ) {
        if( explored[v->getId()-1] )
            cout << v->getName() << "\n";
    }
    cout << "\n";
}

int main() {
    Vertex v1(1, "s");
    Vertex v2(2, "a");
    Vertex v3(3, "b");
    Vertex v4(4, "c");
    Vertex v5(5, "d");
    Vertex v6(6, "e");

    v1.addEdge(&v2); v1.addEdge(&v3);
    v2.addEdge(&v1); v2.addEdge(&v4);
    v3.addEdge(&v1); v3.addEdge(&v4); v3.addEdge(&v5);
    v4.addEdge(&v2); v4.addEdge(&v3); v4.addEdge(&v5); v4.addEdge(&v6);
    v5.addEdge(&v3); v5.addEdge(&v4); v5.addEdge(&v6);
    v6.addEdge(&v4); v6.addEdge(&v5);

    Graph g;

    g.addVertex(&v1);
    g.addVertex(&v2);
    g.addVertex(&v3);
    g.addVertex(&v4);
    g.addVertex(&v5);
    g.addVertex(&v6);

    g.showGraph();

    BFS(g, &v1);

    // Add an unreachable vertex
    Vertex v7(7, "f");
    g.addVertex(&v7);

    BFS(g, &v1);

    return 0;
}
