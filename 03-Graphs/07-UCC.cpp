#include "03-adj_list.hpp"

void UCC(Graph& g) {
    vector<bool> explored(g.getN(), false);
    vector<int> cc(g.getN());
    int numCC = 0;

    for( Vertex* i: g.getVertices() ) {
        if( !explored[i->getId()-1] ) {
            explored[i->getId()-1] = true;
            numCC++;

            queue<Vertex*> Q;
            Q.push(i);
            while( !Q.empty() ) {
                Vertex* v = Q.front();
                Q.pop();
                cc[v->getId()-1] = numCC;
                for(Vertex* w: v->getEdges()) {
                    if( !explored[w->getId()-1] ) {
                        explored[w->getId()-1] = true;
                        Q.push(w);
                    }
                }
            }
        }
    }

    cout << "List of Connected Components:\n";
    for( int c = 1; c <= numCC; c++ ) {
        cout << "Connected Component #" << c << ": ";
        for(int i = 0; i < g.getN(); i++)
            if( cc[i] == c ) cout << i+1 << " ";
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

    v1.addEdge(&v3); v1.addEdge(&v5);
    v2.addEdge(&v4);
    v3.addEdge(&v1); v3.addEdge(&v5);
    v4.addEdge(&v2);
    v5.addEdge(&v1); v5.addEdge(&v3); v5.addEdge(&v7); v5.addEdge(&v9);
    v6.addEdge(&v8); v6.addEdge(&v10);
    v7.addEdge(&v5);
    v8.addEdge(&v6);
    v9.addEdge(&v5);
    v10.addEdge(&v6);

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

    g.showGraph();

    UCC(g);

    return 0;
}
