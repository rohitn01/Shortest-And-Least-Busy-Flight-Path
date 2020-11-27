#include "graph.h"

template <typename V, typename E>
Graph::Graph() {

}

template <typename V, typename E>
void Graph::insertVertex(const K& key) {
    Vertex v;
    v->key_ = key;

}

template <typename V, typename E>
void Graph::insertEdge(const V& src, const V& dest, const K key) {
    if(isAdjacent(src, dest)) {
        return;
    }
    Edge e;
    e->edge.first = src;
    e->edge.second = dest;
    e->weight_ = key;
    adjList.find(src).insert(e);
    adjList.find(dest).insert(e);
}

template <typename V, typename E>
void Graph::removeVertex(const V& vert) {

}

template <typename V, typename E>
void removeEdge(const V& src, const V& dest) {
    if(!isAdjacent(src, dest)) {
        return;
    }
    auto & srcList = adjList.find(src);
    auto & destList = adjList.find(dest);
    for(std::list::iterator it = srcList.begin(); it != srcList.end(); it++) {
        if(it->src_->key_ == dest->key_) {
            srcList.erase(it);
        }
        if(it->dest_->key_ == dest->key_) {
            srcList.erase(it);
        }
    }
    for(std::list::iterator it = destList.begin(); it != destList.end(); it++) {
        if(it->src_->key_ == src->key_) {
            srcList.erase(it);
        }
        if(it->dest_->key_ == src->key_) {
            srcList.erase(it);
        }
    }
}

template <typename V, typename E>
bool isAdjacent(const V& v1, const V& v2) {
    auto v1List = adjList.find(v1);
    for(std::list::iterator it = v1List.begin(); it != v1List.end(); it++) {
        if(it->src_->key_ == v2->key_) {
            return true;
        }
        if(it->dest_->key_ == v2->key_) {
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