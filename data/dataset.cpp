#include "dataset.h"

#include <iostream>
#include <fstream>

Dataset::Dataset(std::string airport_path, std::string route_path) {
    std::fstream file;
    file.open(airport_path, std::ios::in);
    if(file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            Airport a(line);
            if(a.valid()) {
                airport_lookup_.insert(std::pair<std::string, Airport>(a.getCode(), a));
                g_.insertVertex(a.getCode());
            }
        }
    } else {
        std::cout << "ERROR OPENING " << airport_path << std::endl;
        return;
    }
    file.close();

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

            std::cout << "Source: " << source << " Destination: " << destination << std::endl;
            if(airport_lookup_.find(source) != airport_lookup_.end() && airport_lookup_.find(destination) != airport_lookup_.end()) {
                double distance = airport_lookup_[source].distance(airport_lookup_[destination]);
                g_.insertEdge(source, destination, distance);
            }
        }
    } else {
        std::cout << "ERROR OPENING " << route_path << std::endl;
        return;
    }
    file.close();
}

const Graph& Dataset::getGraph() const {
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