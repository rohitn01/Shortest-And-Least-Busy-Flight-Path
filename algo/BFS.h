#pragma once

#include <vector>
#include <map>
#include <queue>

#include "../graph/graph.h"

class BFS {
  public:
    BFS(Graph&);
    std::vector<Vertex> findShortestPath(Vertex start, Vertex end);
  
  private:
    Graph g_;
};
