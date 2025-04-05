#include <stdio.h>
#include "products.h"
#include "customers.h"
#include "warehouses.h"
#include "algorithms.h"

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100
#define MAX_WAREHOUSES 50

int main() {
    Product products[MAX_PRODUCTS];
    Customer customers[MAX_CUSTOMERS];
    Warehouse warehouses[MAX_WAREHOUSES];

    int productCount = loadProducts(products, "../data/products.csv");
    int customerCount = loadCustomers(customers, "../data/customers.csv");
    int warehouseCount = loadWarehouses(warehouses, "../data/warehouses.csv");

    printf("Loaded %d products, %d customers, and %d warehouses.\n\n",
           productCount, customerCount, warehouseCount);

    // Test listing functions
    listProducts(products, productCount);
    printf("\n");
    listCustomers(customers, customerCount);
    printf("\n");
    listWarehouses(warehouses, warehouseCount);
    printf("\n");

    // Test haversine function (example: New York to Los Angeles)
    double distance = haversine(40.7128, -74.0060, 34.0522, -118.2437);
    printf("Distance between New York and Los Angeles: %.2f km\n\n", distance);

    // Test finding best warehouse for a sample product location (lat=40.0, lon=-75.0)
    int bestIndex = findBestWarehouse(warehouses, warehouseCount, 40.0, -75.0);
    if (bestIndex != -1) {
        printf("Best warehouse for product at (40.0,-75.0):\n");
        printf("ID: %d | Name: %s | Location: %s\n",
               warehouses[bestIndex].id, warehouses[bestIndex].name, warehouses[bestIndex].location);
    } else {
        printf("No suitable warehouse found.\n");
    }

    return 0;
}
