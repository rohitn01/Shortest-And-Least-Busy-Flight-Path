#pragma once

#include <vector>

#include "../graph/graph.h"

class BFS {
  public:
    BFS(const Graph g);
    std::vector<Vertex> findShortestPath(Vertex start, Vertex end);
  
  private:
    const Graph g_;
};
