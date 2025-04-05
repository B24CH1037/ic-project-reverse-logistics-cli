#ifndef RESALE_PREDICTION_H
#define RESALE_PREDICTION_H

// Predicts the resale price using K-means clustering on historical resale factors.
// originalPrice: the product's original price
// conditionScore: a float (0.0 to 1.0) representing the product condition (an initial guess for the resale factor)
// Returns the predicted resale price.
float predictResalePriceKMeans(float originalPrice, float conditionScore);

#endif // RESALE_PREDICTION_H
