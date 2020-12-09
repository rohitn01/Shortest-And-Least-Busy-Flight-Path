#include "BetweennessCentrality.h"

std::vector<Vertex> findCentralAirports(int numAirports, Graph& G) {
    std::map<Vertex, int> vertexCentrality;
    std::vector<Vertex> vertices = G.getVertices();
    int pathCount = 0;
    Dijkstra Dijkstra(G);
    for (size_t i = 0; i < vertices.size(); i++) {
        for (size_t j = 0; j < vertices.size(); j++) {
            if (i != j) {
                std::vector<Vertex> shortestPath = Dijkstra.findShortestPath(vertices[i], vertices[j], vertices); //Returns vector of nodes in shortest path between 2 given nodes, not including the given start and end. Empty if no path.
                if (shortestPath.size() != 0) {
                    pathCount++;
                }
                for (const Vertex &v : shortestPath) {
                    vertexCentrality[v]++;
                }
            }
        }
    }

    //Find top numAirports vertices.
    std::vector<std::pair<int, Vertex>> centrality; 
    for(auto const& p : vertexCentrality) {
        centrality.push_back(make_pair(p.second, p.first));
    }

    std::sort(centrality.begin(), centrality.end());
    std::reverse(centrality.begin(), centrality.end());

    std::vector<Vertex> centralAirports;
    for (int i = 0; i < numAirports; i++) {
        centralAirports.push_back(centrality[i].second);
    }
    //centralAirports is now a vector with the top airports
    return centralAirports;
}
