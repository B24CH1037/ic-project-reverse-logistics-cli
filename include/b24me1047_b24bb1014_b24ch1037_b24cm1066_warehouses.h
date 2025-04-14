#ifndef WAREHOUSES_H
#define WAREHOUSES_H

typedef struct {
    int id;
    char name[50];
    char location[100];
    double latitude;
    double longitude;
    int capacity;
    float costPerUnit;
} Warehouse;

int loadWarehouses(Warehouse warehouses[], const char *filename);

void listWarehouses(Warehouse warehouses[], int count);

#endif 
