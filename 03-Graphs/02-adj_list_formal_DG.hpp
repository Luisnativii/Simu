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
    vector<Edge*> starts;
    vector<Edge*> ends;

public:
    Vertex(int i, string n): GraphElement(i, n) {}

    void addStartEdge(Edge* e) {
        starts.push_back(e);
    }

    void addEndEdge(Edge* e) {
        ends.push_back(e);
    }

    vector<Edge*>& getStartEdges() {
        return starts;
    }

    vector<Edge*>& getEndEdges() {
        return ends;
    }
};

class Edge : public GraphElement {
private:
    Vertex* start;
    Vertex* end;

public:
    Edge(int i, string n, Vertex* a = nullptr, Vertex* b = nullptr): GraphElement(i, n), start(a), end(b) {}

    void setVertices(Vertex* a, Vertex* b) {
        start = a;
        end = b;
    }

    Vertex* getV1() {
        return start;
    }

    Vertex* getV2() {
        return end;
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

    void showGraph() {

        cout << "***** Vertices *****\n\n";

        for (Vertex* v : vertices) {
            cout << v->getId() << " - " << v->getName() << "\n";
            cout << "Start Edges: ";
            for (Edge* e : v->getStartEdges()) {
                cout << e->getName() << " ";
            }
            cout << "\nEnd Edges: ";
            for (Edge* e : v->getEndEdges()) {
                cout << e->getName() << " ";
            }
            cout << "\n\n";
        }

        cout << "***** Edges *****\n\n";

        for (Edge* e : edges) {
            cout << e->getId() << " - " << e->getName() << "\n";
            if (e->getV1()) {
                cout << "Start: " << e->getV1()->getName() << "\n";
            }
            if (e->getV2()) {
                cout << "End: " <<  e->getV2()->getName();
            }
            cout << "\n\n";
        }
    }
};
