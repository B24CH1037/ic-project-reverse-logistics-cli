#ifndef CUSTOMERS_H
#define CUSTOMERS_H

typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[15];
    double latitude;   
    double longitude;  
} Customer;

int loadCustomers(Customer customers[], const char *filename);

void listCustomers(Customer customers[], int count);

#endif