#include "../cs225/catch/catch.hpp"

#include <string>
#include <iostream>
#include <vector>

#include "../graph/graph.h"
#include "../algo/BetweennessCentrality.h"

#include "../data/airport.h"
#include "../data/dataset.h"

/*
*  Helper functions for the tests
*/

/*
*  Test to see if this graph works
*/

TEST_CASE("Graph successfully adds vertices", "[weight=1][part=1]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");
    test.insertVertex("D");
    test.insertVertex("E");
    test.insertVertex("F");

    REQUIRE(test.vertexExists("A"));
    REQUIRE(test.vertexExists("B"));
    REQUIRE(test.vertexExists("C"));
    REQUIRE(test.vertexExists("D"));
    REQUIRE(test.vertexExists("E"));
    REQUIRE(test.vertexExists("F"));
    REQUIRE(!test.vertexExists("G"));
}


TEST_CASE("Graph successfully removes vertices", "[weight=1][part=1]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");

    test.removeVertex("B");

    REQUIRE(test.vertexExists("A"));
    REQUIRE(!test.vertexExists("B"));
    REQUIRE(test.vertexExists("C"));
}

TEST_CASE("Graph successfully creates edges", "[weight=1][part=1]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");

    test.insertEdge("A", "B", 9.0);
    test.insertEdge("B", "C", 8.0);

    REQUIRE(test.getEdgeWeight("A", "B") == 9.0);
    REQUIRE(test.getEdgeWeight("B", "C") == 8.0);
    REQUIRE(test.getEdgeWeight("A", "D") == -1.0);
    REQUIRE(test.getEdgeWeight("A", "C") == -1.0);
}

TEST_CASE("Graph successfully removes edges", "[weight=1][part=1]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");

    test.insertEdge("A", "B", 9.0);
    test.insertEdge("B", "C", 8.0);
    test.insertEdge("A", "C", 10.0);

    test.removeEdge("A", "C");

    REQUIRE(test.getEdgeWeight("A", "B") == 9.0);
    REQUIRE(test.getEdgeWeight("B", "C") == 8.0);
    REQUIRE(test.getEdgeWeight("A", "C") == -1.0);
}

TEST_CASE("Graph successfully generates incident edges", "[weight=1][part=1]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");
    test.insertVertex("D");

    test.insertEdge("A", "B", 9.0);
    test.insertEdge("B", "C", 8.0);
    test.insertEdge("A", "C", 10.0);
    test.insertEdge("A", "D", 11.0);

    REQUIRE(test.incidentEdges("A").size() == 3);
    REQUIRE(test.incidentEdges("B").size() == 2);
    REQUIRE(test.incidentEdges("D").size() == 1);
}


//Betweenness Centrality Testing

TEST_CASE("Betweenness Centrality Empty Graph", "[weight=1][part=3]") {
    Graph test;
    REQUIRE(findCentralAirports(1, test).size() == 0);
}

TEST_CASE("Betweenness Centrality One Vertex", "[weight=1][part=3]") {
    Graph test;
    test.insertVertex("A");
    REQUIRE(findCentralAirports(1, test).size() == 0);
}

TEST_CASE("Betweenness Centrality Disconnected graph", "[weight=1][part=3]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");
    test.insertVertex("D");
    REQUIRE(findCentralAirports(1, test).size() == 1);
}

TEST_CASE("Betweenness Centrality 2 Connected Components", "[weight=1][part=3]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");
    test.insertVertex("D");
    test.insertVertex("E");
    test.insertVertex("F");

    test.insertEdge("A", "B", 1);
    test.insertEdge("B", "A", 1);
    test.insertEdge("B", "C", 1);
    test.insertEdge("C", "B", 1);
    test.insertEdge("D", "E", 1);
    test.insertEdge("E", "D", 1);
    test.insertEdge("E", "F", 1);
    test.insertEdge("F", "E", 1);

    std::vector<Vertex> result = findCentralAirports(2, test);
    REQUIRE(result.size() == 2);
    REQUIRE(result[0] == "E");
    REQUIRE(result[1] == "B");
}

TEST_CASE("Betweenness Centrality 1 Central Regular Graph", "[weight=1][part=3]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");
    test.insertVertex("D");
    test.insertVertex("E");

    test.insertEdge("A", "C", 2);
    test.insertEdge("C", "B", 5);
    test.insertEdge("B", "A", 7);
    test.insertEdge("D", "C", 2);
    test.insertEdge("C", "E", 5);
    test.insertEdge("E", "D", 7);

    std::vector<Vertex> result = findCentralAirports(1, test);
    REQUIRE(result.size() == 1);
    REQUIRE(result[0] == "C");
}

TEST_CASE("Betweenness Centrality More Airports than Vertices", "[weight=1][part=3]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");
    test.insertVertex("D");
    test.insertVertex("E");

    test.insertEdge("A", "C", 2);
    test.insertEdge("C", "B", 5);
    test.insertEdge("B", "A", 7);
    test.insertEdge("D", "C", 2);
    test.insertEdge("C", "E", 5);
    test.insertEdge("E", "D", 7);

    std::vector<Vertex> result = findCentralAirports(6, test);
    REQUIRE(result.size() == 5);

}

