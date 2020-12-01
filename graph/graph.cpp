#include "graph.h"

Graph::Graph() {

}

void Graph::insertVertex(const std::string key) {
    Vertex v = key;
    removeVertex(v);
    std::pair<Vector, std::unordered_map<Vector, Edge>> newVertex;
    newVertex->first = v;
    newVertex-second = std::unordered_map<Vector, Edge>();
    adjList.insert(newVertex);
}

void Graph::insertEdge(const Vertex& src, const Vertex& dest, const double key) {
    if(adjList.find(src) == adjList.end() || adjList.find(dest) == adjList.end()) {
        return;
    }
    if(isAdjacent(src, dest)) {
        adjList[src][dest].weight_ = key;
        adjList[dest][src].weight_ = key;
        return;
    }
    Edge e;
    e->src_ = src;
    e->dest_ = dest;
    e->weight_ = key;
    std::pair<Vertex, Edge> fromSource;
    std::pair<Vertex, Edge> fromDest;
    fromSource.first = dest;
    fromDest.first = src;
    fromSource.second = e;
    fromDest.second = e;
    adjList.find(src).insert(fromSource);
    adjList.find(dest).insert(fromDest);
}

void Graph::removeVertex(const Vertex& vert) {
    if(adjList.find(vert) != adjList.end()) {
        adjList.erase(vert);
        for(auto it = adjList.begin(); it != adjList.end(); it++) {
            if(it->second.find(vert) != it->second.end()) {
                it->second.erase(vert);
            }
        }
    }
}

void removeEdge(const Vertex& src, const Vertex& dest) {
    if(!isAdjacent(src, dest)) {
        return;
    }
    adjList.find(src).erase(dest);
    adjList.find(dest).erase(src);
}

bool isAdjacent(const Vertex& v1, const Vertex& v2) {
    if(adjList.find(v1) == adjList.end() || adjList.find(v2) == adjList.end()) {
        return false;
    }
    if(adjList[v1].find(v2) && adjList[v2].find(v1)) {
        return true;
    }
}

const std::vector<Edge> incidentEdges(const Vertex& vert) {
    std::vector<Edge> outlist;
    auto mapping = adjList.find(vert);
    for(auto it = mapping.begin(); it != mapping.end(); it++) {
        outlist.push_back(it->second);
    }
    return outlist
}