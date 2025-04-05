#ifndef RETURN_CLASSIFICATION_H
#define RETURN_CLASSIFICATION_H

// Returns a recommendation string for a product return based on its condition and reason.
const char* classifyReturn(const char* condition, const char* returnReason);

// Reads input from the user and prints the recommended return action.
void processReturnClassification();

#endif // RETURN_CLASSIFICATION_H
