#ifndef CLI_H
#define CLI_H

#include "products.h"
#include "customers.h"
#include "warehouses.h"

// Declare the new return classification process
void processReturnClassification();


// Displays the main menu options
void displayMenu();

// Processes user input and dispatches commands.
// Takes loaded data arrays and their counts.
void processMenu(Product products[], int productCount,
                 Customer customers[], int customerCount,
                 Warehouse warehouses[], int warehouseCount);

            

#endif // CLI_H
