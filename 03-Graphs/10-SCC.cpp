#include "10-adj_list_v2.hpp"

void DFS_Topo_SCC(Graph& g, Vertex* s, vector<bool>& explored, int& currentLabel, vector<int>& f) {
    explored[s->getId()-1] = true;
    for(Vertex* v: s->getIncomingEdges())
        if( !explored[v->getId()-1] )
            DFS_Topo_SCC(g, v, explored, currentLabel, f);
    f[s->getId()-1] = currentLabel;
    currentLabel--;
}

void TopoSort_SCC(Graph& g, vector<int>& f) {
    int currentLabel = g.getN();

    vector<bool> explored(g.getN(), false);
    for( Vertex* i: g.getVertices() ) {
        if( !explored[i->getId()-1] ) {
            DFS_Topo_SCC(g, i, explored, currentLabel, f);
        }
    }
}

void DFS_SCC(Graph& g, Vertex* s, vector<bool>& explored, vector<int>& scc, int numSCC) {
    explored[s->getId()-1] = true;
    scc[s->getId()-1] = numSCC;
    for(Vertex* v: s->getOutgoingEdges())
        if( !explored[v->getId()-1] )
            DFS_SCC(g, v, explored, scc, numSCC);
}

void SCC(Graph& g) {
    int numSCC = 0;
    vector<int> scc(g.getN());

    vector<bool> explored(g.getN(), false);
    vector<int> f(g.getN());
    TopoSort_SCC(g, f);

    explored.assign(g.getN(), false);
    for(int i = 0; i < f.size(); i++) {
        auto it = find(f.begin(), f.end(), i+1);
        Vertex* v = g.getVertices()[ distance(f.begin(), it) ];
        if( !explored[v->getId()-1] ) {
            numSCC++;
            DFS_SCC(g, v, explored, scc, numSCC);
        }
    }

    cout << "List of Strongly Connected Components:\n";
    for( int c = 1; c <= numSCC; c++ ) {
        cout << "Strongly Connected Component #" << c << ": ";
        for(int i = 0; i < g.getN(); i++)
            if( scc[i] == c ) cout << i+1 << " ";
        cout << "\n";
    }
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
    Vertex v8(8, "8");
    Vertex v9(9, "9");
    Vertex v10(10, "10");
    Vertex v11(11, "11");

    v1.addIncomingEdge(&v5);
    v1.addOutgoingEdge(&v3);
    v2.addIncomingEdge(&v9);
    v2.addOutgoingEdge(&v4); v2.addOutgoingEdge(&v10);
    v3.addIncomingEdge(&v1);
    v3.addOutgoingEdge(&v5); v3.addOutgoingEdge(&v11);
    v4.addIncomingEdge(&v2); v4.addIncomingEdge(&v9);
    v4.addOutgoingEdge(&v7);
    v5.addIncomingEdge(&v3);
    v5.addOutgoingEdge(&v1); v5.addOutgoingEdge(&v7); v5.addOutgoingEdge(&v9);
    v6.addIncomingEdge(&v8); v6.addIncomingEdge(&v11);
    v6.addOutgoingEdge(&v10);
    v7.addIncomingEdge(&v4); v7.addIncomingEdge(&v5);
    v7.addOutgoingEdge(&v9);
    v8.addIncomingEdge(&v9); v8.addIncomingEdge(&v10); v8.addIncomingEdge(&v11);
    v8.addOutgoingEdge(&v6);
    v9.addIncomingEdge(&v5); v9.addIncomingEdge(&v7);
    v9.addOutgoingEdge(&v2); v9.addOutgoingEdge(&v4); v9.addOutgoingEdge(&v8);
    v10.addIncomingEdge(&v2); v10.addIncomingEdge(&v6);
    v10.addOutgoingEdge(&v8);
    v11.addIncomingEdge(&v3);
    v11.addOutgoingEdge(&v6); v11.addOutgoingEdge(&v8);

    Graph g;

    g.addVertex(&v1);
    g.addVertex(&v2);
    g.addVertex(&v3);
    g.addVertex(&v4);
    g.addVertex(&v5);
    g.addVertex(&v6);
    g.addVertex(&v7);
    g.addVertex(&v8);
    g.addVertex(&v9);
    g.addVertex(&v10);
    g.addVertex(&v11);

    g.showGraph();

    SCC(g);

    return 0;
}
