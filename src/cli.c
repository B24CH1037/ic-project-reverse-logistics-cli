#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "products.h"
#include "customers.h"
#include "warehouses.h"
#include "algorithms.h"
#include "return_classification.h"
#include "resale_prediction.h"  // Include new module

// Updated menu display with K-means resale prediction option.
void displayMenu() {
    printf("=======================================\n");
    printf(" Reverse Logistics CLI Interface\n");
    printf("=======================================\n");
    printf("1. List Products\n");
    printf("2. List Customers\n");
    printf("3. List Warehouses\n");
    printf("4. Find Best Warehouse (Dijkstra's Algorithm)\n");
    printf("5. Classify Return\n");
    printf("6. Predict Resale Price (K-means Clustering)\n");
    printf("7. Exit\n");
}

void processResalePredictionKMeans() {
    float originalPrice;
    float conditionScore;
    
    // Prompt for original price.
    printf("Enter the product's original price: ");
    scanf("%f", &originalPrice);
    getchar(); // Clear newline

    // Prompt for condition score (a numeric value, e.g., 0.0 to 1.0).
    printf("Enter the product's condition score (0.0 to 1.0): ");
    scanf("%f", &conditionScore);
    getchar();

    // Call the K-means based prediction function.
    float resalePrice = predictResalePriceKMeans(originalPrice, conditionScore);
    printf("Predicted Resale Price using K-means Clustering: $%.2f\n", resalePrice);
}

void processMenu(Product products[], int productCount, Customer customers[], int customerCount, Warehouse warehouses[], int warehouseCount) {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline

        switch(choice) {
            case 1:
                listProducts(products, productCount);
                break;
            case 2:
                listCustomers(customers, customerCount);
                break;
            case 3:
                listWarehouses(warehouses, warehouseCount);
                break;
            case 4: {
                double lat, lon;
                printf("Enter product's current latitude: ");
                scanf("%lf", &lat);
                printf("Enter product's current longitude: ");
                scanf("%lf", &lon);
                int bestIndex = dijkstraFindBestWarehouse(warehouses, warehouseCount, lat, lon);
                if (bestIndex != -1) {
                    printf("Best Warehouse using Dijkstra's Algorithm:\n");
                    printf("ID: %d | Name: %s | Location: %s\n",
                           warehouses[bestIndex].id,
                           warehouses[bestIndex].name,
                           warehouses[bestIndex].location);
                } else {
                    printf("No suitable warehouse found.\n");
                }
                break;
            }
            case 5:
                processReturnClassification();
                break;
            case 6:
                processResalePredictionKMeans();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 7);
}
