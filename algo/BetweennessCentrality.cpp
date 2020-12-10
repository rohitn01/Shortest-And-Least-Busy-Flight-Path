#include "BetweennessCentrality.h"
#include <iostream>

std::vector<Vertex> findCentralAirports(int numAirports, Graph& G) {
    std::unordered_map<Vertex, int> vertexCentrality;
    std::vector<Vertex> vertices = G.getVertices();
    if (vertices.size() <= 1) {
        return std::vector<Vertex>();
    }
    if (numAirports >= int(vertices.size())) {
        return vertices;
    }
    if (numAirports <= 0) {
        return std::vector<Vertex>();
    }
    //
    Dijkstra Dijkstra(G);
    for (size_t i = 0; i < vertices.size(); i++) {
        std::vector<std::vector<Vertex>> shortestPaths = Dijkstra.findShortestPathVector(vertices[i]);
        for (const auto &path : shortestPaths) {
            for (const Vertex &v : path) {
                vertexCentrality[v]++;
            }
        }        
    }

    //Find top numAirports vertices.
    std::vector<std::pair<int, Vertex>> centrality; 
    for(Vertex v : vertices) {
        centrality.push_back(make_pair(vertexCentrality[v], v));
    }

    std::sort(centrality.begin(), centrality.end());
    std::reverse(centrality.begin(), centrality.end());

    std::vector<Vertex> centralAirports;
    for (int i = 0; i < numAirports; i++) {
        centralAirports.push_back(centrality[i].second);
    }
    //Uncomment to print out ordered centrality list of graph
    //for (auto &v : centrality) {
    //    std::cout<<v.second<<": "<<v.first<<std::endl;
    //}
    //centralAirports is now a vector with the top airports
    return centralAirports;
}
