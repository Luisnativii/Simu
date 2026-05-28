#include <bits/stdc++.h>
using namespace std;

class Vertex;
class Edge;

class GraphElement {
protected:
    int id;
    string name;

public:
    GraphElement(int i, string n): id(i), name(n) {}

    virtual ~GraphElement() = default;

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
};

class Vertex : public GraphElement {
private:
    vector<Edge*> edges;

public:
    Vertex(int i, string n): GraphElement(i, n) {}

    void addEdge(Edge* e) {
        edges.push_back(e);
    }

    vector<Edge*>& getEdges() {
        return edges;
    }
};

class Edge : public GraphElement {
private:
    Vertex* v1;
    Vertex* v2;

public:
    Edge(int i, string n, Vertex* a = nullptr, Vertex* b = nullptr): GraphElement(i, n), v1(a), v2(b) {}

    void setVertices(Vertex* a, Vertex* b) {
        v1 = a;
        v2 = b;
    }

    Vertex* getV1() {
        return v1;
    }

    Vertex* getV2() {
        return v2;
    }
};

class Graph {
private:
    vector<Vertex*> vertices;
    vector<Edge*> edges;

public:
    Graph() = default;

    void addVertex(Vertex* v) {
        vertices.push_back(v);
    }

    void addEdge(Edge* e) {
        edges.push_back(e);
    }

    void showGraph() const {

        cout << "***** Vertices *****\n\n";

        for (Vertex* v : vertices) {
            cout << v->getId() << " - " << v->getName() << "\n";
            cout << "Edges: ";
            for (Edge* e : v->getEdges()) {
                cout << e->getName() << " ";
            }
            cout << "\n\n";
        }

        cout << "***** Edges *****\n\n";

        for (Edge* e : edges) {
            cout << e->getId() << " - " << e->getName() << "\n";
            cout << "Vertices: ";
            if (e->getV1()) {
                cout << e->getV1()->getName() << " ";
            }
            if (e->getV2()) {
                cout << e->getV2()->getName() << " ";
            }
            cout << "\n\n";
        }
    }
};
