#pragma once

#include <string>
#include <map>
#include <unordered_map>

#include "airport.h"
#include "../graph/graph.h"

class Dataset {
    public:
        // constructor takes path to airports.dat and routes.dat respectively
        Dataset(std::string airport_path, std::string route_path);
        
        // getter methods to get the graph data structure and airport metadata
        const Graph& getGraph() const;
        const Airport& getAirport(const std::string& code) const;
        size_t size() const;
        
    private:
        // disable default constructor
        Dataset();

        Graph g_;
        Airport invalid_airport_;
        std::unordered_map<std::string, Airport> airport_lookup_;
};

