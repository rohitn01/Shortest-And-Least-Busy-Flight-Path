#include "graph.h"


// Basic Graph Constructor
Graph::Graph() {

}

// Inserts a vertex into the graph by passing in argument of Vertex v (typedef string). 
// Removes vertex first if it exists before inserting. Adds vertex into adjacency list.
void Graph::insertVertex(const Vertex & v) {
    removeVertex(v);
    std::pair<Vertex, std::unordered_map<Vertex, Edge>> newVertex;
    newVertex.first = v;
    newVertex.second = std::unordered_map<Vertex, Edge>();
    adjList.insert(newVertex);
}

// Creates an edge between two existing vertices in graph and assigns weight to that edge.
// Includes edge in adjacency list for both vertices. Ignores duplicate edges if made,
// but will reassign weight.
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

// Check to see if vertex passed exists, deletes the vertex, then iterates through adjacency list 
// at that vertex wiping out all data of edges corresponding to that point.
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

// Checks to see if edge exists between vertices and deletes accordingly
void Graph::removeEdge(const Vertex& src, const Vertex& dest) {
    if(!isAdjacent(src, dest)) {
        return;
    }
    adjList.find(src)->second.erase(dest);
    adjList.find(dest)->second.erase(src);
}

// Checks to see if vertices exist in adjacency list and then check to see if v2 exists in v1's adjacent list and vice versa. Return true if it exists.
bool Graph::isAdjacent(const Vertex& v1, const Vertex& v2) {
    if(adjList.find(v1) == adjList.end() || adjList.find(v2) == adjList.end()) {
        return false;
    }
    if(adjList[v1].find(v2) != adjList[v1].end() && adjList[v2].find(v1) != adjList[v2].end()) {
        return true;
    }
    return false;
}
// Checks to see if vertex exists and then proceeds to add every edge to the return list.
std::vector<Graph::Edge> Graph::incidentEdges(const Vertex& vert) {
    std::vector<Edge> outlist;
    auto mapping = adjList.find(vert);
    /*if(mapping == adjList.end()) {
        return outlist;
    }*/
    for(auto it = mapping->second.begin(); it != mapping->second.end(); ++it) {
        outlist.push_back(it->second);
    }
    return outlist; 
}
// Returns a list of all present vertices on graph using adjacency list.
std::vector<Vertex> Graph::getVertices() {
    std::vector<Vertex> outList;
    for(auto it = adjList.begin(); it != adjList.end(); it++) {
        outList.push_back(it->first);
    }
    return outList;
}