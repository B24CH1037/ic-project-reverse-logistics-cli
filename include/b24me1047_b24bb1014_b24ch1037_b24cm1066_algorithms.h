#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_warehouses.h"

double haversine(double lat1, double lon1, double lat2, double lon2);

int dijkstraFindBestWarehouse(Warehouse warehouses[], int count, double productLat, double productLon);

#endif