#pragma once

#include <vector>
#include <unordered_map>
#include <list>



typedef std::string Vertex;

class Graph {
    public:
        struct Edge {
            double weight_;
            Vertex src_;
            Vertex dest_;
        };
        Graph();
        void insertVertex(const Vertex& V);
        void insertEdge(const Vertex & src, const Vertex& dest, const K key);
        void removeVertex(const Vertex& vert);
        void removeEdge(const Vertex& src, const Vertex& dest);
        bool isAdjacent(const Vertex& v1, const Vertex& v2);
        const std::vector<Edge> incidentEdges(const Vertex& vert);
        


    private:
        std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> adjList;
};