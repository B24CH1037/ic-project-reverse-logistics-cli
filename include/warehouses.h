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

// Loads warehouses from a CSV file.
// Returns the number of records loaded.
int loadWarehouses(Warehouse warehouses[], const char *filename);

// Displays the list of warehouses.
void listWarehouses(Warehouse warehouses[], int count);

#endif // WAREHOUSES_H
