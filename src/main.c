#include <stdio.h>
#include <stdlib.h>
#include "cli.h"
#include "products.h"
#include "customers.h"
#include "warehouses.h"

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100
#define MAX_WAREHOUSES 50

int main() {
    Product products[MAX_PRODUCTS];
    Customer customers[MAX_CUSTOMERS];
    Warehouse warehouses[MAX_WAREHOUSES];

    // Load CSV data from the data folder
    int productCount = loadProducts(products, "data/products.csv");
    int customerCount = loadCustomers(customers, "data/customers.csv");
    int warehouseCount = loadWarehouses(warehouses, "data/warehouses.csv");

    // Process CLI menu with the loaded data
    processMenu(products, productCount, customers, customerCount, warehouses, warehouseCount);

    return 0;
}
