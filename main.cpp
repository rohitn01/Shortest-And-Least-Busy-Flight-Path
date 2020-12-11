#include "graph/graph.h"
#include "data/airport.h"
#include "data/dataset.h"
#include "algo/BFS.h"
#include "algo/Dijkstra.h"
#include "algo/BetweennessCentrality.h"

#include <iostream>

int main() {
  Dataset data("data/airports.dat", "data/routes.dat");
  Dijkstra airportPathsDj(data.getGraph());
  BFS airportPathsBFS(data.getGraph());
  std::vector<Vertex> hubs;
  int option;

  while(1) {
    std::cout << "There are currently " << hubs.size() << " excluded airports. Please select an option:" << std::endl;
    std::cout << "1) Adjust number of excluded hub airports" << std::endl;
    std::cout << "2) Print list of excluded hub airports" << std::endl;
    std::cout << "3) Determine the shortest route using Dijkstras" << std::endl;
    std::cout << "4) Determine the shortest route using BFS" << std::endl;
    std::cout << "5) Quit" << std::endl;
    std::cout << "Selection: ";

    while(!(std::cin >> option) || option < 1 || option > 5) {
      std::cout << "Pleast enter an option between 1 and 5!" << std::endl << "Selection: ";
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

      auto route = airportPathsDj.findShortestPath(origin, destination, hubs);
      std::cout << "Shortest route: ";
      for (Vertex vertex : route) {
        std::cout << vertex << " ";
      }
      std::cout << std::endl;

    } else if (option == 4) {
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

      auto route = airportPathsBFS.findShortestPath(origin, destination, hubs);
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
