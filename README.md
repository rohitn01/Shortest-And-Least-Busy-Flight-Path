# Shortest and Least Busy Flight Path Simulator

This program is intended to calculate airport routes from a given starting and destination airports. Our program has the ability to avoid hub airports, as defined by betweenness centrality. This is a group final project for CS225: Data Structures and Algorithms at the University of Illinois at Urbana-Champaign.

## Building

This project requires CMake installed in order to be built and run. Follow the official instructions [here](https://cmake.org/install/).

To start, clone and navigate into the repository:
```
git clone https://github-dev.cs.illinois.edu/cs225-fa20/txwong2-rohitn2-adtian2-jdlevy3
cd txwong2-rohitn2-adtian2-jdlevy3
```
Next, compile the file and test cases:
```
make clean
make test
make
```
Finally, run the tests and airports executable:
```
./test
./airports
```
