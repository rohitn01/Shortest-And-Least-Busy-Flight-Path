#include <iostream>

#include "BFS.h"

BFS::BFS(Graph& g) {
  g_ = g;
}

std::vector<Vertex> BFS::findShortestPath(const Vertex start, const Vertex end) {
  std::queue<Vertex> q;

  std::map<Vertex, bool> visited; // stores visited vertices
  std::map<Vertex, Vertex> prev; // stores prev vertex from curr

  for (Vertex vertex : g_.getVertices()) {
    visited.insert(std::make_pair(vertex, false));
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
    std::vector<Graph::Edge> edges = g_.incidentEdges(curr);

    for (Graph::Edge edge : edges) {
      if (edge.dest_ == end) { // found shortest path
        prev.insert(std::make_pair(edge.dest_, curr));
        break; 

      } else if (!visited[edge.dest_]) { // add possible adjacent vertices
        q.push(edge.dest_); 
        visited[edge.dest_] = true;
        prev.insert(std::make_pair(edge.dest_, curr));
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
