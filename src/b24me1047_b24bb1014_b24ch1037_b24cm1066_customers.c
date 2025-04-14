#include <stdio.h>
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_customers.h"

int loadCustomers(Customer customers[], const char *filename) 
{
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    char buffer[256];
    int count = 0;

    // Skip header line
    fgets(buffer, sizeof(buffer), fp);

    while (count < 100 &&
           fscanf(fp, "%d,%49[^,],%49[^,],%14[^,],%lf,%lf\n",
                  &customers[count].id,
                  customers[count].name,
                  customers[count].email,
                  customers[count].phone,
                  &customers[count].latitude,
                  &customers[count].longitude) == 6) {
        count++;
    }

    fclose(fp);
    return count;
}

void listCustomers(Customer customers[], int count) 
{
    printf("----- Customer List -----\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Email: %s | Phone: %s | Lat: %.6f | Lon: %.6f\n",
               customers[i].id, customers[i].name,
               customers[i].email, customers[i].phone,
               customers[i].latitude, customers[i].longitude);
    }
}