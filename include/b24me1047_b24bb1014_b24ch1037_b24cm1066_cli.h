#ifndef CLI_H
#define CLI_H

#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_products.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_customers.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_warehouses.h"

void processReturnClassification();

void displayMenu();

void processMenu(Product products[], int productCount,
                 Customer customers[], int customerCount,
                 Warehouse warehouses[], int warehouseCount);

            

#endif 
