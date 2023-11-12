
#pragma once
#include <list>

class Graph;

class Graph {
    int numVertices;
    std::list<int>* adjLists;
    bool* visited;

    public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};
