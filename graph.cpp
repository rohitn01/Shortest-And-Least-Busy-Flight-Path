#include "graph.h"

template <typename V, typename E>
Graph::Graph() {

}

template <typename V, typename E>
void Graph::insertVertex(const K& key) {
    Vertex v = new Vertex();
    v->key_ = key;
    v->edges = {};
}

template <typename V, typename E>
void Graph::insertEdge(const V& src, const V& dest, const K key) {
    Edge e = new Edge();
    e->edge.first = src;
    e->edge.second = dest;
    e->weight_ = key;
}

template <typename V, typename E>
void Graph::removeVertex(const V& vert) {

}

template <typename V, typename E>
void removeEdge(const V& src, const V& dest) {

}

template <typename V, typename E>
bool isAdjacent(const V& v1, const V& v2) {
    auto v1List = adjList.find(v1);
    for(std::list::iterator it = v1List.begin(); it != v1List.end(); it++) {
        if(v1->key_ == v2->key_) {
            return true;
        }
    }
    return false;
}

template <typename V, typename E>
const std::list<E> incidentEdges(const V& vert) {
    auto it = adjList.find(vert);
    return it;
}