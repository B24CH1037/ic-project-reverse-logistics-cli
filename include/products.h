#ifndef PRODUCTS_H
#define PRODUCTS_H

typedef struct {
    int id;
    char name[50];
    char category[30];
    float price;
    int stock;
    int warehouseId;  // Links product to a warehouse
} Product;

// Loads products from a CSV file.
// Returns the number of records loaded.
int loadProducts(Product products[], const char *filename);

// Displays the list of products.
void listProducts(Product products[], int count);

#endif // PRODUCTS_H
