#include "graph.h"

template <class V, class E>
Graph::Graph() {

}

template <class V, class E>
void Graph::insertVertex(const K& key) {
    Vertex v = new Vertex();
    v->key_ = key;
    v->edges = {};
}

template <class V, class E>
void Graph::insertEdge(const V& src, const V& dest, const K key) {
    Edge e = new Edge();
    e->edge.first = src;
    e->edge.second = dest;
    e->weight_ = key;
}

template <class V, class E>
void Graph::removeVertex(const V& vert) {

}

template <class V, class E>
void removeEdge(const V& src, const V& dest) {

}

template <class V, class E>
bool isAdjacent(const V& v1, const V& v2) {

}

template <class V, class E>
const std::list<E> incidentEdges(const V& vert) {

}