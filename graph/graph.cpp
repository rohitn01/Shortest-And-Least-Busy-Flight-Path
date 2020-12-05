#include "graph.h"

Graph::Graph() {

}

void Graph::insertVertex(const Vertex & v) {
    removeVertex(v);
    std::pair<Vertex, std::unordered_map<Vertex, Edge>> newVertex;
    newVertex.first = v;
    newVertex.second = std::unordered_map<Vertex, Edge>();
    adjList.insert(newVertex);
}

void Graph::insertEdge(const Vertex& src, const Vertex& dest, const double weight) {
    if(adjList.find(src) == adjList.end() || adjList.find(dest) == adjList.end()) {
        return;
    }
    if(isAdjacent(src, dest)) {
        adjList[src][dest].weight_ = weight;
        adjList[dest][src].weight_ = weight;
        return;
    }
    Edge e;
    e.src_ = src;
    e.dest_ = dest;
    e.weight_ = weight;
    std::pair<Vertex, Edge> fromSource;
    std::pair<Vertex, Edge> fromDest;
    fromSource.first = dest;
    fromDest.first = src;
    fromSource.second = e;
    fromDest.second = e;
    adjList.find(src)->second.insert(fromSource);
    adjList.find(dest)->second.insert(fromDest);
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

void Graph::removeEdge(const Vertex& src, const Vertex& dest) {
    if(!isAdjacent(src, dest)) {
        return;
    }
    adjList.find(src)->second.erase(dest);
    adjList.find(dest)->second.erase(src);
}

bool Graph::isAdjacent(const Vertex& v1, const Vertex& v2) {
    if(adjList.find(v1) == adjList.end() || adjList.find(v2) == adjList.end()) {
        return false;
    }
    if(adjList[v1].find(v2) != adjList[v1].end() && adjList[v2].find(v1) != adjList[v2].end()) {
        return true;
    }
    return false;
}

std::vector<Graph::Edge> Graph::incidentEdges(const Vertex& vert) {
    std::vector<Edge> outlist;
    auto mapping = adjList.find(vert);
    for(auto it = mapping->second.begin(); it != mapping->second.end(); ++it) {
        outlist.push_back(it->second);
    }
    return outlist; 
}