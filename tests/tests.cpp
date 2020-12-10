#include "../cs225/catch/catch.hpp"

#include <string>
#include <iostream>
#include <vector>

#include "../graph/graph.h"
#include "../algo/BetweennessCentrality.h"


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
