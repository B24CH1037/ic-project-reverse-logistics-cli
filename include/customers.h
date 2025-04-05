#ifndef CUSTOMERS_H
#define CUSTOMERS_H

typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[15];
} Customer;

// Loads customers from a CSV file.
// Returns the number of records loaded.
int loadCustomers(Customer customers[], const char *filename);

// Displays the list of customers.
void listCustomers(Customer customers[], int count);

#endif // CUSTOMERS_H
