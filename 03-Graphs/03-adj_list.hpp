#include <bits/stdc++.h>
using namespace std;

class Vertex {
private:
    int id;
    string name;
    vector<Vertex*> edges;

public:
    Vertex(int i, string n): id(i), name(n) {}

    void setId(int i) {
        id = i;
    }

    int getId() {
        return id;
    }

    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void addEdge(Vertex* v) {
        edges.push_back(v);
    }

    vector<Vertex*>& getEdges() {
        return edges;
    }
};

class Graph {
private:
    vector<Vertex*> vertices;

public:
    Graph() = default;

    void addVertex(Vertex* v) {
        vertices.push_back(v);
    }

    void showGraph() {
        for (Vertex* v : vertices) {
            cout << v->getId() << " - " << v->getName() << "\n";
            cout << "Edges: ";
            for (Vertex* d: v->getEdges()) {
                cout << d->getName() << " ";
            }
            cout << "\n\n";
        }
    }
};
