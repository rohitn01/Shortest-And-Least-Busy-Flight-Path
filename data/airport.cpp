#include "airport.h"

#include <iostream>

Airport::Airport(std::string line) {
    std::string parts[14];
    
    int i = 0;
    std::string::iterator it = line.begin();
    while(i <= 14) {
        if(it == line.end()) {
            break;
        } else if (*it == ',') {
            i++;
        } else {
            parts[i].append(1, *it);
        }
        ++it;
    }

    for(int j = 0; j < 14; j++) {
        std::cout << parts[j] << std::endl;
    }

}
