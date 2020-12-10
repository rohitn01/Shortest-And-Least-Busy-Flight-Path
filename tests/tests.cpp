#include "../cs225/catch/catch.hpp"

#include <string>
#include <iostream>
#include <vector>

#include "../graph/graph.h"


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