#include "03-adj_list.hpp"

int main() {

    // Undirected

    Vertex v1(1, "A");
    Vertex v2(2, "B");
    Vertex v3(3, "C");
    Vertex v4(4, "D");

    v1.addEdge(&v2); v1.addEdge(&v3);
    v2.addEdge(&v1); v2.addEdge(&v3);
    v3.addEdge(&v1); v3.addEdge(&v2); v3.addEdge(&v4);
    v4.addEdge(&v3);

    Graph ug;

    ug.addVertex(&v1);
    ug.addVertex(&v2);
    ug.addVertex(&v3);
    ug.addVertex(&v4);

    ug.showGraph();

    cout << "************************************************************\n\n";

    // Directed

    Vertex w1(1, "A");
    Vertex w2(2, "B");
    Vertex w3(3, "C");
    Vertex w4(4, "D");

    w1.addEdge(&w2); w1.addEdge(&w3);
    w3.addEdge(&w2); w3.addEdge(&w4);

    Graph dg;

    dg.addVertex(&w1);
    dg.addVertex(&w2);
    dg.addVertex(&w3);
    dg.addVertex(&w4);

    dg.showGraph();

    return 0;
}
