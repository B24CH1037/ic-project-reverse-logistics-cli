#include <stdio.h>
#include "warehouses.h"

int loadWarehouses(Warehouse warehouses[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }
    int count = 0;
    while (count < 50 &&
           fscanf(fp, "%d,%49[^,],%99[^,],%lf,%lf,%d,%f\n",
                  &warehouses[count].id,
                  warehouses[count].name,
                  warehouses[count].location,
                  &warehouses[count].latitude,
                  &warehouses[count].longitude,
                  &warehouses[count].capacity,
                  &warehouses[count].costPerUnit) == 7) {
        count++;
    }
    fclose(fp);
    return count;
}

void listWarehouses(Warehouse warehouses[], int count) {
    printf("----- Warehouse List -----\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Location: %s | Lat: %.4f | Lon: %.4f | Capacity: %d | Cost/Unit: $%.2f\n",
               warehouses[i].id, warehouses[i].name, warehouses[i].location,
               warehouses[i].latitude, warehouses[i].longitude,
               warehouses[i].capacity, warehouses[i].costPerUnit);
    }
}
