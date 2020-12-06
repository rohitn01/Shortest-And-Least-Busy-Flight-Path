#include "graph/graph.h"
#include "data/airport.h"
#include "data/dataset.h"
#include "algo/BFS.h"

#include <iostream>

int main() {
  Dataset data("data/airports.dat", "data/routes.dat");

  //std::cout << data.size() << std::endl;
  //Airport a("test");
  //Airport a1("1,\"Goroka Airport\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
  //Airport a2("2,\"Madang Airport\",\"Madang\",\"Papua New Guinea\",\"MAG\",\"AYMD\",-5.20707988739,145.789001465,20,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
  //Airport invalid("invalid");
  //std::cout << invalid.valid() << std::endl;
  //std::cout << a1.distance(a2) << std::endl;
  //Airport a("test");


  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertEdge("A", "B", 1);
  test.insertEdge("B", "D", 1);
  test.insertEdge("B", "C", 1);
  test.insertEdge("A", "C", 1);
  test.insertEdge("C", "D", 1);

  Vertex start = "A";
  Vertex end = "D";

  BFS bfs;
  //std::vector<Vertex> output = bfs.findShortestPath(start, end); 

  //for (Vertex vertex : output) {
  //  std::cout << vertex << " ";
  //}
  //std::cout << std::endl;

  return 0;
}
