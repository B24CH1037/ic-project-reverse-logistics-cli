#include <stdio.h>
#include "customers.h"

int loadCustomers(Customer customers[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }
    int count = 0;
    while (count < 100 &&
           fscanf(fp, "%d,%49[^,],%49[^,],%14s\n",
                  &customers[count].id,
                  customers[count].name,
                  customers[count].email,
                  customers[count].phone) == 4) {
        count++;
    }
    fclose(fp);
    return count;
}

void listCustomers(Customer customers[], int count) {
    printf("----- Customer List -----\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Email: %s | Phone: %s\n",
               customers[i].id, customers[i].name,
               customers[i].email, customers[i].phone);
    }
}
