#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "warehouses.h"

// Existing functions
double haversine(double lat1, double lon1, double lat2, double lon2);

// New function: Dijkstra-based warehouse selection
// Returns the index (in the warehouses array) for the best warehouse
int dijkstraFindBestWarehouse(Warehouse warehouses[], int count, double productLat, double productLon);

#endif // ALGORITHMS_H
