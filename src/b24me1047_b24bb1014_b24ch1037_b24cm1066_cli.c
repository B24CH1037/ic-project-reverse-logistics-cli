#include <stdio.h>
#include <string.h>
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_cli.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_products.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_customers.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_warehouses.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_algorithms.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_return_classification.h"
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_resale_prediction.h" 

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

void processResalePredictionKMeans() 
{
    float originalPrice;
    float conditionScore;
    
    printf("Enter the product's original price: ");
    scanf("%f", &originalPrice);
    getchar(); 

    printf("Enter the product's condition score (0.0 to 1.0): ");
    scanf("%f", &conditionScore);
    getchar();

    float resalePrice = predictResalePriceKMeans(originalPrice, conditionScore);
    printf("Predicted Resale Price using K-means Clustering: ₹%.2f\n", resalePrice);
}

void processMenu(Product products[], int productCount, Customer customers[], int customerCount, Warehouse warehouses[], int warehouseCount) 
{
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

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
                int customerId;
                printf("Enter Customer ID: ");
                scanf("%d", &customerId);

                int found = 0;
                double lat = 0.0, lon = 0.0;
                for (int i = 0; i < customerCount; i++) {
                    if (customers[i].id == customerId) {
                        lat = customers[i].latitude;
                        lon = customers[i].longitude;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Customer with ID %d not found.\n", customerId);
                    break;
                }

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