TEST_CASE("Betweenness Centrality Max Vertices", "[weight=1][part=3]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");
    test.insertVertex("D");
    test.insertVertex("E");

    test.insertEdge("A", "C", 2);
    test.insertEdge("C", "B", 5);
    test.insertEdge("B", "A", 7);
    test.insertEdge("D", "C", 2);
    test.insertEdge("C", "E", 5);
    test.insertEdge("E", "D", 7);

    std::vector<Vertex> result = findCentralAirports(5, test);
    REQUIRE(result.size() == 5);
}

TEST_CASE("Betweenness Centrality 3 Central Regular Graph", "[weight=1][part=3]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");
    test.insertVertex("D");
    test.insertVertex("E");

    test.insertEdge("A", "B", 2);
    test.insertEdge("B", "A", 2);
    test.insertEdge("B", "C", 2);
    test.insertEdge("C", "B", 2);
    test.insertEdge("C", "D", 2);
    test.insertEdge("D", "C", 2);
    test.insertEdge("D", "E", 2);
    test.insertEdge("E", "D", 2);    

    std::vector<Vertex> result = findCentralAirports(3, test);
    REQUIRE(result.size() == 3);
    REQUIRE(result[0] == "C");
    REQUIRE(result[1] == "D");
    REQUIRE(result[2] == "B");
}

TEST_CASE("Betweenness Centrality Negative Airports", "[weight=1][part=3]") {
    Graph test;
    test.insertVertex("A");
    test.insertVertex("B");
    test.insertVertex("C");
    test.insertVertex("D");
    test.insertVertex("E");

    test.insertEdge("A", "C", 2);
    test.insertEdge("C", "B", 5);
    test.insertEdge("B", "A", 7);
    test.insertEdge("D", "C", 2);
    test.insertEdge("C", "E", 5);
    test.insertEdge("E", "D", 7);

    std::vector<Vertex> result = findCentralAirports(-5, test);
    REQUIRE(result.size() == 0);
}

TEST_CASE("Airport correctly loads info", "[weight=1][part=2]") {
    Airport a1("1,\"Goroka Airport\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");

    REQUIRE(a1.getName() == "Goroka Airport");
    REQUIRE(a1.getCity() == "Goroka");
    REQUIRE(a1.getCountry() == "Papua New Guinea");
    REQUIRE(a1.getCode() == "GKA");
    REQUIRE(a1.getLat(true) < -6);
    REQUIRE(a1.getLat(true) > -6.1);
}

TEST_CASE("Invalid airport works correctly", "[weight=1][part=2]") {
    Airport a("invalid");
    REQUIRE(!a.valid());
    REQUIRE(!Airport().valid());
}

TEST_CASE("Dataset loads the correct number of airports", "[weight=1][part=2]") {
    Dataset data("data/airports.dat", "data/routes.dat");
    REQUIRE(data.size() == 6072);
}

TEST_CASE("Dataset contains expected airports and routes", "[weight=1][part=2]") {
    Dataset data("data/airports.dat", "data/routes.dat");
    REQUIRE(data.getGraph().vertexExists("RDU"));
    REQUIRE(data.getGraph().vertexExists("JFK"));
    REQUIRE(data.getGraph().vertexExists("CMI"));

    double distance = data.getAirport("CMI").distance(data.getAirport("ORD"));
    REQUIRE(distance > 135);
    REQUIRE(distance < 136);
}

// BFS Testing
TEST_CASE("BFS finds shortest path", "[weight=1][part=3]") {
  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertVertex("E");

  test.insertEdge("A", "C", 2);
  test.insertEdge("C", "B", 5);
  test.insertEdge("B", "A", 7);
  test.insertEdge("D", "C", 2);
  test.insertEdge("C", "E", 5);
  test.insertEdge("E", "D", 7);

  BFS bfs(test);
  std::vector<Vertex> output = bfs.findShortestPath("A", "E", std::vector<Vertex>());  
  std::vector<Vertex> answer {"A", "C", "E"};
  
  REQUIRE(output.size() == answer.size());

  for (size_t i = 0; i < answer.size(); i++) {
    REQUIRE(output[i] == answer[i]); 
  }
}

TEST_CASE("BFS with no path", "[weight=1][part=3]") {
  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertVertex("E");

  test.insertEdge("A", "C", 2);
  test.insertEdge("C", "B", 5);
  test.insertEdge("B", "A", 7);
  test.insertEdge("D", "C", 2);
  test.insertEdge("C", "E", 5);

  BFS bfs(test);
  std::vector<Vertex> output = bfs.findShortestPath("A", "D", std::vector<Vertex>());  
  
  REQUIRE(output.empty());
}

TEST_CASE("BFS with disconnected", "[weight=1][part=3]") {
  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertVertex("E");

  test.insertEdge("A", "C", 2);
  test.insertEdge("C", "B", 5);
  test.insertEdge("B", "A", 7);
  test.insertEdge("E", "D", 5);

  BFS bfs(test);
  std::vector<Vertex> output = bfs.findShortestPath("A", "D", std::vector<Vertex>());  
  
  REQUIRE(output.empty());
}

