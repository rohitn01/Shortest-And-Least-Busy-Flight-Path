#include "BetweennessCentrality.h"
#include <iostream>

std::vector<Vertex> findCentralAirports(int numAirports, Graph& G) {
    std::unordered_map<Vertex, int> vertexCentrality;
    std::vector<Vertex> vertices = G.getVertices();
    if (numAirports >= vertices.size()) {
        return vertices;
    }
    if (numAirports <= 0) {
        return std::vector<Vertex>();
    } 
    Dijkstra Dijkstra(G);
    for (size_t i = 0; i < vertices.size(); i++) {
        std::cout<<"checking: "<<vertices[i]<<std::endl;
        //std::map<std::pair<Vertex, Vertex>, std::vector<Vertex>> shortestPaths = Dijkstra.findShortestPathMap(vertices[i]);
        std::vector<std::vector<Vertex>> shortestPaths = Dijkstra.findShortestPathMap(vertices[i]);
        /*
        for (const auto &pair : shortestPaths) {
            if (vertices[i] != pair.first.second) {
                for (const Vertex &v : pair.second) {
                    vertexCentrality[v]++;
                }
            }
        }
        */
        for (const auto &path : shortestPaths) {
            for (const Vertex &v : path) {
                vertexCentrality[v]++;
            }
        }        
            /*
            std::cout<<"checking: "<<vertices[i]<<" to "<<vertices[j]<<std::endl;
            std::vector<Vertex> shortestPath = Dijkstra.findShortestPath(vertices[i]); //Returns vector of nodes in shortest path between 2 given nodes, not including the given start and end. Empty if no path.
            //std::cout<<"Path found"<<std::endl;

            for (const Vertex &v : shortestPath) {
                vertexCentrality[v]++;
            }
            //std::cout<<"centrality appened"<<std::endl;
            */
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
    for (auto &v : centrality) {
        std::cout<<v.second<<": "<<v.first<<std::endl;
    }
    //centralAirports is now a vector with the top airports
    return centralAirports;
}
