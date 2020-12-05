#include "graph/graph.h"
#include "data/airport.h"

#include <iostream>

int main() {
  Graph g;
  g.insertVertex("Hi there");
  std::cout << "Hello World" << std::endl;

  //Airport a("test");
  Airport a1("1,\"Goroka Airport\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
  Airport a2("2,\"Madang Airport\",\"Madang\",\"Papua New Guinea\",\"MAG\",\"AYMD\",-5.20707988739,145.789001465,20,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
  Airport invalid("invalid");
  std::cout << invalid.valid() << std::endl;
  std::cout << a1.distance(a2) << std::endl;
  return 0;
}