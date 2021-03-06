#pragma once

#include <string>

class Airport {
    public:
        // default constructor creates invalid airport
        Airport();

        // this constructor takes a line from airports.dat as input
        Airport(std::string line);

        bool valid() const;

        double distance(const Airport& other) const;

        // pass degrees=true for degrees or degrees=false for radians
        double getLat(const bool& degrees) const;
        double getLng(const bool& degrees) const;

        // getters for airport info
        std::string getCode() const;
        std::string getName() const;
        std::string getCity() const;
        std::string getCountry() const;

    private:
        bool valid_;

        // stored internally in radians
        double lat_;
        double lng_;

        std::string code_;
        std::string name_;
        std::string city_;
        std::string country_;
};