#include "dataset.h"

#include <iostream>
#include <fstream>

Dataset::Dataset(std::string airport_path, std::string route_path) {
    std::cout << "Importing airports from " << airport_path << std::endl;

    int invalid_airports = 0;

    // iterate through each line
    std::fstream file;
    file.open(airport_path, std::ios::in);
    if(file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {

            // construct a new airport from each line, and append it if valid
            Airport a(line);
            if(a.valid()) {
                airport_lookup_.insert(std::pair<std::string, Airport>(a.getCode(), a));
                g_.insertVertex(a.getCode());
            } else {
                ++invalid_airports;
            }
        }
    } else {
        std::cout << "ERROR OPENING " << airport_path << std::endl;
        return;
    }
    file.close();

    std::cout << "Loaded " << airport_lookup_.size() << " valid airports (" << invalid_airports << " invalid airports)" << std::endl;
    std::cout << "Importing routes from " << route_path << std::endl;

    int routes = 0;
    file.open(route_path, std::ios::in);
    if(file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            std::string parts[8];

            int i = 0;
            std::string::iterator it = line.begin();
    
            // iterate through all 14 parts
            while(i < 8) {
                // if reached end of string, stop
                if(it == line.end()) {
                    break;

                // move to next part after each comma
                } else if (*it == ',') {
                    i++;

                // append the character to the correct part of the string
                } else {
                    parts[i].append(1, *it);
                }
                ++it;
            }
            std::string source = parts[2];
            std::string destination = parts[4];

            if(airport_lookup_.find(source) != airport_lookup_.end() && airport_lookup_.find(destination) != airport_lookup_.end()) {
                double distance = airport_lookup_[source].distance(airport_lookup_[destination]);
                g_.insertEdge(source, destination, distance);
                routes++;
            }
        }
    } else {
        std::cout << "ERROR OPENING " << route_path << std::endl;
        return;
    }

    std::cout << "Loaded " << routes << " valid routes" << std::endl;
    file.close();
}

Graph& Dataset::getGraph() {
    return g_;
}

const Airport& Dataset::getAirport(const std::string& code) const {
    if(airport_lookup_.find(code) != airport_lookup_.end()) {
        return airport_lookup_.find(code)->second;
    }
    return invalid_airport_;
}

size_t Dataset::size() const {
    return airport_lookup_.size();
}
