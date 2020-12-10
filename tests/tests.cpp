#include "../cs225/catch/catch.hpp"

#include <string>
#include <iostream>
#include <vector>

#include "../graph/graph.h"
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
    REQUIRE( distance > 135);
    REQUIRE( distance < 136);
}
