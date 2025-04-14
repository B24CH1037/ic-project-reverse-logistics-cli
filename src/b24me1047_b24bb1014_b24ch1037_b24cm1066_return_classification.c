#include <stdio.h>
#include <string.h>
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_return_classification.h"

const char* classifyReturn(const char* returnReason, const char* condition) 
{
    if (strcmp(returnReason, "Defective") == 0) {
        if (strcmp(condition, "Damaged") == 0) {
            return "Refurbish";
        } else if (strcmp(condition, "Broken") == 0) {
            return "Recycle";
        } else {
            return "Refurbish";  
        }
    } else if (strcmp(returnReason, "Minor Issue") == 0) {
        return "Resell at Discount";
    } else if (strcmp(returnReason, "Customer Remorse") == 0) {
        return "Resell at Original Price";
    } else {
        return "Manual Inspection Required";
    }
}

void processReturnClassification() 
{
    char returnReason[50];
    char condition[50] = ""; 
    printf("Enter return reason (e.g., Defective, Minor Issue, Customer Remorse): ");
    fgets(returnReason, sizeof(returnReason), stdin);
    returnReason[strcspn(returnReason, "\n")] = '\0'; 

    if (strcmp(returnReason, "Defective") == 0) {
        printf("Enter product condition (e.g., Damaged, Broken): ");
        fgets(condition, sizeof(condition), stdin);
        condition[strcspn(condition, "\n")] = '\0';
    }

    const char* recommendation = classifyReturn(returnReason, condition);
    printf("Recommended Action: %s\n", recommendation);
}