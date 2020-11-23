#pragma once

#include <vector>
#include <unordered_map>
#include <list>

template <class V, class E>
class Graph {
    public:
        struct edge {
            V src;
            V dest;
        }
        Graph();
        void insertVertex(const K& key);
        void insertEdge(const V& src, const V& dest, const K key);
        void removeVertex(const V& vert);
        void removeEdge(const V& src, const V& dest);
        bool isAdjacent(const V& v1, const V& v2);
        


    private:
        std::unordered_map<V, std::list<E> adjList;
};