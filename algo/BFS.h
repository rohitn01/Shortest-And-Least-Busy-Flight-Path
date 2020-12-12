#pragma once

#include <vector>
#include <map>
#include <queue>

#include "../graph/graph.h"

class BFS {
  public:
    // Constructor to input graph to calculate on
    BFS(Graph&);

    // Outputs a vector of vertices that has the shortest path using BFS
    // Inputs are starting and ending vertex and a vector of vertices to avoid
    std::vector<Vertex> findShortestPath(const Vertex, const Vertex, const std::vector<Vertex>);
  
  private:
    Graph g_;
};
