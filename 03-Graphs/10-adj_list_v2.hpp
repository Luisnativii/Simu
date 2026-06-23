#include <bits/stdc++.h>
using namespace std;

class Vertex {
private:
    int id;
    string name;
    vector<Vertex*> in_edges;
    vector<Vertex*> out_edges;

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

    void addIncomingEdge(Vertex* v) {
        in_edges.push_back(v);
    }

    vector<Vertex*>& getIncomingEdges() {
        return in_edges;
    }

    void addOutgoingEdge(Vertex* v) {
        out_edges.push_back(v);
    }

    vector<Vertex*>& getOutgoingEdges() {
        return out_edges;
    }
};

class Graph {
private:
    vector<Vertex*> vertices;

public:
    Graph() = default;

    int getN() {
        return vertices.size();
    }

    vector<Vertex*>& getVertices() {
        return vertices;
    }

    void addVertex(Vertex* v) {
        vertices.push_back(v);
    }

    void showGraph() {
        for (Vertex* v : vertices) {
            cout << v->getId() << " - " << v->getName() << "\n";
            cout << "Incoming Edges: ";
            for (Vertex* d: v->getIncomingEdges()) {
                cout << d->getName() << " ";
            }
            cout << "\nOutgoing Edges: ";
            for (Vertex* d: v->getOutgoingEdges()) {
                cout << d->getName() << " ";
            }
            cout << "\n\n";
        }
    }
};
