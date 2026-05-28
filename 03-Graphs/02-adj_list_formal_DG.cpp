#include "02-adj_list_formal_DG.hpp"

int main() {

    Vertex v1(1, "A");
    Vertex v2(2, "B");
    Vertex v3(3, "C");
    Vertex v4(4, "D");

    Edge e1(1, "e1", &v1, &v2);
    Edge e2(2, "e2", &v1, &v3);
    Edge e3(3, "e3", &v3, &v2);
    Edge e4(4, "e4", &v3, &v4);

    v1.addStartEdge(&e1); v1.addStartEdge(&e2);
    v2.addEndEdge(&e1); v2.addEndEdge(&e3);
    v3.addStartEdge(&e3); v3.addStartEdge(&e4);
    v3.addEndEdge(&e2);
    v4.addEndEdge(&e4);

    Graph g;

    g.addVertex(&v1);
    g.addVertex(&v2);
    g.addVertex(&v3);
    g.addVertex(&v4);

    g.addEdge(&e1);
    g.addEdge(&e2);
    g.addEdge(&e3);
    g.addEdge(&e4);

    g.showGraph();

    return 0;
}