TEST_CASE("BFS with removed hubs", "[weight=1][part=3]") {
  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertVertex("E");

  test.insertEdge("A", "C", 2);
  test.insertEdge("C", "B", 5);
  test.insertEdge("B", "A", 7);
  test.insertEdge("C", "D", 2);
  test.insertEdge("C", "E", 5);
  test.insertEdge("E", "B", 4);
  test.insertEdge("A", "E", 5);
  test.insertEdge("B", "D", 2);

  BFS bfs(test);
  std::vector<Vertex> hubs {"C"};
  std::vector<Vertex> output = bfs.findShortestPath("A", "D", hubs);  
  std::vector<Vertex> answer {"A", "E", "B", "D"};

  REQUIRE(output.size() == answer.size());

  for (size_t i = 0; i < answer.size(); i++) {
    REQUIRE(output[i] == answer[i]);
  }
}

// Dijkstra Testing
TEST_CASE("Dijkstra finds shortest path", "[weight=1][part=3]") {
  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertVertex("E");

  test.insertEdge("A", "C", 2);
  test.insertEdge("C", "B", 5);
  test.insertEdge("B", "A", 7);
  test.insertEdge("D", "C", 2);
  test.insertEdge("C", "E", 5);
  test.insertEdge("E", "D", 7);
  test.insertEdge("A", "E", 8);

  Dijkstra dj(test);
  std::vector<Vertex> output = dj.findShortestPath("A", "E", std::vector<Vertex>());  
  std::vector<Vertex> answer {"A", "C", "E"};
  
  REQUIRE(output.size() == answer.size());

  for (size_t i = 0; i < answer.size(); i++) {
    REQUIRE(output[i] == answer[i]); 
  }
}

TEST_CASE("Dijkstra finds vector of shortest paths", "[weight=1][part=3]") {
  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertVertex("E");

  test.insertEdge("A", "C", 2);
  test.insertEdge("C", "B", 5);
  test.insertEdge("B", "A", 7);
  test.insertEdge("D", "C", 2);
  test.insertEdge("C", "E", 5);
  test.insertEdge("E", "D", 7);
  test.insertEdge("A", "E", 8);

  Dijkstra dj(test);
  std::vector<std::vector<Vertex>> output = dj.findShortestPathVector("A");  
  std::vector<std::vector<Vertex>> answer;
  std::vector<Vertex> answer0 {"A", "C"};
  std::vector<Vertex> answer1 {"A", "C", "B"};
  std::vector<Vertex> answer2 {"A", "C", "E", "D"};
  std::vector<Vertex> answer3 {"A", "C", "E"};
  answer.push_back(answer0);
  answer.push_back(answer1);
  answer.push_back(answer2);
  answer.push_back(answer3);

  REQUIRE(output.size() == answer.size());

  for (size_t i = 0; i < answer.size(); i++) {
    for (size_t j = 0; j < answer[i].size(); j++) {
      REQUIRE(output[i][j] == answer[i][j]); 
    }
  }
}

TEST_CASE("Dijkstra with no path", "[weight=1][part=3]") {
  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertVertex("E");

  test.insertEdge("A", "C", 2);
  test.insertEdge("C", "B", 5);
  test.insertEdge("B", "A", 7);
  test.insertEdge("D", "C", 2);
  test.insertEdge("C", "E", 5);

  Dijkstra dj(test);
  std::vector<Vertex> output = dj.findShortestPath("A", "D", std::vector<Vertex>());  
  
  REQUIRE(output.empty());
}

TEST_CASE("Dijkstra with disconnected", "[weight=1][part=3]") {
  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertVertex("E");

  test.insertEdge("A", "C", 2);
  test.insertEdge("C", "B", 5);
  test.insertEdge("B", "A", 7);
  test.insertEdge("E", "D", 5);

  Dijkstra dj(test);
  std::vector<Vertex> output = dj.findShortestPath("A", "D", std::vector<Vertex>());  
  
  REQUIRE(output.empty());
}

TEST_CASE("Dijkstra with removed hubs", "[weight=1][part=3]") {
  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertVertex("E");

  test.insertEdge("A", "C", 2);
  test.insertEdge("C", "B", 5);
  test.insertEdge("B", "A", 7);
  test.insertEdge("C", "D", 2);
  test.insertEdge("C", "E", 5);
  test.insertEdge("E", "B", 4);
  test.insertEdge("A", "E", 5);
  test.insertEdge("B", "D", 2);

  Dijkstra dj(test);
  std::vector<Vertex> hubs {"C"};
  std::vector<Vertex> output = dj.findShortestPath("A", "D", hubs);  
  std::vector<Vertex> answer {"A", "E", "B", "D"};

  REQUIRE(output.size() == answer.size());

  for (size_t i = 0; i < answer.size(); i++) {
    REQUIRE(output[i] == answer[i]);
  }
}
