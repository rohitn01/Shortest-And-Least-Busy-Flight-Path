#include "graph/graph.h"
#include "data/airport.h"
#include "data/dataset.h"
#include "algo/BFS.h"
#include "algo/Dijkstra.h"
#include "algo/BetweennessCentrality.h"

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
  //test.insertVertex("D");
  //test.insertVertex("E");
  //test.insertVertex("F");
  test.insertEdge("A", "B", 9);
  test.insertEdge("B", "C", 8);
  //test.insertEdge("A", "D", 4);
  //test.insertEdge("C", "D", 5);
  //test.insertEdge("D", "E", 7);
  //test.insertEdge("D", "F", 2);

  Vertex start = "A";
  Vertex end = "C";

  //BFS bfs(test);
  //std::vector<Vertex> output0 = bfs.findShortestPath(start, end); 

  //for (Vertex vertex : output0) {
  //  std::cout << vertex << " ";
  //}
  //std::cout << std::endl;

  Dijkstra dj(test);
  std::vector<Vertex> output1 = dj.findShortestPath(start, end); 

  for (Vertex vertex : output1) {
    std::cout << vertex << " ";
  }
  std::cout << std::endl;

  std::vector<Vertex> output2 = findCentralAirports(1, test); 

  for (Vertex vertex : output2) {
    std::cout << vertex << " ";
  }
  std::cout << std::endl;

  return 0;
}
