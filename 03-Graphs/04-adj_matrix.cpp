#include "04-adj_matrix.hpp"

int main() {

    // Undirected

    Graph ug(4);

    ug.addVertex(1, 2);
    ug.addVertex(1, 3);
    ug.addVertex(2, 1);
    ug.addVertex(2, 3);
    ug.addVertex(3, 1);
    ug.addVertex(3, 2);
    ug.addVertex(3, 4);
    ug.addVertex(4, 3);
    
    ug.showGraph();

    cout << "************************************************************\n\n";

    // Directed

    Graph dg(4);

    dg.addVertex(1, 2);
    dg.addVertex(1, 3);
    dg.addVertex(3, 2);
    dg.addVertex(3, 4);
    
    dg.showGraph();

    return 0;
}
