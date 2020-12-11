#include "graph/graph.h"
#include "data/airport.h"
#include "data/dataset.h"
#include "algo/BFS.h"
#include "algo/Dijkstra.h"
#include "algo/BetweennessCentrality.h"

#include <iostream>

int main() {
  

  //std::cout << data.size() << std::endl;
  //Airport a("test");
  //Airport a1("1,\"Goroka Airport\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
  //Airport a2("2,\"Madang Airport\",\"Madang\",\"Papua New Guinea\",\"MAG\",\"AYMD\",-5.20707988739,145.789001465,20,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
  //Airport invalid("invalid");
  //std::cout << invalid.valid() << std::endl;
  //std::cout << a1.distance(a2) << std::endl;
  //Airport a("test");

  /*
  Graph test;
  test.insertVertex("A");
  test.insertVertex("B");
  test.insertVertex("C");
  test.insertVertex("D");
  test.insertVertex("E");
  test.insertVertex("F");
  test.insertEdge("A", "B", 9);
  test.insertEdge("B", "C", 8);
  test.insertEdge("A", "D", 4);
  test.insertEdge("C", "D", 5);
  test.insertEdge("D", "E", 7);
  test.insertEdge("E", "F", 8);
  test.insertEdge("C", "F", 3);

  Vertex start = "A";
  Vertex end = "F";
  std::vector<Vertex> hubs;
  hubs.push_back("C");
  hubs.push_back("D");

  */
  //BFS bfs(test);
  //std::vector<Vertex> output0 = bfs.findShortestPath(start, end, hubs); 

  //for (Vertex vertex : output0) {
  //  std::cout << vertex << " ";
  //}
  //std::cout << std::endl;

  /*
  Dijkstra dj(test);
  std::vector<Vertex> output1 = dj.findShortestPath(start, end, hubs); 

  for (Vertex vertex : output1) {
    std::cout << vertex << " ";
  }
  std::cout << std::endl;
  */
  /* // Commented out since it uses the old findShortestPathMap
  std::map<std::pair<Vertex, Vertex>, std::vector<Vertex>> boy = dj.findShortestPathMap(start);

  for (auto it = boy.begin(); it != boy.end(); it++) {
    std::cout << ((*it).first).first << " to " << ((*it).first).second << ": ";

    for (Vertex vertex : (*it).second) {
      std::cout << vertex << " ";
    }
    std::cout << std::endl;
  }
  */

  /*
  //Find top 100 centrally locatedAirports
  std::vector<Vertex> top100 = findCentralAirports(100, data.getGraph()); 
  std::cout<<"Top 10 Central Airports: "<<std::endl;
  for (size_t i = 0; i < 10; i++) {
    std::cout << top100[i] << " ";
  }
  std::cout << std::endl;

  //Example shortest paths without top airports
  //These currently do not work properly, 
  Dijkstra airportPaths(data.getGraph());
  std::cout<<"Shortest Path from CMI to Cape Town (CPT)"<<std::endl;
  auto CMICPT = airportPaths.findShortestPath("CMI", "CPT", std::vector<Vertex>());
  for (Vertex vertex : CMICPT) {
    std::cout << vertex << " ";
  }

  std::cout<<"Shortest Path from CMI to Cape Town (CPT) without hubs"<<std::endl;
  auto CMICPTH = airportPaths.findShortestPath("CMI", "CPT", top100);
  for (Vertex vertex : CMICPTH) {
    std::cout << vertex << " ";
  }

  std::cout<<"Shortest Path from CMI to Novosibirsk International Airport (OVB)"<<std::endl;
  auto CMIOVB = airportPaths.findShortestPath("CMI", "OVB", std::vector<Vertex>());
  for (Vertex vertex : CMIOVB) {
    std::cout << vertex << " ";
  }

  std::cout<<"Shortest Path from CMI to Novosibirsk International Airport (OVB) without hubs"<<std::endl;
  auto CMIOVBH = airportPaths.findShortestPath("CMI", "OVB", top100);
  for (Vertex vertex : CMIOVBH) {
    std::cout << vertex << " ";
  }

  std::cout<<"Shortest Path from ABC to DEF"<<std::endl;
  auto ABCDEF = airportPaths.findShortestPath("ABC", "DEF", std::vector<Vertex>());
  for (Vertex vertex : ABCDEF) {
    std::cout << vertex << " ";
  }

  std::cout<<"Shortest Path from ABC to DEF without hubs"<<std::endl;
  auto ABCDEFH = airportPaths.findShortestPath("ABC", "DEF", top100);
  for (Vertex vertex : ABCDEFH) {
    std::cout << vertex << " ";
  }

  */
  Dataset data("data/airports.dat", "data/routes.dat");
  Dijkstra airportPaths(data.getGraph());
  std::vector<Vertex> hubs;
  int option;
  while(1) {
    std::cout << "There are currently " << hubs.size() << " excluded airports. Please select an option:" << std::endl;
    std::cout << "1) Adjust number of excluded hub airports" << std::endl;
    std::cout << "2) Print list of excluded hub airports" << std::endl;
    std::cout << "3) Determine the shortest route" << std::endl;
    std::cout << "4) Quit" << std::endl;
    std::cout << "Selection: ";

    while(!(std::cin >> option) || option < 1 || option > 4) {
      std::cout << "Pleast enter an option 1 and 4!" << std::endl << "Selection: ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if(option == 1) {
      std::cout << "Please enter the number of hub airports you would like to exclude." << std::endl;
      std::cout << "Hub airports: ";
      int excluded;
      while(!(std::cin >> excluded) || excluded < 0 || excluded > 500) {
        std::cout << "Pleast enter an option between 1 and 500!" << std::endl  << "Hub airports: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      std::cout << "Identifying the top " << excluded << " most central airports (this might take a few minutes)" << std::endl;
      hubs = findCentralAirports(excluded, data.getGraph()); 
      std::cout << "Done!" << std::endl;

    } else if (option == 2) {
      if(hubs.size() > 0) {
        for(size_t i = 0; i < hubs.size() - 1; i++) {
          std::cout << hubs[i] << ", ";
        }
        std::cout << hubs[hubs.size() - 1] << std::endl;
      } else {
        std::cout << "No hubs!" << std::endl;
      }

    } else if (option == 3) {
      std::string origin;
      std::string destination;

      std::cout << "Please enter 3-character airport codes in ALL CAPS" << std::endl;
      std::cout << "Origin: ";
      while(!(std::cin >> origin) || !data.getAirport(origin).valid()) {
        std::cout << "Could not find an airport with that code!" << std::endl << "Origin: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }

      std:: cout << "Destination: ";
      while(!(std::cin >> destination) || !data.getAirport(destination).valid()) {
        std::cout << "Could not find an airport with that code!" << std::endl << "Destination: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }

      auto route = airportPaths.findShortestPath(origin, destination, hubs);
      std::cout << "Shortest route: ";
      for (Vertex vertex : route) {
        std::cout << vertex << " ";
      }
      std::cout << std::endl;

    } else {
      return 0;
    }
    std::cout << std::endl;
  }
  return 0;
}
