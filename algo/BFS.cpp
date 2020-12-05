#include <queue>
#include <map>

#include "BFS.h"

BFS::BFS(const Graph g) {
  g_ = g;
}

std::vector<Vertex> BFS::findShortestPath(Vertex start, Vertex end) {
  std::queue<Vertex> q;

  std::map<Vertex, bool> visited; // stores visited vertices
  std::map<Vertex, Vertex> prev; // stores prev vertex from curr

  for (Vertex vertex : g_.getVertices()) {
    visited.insert(std::make_pair(vertex, -1));
  }

  // checks if start and end are vertices in the graph
  std::map<Vertex, bool>::iterator it0 = visited.find(start);
  std::map<Vertex, bool>::iterator it1 = visited.find(end);
  if ((it0 == visited.end()) 
    || (it1 == visited.end())) {

    return std::vector<Vertex>();
  }

  q.push(start);

  while(!q.empty()) {
    Vertex curr = q.front();
    q.pop();

    // iterate through all possible edges
    std::vector<Edge> edges = g_.incidentEdges(curr);
    for (Edge edge : edges) {
      if (edge.dest_ == end) {
        prev.insert(std::make_pair(edge.dest_, curr));
        break; 

      } else if (visited[edge.dest_] < 0) {
        q.push_back(edge.dest_); 
        visited[edge.dest_] += 1;
        prev.insert(std::make_pair(edge.dest_, curr));
      }
    }
  }
  

  return path;
}
