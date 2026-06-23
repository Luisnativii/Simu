#include "03-adj_list.hpp"

void DFS_Topo(Graph& g, Vertex* s, vector<bool>& explored, int& currentLabel, vector<int>& f) {
    explored[s->getId()-1] = true;
    for(Vertex* v: s->getEdges())
        if( !explored[v->getId()-1] )
            DFS_Topo(g, v, explored, currentLabel, f);
    f[s->getId()-1] = currentLabel;
    currentLabel--;
}

void TopoSort(Graph& g) {
    vector<int> f(g.getN());
    int currentLabel = g.getN();

    vector<bool> explored(g.getN(), false);
    for( Vertex* i: g.getVertices() ) {
        if( !explored[i->getId()-1] ) {
            DFS_Topo(g, i, explored, currentLabel, f);
        }
    }

    cout << "Order assigned to each vertex:\n";
    for(int i = 0; i < f.size(); i++)
        cout << "Vertex " << i+1 << ": " << f[i] << "\n";
    cout << "\n";
}

int main() {
    Vertex v1(1, "1");
    Vertex v2(2, "2");
    Vertex v3(3, "3");
    Vertex v4(4, "4");
    Vertex v5(5, "5");
    Vertex v6(6, "6");
    Vertex v7(7, "7");

    v1.addEdge(&v2); v1.addEdge(&v3);
    v2.addEdge(&v3); v2.addEdge(&v6);
    v3.addEdge(&v4);
    v6.addEdge(&v4); v6.addEdge(&v5);
    v7.addEdge(&v2); v7.addEdge(&v6);

    Graph g;

    g.addVertex(&v1);
    g.addVertex(&v2);
    g.addVertex(&v3);
    g.addVertex(&v4);
    g.addVertex(&v5);
    g.addVertex(&v6);
    g.addVertex(&v7);

    g.showGraph();

    TopoSort(g);

    return 0;
}
