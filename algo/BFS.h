#pragma once

#include <vector>
#include <map>
#include <queue>

#include "../graph/graph.h"

class BFS {
  public:
    BFS(Graph&);
    std::vector<Vertex> findShortestPath(const Vertex, const Vertex, const std::vector<Vertex>);
  
  private:
    Graph g_;
};
