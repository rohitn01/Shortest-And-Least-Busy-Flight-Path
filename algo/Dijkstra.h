#pragma once

#include <vector>
#include <map>
#include <queue>

#include "../graph/graph.h"

class Dijkstra {
  public:
    Dijkstra(Graph&);
    std::vector<Vertex> findShortestPath(const Vertex, const Vertex, const std::vector<Vertex>);
    std::vector<std::vector<Vertex>> findShortestPathVector(const Vertex);

  private:
    Graph g_;
};
