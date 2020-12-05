#pragma once

#include <string>

class Airport {
    public:
        // this constructor takes a line from airports.dat as input
        Airport(std::string line);

        double distance(const Airport& other);

        double getLat() const;
        double getLng() const;
        std::string getCode() const;
        std::string getName() const;
        std::string getCity() const;
        std::string getCountry() const;

    private:
        // disable default constructor
        Airport();

        double lat;
        double lng;

        std::string code_;
        std::string name_;
        std::string city_;
        std::string country_;
};