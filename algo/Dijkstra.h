#pragma once

#include <vector>
#include <map>
#include <queue>

#include "../graph/graph.h"

class Dijkstra {
  public:
    Dijkstra(Graph&);
    std::vector<Vertex> findShortestPath(const Vertex, const Vertex, const std::vector<Vertex>);
    //std::map<std::pair<Vertex, Vertex>, std::vector<Vertex>> findShortestPathMap(const Vertex);
    std::vector<std::vector<Vertex>> findShortestPathMap(const Vertex);

  private:
    Graph g_;
};
