#include <stdio.h>
#include <stdlib.h>
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_cli.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_products.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_customers.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_warehouses.h"

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100
#define MAX_WAREHOUSES 50

int main() 
{
    Product products[MAX_PRODUCTS];
    Customer customers[MAX_CUSTOMERS];
    Warehouse warehouses[MAX_WAREHOUSES];

    int productCount = loadProducts(products, "data/products.csv");
    int customerCount = loadCustomers(customers, "data/customers.csv");
    int warehouseCount = loadWarehouses(warehouses, "data/warehouses.csv");

    processMenu(products, productCount, customers, customerCount, warehouses, warehouseCount);

    return 0;
}