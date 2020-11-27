#pragma once

#include <vector>
#include <unordered_map>
#include <list>



template <typename V, typename E>
class Graph {
    public:
        struct Vertex {
            K key_;
        }
        struct Edge {
            K weight_;
            V src_;
            V dest_;
        }
        Graph();
        void insertVertex(const K& key);
        void insertEdge(const V& src, const V& dest, const K key);
        void removeVertex(const V& vert);
        void removeEdge(const V& src, const V& dest);
        bool isAdjacent(const V& v1, const V& v2);
        const std::list<E> incidentEdges(const V& vert);
        


    private:
        std::unordered_map<V, std::list<E>> adjList;
};