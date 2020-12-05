#pragma once

#include <string>

class Airport {
    public:
        // this constructor takes a line from airports.dat as input
        Airport(std::string line);

        bool valid() const;

        double distance(const Airport& other);

        // pass degrees=true for degrees or degrees=false for radians
        double getLat(const bool& degrees) const;
        double getLng(const bool& degrees) const;

        std::string getCode() const;
        std::string getName() const;
        std::string getCity() const;
        std::string getCountry() const;

    private:
        // disable default constructor
        Airport();

        bool valid_;

        // stored internally in radians
        double lat_;
        double lng_;

        std::string code_;
        std::string name_;
        std::string city_;
        std::string country_;
};