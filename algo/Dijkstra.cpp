#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph& g) {
  g_ = g;
}

std::vector<Vertex> Dijkstra::findShortestPath(const Vertex start, const Vertex end) {
  std::priority_queue<std::pair<int, Vertex>, std::vector<std::pair<int, Vertex>>, std::greater<std::pair<int, Vertex>>> pq;

  std::map<Vertex, int> dist; // stores shortest distances
  std::map<Vertex, bool> visited; // stores visited vertices
  std::map<Vertex, Vertex> prev; // stores prev vertex for shortest path

  std::vector<Vertex> vertices = g_.getVertices();
  // checks if start and end are vertices in the graph
  if ((std::find(vertices.begin(), vertices.end(), start) == vertices.end())
    || ((std::find(vertices.begin(), vertices.end(), end) == vertices.end()))) {
 
    return std::vector<Vertex>();
  }

  for (Vertex vertex : vertices) {
    if (vertex != start) {
      dist.insert(std::make_pair(vertex, INT_MAX));
    }

    visited.insert(std::make_pair(vertex, false));
  }

  pq.push(std::make_pair(0, start));
  dist.insert(std::make_pair(start, 0));
  
  while(!pq.empty()) {
    int currWeight = (pq.top()).first;
    Vertex curr = (pq.top()).second;
    pq.pop();

    visited[curr] = true;

    std::vector<Graph::Edge> edges = g_.incidentEdges(curr);

    for (Graph::Edge edge : edges) {
      int weightSum = currWeight + edge.weight_;

      if (!visited[edge.dest_] && (weightSum < dist[edge.dest_])) {
        pq.push(std::make_pair(weightSum, edge.dest_));  
        dist[edge.dest_] = weightSum;

        std::map<Vertex, Vertex>::iterator it = prev.find(edge.dest_);

        if (it != prev.end()) {
          prev[edge.dest_] = curr;

        } else {
          prev.insert(std::make_pair(edge.dest_, curr));
        }
      }
    }
  }

  std::vector<Vertex> path;
  Vertex curr = end;
  path.push_back(curr);

  while (path[path.size() - 1] != start) {
    path.push_back(prev[curr]);
    curr = prev[curr];
  }

  std::reverse(path.begin(), path.end());

  return path;
}
