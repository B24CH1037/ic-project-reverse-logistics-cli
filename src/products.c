#include <stdio.h>
#include "products.h"

int loadProducts(Product products[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }
    int count = 0;
    while (count < 100 &&
           fscanf(fp, "%d,%49[^,],%29[^,],%f,%d,%d\n",
                  &products[count].id,
                  products[count].name,
                  products[count].category,
                  &products[count].price,
                  &products[count].stock,
                  &products[count].warehouseId) == 6) {
        count++;
    }
    fclose(fp);
    return count;
}

void listProducts(Product products[], int count) {
    printf("----- Product List -----\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Category: %s | Price: $%.2f | Stock: %d | Warehouse ID: %d\n",
               products[i].id, products[i].name, products[i].category,
               products[i].price, products[i].stock, products[i].warehouseId);
    }
}
