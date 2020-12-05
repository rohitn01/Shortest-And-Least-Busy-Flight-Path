#include "graph/graph.h"
#include "data/airport.h"

#include <iostream>

int main() {
  Graph g;
  g.insertVertex("Hi there");
  std::cout << "Hello World" << std::endl;

  //Airport a("test");
  Airport a("1,\"Goroka Airport\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");

  return 0;
}