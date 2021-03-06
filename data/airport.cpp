#include "airport.h"

#include <iostream>
#include <math.h>

// radius of earth, in miles
#define R 3950

// pi / 180
#define DEG_TO_RAD 0.01745329252

// 180 / pi
#define RAD_TO_DEG 57.29577951308

Airport::Airport() {
    valid_ = false;
}

Airport::Airport(std::string line) {
    valid_ = true;
    bool in_quotes = false;

    std::string parts[14];
    
    int i = 0;
    std::string::iterator it = line.begin();
    
    // iterate through all 14 parts
    while(i < 14) {
        // if reached end of string, stop
        if(it == line.end()) {
            break;

        } else if (*it == '"') {
            in_quotes = !in_quotes;


        // move to next part after each comma
        } else if (*it == ',' && !in_quotes) {
            i++;

        // append the character to the correct part of the string
        } else {
            parts[i].append(1, *it);
        }
        ++it;
    }

    // assign the parts based on position in list
    try {
        name_ = parts[1];
        city_ = parts[2];
        country_ = parts[3];
        code_ = parts[4];
        lat_ = stod(parts[6]) * DEG_TO_RAD;
        lng_ = stod(parts[7]) * DEG_TO_RAD;
    } catch (const std::exception& e) {
        valid_ = false;
        //std::cout << "Invalid airport: " << line << std::endl;
    }
    if(code_ == "\\N" || code_.size() != 3) valid_ = false;
}

// Returns distance between airports in miles
// or -1 if either airport is invalid
double Airport::distance(const Airport& other) const {
    // edge case: fed invalid airport
    if(!valid_ || !other.valid()) {
        return -1;
    } else {
        // https://en.wikipedia.org/wiki/Haversine_formula
        double dist = sin((other.getLat(false) - lat_)/2)*sin((other.getLat(false) - lat_)/2);
        dist += cos(lat_)*cos(other.getLat(false))*sin((other.getLng(false) - lng_)/2)*sin((other.getLng(false) - lng_)/2);
        dist = 2*R*asin(sqrt(dist));

        return dist;
    } 
}

bool Airport::valid() const {
    return valid_;
}

double Airport::getLat(const bool& degrees) const {
    if(degrees) {
        return valid_ ? lat_*RAD_TO_DEG : 0;
    }
    return valid_ ? lat_ : 0;
}

double Airport::getLng(const bool& degrees) const {
    if(degrees) {
        return valid_ ? lng_*RAD_TO_DEG : 0;
    }
    return valid_ ? lng_ : 0;
}

std::string Airport::getCode() const {
    return valid_ ? code_ : "INVALID";
}

std::string Airport::getName() const {
    return valid_ ? name_ : "INVALID";
}

std::string Airport::getCity() const {
    return valid_ ? city_ : "INVALID";
}

std::string Airport::getCountry() const {
    return valid_ ? country_ : "INVALID";
}