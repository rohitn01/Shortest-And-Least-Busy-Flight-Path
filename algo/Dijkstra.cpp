#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph& g) {
  g_ = g;
}

std::vector<Vertex> Dijkstra::findShortestPath(const Vertex start, const Vertex end) {
  std::priority_queue<std::pair<int, Vertex>, vector<std::pair<int, Vertex>>, greater<std::pair<int, Vertex>>> pq;

  std::map<Vertex, int> dist; // stores dist to each vertex

  for (Vertex vertex : g_.getVertices()) {
    dist.insert(std::make_pair(vertex, INT_MAX));
  }

  // checks if start and end are vertices in the graph
  std::map<Vertex, bool>::iterator it0 = dist.find(start);
  std::map<Vertex, bool>::iterator it1 = dist.find(end);
  if ((it0 == dist.end())
    || (it1 == dist.end())) {
 
    return std::vector<Vertex>();
  }

  
}
