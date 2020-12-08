#pragma once

#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#include "../graph/graph.h"
#include "BFS.h"
#include "Dijkstra.h"

/**
 * Finds the most central airports in the provided graph using the unweighted version of the betweenness centrality algorithm.
 * The unweighted version is used since the number of flights at an airports is more relevant than the distices of those flights.
 * 
 * @param numAirports The number of central airports to find
 * @param G Graph to search
 * 
 * @return A vector with the most central vertices (airports)
 */
std::vector<Vertex> findCentralAirports(int numAirports, Graph G);