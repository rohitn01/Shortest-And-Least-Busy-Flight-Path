#pragma once

// Vertex is a string for airport codes
#define Vertex std::string

#include <vector>
#include <unordered_map>
#include <list>
#include <string>

class Graph {
    public:
        // Edges are defined as a struct.
        struct Edge {
            double weight_;
            Vertex src_;
            Vertex dest_;
        };

        Graph();
        void insertVertex(const Vertex& V);
        void insertEdge(const Vertex & src, const Vertex& dest, const double weight);
        void removeVertex(const Vertex& vert);
        void removeEdge(const Vertex& src, const Vertex& dest);
        double getEdgeWeight(const Vertex& src, const Vertex& dest);
        bool vertexExists(const Vertex& V);
        bool isAdjacent(const Vertex& v1, const Vertex& v2);
        std::vector<Edge> incidentEdges(const Vertex& vert);
        std::vector<Vertex> getVertices();
        


    private:
        // Utilizing the adjacency list to store vertex/edge relations
        std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> adjList;
};