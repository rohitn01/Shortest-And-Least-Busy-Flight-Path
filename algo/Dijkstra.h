#pragma once

#include <vector>
#include <map>
#include <queue>

#include "../graph/graph.h"

class Dijkstra {
  public:
    // Constructor to input graph to calculate on
    Dijkstra(Graph&);

    // Outputs a vector of vertices that has the shortest path using Dijkstras
    // Inputs are starting and ending vertex and a vector of vertices to avoid
    std::vector<Vertex> findShortestPath(const Vertex, const Vertex, const std::vector<Vertex>);

    // Outputs a vector of vectors that have all the shortest paths to all other vertices using Dijkstras
    // Input is only starting vertex
    // Used only for BetwennessCentrality algo and therefore does not need a vector of vertices to avoid
    std::vector<std::vector<Vertex>> findShortestPathVector(const Vertex);

  private:
    Graph g_;
};
