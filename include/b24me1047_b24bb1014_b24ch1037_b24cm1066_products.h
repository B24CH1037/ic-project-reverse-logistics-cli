#ifndef PRODUCTS_H
#define PRODUCTS_H

typedef struct {
    int id;
    char name[50];
    char category[30];
    float price;
    int stock;
    int warehouseId;  
} Product;

int loadProducts(Product products[], const char *filename);

void listProducts(Product products[], int count);

#endif
